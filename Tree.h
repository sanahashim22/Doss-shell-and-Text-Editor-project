#pragma once
#include"Folder.h"
class Tree
{
public:
	Folder* root;
	Folder* CF;
public:
	Tree()
	{
		CF = root = new Folder("V");
	}
	void insert(Folder* f)
	{
		CF->Folders.push_back(f);
	}
	void SetPath(Folder* f)
	{
		string path = CF->name;
		Folder* parent = new Folder();
		while (parent != nullptr)
		{
			path = parent->name + "/" + path;
			parent = parent->parent;
		}
		f->path = path;
		delete parent;
	}
	void print(string prompt = "\\>")
	{
		if (CF->name == "V")
		{
			cout << "V:" << prompt;
		}
		else
		{
			cout << "V:" << CF->path.substr(2, CF->path.length()) << "\\" << CF->name << prompt;
		}
	}
	bool Folder_exists(string name)
	{
		for (int i = 0; i < CF->Folders.size(); i++)
		{
			if (CF->Folders[i]->name == name)
			{
				return true;
			}
		}
		return false;
	}
	File* Find(string name)
	{
		if (CF != nullptr)
		{
			for (int i = 0; i < CF->Files.size(); i++)
			{
				if (CF->Files[i]->name == name)
				{
					return CF->Files[i];
				}
			}
		}
		return nullptr;
	}
	Folder* FindFolder(string name)
	{
		if (CF != nullptr)
		{
			for (int i = 0; i < CF->Folders.size(); i++)
			{
				if (CF->Folders[i]->name == name)
				{
					return CF->Folders[i];
				}
			}
		}
		return nullptr;
	}
};