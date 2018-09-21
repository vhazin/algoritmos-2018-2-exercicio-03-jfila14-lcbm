# JFILA14 - Fila
![PyPI - Status](https://img.shields.io/pypi/status/Django.svg)

JQUEUE is a Queue challenge from phase 1 of the Brazilian Computing Olympics 2014. This repo is an attempt to solve [SPOJ's version](https://br.spoj.com/problems/JFILA14/) of the problem.

## Context
With the World CUp approaching, the flow of people in lines (queues) to buy tickets has increased considerably. Since queues are bigger and bigger, less patient people tend to give up the ticket purchase and leave the queue - openning space to other people. When someone leave the queue, everyone that was behind her gives a step ahead, this way there is enver an empty space between two people. Initially, the queue has N people, each with an identifier. Johnzinho knows the initial state of the queue and the identifiers in order of those who left the queue, each with a different identifier. Knowing that after the initial state no one entered the line, Johnzinho wishes to know the final state of the queue.

### Input
The first line contains one integer N representing the quantity of people IN the queue, initially.
The second line contains N integers representing the identifiers of the people in the queue. The first identifier corresponds to the identifier of the first person in the queue. Its guaranteed that two different people DO NOT have the same identifier.
The third line contains one integer M representing the quantity of people that LEFT the queue.
The fourth line contains M integers representing the identifiers of the people that left the line, in the order they left. 
Its guaranteed that one single identifier WILL NOT appear twice in this line.

### Output
Program must print one line containing (N - M) integers with the identifiers of the people which stayed in line (queue), in order of arrival.

### Example
```
Input:
8
5 100 9 81 70 33 2 1000
3
9 33 5

Output:
100 81 70 2 1000

Input:
4
10 9 6 3
1
3

Output:
10 9 6
```
