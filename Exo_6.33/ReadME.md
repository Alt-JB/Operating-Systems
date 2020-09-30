The preceding program segment produces a race condition. Do the following:
a.Identify the data involved in the race condition.
	There's a race condition on the variable "available_resources" , as 2 process may concurrently try to modify (increase/decrease) its value .
	
b. Identify the location (or locations) in the code where the race condition occurs.

	The critical section (ie location where the race condition occurs) for the function "int decrease_count(int count)" is :
		available_resources -= count; 
		//When it tries to modifiy available_resources.
		
	The critical section (ie location where the race condition occurs) for the function "int increase_count(int count)" is :
		available_resources += count;
		 //When it tries to modifiy available_resources.
	
c. Using a semaphore or mutex lock, fix the race condition. It is permissible to modify the decrease_count() function so that the
calling process is blocked until sufficient resources are available.


Commentaires
------------
	Il n'y aura de concurrence pour l'acces a "available_resources" que si les 2 processus essaient de modifier la valeur en meme temps. De ce fait, nous avons implemente des threads en nous inspirant du modele classique producteur/consommateur. (Exo5_implementation.c)
	Producteur et consommateur auront a acceder :available_ressources et nous utiliserons 2 semaphores pour gerer l'access a cette derniere lors de l'entree en section critique.



