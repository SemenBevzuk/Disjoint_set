#include <gtest.h>
#include "double_list.h"

TEST(Node, can_create) {
	ASSERT_NO_THROW(new Node<int>());
}
TEST(Node, can_create_with_parameter) {
	ASSERT_NO_THROW(new Node<int>(10));
}
TEST(Node, can_create_whith_parameter_and_connection) { //1,2,3
	Node<int> *node1 = new Node<int>();
	Node<int> *node3 = new Node<int>();
	Node<int> *node2;
	ASSERT_NO_THROW(node2 = new Node<int>(10, node1, node3));
	EXPECT_EQ(10, node2->GetVar());
	EXPECT_EQ(node1, node2->GetPrevious());
	EXPECT_EQ(node3, node2->GetNext());
}

TEST(Node, can_set_next) { //1,2
	Node<int> *node1 = new Node<int>();
	Node<int> *node2 = new Node<int>();
	ASSERT_NO_THROW(node1->SetNext(node2););
	EXPECT_EQ(node2, node1->GetNext());
}