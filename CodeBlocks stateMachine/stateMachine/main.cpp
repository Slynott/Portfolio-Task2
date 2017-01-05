#include <iostream>

#include "sensor.h"
#include "idle.h"
#include "reading.h"
#include "button.h"
#include "display.h"
#include "system.h"

using namespace std;

class Machine
{
  class State *current;
  public:
    Machine();
    void setCurrent(State *s)
    {
        current = s;
    }
    void sensing();
    void idle();
    void Processing();
};

class State
{
  public:
    virtual void sensing(Machine *m)
    {
        cout << "   System Sensing\n";
    }
    virtual void Idle(Machine *m)
    {
        cout << "   System Idle\n";
    }
    virtual void Processing(Machine *m)
    {
        cout <<" System Processing\n";
    }
};

void Machine::Sensing()// sensing is a class
{
  current->sensing(this);//callback function
}

void Machine::idle()//idle is a class
{
  current->idle(this);//callback function
}

void Machine::Processing()//processing is a class
{
    current->processing(this);//callback function
}

class Processing: public State
{
  public:
    Processing()
    {
        cout << "   Processing-ctor ";//machine on processing
    };
    ~Processing()
    {
        cout << "   dtor-processing\n";// machine off idle
    };
    {
        cout << "   going from Processing to Idle";
        m->setCurrent(new Processing());
        delete this;
    }
    void idle(Machine *m);
};

class Sensing: public State
{
  public:
    Sensing()
    {
        cout << "   Sensing-ctor ";// machine sensing
    };
    ~Sensing()
    {
        cout << "   dtor-Sensing\n";
    };
    void processing(Machine *m)
    {
        cout << "   going from Sensing to Processing";
        m->setCurrent(new Processing());
        delete this;
    }
};

{
  public:
    Idle()
    {
        cout << "   Idle-ctor ";// machine idle
    };
    ~Idle()
    {
        cout << "   dtor-idle\n";
    };
    void Sensing(Machine *m)
    {
        cout << "   going from Idle to Sensing";
        m->setCurrent(new Processing());
        delete this;
    }
};



Machine::Machine()
{
  current = new Idle();// all machines start in Idle state
  cout << '\n';
}

int main()
{
  void(Machine:: *ptrs[])() =// ptrs pointers
  {
    Machine::Idle, Machine::Sensing, Machine::Processing //machine pointers
  };
  Machine fsm;
  int num;
  while (1)
  {
    cout << "Enter 0/1: ";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}
