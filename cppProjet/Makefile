CPP=g++ --std=c++11 -Wall

all :  
	@echo "Vous pouvez lancer"
	@echo " make ebaucheModel"
	@echo " make ebaucheVue (mais il faut avoir préalablement installé SFML)"
	@echo " make clean"

ebaucheModel : ebaucheModel.cpp
	$(CPP) ebaucheModel.cpp

ebaucheVue1 : ebaucheVue1.cpp
	$(CPP) -c ebaucheVue1.cpp
	g++ -o ebaucheVue1 ebaucheVue1.o -lsfml-system -lsfml-graphics -lsfml-window
	./ebaucheVue1

clean :
	rm *.o ebaucheVue1 a.out
