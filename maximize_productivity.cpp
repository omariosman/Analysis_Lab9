
#include <iostream>

using namespace std;



#include <bits/stdc++.h> 
using namespace std; 


/******* Job Class *************/
class Job {
    private:
        int start_time, finish_time;
    
    public:
        void set_start_time(int _start_time); 
        void set_finish_time(int _finish_time); 
        int get_start_time(); 
        int get_finish_time(); 
    
};

void Job::set_start_time(int _start_time){
    start_time = _start_time;
}

void Job::set_finish_time(int _finish_time){
    finish_time = _finish_time;
}

int Job::get_start_time(){
    return start_time;
}



int Job::get_finish_time(){
    return finish_time;
}



/********* QuickSort ***********/

void swap(Job* a, Job* b) 
{ 
	Job t = *a; 
	*a = *b; 
	*b = t; 
} 


int partition (Job arr[], int low, int high) 
{ 
	int pivot = arr[high].get_finish_time(); 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{ 

		if (arr[j].get_finish_time() < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 


void quickSort(Job arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
	
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

void print(Job arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) {
	    cout << "Job " << i + 1 <<": " << endl;
		cout << "start time: " << arr[i].get_start_time() << endl; 
		cout << "finish time: " << arr[i].get_finish_time() << endl; 
		cout << endl;
}
	cout << endl; 
} 





int track = 1;
/******** Greedy Algorithm **********/
Job *maximize_productivity(Job arr[], int size){
    Job *solutionArray;
    solutionArray = new Job();
    
    
    quickSort(arr, 0, size - 1);

    solutionArray[0] = arr[0];

    int i = 0;
    int j = i + 1;
    while (i < size - 1) {
        if (arr[i].get_finish_time() < arr[j].get_start_time()){
            solutionArray[track] = arr[j]; 
            track++;
            i = j;
            j++;

        } else {
            j++;
            //continue;
        }
    }
    return solutionArray;
}










int main()
{
    //TestCase #1
    //instantiating 3 jobs
    
    cout << "Test Case #1: " << endl;
    Job job1;
    job1.set_start_time(22);
    job1.set_finish_time(30);
    
    Job job2;
    job2.set_start_time(10);
    job2.set_finish_time(20);
    
    Job job3;
    job3.set_start_time(12);
    job3.set_finish_time(25);


    //Creating an array contains 3 jobs
    Job arr[3] = {job1, job2, job3};
    
    
    Job *finalArray;
    finalArray = new Job();
    
    finalArray = maximize_productivity(arr, 3);
    cout << "Number of jobs: " << track << endl;
    print(finalArray, track);

    cout << endl;
    
    track = 1;
    
    cout << "Test Case #2: " << endl;

    //TestCase #2
    //instantiating 6 jobs
    job1.set_start_time(1);
    job1.set_finish_time(2);
    
    job2.set_start_time(3);
    job2.set_finish_time(4);
    
    job3.set_start_time(0);
    job3.set_finish_time(6);
    
    
    Job job4;
    job4.set_start_time(5);
    job4.set_finish_time(7);

    Job job5;
    job5.set_start_time(8);
    job5.set_finish_time(9);


    Job job6;
    job6.set_start_time(5);
    job6.set_finish_time(9);

    //Creating an array contains 6 jobs
    Job arr2[6] = {job1, job2, job3, job4, job5, job6};
    

    finalArray = maximize_productivity(arr2, 6);
    cout << "Number of jobs: " << track << endl;
    print(finalArray, track);
    

}
