cmake_minimum_required(VERSION 3.8)
project(SwordOffer_mac)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES List.cpp List.h
        BinaryTree.cpp BinaryTree.h
        ComplexList.cpp ComplexList.h
        Myoffer3_01_array_duplication.cpp
        Myoffer4_array_FindInPartiallySortedMatrix.cpp
        Myoffer5_String_ReplaceSpace.cpp
        Myoffer6_List_PrintListInReversedOrder.cpp
        Myoffer7_Tree_ConstructBinaryTree.cpp
        Myoffer8_Tree_NextNodeInBinaryTrees.cpp
        Myoffer18_02_List_DeleteDuplicatedNode.cpp
        Myoffer22_List_KthNodeFromEnd.cpp
        Myoffer23_List_EntryNodeInListLoop.cpp
        Myoffer24_List_ReverseList.cpp
        Myoffer25_List_MergeSortedLists.cpp
        Myoffer35_List_CopyComplexList.cpp
        Myoffer52_List_FirstCommonNodesInLists.cpp Myoffer8_Tree_NextNodeInBinaryTrees.cpp)

add_executable(SwordOffer_mac ${SOURCE_FILES}
        List.cpp List.h
        BinaryTree.cpp BinaryTree.h
        ComplexList.cpp ComplexList.h
        Myoffer3_01_array_duplication.cpp
        Myoffer4_array_FindInPartiallySortedMatrix.cpp
        Myoffer5_String_ReplaceSpace.cpp
        Myoffer6_List_PrintListInReversedOrder.cpp
        Myoffer7_Tree_ConstructBinaryTree.cpp
        Myoffer8_Tree_NextNodeInBinaryTrees.cpp
        Myoffer18_02_List_DeleteDuplicatedNode.cpp
        Myoffer22_List_KthNodeFromEnd.cpp
        Myoffer23_List_EntryNodeInListLoop.cpp
        Myoffer24_List_ReverseList.cpp
        Myoffer25_List_MergeSortedLists.cpp
        Myoffer35_List_CopyComplexList.cpp
        Myoffer52_List_FirstCommonNodesInLists.cpp)