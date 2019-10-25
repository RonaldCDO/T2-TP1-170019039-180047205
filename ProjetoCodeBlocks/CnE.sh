g++ dominios.hpp
g++ dominios.cpp -c
g++ entidades.hpp
g++ entidades.cpp -c

g++ interfaces.hpp
g++ MAutApres.hpp
g++ MAutApres.cpp -c
g++ MAutServ.hpp
g++ MAutServ.cpp -c

g++ dominios.o entidades.o MAutApres.o MAutServ.o main.cpp -o main