#include "TestHarness.h"
#include "dynarray.h"
#include "ptxy.h"

// Created a simple class PtXY to probe.
TEST(PtXY, Content) {
	int x = 3;
	int y = 4;
	PtXY pt(x, y);
	CHECK_EQUAL(x, pt.GetX());
	CHECK_EQUAL(y, pt.GetY());
}


TEST(Probe, Counters) {
	PtXY a(0, 0);
	PtXY b(1, 1);

	CHECK_EQUAL((std::size_t) 2, a.GetCountActiveInstances());
	CHECK_EQUAL((std::size_t) 2, b.GetCountActiveInstances());

	PtXY* pXY = new PtXY(2, 2);
	CHECK_EQUAL((std::size_t) 3, pXY->GetCountActiveInstances());
	CHECK_EQUAL(a.GetCountActiveInstances(), pXY->GetCountActiveInstances());

	delete pXY;
	CHECK_EQUAL((std::size_t) 2, a.GetCountActiveInstances());
	CHECK_EQUAL(a.GetCountActiveInstances(), b.GetCountActiveInstances());
}


TEST(Dynarray, get_with_valid_index) {
	DynamicArray da;
	
	for (int i = 0; i < 4; i++) {
		da.put(i, i);
	}

	for (int i = 0; i < 4; i++) {
		CHECK_EQUAL(i, da.get(i));
	}
}


TEST(DynArray, get_with_invalid_index) {
	DynamicArray da;

	CHECK_EQUAL(da.get_undef_value(), da.get(-1024));
	CHECK_EQUAL(da.get_undef_value(), da.get(1024));
}


TEST(DynamicArray, put_in_order) {
	DynamicArray da;
	da.put(0, 0);
	da.put(1, 1);

	CHECK_EQUAL(0, da.get(0));
	CHECK_EQUAL(1, da.get(1));
}


TEST(Dynarray, put_into_undefined_space) {
	DynamicArray da;

	// This inserts undef values, then a valid value.
	da.put(4, 4);
	CHECK_EQUAL(4, da.get(4));

	CHECK_EQUAL(da.get_undef_value(), da.get(0));
	CHECK_EQUAL(da.get_undef_value(), da.get(1));
	CHECK_EQUAL(da.get_undef_value(), da.get(2));
	CHECK_EQUAL(da.get_undef_value(), da.get(3));

	da.put(2, 2);
	CHECK_EQUAL(2, da.get(2));
}


TEST(DynamicArray, remove) {
	DynamicArray da;
	for (int i = 0; i < 10; i++) {
		da.put(i, i);
	}

	da.remove(4);
	CHECK_EQUAL(9, da.get(8));
	CHECK_EQUAL(5, da.get(4));
	CHECK_EQUAL(3, da.get(3));
}


TEST(DynamicArray, indexed_read) {
	DynamicArray da;

	da.put(0, 0);
	CHECK_EQUAL(0, da[0]);

	int result = da[0];
	CHECK_EQUAL(0, result);

	const int resolute = da[0];
	CHECK_EQUAL(0, resolute);
}

