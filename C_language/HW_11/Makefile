all: sensor

sensor: temp_api.o 
	gcc -o sensor: temp_api.o 

temp_api.o: temp_api.c
	gcc -c -o temp_api.o temp_api.c

clean:
	del *.o
	del sensor.exe