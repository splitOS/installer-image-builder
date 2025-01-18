.PHONY: build

build:
	g++ src/main.cpp -o dist/splitos-iib

clean:
	rm -rf dist/*

test:
	dist/splitos-iib