#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;
using namespace chrono;

void convertToGrayscaleOpenMP(Mat& image) {
    #pragma omp parallel for
    for (int r = 0; r < image.rows; ++r) {
        for (int c = 0; c < image.cols; ++c) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            uchar gray_value = static_cast<uchar>(0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0]);
            image.at<uchar>(r, c) = gray_value;
        }
    }
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

    convertToGrayscaleOpenMP(imagen);

    imwrite(argv[2], imagen);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end_time - start_time);

    cout << "Total time spent in seconds: " << duration.count() << endl;

    return 0;
}
