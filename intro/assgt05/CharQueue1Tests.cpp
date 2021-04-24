#include <string>
#include <vector>

#include "CharQueue1.h"
#include "TestHarness.h"

// General comment:  Many of the unit tests for CharQueue1 were focused upon
// capacity verification.  These tests are not relevant in CharQueue2 since
// capacity is not managed.

// Other comment:  This would be a good pImpl exercise.

TEST(deque, various) {
  std::size_t default_capacity = 32;
  auto original = CharQueue1();

  // Test default creation state:
  CHECK_EQUAL(default_capacity, original.capacity());
  CHECK_EQUAL(true, original.isEmpty());

  // Test simple in and out:
  auto specimen = 'a';
  original.enqueue(specimen);
  CHECK_EQUAL(false, original.isEmpty());

  auto result = original.dequeue();
  CHECK_EQUAL(result, specimen);
  CHECK_EQUAL(true, original.isEmpty());

  // Load to capacity:
  for (std::size_t i = 0; i < default_capacity; i++) {
    original.enqueue(specimen);
  }
  
  // Verify that growth has occurred:
  CHECK_EQUAL(2 * default_capacity, original.capacity());
  CHECK_EQUAL(false, original.isEmpty());

  // Enqueue after growth:  
  original.enqueue(specimen);

  // At this point, the queue has 33 members and a capacity of 64.
  // Create a second queue:
  std::size_t low_capacity = 16;
  auto other = CharQueue1(low_capacity);

  CHECK_EQUAL(low_capacity, other.capacity());
  CHECK_EQUAL(true, other.isEmpty());

  // Add some content to make the other queue grow:
  auto other_specimen = 'b';
  for (std::size_t i = 0; i < default_capacity; i++) {
    other.enqueue(other_specimen);
  }

  CHECK_EQUAL(low_capacity + default_capacity, other.capacity());
  
  // Create a queue with the copy constructor:
  auto copy = CharQueue1(other);
  CHECK_EQUAL(other.capacity(), copy.capacity());

  // Assign the copy queue to the original queue.
  original = copy;
  CHECK_EQUAL(original.capacity(), copy.capacity());
  result = original.dequeue();
  CHECK_EQUAL(result, other_specimen);

  // Create two queues,
  // Load them with different specimens.
  // Swap them and test the results.
  auto has_specimen = CharQueue1();
  auto has_other_specimen = CharQueue1();
  auto test_count = 4;

  for (auto i = 0; i < test_count; i++) {
    has_specimen.enqueue(specimen);
  }


  for (auto i = 0; i < test_count; i++) {
    has_other_specimen.enqueue(other_specimen);
  }

  CHECK_EQUAL(specimen, has_specimen.dequeue());
  CHECK_EQUAL(other_specimen, has_other_specimen.dequeue());

  has_specimen.swap(has_other_specimen);

  CHECK_EQUAL(other_specimen, has_specimen.dequeue());
  CHECK_EQUAL(specimen, has_other_specimen.dequeue());
}
