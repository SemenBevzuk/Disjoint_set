#include <gtest.h>
#include "list.h"

TEST(List, can_add_to_head) {
	List<int> list;
	list.AddToHead(2);
	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(2,list.GetHead()->GetVar());
	EXPECT_EQ(NULL, list.GetHead()->GetNext());
}

TEST(List, can_add_to_tail) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(1, list.GetHead()->GetVar());
	EXPECT_EQ(4, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_delete_single_element)
{
	List<int> list;
	list.AddToHead(1);
	list.DeleteFirst();

	EXPECT_EQ(0, list.GetLength());
	EXPECT_EQ(NULL, list.GetHead());

}
TEST(List, can_delete_first_element) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	list.DeleteFirst();

	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(4, list.GetHead()->GetVar());

}
TEST(List, can_find_element_by_index) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);//1

	EXPECT_EQ(4, list.At(1)->GetVar());

}
TEST(List, can_not_find_element_by_negative_index) {
	List<int> list;

	EXPECT_ANY_THROW(list.At(-1));
}
TEST(List, can_not_find_element_by_index_more_then_length) {
	List<int> list;

	EXPECT_ANY_THROW(list.At(1));
}

TEST(List, can_add_element_by_index) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	list.AddElement(2,1);//1,2,4

	EXPECT_EQ(3, list.GetLength());
	EXPECT_EQ(2, list.At(1)->GetVar());
}

TEST(List, can_add_element_at_head) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	list.AddElement(2, 0);//2,1,4

	EXPECT_EQ(3, list.GetLength());
	EXPECT_EQ(2, list.At(0)->GetVar());
}

TEST(List, can_add_element_orderly) { //
	List<int> list;
	list.AddToHead(1);
	list.AddToHead(3);//3,1

	list.AddElementOrdered(2);
	
	EXPECT_EQ(3, list.GetHead()->GetVar());
	EXPECT_EQ(2, list.GetHead()->GetNext()->GetVar());
	EXPECT_EQ(1, list.GetHead()->GetNext()->GetNext()->GetVar());
}

TEST(List, can_add_element_orderly_first) { //
	List<int> list;
	list.AddToHead(1);
	list.AddToHead(2);//2,1

	list.AddElementOrdered(3);

	EXPECT_EQ(3, list.GetHead()->GetVar());
	EXPECT_EQ(2, list.GetHead()->GetNext()->GetVar());
	EXPECT_EQ(1, list.GetHead()->GetNext()->GetNext()->GetVar());
}

TEST(List, can_delete) { //
	List<int> list;
	list.AddToHead(1);
	list.AddToHead(2);//2,1
	list.AddElementOrdered(3);
	ASSERT_NO_THROW(list.Delete());
}