//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author JMENO PRIJMENI
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

#include <cstdlib>

class EmptyTree : public ::testing::Test{
protected:
    BinaryTree tree;
};

class NonEmptyTree : public  ::testing::Test{
protected:
    virtual void SetUp(){
        int values[] = {7,8,2,10,4,12,5,11,16,25,17,18,3,158,1,};
        for (int i = 0; i < 15; i++){
            tree.InsertNode(values[i]);
        }

    }
    BinaryTree tree;
};

class TreeAxioms : public  ::testing::Test{
protected:
    virtual void SetUp(){
        int values[] = {7,8,2,10,4,12,5,11,16,25,17,18,3,158,1,};
        for (int i = 0; i < 15; i++){
            tree.InsertNode(values[i]);
        }

    }
    BinaryTree tree;
};

TEST_F(EmptyTree, InsertNode){

    // Insertging first value 
    auto first_node = tree.InsertNode(5);

    ASSERT_TRUE(first_node.first);
    EXPECT_EQ(first_node.second->key, 5);

    //Leaf Left
    auto *left = first_node.second->pLeft; 
    EXPECT_EQ(left->pLeft, nullptr);
    EXPECT_EQ(left->pRight, nullptr);
    EXPECT_EQ(tree.GetRoot(), left->pParent);
    EXPECT_EQ(left->color, BinaryTree::BLACK);

    //Leaf Right
    auto *right = first_node.second->pRight;
    EXPECT_EQ(right->pLeft, nullptr);
    EXPECT_EQ(right->pRight, nullptr);
    EXPECT_EQ(tree.GetRoot(), right->pParent);
    EXPECT_EQ(left->color, BinaryTree::BLACK);


    // Inserting second value

    auto second_node = tree.InsertNode(10);

    ASSERT_TRUE(second_node.first);
    EXPECT_EQ(second_node.second->key, 10);
    EXPECT_EQ(second_node.second->pParent, tree.GetRoot());
    EXPECT_EQ(second_node.second->color, BinaryTree::RED);

    // Leaf left
    left = second_node.second->pLeft; 
    EXPECT_EQ(left->pLeft, nullptr);
    EXPECT_EQ(left->pRight, nullptr);
    EXPECT_EQ(second_node.second, left->pParent);
    EXPECT_EQ(left->color, BinaryTree::BLACK);

    // Leaf Right 
    right = second_node.second->pRight;
    EXPECT_EQ(right->pLeft, nullptr);
    EXPECT_EQ(right->pRight, nullptr);
    EXPECT_EQ(second_node.second, right->pParent);
    EXPECT_EQ(right->color, BinaryTree::BLACK);


    // Order control
    EXPECT_EQ(tree.GetRoot()->key, 5);
    EXPECT_EQ(tree.GetRoot()->pRight->key, 10);

    // Inserting third value

    auto third_node = tree.InsertNode(2);
    ASSERT_TRUE(third_node.first);
    EXPECT_EQ(third_node.second->key, 2);
    EXPECT_EQ(third_node.second->color, BinaryTree::RED);

    // Epecting that leaves are fine
    // Order control
    EXPECT_EQ(tree.GetRoot()->key, 5);
    EXPECT_EQ(tree.GetRoot()->pRight->key, 10);
    EXPECT_EQ(tree.GetRoot()->pLeft->key,2);
    
}

TEST_F(EmptyTree, DeleteNode){
    for (int i=0; i<30;i++){
        EXPECT_FALSE(tree.DeleteNode(rand()));
    }

    EXPECT_FALSE(tree.DeleteNode(10));
    EXPECT_FALSE(tree.DeleteNode(2));

    auto first_node = tree.InsertNode(10);
    auto second_node = tree.InsertNode(2);

    EXPECT_TRUE(tree.DeleteNode(10));
    EXPECT_EQ(tree.GetRoot(), second_node.second);

    EXPECT_TRUE(tree.DeleteNode(2));
    EXPECT_EQ(tree.GetRoot() , nullptr);
}

TEST_F(EmptyTree, FindNode){
   for (int i=0; i<10; i++){
        EXPECT_TRUE(tree.FindNode(rand()) == NULL);
    }
 
    EXPECT_TRUE(tree.FindNode(10) == NULL);
    EXPECT_TRUE(tree.FindNode(2) == NULL);

    auto first_node = tree.InsertNode(10);
    auto second_node = tree.InsertNode(2); 

    EXPECT_TRUE(tree.FindNode(10) != NULL);
    EXPECT_TRUE(tree.FindNode(2) != NULL);  
}

