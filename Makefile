CXX = g++
MACHINE= $(shell uname -s)
ifeq ($(MACHINE),Darwin)
    SDL = -framework SDL2 -framework SDL2_image
    CXXFLAGS = -Wall -c -std=c++11
    LDFLAGS = $(SDL)
else
    SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_image -Wl,-rpath=/usr/local/lib
	SDL_INCLUDE = -I/usr/local/include
	CXXFLAGS = -Wall -c -std=c++11 $(SDL_INCLUDE)
	LDFLAGS = $(SDL_LIB)
endif

CPP_FILES = $(wildcard src/*.cpp)

OBJ_FILES = $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
EXE = SimpleRPG


all: $(EXE)

$(EXE): $(OBJ_FILES)
	$(CXX) $^ $(LDFLAGS) -o $@

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm obj/* && rm $(EXE)

run:
	@$(MAKE) && ./$(EXE)
