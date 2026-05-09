all: diversidad testsUnitarios tiempos

diversidad: main.cpp bt.cpp bt_aux.cpp bt_aux.hpp
	g++ main.cpp bt.cpp bt_aux.cpp -o diversidad

testsUnitarios: testsUnitarios.cpp bt.cpp bt_aux.cpp bt_aux.hpp
	g++ testsUnitarios.cpp bt.cpp bt_aux.cpp -o testsUnitarios

tiempos: tiempos.cpp bt.cpp bt_aux.cpp bt_aux.hpp
	g++ tiempos.cpp bt.cpp bt_aux.cpp -o tiempos

clean:
	rm -f diversidad testsUnitarios tiempos *.o *.csv assets/*.jpg
