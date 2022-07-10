# Task 3. Leafs (Hard)

[HackerRank link](<https://www.hackerrank.com/contests/exam-2022-part2-sda/challenges/leafs>)

## Statement:

Даден ви е е ацикличен насочен граф като списък от ребра. Всеки връх има тежест колкото номера му. Дадени са ви заявки, под формата на номер на връх. За всяка една върнете сбора от всичките тежести на наседниците му.

**Input Format**

На първия ред на стандартният вход ще получите броя на ребрата `m` и броя на заявките `t`. На следващите `m` реда ще получите ребрата под формата на две числа - номера на началото на реброто и номера на края му. На следващите `t` реда ще получите заявки под формата на единствено число - номер на връх, чийто сбор на наследници трябва да върнете.

**Constraints**

$1\le m,t\le 2\cdot 10^5$

$1\le$ номер на връх $\le 2\cdot 10^5$

**Output Format**

На отделни редове изкарайте на стандартния изход отговора за всяка заявка.

---

**Sample Input 0**

```
4 3
1 2
1 3
2 4
3 5
2
1
5
```

**Sample Output 0**

```
4
14
0
```