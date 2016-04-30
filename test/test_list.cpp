#include <gtest.h>
#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

TEST(List, can_insert_to_empty_head) {
	List<int> list;
	list.InsertBeforHead(10);
	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(10, list.GetHead()->GetVar());

	EXPECT_EQ(NULL, list.GetHead()->GetNext());
	EXPECT_EQ(NULL, list.GetHead()->GetPrevious());
}

TEST(List, can_insert_to_head) {
	List<int> list;
	list.InsertBeforHead(20);
	list.InsertBeforHead(10);
	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(10, list.GetHead()->GetVar());

	EXPECT_EQ(NULL, list.GetHead()->GetPrevious());
	EXPECT_EQ(20, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_not_find_element_by_negative_index) {
	List<int> list;
	EXPECT_ANY_THROW(list.Search(-1));
}

TEST(List, can_not_find_element_by_index_more_then_length) {
	List<int> list;

	EXPECT_ANY_THROW(list.Search(1));
}

TEST(List, can_find_element_by_index) {
	List<int> list;
	list.Insert(1);//0
	list.Insert(2);//1
	list.Insert(3);//2

	EXPECT_EQ(2, list.Search(1)->GetVar());
}

TEST(List, can_insert_to_tail) {
	List<int> list;
	list.InsertBeforHead(10);
	list.InseråtInTail(20);
	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(10, list.GetHead()->GetVar());

	EXPECT_EQ(NULL, list.GetHead()->GetNext()->GetNext());
	EXPECT_EQ(20, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_insert_between_elements) {
	List<int> list;
	list.InsertBeforHead(40);
	list.InsertBeforHead(30);
	list.InsertBeforHead(10);
	list.Insert(20,1);
	EXPECT_EQ(4, list.GetLength());
	
	EXPECT_EQ(30, list.GetHead()->GetNext()->GetNext()->GetVar());
	EXPECT_EQ(20, list.GetHead()->GetNext()->GetVar());
	EXPECT_EQ(10, list.GetHead()->GetVar());
}
TEST(List, can_add_to_tail_by_insert) {
	List<int> list;
	list.InsertBeforHead(10);
	list.Insert(20, 1);
	EXPECT_EQ(2, list.GetLength());

	EXPECT_EQ(20, list.GetHead()->GetNext()->GetVar());
	EXPECT_EQ(10, list.GetHead()->GetVar());
}


TEST(List, can_delete_first_element) {
	List<int> list;
	list.Insert(1);
	list.Insert(4);
	list.DeleteFirst();

	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(4, list.GetHead()->GetVar());

}

TEST(List, can_delete_list) {
	List<int> list;
	list.Insert(1);
	list.Insert(2);
	list.Insert(3);
	list.Delete();

	EXPECT_EQ(0, list.GetLength());
	EXPECT_EQ(NULL, list.GetHead());

}

TEST(List, can_delete_by_index) { //
	List<int> list;
	list.Insert(1);
	list.Insert(2);//0,1,2
	list.Insert(3);//1,2,3
	list.DeleteElement(1);

	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(1, list.GetHead()->GetVar());
	EXPECT_EQ(3, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_insert_orderedly)
{
	List<int> list;
	list.Insert(1);
	list.Insert(3);
	list.InsertOrdered(2);

	EXPECT_EQ(3, list.GetLength());
	EXPECT_EQ(2, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_insert_orderedly_to_head) {
	List<int> list;
	list.Insert(3);
	list.InsertOrdered(1);

	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(1, list.GetHead()->GetVar());
}

TEST(List, can_insert_orderedly_to_tail) {
	List<int> list;
	list.Insert(1);
	list.InsertOrdered(2);

	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(2, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_get_value_using_brackets) {
	List<int> list;
	list.Insert(1);
	list.Insert(2);
	list.Insert(3);
	list.Insert(4);

	EXPECT_EQ(4, list.GetLength());
	EXPECT_EQ(1, list[0]);
	EXPECT_EQ(2, list[1]);
	EXPECT_EQ(3, list[2]);
	EXPECT_EQ(4, list[3]);
}
