default: stackapp

dynArray : dynArray.c dynArray.h type.h 
	gcc -Wall -ansi -c dynArray.c 
	
stackapp : stackapp.c dynArray.c dynArray.h type.h 	
	gcc -Wall -ansi -c stackapp.c dynArray.c
	
clean:
	rm dynArray stackapp

cleanall: clean
	rm prog 