TEST_F(NonEmptyTree, InsertNode){

    // Inserting new value 
    auto new1_node = tree.InsertNode(9);
    ASSERT_TRUE(new1_node.second != nullptr && new1_node.first == true);
    EXPECT_TRUE(new1_node.second->color == BinaryTree::RED);
    
    // Testing left leaf
    auto *left = new1_node.second->pLeft;
    EXPECT_EQ(left->pLeft, nullptr);
    EXPECT_EQ(left->pRight, nullptr);
    EXPECT_EQ(left->pParent, new1_node.second);
    EXPECT_TRUE(left->color == BinaryTree::BLACK);


    // Testing right leaf
    auto *right = new1_node.second->pRight;
    EXPECT_EQ(right->pLeft, nullptr);
    EXPECT_EQ(right->pRight, nullptr);
    EXPECT_EQ(right->pParent, new1_node.second);
    EXPECT_TRUE(right->color == BinaryTree::BLACK);


    // Inserting existing value -> expecting .first = false .second = pointer_to_existing_node

    auto ex_node = tree.InsertNode(2);     // ex_node -> existing node 
    ASSERT_TRUE(ex_node.second != nullptr && ex_node.first == false);
    EXPECT_TRUE(new1_node.second->color == BinaryTree::RED);

    // Testing left leaf
    left = ex_node.second->pLeft;
    EXPECT_EQ(left->key, 1);
    EXPECT_TRUE((left->pLeft->pLeft == nullptr) && (left->pRight->pRight == nullptr));  // expecting that next nodes are leafs
    EXPECT_EQ(left->pParent, ex_node.second);

    // Testing right leaf
    right = ex_node.second->pRight;
    EXPECT_EQ(right->key, 3);
    EXPECT_TRUE((right->pLeft->pLeft == nullptr) && (right->pRight->pRight == nullptr));
    EXPECT_EQ(right->pParent, ex_node.second);

}

TEST_F(NonEmptyTree, DeleteNode){
    int values_to_delete[] = {84, 63, 78 , 64 , 13 , 99 , 183 , 168 , 101, 244};
    for (int i=0; i<10; i++){
        EXPECT_FALSE(tree.DeleteNode(values_to_delete[i]));
    }

    EXPECT_TRUE(tree.DeleteNode(2));
    EXPECT_TRUE(tree.DeleteNode(17));
    EXPECT_TRUE(tree.DeleteNode(10));
    EXPECT_EQ(tree.GetRoot()->key, 8);
}

TEST_F(NonEmptyTree, FindNode){
    for (int i=0; i<10; i++){
        EXPECT_TRUE(tree.FindNode(rand()+300) == NULL);
    }

    EXPECT_TRUE(tree.FindNode(0) == NULL);
    EXPECT_TRUE(tree.FindNode(10) == tree.GetRoot());
    EXPECT_TRUE(tree.FindNode(7)->pParent == tree.GetRoot());
    EXPECT_TRUE(tree.FindNode(158)->pLeft->pLeft == nullptr && tree.FindNode(158)->pRight->pRight == nullptr);
}

TEST_F(TreeAxioms, Axiom1){
    std::vector<Node_t *> outLeafNodes {};
    tree.GetLeafNodes(outLeafNodes);
    for (auto node : outLeafNodes){
        EXPECT_TRUE(node->color == BinaryTree::BLACK);
    }
}

TEST_F(TreeAxioms, Axiom2){
    std::vector<Node_t *> outNonLeafNodes {};
    tree.GetNonLeafNodes(outNonLeafNodes);
    for (auto node : outNonLeafNodes){
        if (node->color == BinaryTree::RED){
            EXPECT_TRUE(node->pLeft->color == BinaryTree::BLACK);
            EXPECT_TRUE(node->pRight->color == BinaryTree::BLACK);
        }
        
    } 

}

TEST_F(TreeAxioms, Axiom3){
    std::vector<Node_t *> outLeafNodes {};
    tree.GetLeafNodes(outLeafNodes);

    auto node = outLeafNodes[0];
    int number_of_black_nodes = 0;
    while (node != tree.GetRoot()){
            node = node->pParent;
            if (node->color == BinaryTree::BLACK)
                number_of_black_nodes++;
        }


    for (auto node : outLeafNodes){
        int counter = 0;
        while (node != tree.GetRoot()){
            node = node->pParent;
            if (node->color == BinaryTree::BLACK)
                counter++;      
        }
        EXPECT_EQ(counter, number_of_black_nodes);
    }
}



/*** Konec souboru black_box_tests.cpp ***/
