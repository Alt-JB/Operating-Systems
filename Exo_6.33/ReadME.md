The preceding program segment produces a race condition. Do the following:
a.Identify the data involved in the race condition.
	There's a race condition on the variable "available_resources" , as 2 process may concurrently try to increase and decrease its value .
	
b. Identify the location (or locations) in the code where the race condition occurs.
	The critical section (ie location where the race condition occurs) for the function "int decrease_count(int count)" is :
		available_resources -= count; //When it tries to modifiy available_resources.
		
	The critical section (ie location where the race condition occurs) for the function "int increase_count(int count)" is :
		available_resources += count; //When it tries to modifiy available_resources.
	
c. Using a semaphore or mutex lock, fix the race condition. It is permissible to modify the decrease_count() function so that the
calling process is blocked until sufficient resources are available.

*********************
Comments:

Ok ,so nou besoin que leu variable lan paka augmenter e diminuer en meme ,aussi nou pa vle que pendant moun lan ap verifier si gen resource disponibles que li ta varier(like ou finn wel null et en meme temos li gentan a 1 et vice versa).
So race condition lan c sou variable available resources lan et donc section critique lan c periode pendant laquelle fonction yo ap soit check soit update variable ca. 
Nou declarer 2 semaphores: sem_dec,sem_inc;
Fok nou fon jan pou leu nan section critique increase lan pou decrease lan nan section critique li:exclusion mutuelle
donc nan fonction increase lan,exactement avant section critique li,m mete "sem_wait(&sem_dec);" ki fait li tann si decrease lan nan section critique pal. et vice versa
then leu ou soti de section an ,ou release semaphore lan ie ou di ou pa na section critique anko.sem_post(&sem_dec)
