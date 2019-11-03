DE = -I ./DominiosEntidades/
INT = -I ./Interfaces/
SA = -I ./SubSistAutentic/
SU = -I ./SubSistUser/
STUB = -I ./Stubs/
LDLIBS = -lncurses

executable: main.o dominios.o entidades.o stubs.o MAutApres.o MUserApres.o
	g++ main.o entidades.o dominios.o stubs.o MAutApres.o MUserApres.o -o executable -lncurses

mai: main.cpp DominiosEntidades/dominios.hpp DominiosEntidades/entidades.hpp SubSistAutentic/MAutApres.hpp SubSistUser/MUserApres.hpp Stubs/stubs.hpp
	g++ $(DE) $(SA) $(SU) $(STUB) $(INT) -c main.cpp

MUserApres.o: SubSistUser/MUserApres.cpp SubSistUser/MUserApres.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(SU) $(DE) -c SubSistUser/MUserApres.cpp

stubs.o: Stubs/stubs.cpp Stubs/stubs.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(STUB) $(DE) -c Stubs/stubs.cpp

MAutApres.o: SubSistAutentic/MAutApres.cpp SubSistAutentic/MAutApres.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(SA) $(DE) -c SubSistAutentic/MAutApres.cpp

entidades.o: DominiosEntidades/entidades.cpp DominiosEntidades/entidades.hpp DominiosEntidades/dominios.hpp
	g++ $(DE) -c DominiosEntidades/entidades.cpp

dominios.o: DominiosEntidades/dominios.cpp DominiosEntidades/dominios.hpp
	g++ $(DE) -c DominiosEntidades/dominios.cpp

clean:
	rm main.o MAutApres.o MUserApres.o stubs.o dominios.o entidades.o