all: diversidad testsUnitarios tiempos

diversidad: main.cpp bt.cpp bt_aux.cpp bt.hpp bt_aux.hpp common.hpp
	g++ main.cpp bt.cpp bt_aux.cpp -o diversidad

testsUnitarios: testsUnitarios.cpp bt.cpp bt_aux.cpp bt.hpp bt_aux.hpp common.hpp
	g++ testsUnitarios.cpp bt.cpp bt_aux.cpp -o testsUnitarios

tiempos: tiempos.cpp bt.cpp bt_aux.cpp bt.hpp bt_aux.hpp common.hpp
	g++ tiempos.cpp bt.cpp bt_aux.cpp -o tiempos

clean:
	rm -f diversidad testsUnitarios tiempos resultados.csv

.PHONY: clean all
