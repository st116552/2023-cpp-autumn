#include <fstream>
#include <stdlib.h>

using namespace std;

int main() 
{
    int n;
    int sum;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    fin.close();
    if (n <= 0) {
        sum = (n + 1) * (abs(n) + 2) / 2;
    } else {
        sum = (n + 1) * n / 2;
    }
    //sum = ((n + 1) * (abs(n) + 1 - n / abs(n))) / 2;
    ofstream fout;
    fout.open("output.txt");
    fout << sum;
    fout.close();
    return 0;
}