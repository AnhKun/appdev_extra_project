OBJ = main.o 
APPNAME = chart.out

#math library is used
$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

clean : 
	rm $(APPNAME) $(OBJ)

tar : 
	tar chart.tar *.c *.h makefile
