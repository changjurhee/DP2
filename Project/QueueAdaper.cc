#include <iostream>
#include <list>
using namespace std;
template<typename T, typename C = list<T>>
class Queue{
  C q;
public:
  inline void Push(const T& a){
    q.push_back(a);
  };
  inline T Pop(){ 
    T tmp = q.front();
    q.pop_front();
    return tmp;
  };
};

template<typename T>
class Queue1 : public list<T>
{

public:
  void Push(const T& a) { list<T>::push_back(a); }
  T Pop(){
    T tmp = list<T>::front();
    list<T>::pop_front();
    return tmp;
  }
};

template<typename T>
class Queue2
{
  list<T> li;
public:
  void Push(const T& a) { li.push_back(a);}
  T Pop(){
    T tmp = li.front();
    li.pop_front();
    return tmp;
  }
};

int main(){
  Queue<int> q;

  q.Push(10);
  q.Push(20);
  cout << q.Pop() << "\n";
  cout << q.Pop() << "\n";

  Queue1<int> q1;
  
  q1.Push(10);
  q1.Push(20);

  cout << q1.Pop() << "\n";
  cout << q1.Pop() << "\n";

  Queue2<int> q2;
  q2.Push(10);
  q2.Push(20);

  cout << q2.Pop() << "\n";
  cout << q2.Pop() << "\n";

  return 0;
}
