EXERCICE 3.21
------------------------------------------------------------------------------
Program  : The Collatz conjecture
FileName : Exo3.c
Input    : Any positive number
Output 	 : The input, .... (all the numbers found) ..., 1.
By       : ALTIDOR Jean Bernard T., DUBUCHE Kevin J., THEODORE Barbara G.  
-----------------------------------------------------------------------------

Dans ce programme écrit en C, l'objectif est de créer un algorithme demandant à un utilisateur de rentrer un entier strictement positif, n.
Une fois cette valeur entrée, l'algorithme sera le suivant:
n=n/2,      si n est pair
n=3*n+1,    si n est impair
Et cet algorithme continuera jusqu'a ce que le système obtienne '1' pour résultat.

Comment cela se passe-t-il au coeur du programme?

Pour commencer, il est demandé à l'utilisateur d'entrer un nombre entier positif. Tant que ce nombre ne sera pas positif, l'algorithme en question ne pourra pas être lancé.

Il s'agit d'un programme mondialement connu et jusqu'à présent impossible à prouver.

EXPLICATION PARENT VS CHILD PROCESS
======================================

Après avoir vérifié la création du processus 'enfant', l'algorithme peut alors être mis en marche. Afin d'assurer cette vérification, il suffit de prendre en compte l'identifiant du processus. Si ce dernier est négatif, le processus n'a pas été créé. Néanmoins, si l'identifiant est nul, cela sous-entend que le processus 'parent' est en pleine exécution, alors une interruption d'attente est imposée au processus 'enfant'.



EXERCISE 3.21

The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
n = n∕2, if n is even
n = 3 × n + 1, if n is odd

The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is:
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1.
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive
integer is passed on the command line.