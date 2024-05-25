#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <tuple>
using namespace std;
using INPUT = tuple<int, int, int>;
using RESULT = tuple<int, int>;

class BaseBallGame
{
  vector<pair<INPUT, RESULT>> v;
  public:
  BaseBallGame(){srand((unsigned)time(0));}

  // 1. template method
  virtual INPUT predict(){ 
    int x = 0, y = 0, z = 0;
    do{
      x = rand()%9+1;
      y = rand()%9+1;
      z = rand()%9+1;
    }while(x == y || y == z || x == z);

    return INPUT(x, y, z);  
  }

  void run(){
    while(1){
      int x = 0, y = 0, z = 0;
      INPUT _result = predict();
      x = get<0>(_result);
      y = get<1>(_result);
      z = get<2>(_result);
      cout << "What is your number " << x << ", " << y << ", " << z << "?\n";
      int strike = 0, ball = 0;
      cout << "strike : ";
      cin >> strike;
      if(strike == 3){
        cout << "Success!\n";
        break;
      }
      cout << "Ball : ";
      cin >> ball;
      v.push_back(pair(INPUT(x,y,z), RESULT(strike, ball)));
      dump();
    }
  }
  void dump(){
    cout << "-------------------\n";
    cout << "Input s b\n";
    for(auto & p : v){
      cout << get<0>(p.first) << " " << get<1>(p.first) << " " << get<2>(p.first) << " : ";
      cout << get<0>(p.second) << " " << get<1>(p.second) << "\n";
    }
    cout << "-------------------\n";
  }
};

// 2. strategy pattern
struct IPredictor
{
  virtual INPUT predict() = 0;
  virtual ~IPredictor() {}
};

class BaseBallGame2
{
  vector<pair<INPUT, RESULT>> v;
  IPredictor* pPred = 0;

  public:
  void setPredictor(IPredictor* p){pPred = p;}
  BaseBallGame2(){}

  void run(){
    while(1){
      int x = 0, y = 0, z = 0;
      INPUT _result = pPred->predict();
      x = get<0>(_result);
      y = get<1>(_result);
      z = get<2>(_result);
      cout << "What is your number " << x << ", " << y << ", " << z << "?\n";
      int strike = 0, ball = 0;
      cout << "strike : ";
      cin >> strike;
      if(strike == 3){
        cout << "Success!\n";
        break;
      }
      cout << "Ball : ";
      cin >> ball;
      v.push_back(pair(INPUT(x,y,z), RESULT(strike, ball)));
      dump();
    }
  }
  void dump(){
    cout << "-------------------\n";
    cout << "Input s b\n";
    for(auto & p : v){
      cout << get<0>(p.first) << " " << get<1>(p.first) << " " << get<2>(p.first) << " : ";
      cout << get<0>(p.second) << " " << get<1>(p.second) << "\n";
    }
    cout << "-------------------\n";
  }
};

class Easy
{
  public:
    Easy(){srand((unsigned)time(0));}
    inline INPUT predict(){
      int x = 0, y = 0, z = 0;
      do{
        x = rand()%9+1;
        y = rand()%9+1;
        z = rand()%9+1;
      }while(x==y || y == z || x == z);

      return INPUT(x, y, z);  
    }
};

template<typename PredictA = Easy>
class BaseBallGameT
{
  vector<pair<INPUT, RESULT>> v;
  PredictA pa;

  public:
  BaseBallGameT(){}
  void run(){
    while(1){
      int x = 0, y = 0, z = 0;
      INPUT _result = pa.predict();
      x = get<0>(_result);
      y = get<1>(_result);
      z = get<2>(_result);
      cout << "What is your number " << x << ", " << y << ", " << z << "?\n";
      int strike = 0, ball = 0;
      cout << "strike : ";
      cin >> strike;
      if(strike == 3){
        cout << "Success!\n";
        break;
      }
      cout << "Ball : ";
      cin >> ball;
      v.push_back(pair(INPUT(x,y,z), RESULT(strike, ball)));
      dump();
    }
  }
  void dump(){
    cout << "-------------------\n";
    cout << "Input s b\n";
    for(auto & p : v){
      cout << get<0>(p.first) << " " << get<1>(p.first) << " " << get<2>(p.first) << " : ";
      cout << get<0>(p.second) << " " << get<1>(p.second) << "\n";
    }
    cout << "-------------------\n";
  }
};


class EasyGame : public BaseBallGame 
{
  public:
    virtual INPUT predict(){
      int x = 0, y = 0, z = 0;
      do{
        x = rand()%99+1;
        y = rand()%99+1;
        z = rand()%99+1;
      }while(x==y || y == z || x == z);

      return INPUT(x, y, z);  
    }
};

class MiddleGame : public BaseBallGame
{
  public:
    virtual INPUT predict(){
      int x = 0, y = 0, z = 0;
      do{
        x = rand()%999+1;
        y = rand()%999+1;
        z = rand()%999+1;
      }while(x==y || y == z || x == z);

      return INPUT(x, y, z);  
    }
};

class DifficultGame : public BaseBallGame
{
  public:
    virtual INPUT predict(){
      int x = 0, y = 0, z = 0;
      do{
        x = rand()%9999+1;
        y = rand()%9999+1;
        z = rand()%9999+1;
      }while(x==y || y == z || x == z);

      return INPUT(x, y, z);  
    }
};

class LevelPredictor : public IPredictor
{
  int level;
  public:
  LevelPredictor(int _level) : level(_level) {srand((unsigned)time(0)); }
  virtual INPUT predict(){
    int x = 0, y = 0, z = 0;
    do{
      x = rand()%level+1;
      y = rand()%level+1;
      z = rand()%level+1;
    }while(x==y || y == z || x == z);

    return INPUT(x, y, z);  
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  BaseBallGame bbg;
  bbg.run();

  // 1. template method
  EasyGame e_bbg;
  MiddleGame m_bbg;
  DifficultGame d_bbg;

  bbg.run();
  e_bbg.run();
  m_bbg.run();
  d_bbg.run();

  // strategy pattern
  BaseBallGame2 bbg2;
  LevelPredictor lp(999999);
  bbg2.setPredictor(&lp);
  bbg2.run();

  // 3. PBD
  BaseBallGameT bbgt;
  bbgt.run();

  return 0;
}
