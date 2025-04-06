#include<iostream>
#include"DOS.h"
using namespace std;

int main()
{
    DOS a1;

    cout << "Welcome to DOS Simulator!" << endl;
    cout << "Type 'help' for a list of commands." << endl;

    a1.run();

    cout << "Exiting DOS Simulator. Goodbye!" << endl;

    return 0;
}
