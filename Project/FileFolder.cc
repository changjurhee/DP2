#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Base{
  string name;
  int size;
  public:
  Base(string _name, int _size = 0) : name(_name), size(_size) {}
  string getName() {return name;}
  int getSize() {return size;}
  virtual void setSize(int _sz) { size += _sz;}
  virtual void print() = 0;
};

class Folder : public Base{
  vector<Base*> v;
  public:
  Folder(string _name) : Base(_name) {}
  void add(Base* p){
    v.push_back(p);
    setSize(p->getSize());
  }
  virtual void setSize(int _sz){
    size += _sz;
    Base::setSize(size);
  }
  virtual void print(){
    int sz = v.size();
    cout << "[" << getName() << "]\n";
    for(int i = 0; i<sz; i++){
      v[i]->print();
    }
  }
};

class File : public Base{
  public:
  File(string _name, int _size) : Base(_name, _size) {}
  virtual void print(){ cout << "(" << getName() << ", " << getSize() << ")\n";}
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  Folder* rootFolder = new Folder("ROOT");
  Folder* aaaaFolder = new Folder("AAAA");
  Folder* bbbbFolder = new Folder("BBBB");

  File* file1 = new File("a.txt", 10);
  File* file2 = new File("b.txt", 20);
  File* file3 = new File("c.txt", 30);
  File* file4 = new File("d.txt", 40);

  rootFolder->add(aaaaFolder);
  rootFolder->add(bbbbFolder);
  rootFolder->add(file1);

  aaaaFolder->add(file2);
  aaaaFolder->add(file3);

  bbbbFolder->add(file4);

  cout << file1->getSize() << "\n";
  cout << aaaaFolder->getSize() << "\n";
  cout << bbbbFolder->getSize() << "\n";

  file1->print();
  rootFolder->print();

  delete rootFolder;
  return 0;
}
