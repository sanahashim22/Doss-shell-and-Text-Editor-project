#pragma once
#include<string>
#include<iostream>
using namespace std;
class File
{
public:
    string name, path, no_of_chars, no_of_lines, avg_chars_per_line, owner, type;
    string data;
    bool ReadOnly;
    int priority, time_to_print;
    File(string name = "NULL", string owner = "admin") : type(".txt"),
        name(name),
        path(""),  // Initialize path to an empty string
        no_of_chars("0"),  // Assuming initial values for these attributes
        no_of_lines("0"),
        avg_chars_per_line("0"),
        owner(owner),
        data(""),
        ReadOnly(false),
        priority(0),  // Assuming an initial priority value
        time_to_print(0)  // Assuming an initial time to print value
    {

    }

    void print()
    {
        cout << "File Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "Path: " << path << endl;
        cout << "Number of Characters: " << no_of_chars << endl;
        cout << "Number of Lines: " << no_of_lines << endl;
        cout << "Average Characters per Line: " << avg_chars_per_line << endl;
        cout << "Owner: " << owner << endl;
        cout << "Type: " << type << endl;
        cout << "Data: " << data << endl;
        cout << "Read-Only: " << (ReadOnly ? "Yes" : "No") << endl;
        cout << "Priority: " << priority << endl;
        cout << "Time to Print: " << time_to_print << endl;
    }
};