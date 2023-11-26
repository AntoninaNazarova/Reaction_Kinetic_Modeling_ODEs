#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip> 

// Function to read data from file into a vector, specifically data_A1_new.dat","time.dat
bool readDataFromFile(const std::string& filename, std::vector<double>& data) {
    std::ifstream stream(filename);
    if (!stream) {
        std::cerr << "Error opening " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(stream, line)) {
        std::istringstream iss(line);
        double value;
        if (iss >> value) {
            data.push_back(value);
        } else {
            std::cerr << "Warning: Invalid data format in " << filename << std::endl;
        }
    }
    stream.close();
    return true;
}

// Function to perform the Runge-Kutta procedure
void rungeKutta(const std::vector<double>& s, const std::vector<double>& ds) {
    double a0 = 0.00535;
    double cat0 = 0.00058 * 2.;
    double h = 0.01;
    double sum1 = 10000.;
    double ka, kma, k11, k21, k31, k41, cat, sum, r7, r8;
    double ka1 = 0.0, kma1 = 0.0;  // Best ka and kma
    int i1;

    for (int i2 = 500; i2 < 6000; --i2) {
        ka = 0.005 * i2;
        for (int i3 = 1; i3 < 3000; ++i3) {
            kma = 0.00001 * i3;

            i1 = 0;
            cat = cat0;
            sum = 0.0;
            for (size_t i = 0; i < s.size() && i1 < ds.size(); ++i) {
                r7 = i * h;
                r8 = (i + 1) * h;
                k11 = -ka * (a0 - cat0 + cat) * cat + kma * (cat0 - cat);
                k21 = -ka * (a0 - cat0 + (cat + 0.5 * h * k11)) * (cat + 0.5 * h * k11) + kma * (cat0 - (cat + 0.5 * h * k11));
                k31 = -ka * (a0 - cat0 + (cat + 0.5 * h * k21)) * (cat + 0.5 * h * k21) + kma * (cat0 - (cat + 0.5 * h * k21));
                k41 = -ka * (a0 - cat0 + (cat + h * k31)) * (cat + h * k31) + kma * (cat0 - (cat + h * k31));

                cat = cat + h / 6.0 * (k11 + 2.0 * k21 + 2.0 * k31 + k41);

                if ((ds[i1] >= r7) && (ds[i1] < r8)) {
                    sum += std::pow((1.0 - s[i1] / cat), 2.0);
                    ++i1;
                }
            }

            if (sum1 > std::sqrt(sum)) {
                sum1 = std::sqrt(sum);
                ka1 = ka;
                kma1 = kma;
            }
        }

        std::cout << std::fixed << std::setprecision(3)  
          << "i2= " << i2 << " i3= " << i3 
          << " sum= " << sum << " sum1= " << sum1 
          << " ka= " << ka1 << " kma= " << kma1 << std::endl;
    }
}

int main() {
    std::vector<double> s, ds;

    // Read data from files
    if (!readDataFromFile("data_A1_new.dat", s)) return 1;
    if (!readDataFromFile("time.dat", ds)) return 1;

    // Call the Runge-Kutta procedure
    rungeKutta(s, ds);

    return 0;
}