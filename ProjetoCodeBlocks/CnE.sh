g++ dominios.hpp
g++ dominios.cpp -c
g++ entidades.hpp
g++ entidades.cpp -c

g++ interfaces.hpp
g++ MAutApres.hpp
g++ MAutApres.cpp -c
g++ MUserApres.hpp
g++ MUserApres.cpp -c

g++ stubs.hpp
g++ stubs.cpp -c

g++ dominios.o entidades.o MAutApres.o MUserApres.o stubs.o main.cpp -o main
