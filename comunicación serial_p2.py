import serial  
import time
from Adafruit_IO import RequestError, Client, Feed

#Introducimos USERNAME de Adafruit
ADAFRUIT_IO_USERNAME = '######'
#introducimos adafuir IO key
ADAFRUIT_IO_KEY = '#####'
#Creamos el instance del REST CLIENT
aio = Client(ADAFRUIT_IO_USERNAME, ADAFRUIT_IO_KEY )

potenciometro_feed = aio.feeds('potenciometro-mduino')

ser = serial.Serial('COM3',9600) #inicializamos el puerto y velocidad de la comunicación serial
time.sleep(1)
estado = 0

while True: 
    leds_feed = aio.receive('start') #recibimos el valor del arranque
    estado = (leds_feed.value) #guardamos el valor en una variable
    print("valor de led",estado)
    time.sleep(1)


    if estado=="on":
        delay1_feed = aio.receive('delay1') #recibimos el tiempo del FOCO 1
        delay2_feed = aio.receive('delay2') #recibimos el tiempo del FOCO 2
        delay3_feed = aio.receive('delay3') #recibimos el tiempo del FOCO 3
        n1 = (delay1_feed.value) #guardamos el tiempo 1 en una variable
        n2 = (delay2_feed.value) #guardamos el tiempo 2 en una variable
        n3 = (delay3_feed.value) #guardamos el tiempo 3 en una variable
        print("valor de n1",n1)
        print("valor de n2",n2)
        print("valor de n3",n3)
        time.sleep(2)
        ser.write(estado.encode()) #enviamos al PLC el valor de estado para inicializar
        time.sleep(2.5)
        ser.write(n1.encode())
        time.sleep(2.5)
        ser.write(n2.encode())
        time.sleep(2.5)
        ser.write(n3.encode())
        print("serial enviado")
        time.sleep(15) # tiempo de espera para recibir mismos valores o un cambio de valores
    else: 
        print("Define los tiempos de cada FOCO e inicializa")

