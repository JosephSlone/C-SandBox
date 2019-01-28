#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int rows;
    int queries;

    cin >> rows;
    cin >> queries;

    cout << "Rows: " << rows << endl;
    cout << "Queries: " << queries << endl;

    vector<string> line;
    vector<string> query;

    string input_string;
    for(int i=0; i < rows; i++)
    {
        cout << ": ";
        getline(cin, input_string);
        line[i] = input_string;
        cout << ">" << line[i];
    }

    for(int i=0; i < queries; i++)
    {
        getline(cin, input_string);
        query[i] = input_string;
    }


    for(int i=0; i < rows; i++)
    {

        cout << line[i] << endl;
    }

    return 0;
}
