CXX = g++
CXXFLAGS = -std=c++11 -O3

# Configuración específica de OpenCV
OPENCV_CFLAGS = $(shell pkg-config --cflags opencv4)
OPENCV_LIBS = $(shell pkg-config --libs opencv4)

all: secuencial paralelo_thread paralelo_openmp

secuencial: secuencial.cpp
	$(CXX) $(CXXFLAGS) $(OPENCV_CFLAGS) -o secuencial secuencial.cpp $(OPENCV_LIBS)

paralelo_thread: paralelo_thread.cpp
	$(CXX) $(CXXFLAGS) $(OPENCV_CFLAGS) -o paralelo_thread paralelo_thread.cpp -lpthread $(OPENCV_LIBS)

paralelo_openmp: paralelo_openmp.cpp
	$(CXX) $(CXXFLAGS) $(OPENCV_CFLAGS) -fopenmp -o paralelo_openmp paralelo_openmp.cpp $(OPENCV_LIBS)

clean:
	rm -f secuencial paralelo_thread paralelo_openmp

