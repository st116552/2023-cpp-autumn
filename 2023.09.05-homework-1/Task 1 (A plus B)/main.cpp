#include <fstream>

using namespace std;

int main() 
{
    int a = 0;
    int b = 0;
    ifstream fin;
    fin.open("input.txt");
    fin >> a >> b;
    fin.close();
    ofstream fout;
    fout.open("output.txt");
    fout << a + b;
    fout.close();
    return 0;
}