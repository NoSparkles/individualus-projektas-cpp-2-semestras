all: build run

build:
	g++ -o proj proj.cpp

run: build
	./proj