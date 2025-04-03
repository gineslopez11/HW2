CXX = g++
CXXFLAGS = -std=c++14

EJ1_EXEC = EJ1/Main1
EJ2_EXEC = EJ2/Main2
EJ3_EXEC = EJ3/Main3
EJ4_EXEC = EJ4/Main4

EJ1_SRC = EJ1/Main1.cpp EJ1/Implementacion1.cpp
EJ2_SRC = EJ2/Main2.cpp EJ2/Implementacion2.cpp
EJ3_SRC = EJ3/Main3.cpp EJ3/Implementacion3.cpp
EJ4_SRC = EJ4/Main4.cpp EJ4/Implementacion4.cpp


all: $(EJ1_EXEC) $(EJ2_EXEC) $(EJ3_EXEC) $(EJ4_EXEC)

$(EJ1_EXEC): $(EJ1_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EJ2_EXEC): $(EJ2_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EJ3_EXEC): $(EJ3_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(EJ4_EXEC): $(EJ4_SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EJ1_EXEC) $(EJ2_EXEC) $(EJ3_EXEC) $(EJ4_EXEC)
