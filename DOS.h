#pragma once
#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

class DOS
{
private:
    string lower(string str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }
        return str;
    }
    bool prompt = false;

public:
    Tree t;
    string user = "Laiba";

    DOS() {}

    void print()
    {
        cout << "\t\t\t\t\t" << "Laiba Iqbal | bscs22039 | DSA-ITU-2022" << endl << endl;
        t.print();
    }

    void run()
    {
        print();
        bool exit = false;
        while (!exit)
        {
            exit = input();
        }
    }

    bool input()
    {
        string command;
        cout << "$ ";
        getline(cin, command);

        if (command.empty())
        {
            cout << "Error: Empty command." << endl;
            return false;
        }

        string opr = command.substr(0, command.find(' '));
        opr = lower(opr);

        if (opr == "mkdir")
        {
            if (command.length() <= 6)
            {
                cout << "Error: Missing directory name for mkdir." << endl;
                return false;
            }

            t.insert(new Folder(command.substr(6, command.length()), t.CF->path + "\\" + t.CF->name, t.CF));
        }
        else if (opr == "create")
        {
            if (command.length() <= 7)
            {
                cout << "Error: Missing file name for create." << endl;
                return false;
            }

            File* f = new File(command.substr(7, command.length()), user);
            t.CF->Files.push_back(f);
        }
       
        else if (opr == "ver")
        {
            if (system("ver") != 0)
            {
                cout << "Error: Unable to display version information on this system." << endl;
            }
            else
            {
                cout << "DOS Program Version 1.0" << endl;
            }
        }
        else if (opr == "del")
        {
            if (command.length() <= 4)
            {
                cout << "Error: Missing file name for del." << endl;
                return false;
            }

            t.CF->remove_file(command.substr(4, command.length()));
        }
        else if (opr == "cd")
        {
            if (command.length() <= 3)
            {
                cout << "Error: Missing folder name for cd." << endl;
                return false;
            }

            string folder = command.substr(3, command.length());
            if (t.Folder_exists(folder))
            {
                t.CF = t.FindFolder(folder);
            }
            else
            {
                cout << "Error: No such directory exists!" << endl;
            }
        }
        else if (opr == "cd..")
        {
            if (t.CF->parent != nullptr)
            {
                t.CF = t.CF->parent;
            }
        }
        else if (opr == "cd\\")
        {
            if (t.CF->parent != nullptr)
            {
                t.CF = t.root;
            }
        }
        else if (opr == "dir" || opr == "cd.")
        {
            t.CF->print();
        }
        else if (opr == "cls")
        {
            system("cls");
            print();
        }
        else if (opr == "exit")
        {
            return true;
        }
        else if (opr == "find")
        {
            string name = command.substr(5, command.length());
            File* f = t.Find(name);
            cout << f->data;
        }
        else if (opr == "attrib")
        {
            string name = command.substr(7, command.length());
            File* f = t.Find(name);
            f->print();
        }
        else if (opr == "findf")
        {
            string fileName;
            cout << "Enter the file name (including extension): ";
            cin.ignore();
            getline(cin, fileName);
            File* fileToSearch = t.Find(fileName);
            if (fileToSearch != nullptr)
            {
                string searchString;
                cout << "Enter the text string to search for: ";
                getline(cin, searchString);

                size_t found = fileToSearch->data.find(searchString);
                if (found != string::npos)
                {
                    cout << "Text string found in the specified file." << endl;
                }
                else
                {
                    cout << "Text string not found in the specified file." << endl;
                }
            }
            else
            {
                cout << "File not found." << endl;
            }
        }
        else if (opr == "convert")
        {
            cout << "Enter the source file type (e.g., txt): ";
            string sourceType;
            cin >> sourceType;

            cout << "Enter the destination file type (e.g., doc): ";
            string destType;
            cin >> destType;
            for (File* file : t.CF->Files)
            {
                string fileName = file->name;

                size_t dotIndex = fileName.find_last_of('.');
                if (dotIndex != string::npos && fileName.substr(dotIndex + 1) == sourceType)
                {
                    fileName = fileName.substr(0, dotIndex + 1) + destType;
                    file->name = fileName;
                }
            }
        }
        else if (opr == "format")
        {
            t.CF->EmptyDir();
        }
        else if (opr == "rmdir")
        {
            Folder* current = t.CF;
            t.CF = t.CF->parent;
            t.CF->remove_folder(current->name);
        }
        else if (opr == "prompt")
        {
            prompt = !prompt;
        }
        else if (opr == "rename")
        {
            command = command.substr(opr.length() + 1, command.length());
            string currname = command.substr(0, command.find(' '));
            string newname = command.substr(currname.length() + 1, command.length());
            File* f = t.CF->Find(currname);
            f->name = newname;
        }
        else if (opr == "copy")
        {
            command = command.substr(opr.length() + 3, command.length());
            int ind = command.find(' ');
            string sourcepath = command.substr(0, command.find(' '));
            string destpath = command.substr(sourcepath.length() + 3, command.length());
            File* file_to_copy;
            Folder* CurrFolder = t.root;
            string f;
            while (sourcepath.length() > 0)
            {
                f = sourcepath.substr(0, sourcepath.find('\\'));
                sourcepath = sourcepath.substr(f.length() + 1, sourcepath.length());
                if (sourcepath.length() != 0)
                {
                    CurrFolder = CurrFolder->FindFolder(f);
                }
                if (CurrFolder == nullptr)
                {
                    cout << "Path was not found";
                    return true;
                }
            }
            file_to_copy = CurrFolder->Find(f);
            CurrFolder = t.root;
            while (destpath.length() > 0)
            {
                f = destpath.substr(0, destpath.find('\\'));
                destpath = destpath.substr(f.length() + 1, destpath.length());
                CurrFolder = CurrFolder->FindFolder(f);
                if (CurrFolder == nullptr)
                {
                    cout << "Path was not found";
                    return true;
                }
            }
            CurrFolder->InsertFile(file_to_copy);
        }
        else if (opr == "mov")
        {
            command = command.substr(opr.length() + 3, command.length());
            int ind = command.find(' ');
            string sourcepath = command.substr(0, command.find(' '));
            string destpath = command.substr(sourcepath.length() + 3, command.length());
            File* file_to_mov;
            Folder* CurrFolder = t.root;
            string f;
            while (sourcepath.length() > 0)
            {
                f = sourcepath.substr(0, sourcepath.find('\\'));
                sourcepath = sourcepath.substr(f.length() + 1, sourcepath.length());
                if (sourcepath.length() != 0)
                {
                    CurrFolder = CurrFolder->FindFolder(f);
                }
                if (CurrFolder == nullptr)
                {
                    cout << "Path was not found";
                    return true;
                }
            }
            file_to_mov = CurrFolder->Find(f);
            CurrFolder->remove_file(file_to_mov->name);
            CurrFolder = t.root;
            while (destpath.length() > 0)
            {
                f = destpath.substr(0, destpath.find('\\'));
                destpath = destpath.substr(f.length() + 1, destpath.length());
                CurrFolder = CurrFolder->FindFolder(f);
                if (CurrFolder == nullptr)
                {
                    cout << "Path was not found";
                    return true;
                }
            }
            CurrFolder->InsertFile(file_to_mov);
        }
        else if (opr == "help")
        {
            cout << "mkdir\tMakes a new directory in the current directory" << endl;
            cout << "cd\tChanges the current directory" << endl;
            cout << "cd..\tChanges the directory to its parent directory" << endl;
        }
        else
        {
            cout << "Error: Unknown command." << endl;
        }

        if (prompt)
        {
            t.print("$");
        }
        else
        {
            t.print();
        }

        return false;
    }
};
