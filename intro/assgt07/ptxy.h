#ifndef INC_PTXY
#define INC_PTXY

#include "probe.h"


class PtXY {
  public:
    PtXY(int x, int y);
    ~PtXY();
    
    PtXY() = delete;
    PtXY& operator=(const PtXY&) = delete;
    
    int GetX();
    int GetY();

    static std::size_t GetCountCreatedInstances();
    static std::size_t GetCountActiveInstances();

  private:
    int m_X;
    int m_Y;
};

#endif
