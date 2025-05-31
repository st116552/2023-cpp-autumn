#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// среднее
double avar(const vector<double>& data)
{
    double sum = 0.0;
    for (double u : data)
    {
        sum += u;
    }
    return sum / data.size();
}

//квадрат отклонения
vector<double> deviationSquar(vector<double>& randDevAr)
{
    vector<double> standAr;
    for (int i = 0; i < randDevAr.size(); i++)
    {
        double t = randDevAr[i];
        standAr.push_back(t * t);
    }
    return standAr;
}

//отклонение
vector<double> deviation(const vector<double>& data, double avar)
{
    vector<double> randDevAr;
    for (int i = 0; i < data.size(); i++)
    {
        randDevAr.push_back(data[i] - avar);
    }

    return randDevAr;
}


int main()
{
        const double gamma = 3.5;

    ifstream file("input1.txt");
    string line;
    vector<double> values;

    if (!file.is_open())
    {
        cerr << "no such file1" << endl;
        return 0;
    }

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;  
        }

        values.push_back(stod(line));
    }

    file.close();

    double mean = avar(values);
    cout << "mean: " << mean << endl;

    cout << "deltaR приб: " << gamma*mean/100;

    vector<double> dev = deviation(values, mean);

    for (int i = 0; i < dev.size(); i++)
    {
        cout << dev[i] << "\n";
    }
    cout << endl;

    vector<double> devSq = deviationSquar(dev);
    for (int i = 0; i < devSq.size(); i++)
    {
        cout << devSq[i] << "\n";
    }

    double tmp = 0;
    for (int i = 0; i < devSq.size(); i++) {
        tmp = tmp + devSq[i];
    }
     tmp = sqrt(tmp/(devSq.size() - 1));
    cout << "sigma: " << tmp << endl;
    cout << "sigmax-: " << tmp/sqrt((devSq.size()));

    return 0;
}
