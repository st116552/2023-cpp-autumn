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
    sum = (n + 1) * (abs(n - 1) + 1) / 2;
    ofstream fout;
    fout.open("output.txt");
    fout << sum;
    fout.close();
    return 0;
}