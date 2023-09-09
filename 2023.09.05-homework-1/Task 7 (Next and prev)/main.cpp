#include <fstream>
using namespace std;

int main()
{
    int a = 0;
    ifstream fin;
    fin.open("input.txt");
    fin >> a;
    fin.close();
    ofstream fout;
    fout.open("output.txt");
    fout <<  "The next number for the number " << a << " is " << a + 1 << ".\n";
    fout <<  "The previous number for the number " << a << " is " << a - 1 << ".";
    fout.close();
    return 0;
}