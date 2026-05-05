all: planificacion testsUnitarios tiempos

planificacion: main.cpp ar.cpp ar.hpp
	g++ main.cpp ar.cpp -o planificacion

testsUnitarios: testsUnitarios.cpp ar.cpp ar.hpp
	g++ testsUnitarios.cpp ar.cpp -o testsUnitarios

tiempos: tiempos.cpp ar.cpp ar.hpp
	g++ tiempos.cpp ar.cpp -o tiempos

clean:
	rm -f planificacion testsUnitarios tiempos resultados_ar.csv
