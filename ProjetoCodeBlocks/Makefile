DE = -I ./DominiosEntidades/
INT = -I ./Interfaces/
SA = -I ./SubSistAutentic/
SU = -I ./SubSistUser/
SR = -I ./SubSistRide/
STUB = -I ./Stubs/
REPO = -I ./Containers/
LDLIBS = -lncurses

executable: main.o dominios.o entidades.o stubs.o MAutApres.o MUserApres.o MRidApres.o MUserServ.o containers.o
	g++ main.o entidades.o dominios.o stubs.o MAutApres.o MUserApres.o MRidApres.o containers.o MUserServ.o -o executable -lncurses

main.o: main.cpp DominiosEntidades/dominios.hpp DominiosEntidades/entidades.hpp SubSistAutentic/MAutApres.hpp SubSistUser/MUserApres.hpp SubSistRide/MRidApres.hpp Stubs/stubs.hpp SubSistUser/MUserServ.hpp Containers/containers.hpp
	g++ $(DE) $(SA) $(SU) $(STUB) $(SR) $(INT) $(REPO) -c main.cpp

stubs.o: Stubs/stubs.cpp Stubs/stubs.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(STUB) $(DE) -c Stubs/stubs.cpp

MUserServ.o: SubSistUser/MUserServ.cpp SubSistUser/MUserServ.hpp Containers/containers.hpp
	g++ $(INT) $(REPO) $(DE) -c SubSistUser/MUserServ.cpp

MRidApres.o: SubSistRide/MRidApres.cpp SubSistRide/MRidApres.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(SR) $(DE) $(REPO) -c SubSistRide/MRidApres.cpp

MUserApres.o: SubSistUser/MUserApres.cpp SubSistUser/MUserApres.hpp Interfaces/interfaces.hpp Containers/containers.hpp
	g++ $(INT) $(SU) $(DE) $(REPO) -c SubSistUser/MUserApres.cpp

MAutApres.o: SubSistAutentic/MAutApres.cpp SubSistAutentic/MAutApres.hpp Interfaces/interfaces.hpp
	g++ $(INT) $(SA) $(DE) $(REPO) -c SubSistAutentic/MAutApres.cpp

containers.o: Containers/containers.cpp Containers/containers.hpp
	g++ $(REPO) $(DE) -c Containers/containers.cpp

entidades.o: DominiosEntidades/entidades.cpp DominiosEntidades/entidades.hpp DominiosEntidades/dominios.hpp
	g++ $(DE) -c DominiosEntidades/entidades.cpp

dominios.o: DominiosEntidades/dominios.cpp DominiosEntidades/dominios.hpp
	g++ $(DE) -c DominiosEntidades/dominios.cpp

clean:
	rm main.o MAutApres.o MUserApres.o stubs.o dominios.o entidades.o