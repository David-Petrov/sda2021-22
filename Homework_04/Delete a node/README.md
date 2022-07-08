# Task 3. Delete a node (Easy)

[HackerRank link](<https://www.hackerrank.com/contests/sda-hw-4/challenges/delete-a-node-from-a-linked-list>)

## Statement:

Delete the node at a given position in a linked list and return a reference to the head node. The head is at position 0. The list may be empty after you delete the node. In that case, return a null value.

**Example**

$llist = 0 \rightarrow 1 \rightarrow 2 \rightarrow 3$

$position = 2$

After removing the node at position $2$, $llist' = 0 \rightarrow 1 \rightarrow 3$

**Function description**

Complete the  _deleteNode_  function in the editor below.

_deleteNode_  has the following parameters:  
-  _SinglyLinkedListNode pointer llist:_  a reference to the head node in the list  
-  _int position:_  the position of the node to remove

**Returns**

- _SinglyLinkedListNode pointer:_ a reference to the head of the modified list

**Input format**

The first line of input contains an integer $n$, the number of elements in the linked list.  
Each of the next $n$ lines contains an integer, the node data values in order.  
The last line contains an integer, $position$, the position of the node to delete.

**Constraints**

$1 \le n\le 1000$

$1 \le list[i]\le 1000$, where $list[i]$ is the $i^{th}$ element of the linked list.

---

**Sample input**


```
8
20
6
2
19
7
4
15
9
3
```

**Sample output**

```
20 6 2 7 4 15 9
```

**Explanation**

The original list is $20 \rightarrow 6 \rightarrow 2 \rightarrow 19 \rightarrow 7 \rightarrow 4 \rightarrow 15 \rightarrow 9$. After deleting the node at position $3$, the list becomes $20 \rightarrow 6 \rightarrow 2 \rightarrow 7 \rightarrow 4 \rightarrow 15 \rightarrow 9$.