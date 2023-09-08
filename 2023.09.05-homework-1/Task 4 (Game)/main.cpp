#include <fstream>

using namespace std;

int main() 
{
    int a, b, c, n;
    ifstream fin;
    fin.open("input.txt");
    fin >> n;
    fin.close();
    ofstream fout;
    fout.open("output.txt");
    fout << n * 100 + 90 + 9 - n;
    fout.close();
    return 0;
}