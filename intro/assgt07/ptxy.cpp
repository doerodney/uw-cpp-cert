// Copyright [2021] cpplint placation
#include "ptxy.h"

static Probe ms_probe;

PtXY::PtXY(int x, int y) : m_X(x), m_Y(y) {
  ms_probe.Increment();
}


PtXY::~PtXY() {
  ms_probe.Decrement();
}


int PtXY::GetX() { return m_X; }


int PtXY::GetY() { return m_Y; }


std::size_t PtXY::GetCountActiveInstances() {
  return ms_probe.GetActiveInstanceCount();
}


std::size_t PtXY::GetCountCreatedInstances() {
  return ms_probe.GetCreatedInstanceCount();
}
