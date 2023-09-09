#include <fstream>

using namespace std;

int main() 
{
    long long a = 0;
    long long ans = 0;;
    ifstream fin;
    fin.open("input.txt");
    fin >> a;
    fin.close();
    long long tmp = a / 10;
    ans = (tmp) * (tmp + 1) * 100 + 25;
    ofstream fout;
    fout.open("output.txt");
    fout << ans;
    fout.close();
    return 0;
}