# Run the build target as a default
.PHONY: build

# Utilities
compiler := g++
compilerOutFlag := -o

# Directories
sourceDirectory := src
objectsDirectory := dist

# Sources and objects
sources = $(sourceDirectory)/main.cpp $(sourceDirectory)/lib/api.cpp
mainObject = $(objectsDirectory)/splitos-iib

# Builds the program
build:
	mkdir -p $(objectsDirectory)
	$(compiler) $(sources) $(compilerOutFlag) $(mainObject)

# Cleans the objects directory
clean:
	rm -rf $(objectsDirectory)/*

# Test-runs the program
test:
	$(mainObject)