# Nombre del compilador
CXX = g++

# Opciones del compilador
CXXFLAGS = -g -Wall -I./src/Logica/Dto -I./src/Logica/Dominio -I./src/Logica/Controller -I./src/Presentacion

# Directorios de los archivos fuente
SRC_DIRS = ./src/Logica/Dto ./src/Logica/Dominio ./src/Logica/Controller ./src/Presentacion ./src

# Archivos fuente
SRCS = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))

# Archivos objeto
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
EXEC = lab4

# Regla principal
all: $(EXEC)

# Regla para enlazar el ejecutable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Regla para recompilar todo desde cero
rebuild: clean all

# Regla para crear un archivo zip del código fuente
zip: $(SRCS) $(wildcard $(addsuffix /*.h, $(SRC_DIRS))) Makefile
	rm -f codigo.tar.gz
	tar -cvf codigo.tar $(SRCS) $(wildcard $(addsuffix /*.h, $(SRC_DIRS))) Makefile
	gzip codigo.tar