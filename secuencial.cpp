#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;
using namespace chrono;

void convertToGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

int main(int argc, char** argv) {
    if (argc != 4) {
        cout << "Uso: " << argv[0] << " <imagen_color> <imagen_gris> <num_hebras>" << endl;
        return -1;
    }

    Mat imagen = imread(argv[1], IMREAD_COLOR);
    if (imagen.empty()) {
        cout << "Error: No se pudo leer el archivo de imagen." << endl;
        return -1;
    }

    int num_hebras = stoi(argv[3]);

    auto start_time = high_resolution_clock::now();

    convertToGrayscale(imagen);

    imwrite(argv[2], imagen);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end_time - start_time);

    cout << "Total time spent in seconds: " << duration.count() << endl;

    return 0;
}

