#pragma once
#include<list>
#include<string>
#include<iostream>
#include<vector>
#include<ctime>
#include"File.h"
using namespace std;
class Folder
{
public:
	string name;
	vector<Folder*> Folders;
	vector<File*> Files;
	Folder* parent;
	time_t creation_time;
	string owner;
	string path;
	bool hidden;
public:
	Folder(string n = "NULL", string p = "", Folder* parent_ = nullptr, vector<File*> fs = vector<File*>(), vector<Folder*> Fs = vector<Folder*>())
	{
		name = n;
		Folders = Fs;
		Files = fs;
		hidden = false;
		path = p;
		parent = parent_;
	}
	void remove_file(string name)
	{
		for (int i = 0; i < Files.size(); i++)
		{
			if (Files[i]->name == name)
			{
				swap(Files[i], Files[Files.size() - 1]);
				Files.pop_back();
			}
		}
	}
	void remove_folder(string name)
	{
		for (int i = 0; i < Folders.size(); i++)
		{
			if (Folders[i]->name == name)
			{
				swap(Folders[i], Folders[Folders.size() - 1]);
				Folders.pop_back();
			}
		}
	}
	void EmptyDir()
	{
		Files.resize(0);
		Folders.resize(0);
	}
	File* Find(string name)
	{
		for (int i = 0; i < Files.size(); i++)
		{
			if (Files[i]->name == name)
			{
				return Files[i];
			}
		}
		return nullptr;
	}
	Folder* FindFolder(string name)
	{
		for (int i = 0; i < Folders.size(); i++)
		{
			if (Folders[i]->name == name)
			{
				return Folders[i];
			}
		}
		return nullptr;
	}
	void InsertFile(File* f)
	{
		Files.push_back(f);
	}
	void InsertFolder(Folder* f)
	{
		Folders.push_back(f);
	}
	void print()
	{
		cout << "Directory of " << path << "\\" << name << endl << endl;
		for (int i = 0; i < Folders.size(); i++)
		{
			cout << "           <DIR>       " << Folders[i]->name << endl;
		}
		for (int i = 0; i < Files.size(); i++)
		{
			cout << "           <DIR>       " << Files[i]->name << endl;
		}
	}
};