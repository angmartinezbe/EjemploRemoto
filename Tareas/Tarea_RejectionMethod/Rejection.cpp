#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <vector>

double fun(double x) {
    return 3.0*(1-x*x)/4.0;
}

int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);
    const int SAMPLES = std::atoi(argv[2]);
    const double XMIN = std::atoi(argv[3]);
    const double XMAX = std::atoi(argv[4]);
    const int NBINS = std::atoi(argv[5]);
    const double DX = (XMAX-XMIN)/NBINS;

    std::vector<double> histo(NBINS, 0.0);
    std::mt19937 gen(SEED);
    std::uniform_real_distribution<double> xu(-1.0, 1.0);
    std::uniform_real_distribution<double> yu(0.0, 3.0/4.0);
    std::ofstream fout("datos.txt");
    for (int ii = 0; ii < SAMPLES;) {
        double xr = xu(gen);
        double yr = yu(gen);
        if (yr < fun(xr)) {
            fout << xr << "\n";
            int bin = int((xr - XMIN)/DX);
            if (0 <= bin && bin < NBINS) {
                histo[bin]++;
		++ii;
            }
        }
    }
    fout.close();

    fout.open("density.txt");
    for (int ii = 0; ii < NBINS; ii++) {
        fout << XMIN + ii*DX << "\t" << histo[ii]/(DX*SAMPLES) << "\n";
    }
    fout.close();

    return 0;
}
