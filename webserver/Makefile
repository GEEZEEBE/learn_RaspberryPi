SRCS = webserver.c cwe_webWiringPiControl.c
OPTIONS = -lwiringPi -lpthread 
OFILE = test 

test : 
	gcc -o $(OFILE) $(SRCS) $(OPTIONS) 

clean : 
	rm -f $(OFILE)
