

# lab10
# Group: 2
# Members: Neshko and Ethan

game:
	mkdir bin && mkdir obj && cd src && make && mv game ../bin/game && cp -r assets ../bin/assets && mv *.o ../obj/

.PHONY:
clean:
	rm -f -r html latex
	cd bin && rm -f game *.o *~ && rm -r assets
	cd obj && rm -f game *.o *~

docs:
	doxygen config
	

