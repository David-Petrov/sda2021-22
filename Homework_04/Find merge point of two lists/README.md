# Task 2. Find merge point of two lists (Easy)

[HackerRank link](<https://www.hackerrank.com/contests/sda-hw-4/challenges/find-the-merge-point-of-two-joined-linked-lists>)

## Statement:

Given pointers to the head nodes of two linked lists that merge together at some point, find the node where the two lists merge. The merge point is where both lists point to the same node, i.e. they reference the same memory location. It is guaranteed that the two head nodes will be different, and neither will be NULL. If the lists share a common node, return that node's `data` value.

**Note:** After the merge point, both lists will share the same node pointers.

**Example**

In the diagram below, the two lists converge at Node  `x`:

```
[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
```

**Function Description**

Complete the  _findMergeNode_  function in the editor below.

_findMergeNode_  has the following parameters:

-   _SinglyLinkedListNode pointer head1:_  a reference to the head of the first list
-   _SinglyLinkedListNode pointer head2:_  a reference to the head of the second list

**Returns**

-   _int:_  the  value of the node where the lists merge

**Input Format**

_Do not read any input from stdin/console._

The first line contains an integer $t$, the number of test cases.

Each of the test cases is in the following format:  
The first line contains an integer,  $index$, the node number where the merge will occur.  
The next line contains an integer, $list1\\_count$, that is the number of nodes in the first list.  
Each of the following $list1\\_count$ lines contains a `data` value for a node. The next line contains an integer, $list2\\_count$, that is the number of nodes in the second list.  
Each of the following $list2\\_count$ lines contains a `data` value for a node.

**Constraints**

The lists will merge.

$head1,head2\ne null$

$head1 \ne head2$

---

**Sample Input**

The diagrams below are graphical representations of the lists that input nodes $head1$ and $head2$ are connected to.

**Test Case 0**

```
 1
  \
   2--->3--->NULL
  /
 1
```

**Test Case 1**

```
1--->2
      \
       3--->Null
      /
     1
```

**Sample Output**

```
2
3
```

**Explanation**

_Test Case 0:_  As demonstrated in the diagram above, the merge node's data field contains the integer  $2$.  

_Test Case 1:_  As demonstrated in the diagram above, the merge node's data field contains the integer  $3$.