OSTYPE   := $(shell echo $$OSTYPE)
WINDOWS  := msys
LINUX    := "linux"
OSX      := "darwin"
CXX      := g++

ifeq ("$(OSTYPE)", "$(WINDOWS)")
LDFLAGS  := -LSDL2/lib -mwindows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
INCLUDE  := -Iinclude/ -ISDL2/include/
BUILD    := ./build/build-windows
CXXFLAGS := -std=c++0x -g -O3 -w -Wl,-subsystem,windows
else
LDFLAGS  := -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
INCLUDE  := -Iinclude/
BUILD    := ./build/build-linux
CXXFLAGS :=
endif

OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
SRC      :=                      \
   $(wildcard src/engine/*.cpp)    \
   $(wildcard src/engine/**/*.cpp)    \
   $(wildcard src/game/*.cpp)    \
   $(wildcard src/*.cpp)         \

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES \
         := $(OBJECTS:.o=.d)

all: clean build $(APP_DIR)/$(TARGET) run

run:
	$(APP_DIR)/program

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all build clean debug release info

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"