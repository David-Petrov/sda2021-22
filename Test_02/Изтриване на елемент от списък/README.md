# Task 1. Изтриване на елемент от списък (Medium)

[HackerRank link](<https://www.hackerrank.com/contests/sda-2021-2021-test-2-test/challenges/challenge-3111>)

## Statement:

В класа `SinglyLinkedList`, дефиниран по-долу, реализирайте функция, която премахва всички срещания на елемент в списък. 

В кода по-долу е отбелязано мястото на което да пишете с `//TODO: Write your code here`.

**Input format**

Входа на функцията е int елемент. Програмата има доста по-сложен вход, чиято цел е да тества дали всичко работи.

**Constraints**

Очаква се решението да е линейно.
Функцията следва да може да работи върху списък с дължина милион елемента.

**Output Format**

Функцията се очаква да няма изход. Самата програма има доста по сложен вход, за да се тества дали всичко работи.

---

**Sample Input 0**

```
4
5
add 1 0
add 2 0
add 3 0
remove_all 2
print
5
add 1 0
add 1 1
add 1 1
remove_all 1
print
5
add 1 0
add 2 1
add 2 2
remove_all 2
print
7
add 1 0
add 2 1
add 3 2
add 2 1
add 2 4
remove_all 2
print
```

**Sample Output 0**

```
3#1#

1#
1#3#
```