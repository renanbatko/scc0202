all:clear
	@gcc -c listaestatica.c

run:
	@gcc listaestatica.o main.c -o programa; ./programa > $(RUNCODES_OUTPUT)

clear:
	@rm programa -rf
