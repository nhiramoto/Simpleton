COMP=g++
FLAGS=

executa: main
	@echo "[Enter] para continuar..."
	@read a
	@clear
	@rm *.o
	@chmod 755 ./main
	@./main

main: main.o simpleton.o memoria.o reg.o glob.o
	$(COMP) $(FLAGS) -o $@ main.o simpleton.o memoria.o reg.o glob.o

main.o: main.cpp
	$(COMP) $(FLAGS) -c main.cpp

simpleton.o: simpleton.cpp
	$(COMP) $(FLAGS) -c simpleton.cpp

memoria.o: memoria.cpp
	$(COMP) $(FLAGS) -c memoria.cpp

reg.o: reg.cpp
	$(COMP) $(FLAGS) -c reg.cpp
	
glob.o: glob.cpp
	$(COMP) $(FLAGS) -c glob.cpp