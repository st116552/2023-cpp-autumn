#include <fstream>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;;
    ifstream fin;
    fin.open("input.txt");
    fin >> a >> b;
    fin.close();
    ofstream fout;
    fout.open("output.txt");
    fout << (a / b * a + b / a * b) / (a / b + b / a);
    fout.close();
    return 0;
}