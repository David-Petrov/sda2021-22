# Task 1. Елитизъм (Medium)

[HackerRank link](<https://www.hackerrank.com/contests/sda-hw-8-2021/challenges/elitism>)

## Statement:

Алгоритмия e станала много елитна държава и всеки ден населението й расте! Държавният глава се интересува от гражданите си и наема статистици да следят за различни показатели на населението.

Един показател, който иска да знае е  **_медиана на състоянието_**. Това е число, което разделя населението на две равни части - едната част има повече пари в сметката си от това число, а другата по-малко.

[Повече за това какво е медиана](https://en.wikipedia.org/wiki/Median)

Понеже Алгоритмия е много популярна държава, следенето на този показател е трудно, тъй като всеки ден нов гражданин се преселва в държавата. Помогнете на статистиците, като след всеки нов регистриран гражданин отпечатате на стандартния изход медианата.

**Input Format**

Първият ред на стандартния вход съдържа едно цяло число $N$ (брой граждани).

Следват $N$ на брой цели положителни числа $a_0,\dots,a_{n-1}$, всяко на нов ред (парите на поредния гражданин).

**Constraints**

$1 \le N \le 5\cdot10^5$

$0\le a_i \le 2^{24}$

_Алгоритмия е приела политика да не дава гражданство на хора с отрицателна сума в сметката си_ 😕

**Output Format**

След всеки регистриран гражданин, отпечатайте на нов ред на стандартния изход обновената статистика с точност до първия знак след десетичната запетая (с точност до $10^{-1}$).

---

**Sample Input 0**

```
10
1
2
3
4
5
6
7
8
9
10
```

**Sample Output 0**

```
1.0
1.5
2.0
2.5
3.0
3.5
4.0
4.5
5.0
5.5
```

---

**Sample Input 1**

```
4
3
11
4
2
```

**Sample Output 1**

```
3.0
7.0
4.0
3.5
```