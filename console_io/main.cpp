#include <iostream>
#include <string>
#include <sstream>


using namespace std;


int main()
{

//    #ifdef FOO_DEBUG
//        freopen("in_d.txt","r",stdin);
//        freopen("out_d.log","w",stdout);
//    #else
//        freopen("in_r.txt","r",stdin);
//        freopen("out_r.txt","w+",stdout);
//    #endif

    string input_str;
    string word;

    cout << "Please type something: ";

    while (getline(cin, input_str)) {
        cout << "You Typed: " << input_str << endl;
        if(input_str == "END") {
            return 0;
        }

        cout << "Breaking it into words delimited by spaces: \n";
        std::istringstream iss (input_str);
        while(iss.good()) {
            iss >> word;
            cout << word << "\n";
        }

        cout << "Please type something else ['END' Exits]: ";
    }



    return 0;
}
