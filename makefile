CXX := g++
CXXFLAGS := -Wall -MMD
EXEC := main
SOURCES := *.cc
OBJECTS := ${SOURCES:.cc=.o}
DEPENDS := ${SOURCES:.cc=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
	
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}