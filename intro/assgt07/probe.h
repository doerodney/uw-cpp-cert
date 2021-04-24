#ifndef INC_PROBE_H
#define INC_PROBE_H

#include <cstddef>
#include <string>
#include <ostream>

class Probe {
  
  public:
    Probe();
    Probe(const Probe&) = delete;
    Probe& operator=(const Probe&) = delete;
    friend std::ostream& operator<< (std::ostream& stream, Probe& probe);

    void Increment();
    void Decrement();

    std::size_t GetActiveInstanceCount() { return active_instances; }
    std::size_t GetCreatedInstanceCount() { return created_instances; }
  
  private:
    std::size_t active_instances;
    std::size_t created_instances;

};

std::ostream& operator<< (std::ostream& stream, Probe& probe);

#endif

