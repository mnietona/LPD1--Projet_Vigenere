# MATIAS NIETO NAVARRETE

FLAGS =  -Wpedantic -Wall -Wextra -Wconversion \
-Wsign-conversion -Weffc++ -Wstrict-null-sentinel \
-Wold-style-cast -Wnoexcept -Wctor-dtor-privacy \
-Woverloaded-virtual -Wsign-promo -Wzero-as-null-pointer-constant \
-Wsuggest-final-types -Wsuggest-final-methods -Wsuggest-override

ERREUR = -Werror

CC = g++
SOURCES=  Vigenere.cpp Fichier.cpp Decriptage.cpp Texte.cpp 
ATK = attack.cpp 
DECR = decrypt.cpp
OBJS=$(SOURCES:.cpp=.o)

all : attack decrypt

attack :${OBJS} $(ATK:.cpp=.o)
	${CC} $^ -o $@
	
decrypt :${OBJS} $(DECR:.cpp=.o)
	${CC} $^ -o $@
	
$(OBJS) $(ATK:.cpp=.o) $(DECR:.cpp=.o) : ${SOURCES} ${ATK} ${DECR}
	${CC} ${FLAGS} -c ${ATK} -o ${ATK:.cpp=.o} 
	${CC} ${FLAGS} -c ${DECR} -o ${DECR:.cpp=.o}
	${CC} ${FLAGS} -c Vigenere.cpp -o Vigenere.o
	${CC} ${FLAGS} -c Fichier.cpp -o Fichier.o
	${CC} ${FLAGS} -c Decriptage.cpp -o Decriptage.o
	${CC} ${FLAGS} -c Texte.cpp -o Texte.o

clean :
	-rm -f *.o core *.core

rm : clean
	-rm -f attack decrypt




