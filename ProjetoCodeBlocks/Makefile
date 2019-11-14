DE = -I ./DominiosEntidades/
INT = -I ./Interfaces/
SA = -I ./SubSistAutentic/
SU = -I ./SubSistUser/
SR = -I ./SubSistRide/
SI = -I ./SubSistInicializacao/
REPO = -I ./Containers/
LDLIBS = -lncurses

executable: main.o dominios.o entidades.o MAutApres.o MUserApres.o MRidApres.o MUserServ.o MAutServ.o MRidServ.o MInit.o containers.o
	g++ main.o entidades.o dominios.o MAutApres.o MUserApres.o MRidApres.o containers.o MUserServ.o MAutServ.o MRidServ.o MInit.o -o executable -lncurses

main.o: main.cpp DominiosEntidades/dominios.hpp DominiosEntidades/entidades.hpp SubSistAutentic/MAutApres.hpp SubSistUser/MUserApres.hpp SubSistRide/MRidApres.hpp SubSistUser/MUserServ.hpp SubSistAutentic/MAutServ.hpp SubSistRide/MRidServ.hpp SubSistInicializacao/MInit.hpp Containers/containers.hpp
	g++ $(DE) $(SA) $(SU) $(SR) $(INT) $(REPO) $(SI) -c main.cpp

MInit.o: SubSistInicializacao/MInit.cpp SubSistInicializacao/MInit.hpp DominiosEntidades/dominios.hpp DominiosEntidades/entidades.hpp SubSistAutentic/MAutApres.hpp SubSistUser/MUserApres.hpp SubSistRide/MRidApres.hpp SubSistUser/MUserServ.hpp SubSistAutentic/MAutServ.hpp SubSistRide/MRidServ.hpp Containers/containers.hpp
	g++ $(DE) $(SA) $(SU) $(SR) $(INT) $(REPO) $(SI) -c SubSistInicializacao/MInit.cpp

MRidServ.o: SubSistRide/MRidServ.cpp SubSistRide/MRidServ.hpp Containers/containers.hpp
	g++ $(INT) $(REPO) $(DE) -c SubSistRide/MRidServ.cpp

MUserServ.o: SubSistUser/MUserServ.cpp SubSistUser/MUserServ.hpp Containers/containers.hpp
	g++ $(INT) $(REPO) $(DE) -c SubSistUser/MUserServ.cpp

MAutServ.o: SubSistAutentic/MAutServ.cpp SubSistAutentic/MAutServ.hpp Containers/containers.hpp
	g++ $(INT) $(REPO) $(DE) -c SubSistAutentic/MAutServ.cpp

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
	rm main.o MAutApres.o MUserApres.o dominios.o entidades.o