#include "TStack.h"

#include "conio.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	//ADD_FAILURE();
	 ASSERT_NO_THROW(TStack v(5));
}

TEST(TStack, new_stack_is_empty)
{
	TStack v(2);
	EXPECT_TRUE(v.IsEmpty());
}

TEST(TStack, cant_create_too_large_stack)
{
	ASSERT_ANY_THROW(TStack v(MemSize + 1));
}

TEST(TStack, new_stack_is_full)
{
	TStack v(2);
	v.Put(1);
	v.Put(1);
	EXPECT_TRUE(v.IsFull());
}

TEST(TStack, throws_when_create_vector_with_negative_length)
{
	//ADD_FAILURE();
	ASSERT_ANY_THROW(TStack v(-5));
}

TEST(TStack, can_copy_stacks)
{
	//	ADD_FAILURE();
	TStack s1(3);
	ASSERT_NO_THROW(TStack s2(s1));
}

TEST(TStack, correct_copying_stacks)
{
	//ADD_FAILURE();
	TStack s1(3);
	s1.Put(4);
	TStack s2(s1);
  EXPECT_EQ(s2.Peek(), s1.Peek());
}



TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack s1(3);
	TStack s2(s1);
	EXPECT_NE(&s1, &s2);
  //ADD_FAILURE();
}

TEST(TStack, can_set_and_get_element)
{
 TStack v(4);
  v.Put(4);
	//ADD_FAILURE();
  EXPECT_EQ(4, v.Peek());
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack s(5);

	ASSERT_NO_THROW(s = s);
}

TEST(TStack, can_show_top_value_of_stack)
{
	TStack  s(5);
	s.Put(3);
	s.Put(5);

	EXPECT_EQ(5, s.Peek());
	EXPECT_EQ(5, s.Peek());
}

TEST(TStack, cant_show_top_value_of_empty_stack)
{
	TStack  s(5);

	ASSERT_ANY_THROW(s.Peek());
}

TEST(TStack, can_pull_top_value_from_stack)
{
	TStack  s(5);
	s.Put(3);

	EXPECT_EQ(3, s.Push());
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(TStack, cant_pull_top_value_from_empty_stack)
{
	TStack  s(5);

	ASSERT_ANY_THROW(s.Push());
}

TEST(TStack, can_push_number_to_stack)
{
	TStack  s(5);
	s.Put(5);

	EXPECT_EQ(5, s.Peek());
}

TEST(TStack, cant_push_number_to_full_stack)
{
	TStack s(3);
	s.Put(4);
	s.Put(5);
	s.Put(5);

	ASSERT_ANY_THROW(s.Put(3));
}

TEST(SHOWDOWN)//---------------------------//
{
	getch();
	SUCCEED();
}
