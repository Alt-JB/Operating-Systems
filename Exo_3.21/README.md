Dans ce programme écrit en C, l'objectif est de créer un algorithme demandant à un utilisateur de rentrer un entier strictement positif, n.
Une fois cette valeur entrée, l'algorithme sera le suivant:
n=n/2,      si n est pair
n=3*n+1,    si n est impair
Et cet algorithme continuera jusqu'a ce que le système obtienne '1' pour résultat.

Comment cela se passe-t-il au coeur du programme?

Pour commencer, il est demandé à l'utilisateur d'entrer un nombre entier positif. Tant que ce nombre ne sera pas positif, l'algorithme en question ne pourra pas être lancé.

EXPLICATION PARENT VS CHILD PROCESS
======================================
VERIFIER 3 RETURN VALUE NAN PARAGRAF SA AVAN NOU VOYEL, GEN YON TYPO
Après avoir vérifié la création du processus 'enfant', l'algorithme peut alors être mis en marche. Afin d'assurer cette vérification, il suffit de prendre en compte l'identifiant du processus. Si ce dernier est négatif, le processus n'a pas été créé. Néanmoins, si l'identifiant est nul, cela sous-entend que le processus 'parent' est en pleine exécution, alors une interruption d'attente est imposée au processus 'enfant'.

EXPLICATION DE fork()
----------------------
Supposons qu'on aie 2 variables dans notre programme:
a=1;  b=2;
Le processus qui contient ces 2 variables est identie grace a son PID, mis pour Process Identifier.

On utilise la fonction getPID pour recuperer l'identifiant d'un processus.
Supposons que PID de notre processus soit 5.
Lorsque nous faisons l'appel system "fork()" dans notre processus, il cree une nouveau processu appele "child" qui est une duplication du processus parent.

Ces deux processus sont exactement les memes (a=1; b=2) a l'exception de leur PID.
Les 2 processus vont commencer leur execution a partir de la prochaine instruction qui suit l'appel de fork().

Ce qui est important c'est la valeur retournee par ces processus.
Si le processus retourne 0, nous savons que nous sommes dans le processus "child". S'il retourne une valeur different de 0 et positif, nous savons que nous sommes dans le processus parent. Pour une valeur < 0, il s'agit d'une erreur.

Apres avoir appele fork(), on ne sait pas quel processus sera execute avant. Pour cette raison, on dit le processus parent t'atendre (wait()) la fin de l'execution du child.

Au cours de l'execution du processus enfant, on peut temporairement modifier les valeurs de a et b (pour n'importe quel raison: a=7; b=8;).
Les changement se feront seulement dans le processsus enfant.
Apres l'utilisation de a=7; et b=8; le processus enfant sera termine et le processus parent sera execute comme si les variables n'avaient jamais ete change (i.e a=1; b=2;).

Ce qui arrive dans le processus enfant reste local et temporaire. Une fois le le processus enfant termine, les changement sont effaces.

Fork() permet la gestion de plusieurs processus independemment les uns des autres. Ce qui arrive dans un processus n'afectera pas un autre processus.

L'appel de wait() libere les ressources utilisees par le processus enfant.
Un processus enfant termine qui ne libere pas ses ressources (si on appel pas wait()) est considere comme un zombie.

Si le programme est assez petit et que vous oubliez de liberer les ressources des processus enfant, vous n'allez pas remarquer les effets car ils seront negligeable. Mais, plus le proogramme est gros, plus vous rarquer le gaspillage des ressouces.

INFO
In software engineering, a project fork happens when developers take a copy of source code from one software package and start independent development on it, creating a distinct and separate piece of software.

EXERCISE 3.21

The Collatz conjecture concerns what happens when we take any positive integer n and apply the following algorithm:
n = n∕2, if n is even
n = 3 × n + 1, if n is odd

The conjecture states that when this algorithm is continually applied, all positive integers will eventually reach 1. For example, if n = 35, the sequence is:
35, 106, 53, 160, 80, 40, 20, 10, 5, 16, 8, 4, 2, 1.
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the command line. For example, if 8 is passed as a parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data, it will be necessary for the child to output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. Perform necessary error checking to ensure that a positive
integer is passed on the command line.