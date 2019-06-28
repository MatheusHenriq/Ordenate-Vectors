#include <iostream>
#include "ord.h"
#include <time.h>
#include <math.h>

Ordenate :: Ordenate(int n){

	dim = n;
	data = new int[dim];
	

}

Ordenate :: ~Ordenate(){
	
	delete[] data;

}

//Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
//Reference :: GeeksForGeeks


void Ordenate :: BubbleSort(){

	int aux;
	int swap=0;	

	for(int i=0; i<dim-1; i++){
		for(int j=0; j<dim-i-1; j++){
			if(data[j]>data[j+1]){
				aux = data[j];
				data[j] = data[j+1];
				data[j+1] = aux;
				swap++;
			}
		}
	}
	
	std::cout<<"swap = "<<swap<<std::endl;

}

//assumes that the first one is ordered, and if the adjacent one is smaller, it changes, and makes successive changes if necessary 

void Ordenate :: InsertionSort(){

	int i,j,aux;
	int swap = 0;
	
	for(i = 1; i < dim; i++){

		aux = data[i];
		j = i-1;
		
		while(j >= 0 && data[j] > aux){

			data[j+1] = data[j];
			j--;
			swap++;
		}

		data[j+1] = aux;
	}
	
	std::cout<<"swap = "<<swap<<std::endl;	

} 

//The selection sort algorithm sorets an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. Reference :: GeeksForGeeks

void Ordenate :: SelectionSort(){

	int aux,min,count;
	int swap = 0;
	
	for(int i=0; i<dim-1; i++){
		
		min = i;		
		count =0;
		for(int j= i+1; j<dim; j++)
		{
			if(data[j] < data[min]){
				min = j;
				count++;
			}
			
			if(count>0)
				swap++;
		}

		aux = data[min];
		data[min] = data[i];
		data[i] = aux;
					
	}

	std::cout<<"swap = "<<swap<<std::endl;	

}

//ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items. In shellSort, we make the array h-sorted for a large value of h. We keep reducing the value of h until it becomes 1. An array is said to be h-sorted if all sublists of every h’th element is sorted. Reference :: GeeksForGeeks



void Ordenate :: ShellSort(){
	
	int i,j,aux;
	int hiatus = 1;
	int swap 	= 0;
	

	while(hiatus < dim){
		hiatus = 3*hiatus + 1;
	}
	
	while(hiatus > 0){
			
		for(i = hiatus; i < dim; i++){
			aux = data[i];
			j = i ;
			while(j > hiatus-1 && aux < data[j-hiatus]){
	
				data[j] = data[j-hiatus];
				j -= hiatus;
				swap++;	
			}
		
			data[j] = aux;	
		}
		hiatus/=3;
	}
	

	std::cout<<"swap = "<<swap<<std::endl;


}

void Ordenate :: Show(){

	for(int i=0; i < dim; i++){
		
		std::cout << data[i] <<" ";	

	}	
	
	std::cout<<std::endl;

}
