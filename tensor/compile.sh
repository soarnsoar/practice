g++ -c src/Vector.cc
#g++ -o main.exe main.cc Vector.o
g++ -c src/Transform.cc
g++ -c src/LorentzSpace.cc
g++ -o main.exe main.cc Vector.o Transform.o LorentzSpace.o
#g++ src/Vector.cc src/Transform.cc
#g++ -c src/Transform.cc

#
#g++ -o main.exe main.cc Vector.o Transform.o
./main.exe
