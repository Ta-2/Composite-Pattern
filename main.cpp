#include "Composite.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string space;

//　forward declaration
class Folder;
class File;

// declaration
class Folder : public Composite {
private:
  string name_m;
  vector<Composite *> files;
public:
  Folder (string name){ name_m = name; }
  void Display();
  void AddFolder(Folder *folder);
  void AddFile(File *file);
};

class File : public Composite {
private:
  string name_m;
public:
  void Display();
  File (string name){ name_m = name; }
};

// definition
void Folder::AddFolder (Folder *folder){ files.push_back(folder); }
void Folder::AddFile (File *file){ files.push_back(file); }
void Folder::Display() {
  cout << space << name_m  << " includes↓" << endl;
  space += "-";
  for(auto it : files) it->Display();
  space.erase(space.size()-1);
}
void File::Display(){
  cout << space << name_m << endl;
}

int main() {
  Folder *folder1 = new Folder("root Folder");
  Folder *folder2 = new Folder("Folder1");
  File *file1 = new File("File1");
  File *file2 = new File("File2");
  File *file3 = new File("File3");
  File *file4 = new File("File4");
  folder1->AddFolder(folder2);
  folder1->AddFile(file1);
  folder1->AddFile(file2);
  folder2->AddFile(file3);
  folder2->AddFile(file4);

  folder1->Display();

  return 0;
}
