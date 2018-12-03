/*
 *   Name : Ghaida Al-Atoum         ID#: **********
 *                            Lab
 *   Compile Using : gcc -std = c99 Solution.c 
*/
#include <stdio.h>
#include <stdlib.h>

/* Declaring Global Variables */
    // Main Array    :
        int * Array ;
    // Link Array    :
        int * Link ;
    // Small Array  , For saving the index of the smallest component in each merge
        int * Small;      
    // Length Of the Array
        int length;
/* Merge Function */
    void Merge (int nL, int stL, int nR, int stR)
       {
         // nL = length of left array  , stL = start index of the left array
         // nR = length of right array , stR = start index of the right array
         int i = stL;     // (i) for looping through the left array
         int j = stR;     // (j) for looping through the right array
         int z ;          // Dump Variable used for storing the values that will be changed
         int check =0;    // This Variable indicates if this merge has found the smalles value or not
         
         // if we are not merging the "leafs" of the tree then the looping variables will start from the smallest component
         if(nL != 1)
              i = Small[stL]; // For looping the left array the smallest of the left is always stored in small[stL]
         if(nR != 1)
              j = Small[stR]; // For looping the right array the smallest of the right is always stored in small[stR]
               
         while ( i != -1 && j != -1) 
           {
               if( Array[i] <= Array[j])
                 {
                    // Left Component is smaller
                    if( !check ) 
                      {
                          // If the smallest value of this merge is not set 
                          Small [stL]= i ; // save the index of the smallest at the stL index 
                          check = 1; 
                      } //end_check_IF
                    z = Link [i];
                    Link [i] = j;
                    if( z != -1) 
                      {  // to check if the component was pointing to a smaller value already 
                         if( Array[z] <= Array[j])
                           { 
                              Link[i] = z; // if it was pointing to a smaller value keep it pointing to that value 
                                           // the equal sign here is to ensure stablitiy so if it was pointing to a value that is the 
                                           // same in Array[j] the left has priority
                           }
                      }
                    i = z;
                 }
               else
                 {
                    if( !check)
                     {
                        Small [stL] = j;
                        check = 1;
                     }
                    z = Link[j];
                    Link[j] = i;
                    if( z != -1 )
                      {
                         if( Array[z] < Array[i] )
                           {
                              Link[j] = z;
                           }
                      }
                    j = z;
                 }
           }        
       }

/* MergeSort Function (Dividing the Array) */
    void MergeSort (int size, int start)
       {
         if( size < 2 )
              return ;
         int mid = size /2;
         MergeSort (mid, start);                         // Left  Array ( length = mid , start  = original start)
         MergeSort (size - mid , mid + start);           // Right Array ( length = original length - mid , start = mid + original start)
         Merge ( mid, start, size - mid, mid + start);   // Merge the Left and Right Array
         }

/* Main Function */
    int main(void) 
       {
        scanf("%d",&length);
        Array  = (int*) calloc ( length, sizeof( int ));             // Allocating the Array
        Link   = (int*) calloc ( length, sizeof( int ));
		Small  = (int*) calloc ( length, sizeof( int ));
        for(int loop =0 ; loop < length ; loop ++)                  // Reading the values + initalizing the Link and small Array to -1
          {
             scanf("%d",&Array[loop]);
             Link[loop]=-1; 
             Small[loop]=-1;
          }
       // Call The Merge Sort
       MergeSort(length,0);
       // Print The Results
       printf("\nFirst Element At Index %d\n",Small[0]);
       for(int j=0; j< length ; j++)
          {
             printf("%d\t%d\t%d\n",j,Array[j],Link[j]);
          }
       free(Array);
       free(Link);
       free(Small);
       return 0; 
       }  
