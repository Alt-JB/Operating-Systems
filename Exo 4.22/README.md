JE TIENS A  PRECISER QUE PROGRAMME SA A PA MACHE POU MW. SO AVNT DE MODIFIER, JAIMERAIS SAVOIR SI JE SUIS LA SEULE A AVOIR UN PROBLEME.

Ce programme a pour principal objectif de mettre en avant l'utilisation des 'threads'. Nous disposons, en effet, de cinq threads responsables respectivement de:
- Trouver le maximum (Max)
- Trouver le minimum (Min)
- Trouver la moyenne (Moy)
- Trouver la médiane (Med)
- Trouver la déviation (StD)

Avant tout, que vaut l'existence de cet algorithme? Il s'agit de trouver le maximum, le minimum, la moyenne, la médiane et la déviation d'une liste de nombres entrés par l'utilisateur.

De ce fait, chacun des 'threads' devra attendre que le précédent libère les ressources communes avant de s'exécuter.

EXERCICE 4.22
=============
Write a multithreaded program that calculates various statistical values for a list of numbers. This program will be passed a series of numbers on the command line and will then create three separate worker threads. One thread will determine the average of the numbers, the second will determine the maximum value, and the third will determine the minimum value. For example, suppose your program is passed the integers:
90 81 78 95 79 72 85
The program will report:
The average value is 82
The minimum value is 72
The maximum value is 95
The variables representing the average, minimum, and maximum values will be stored globally. The worker threads will set these values, and the parent thread will output the values once the workers have exited.
(We could obviously expand this program by creating additional threads that determine other statistical values, such as median and standard deviation.)