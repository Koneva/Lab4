#include "gtest.h"
#include "set.hpp"

TEST(SET, can_create_set)
{
	SET* set;
	ASSERT_NO_THROW(set = new SET(5));
}

TEST(SET, can_copy_heap)
{
	SET *set = new SET(5);
	ASSERT_NO_THROW(set = new SET(*set));
}
