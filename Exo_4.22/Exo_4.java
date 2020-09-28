/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exo_4;

/**
 *
 * @author Administrateur
 */
import java.util.Arrays;
import java.lang.Thread;
import java.util.Scanner;

public class Exo_4
{
    public static Scanner scanner = new Scanner(System.in);
    
    public static int nextInt(){
    int i=0;
    boolean done=false;
    
    System.out.println("Please enter a number:");
    while (!scanner.hasNextInt()){//ou i== 0
        System.out.println("Please enter a number:");
        scanner.nextLine();
      
    }
      i = scanner.nextInt();
    
    return i;
}
       public static int [] readNumsFromCommandLine() {
        System.out.println("Enter n : ");
      int input = nextInt();
      

       
       int[] array = new int[input];
       for(int i = 0; i < array.length; i++){
           System.out.println("Enter le nombre  #"+(i+1)+" : ");
           array[i]=nextInt();
       }
       scanner.close();
        return array;
    }

    //declare the variables globally
  //  public static int input[]= {12,123,1324,13242,92,24,24,56,73,2} ;//temporary
       public static int input[]= readNumsFromCommandLine();
    public static int max =0 ,min = 0;
    public static double  average = 0 , median = 0 ,StandardDeviation = 0;
    
 
    
    public static void main(String[] args) throws InterruptedException
		{
					
            //Get and check user input 
            //using predefined array "input" for now

            Arrays.sort(input);//Sort the list to calculate the median later 
                               //m sort li depuis avant pou leu thread yo ap lage poul pa bay problems

            Thread Max  = new GetMax();
            Thread Min  = new GetMin();
            Thread Moy  = new GetAverage();
            Thread Med  = new GetMedian();
            Thread StD  = new GetStandardDeviation();

            //Starting threads
            Max.start();
            Min.start();
            Moy.start();
            Med.start();
            StD.start();

            //Waiting for all threads to finish
            Max.join();
            Min.join();
            Moy.join();
            Med.join();
            StD.join();

            //Printing results 
            System.out.println("The maximum value is "+ max);
            System.out.println("The minimum value is "+ min);
            System.out.println("The average  value is "+ average);
            System.out.println("The median value is "+ median);
			System.out.println("The Standard Deviation  is "+ StandardDeviation);
		} 
}


class GetMax extends Thread
    {
       //Thread to get the maximun value
       
        public void run ()
        {
            Exo_4.max = Exo_4.input[Exo_4.input.length-1];
        } 
    }
    
    class GetMin extends Thread
    {
       //Thread to get the minimum value
       
        public void run ()
        {
            Exo_4.min = Exo_4.input[0];
        } 
    }

    class GetAverage extends Thread
    {
       //Thread to get the average 
       
        public void run ()
        {
            Exo_4.average = Arrays.stream(Exo_4.input).average().getAsDouble();
        } 
    }

    class GetMedian  extends Thread
    {
       //Thread to get the median
       
        public void run ()
        {
            
            int mitan = Exo_4.input.length/2;
            //Si la liste est de longueur impaire,la mediane est le chiffre au milieu.
            //sinon c'est la moyenne des 2 nombres au milieu
            if (Exo_4.input.length%2 == 1)
            Exo_4.median = Exo_4.input[mitan];
            else 
            Exo_4.median = (Exo_4.input[mitan] + Exo_4.input[mitan+1])/2; 

        } 
    }

    class GetStandardDeviation extends Thread
    {
        public void run ()
        { 
            //Standard deviation formula : sum [1,i,n](i-average)^2/n
            double sd = 0;
            for (int i=0;i<Exo_4.input.length;i++)
            {
                sd = sd +Math.pow(Exo_4.input[i]- Exo_4.average, 2);
            }
            Exo_4.StandardDeviation = sd/Exo_4.input.length;
        }

    }
    