all: report

report: temp_function.o report.o
	gcc -o report temp_function.o report.o

temp_function.o: temp_function.c
	gcc -c -o temp_function.o temp_function.c

report.o: report.c
	gcc -c -o report.o report.c

clean:
	del *.o
	del report.exe