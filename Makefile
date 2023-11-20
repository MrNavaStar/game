# lab09

game:
	cd src && make && mv game ../game && cp -r assets ../assets

.PHONY:
clean:
	rm -r -f game assets
	cd src && make clean