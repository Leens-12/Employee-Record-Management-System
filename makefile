proFile: main.o helper.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o
	gcc -std=c99 -Wall main.o helper.o recruitEmployee.o printAll.o printOne.o lookOnId.o lookOnFullName.o countEmployees.o sortEmployeesId.o fireOne.o fireAll.o -o bin/proFile

main.o: src/main.c include/header.h
	gcc -std=c99 -Wall -c src/main.c

helper.o: src/helper.c include/header.h
	gcc -std=c99 -Wall -c src/helper.c

recruitEmployee.o: src/recruitEmployee.c include/header.h
	gcc -std=c99 -Wall -c src/recruitEmployee.c

printAll.o: src/printAll.c include/header.h
	gcc -std=c99 -Wall -c src/printAll.c

printOne.o: src/printOne.c include/header.h
	gcc -std=c99 -Wall -c src/printOne.c

lookOnId.o: src/lookOnId.c include/header.h
	gcc -std=c99 -Wall -c src/lookOnId.c

lookOnFullName.o: src/lookOnFullName.c include/header.h
	gcc -std=c99 -Wall -c src/lookOnFullName.c

countEmployees.o: src/countEmployees.c include/header.h
	gcc -std=c99 -Wall -c src/countEmployees.c

sortEmployeesId.o: src/sortEmployeesId.c include/header.h
	gcc -std=c99 -Wall -c src/sortEmployeesId.c

fireOne.o: src/fireOne.c include/header.h
	gcc -std=c99 -Wall -c src/fireOne.c

fireAll.o: src/fireAll.c include/header.h
	gcc -std=c99 -Wall -c src/fireAll.c

clean:
	rm *.o bin/proFile
