#include<iostream>
using namespace std;

// The function that solves the tower of Hanoi problem using recursion.
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) 
{ 
    if (n == 1) 
    { 
        // Moving only one disk is straightforward: just move it.
        cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl; 
        return; 
    } 
    // Move n-1 disks from source rod to auxiliary rod. 
    // Here, the destination rod is used as auxiliary rod.
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod); 

    // Move the remaining disk from source rod to destination rod.
    cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;

    // Move the n-1 disks that we left on auxiliary rod to destination rod.
    // Here, the source rod is used as auxiliary rod.
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
} 

int main() 
{ 
    int n; // Number of disks 

    cout<<"Enter the number of disks: ";
    cin>>n;

    // The names of rods
    char rodA = 'A', rodB = 'B', rodC = 'C';

    // Calling the function to solve the problem
    towerOfHanoi(n, rodA, rodB, rodC);

    return 0;
} 

/* 
Input: 3

Output:
Move disk 1 from rod A to rod B
Move disk 2 from rod A to rod C
Move disk 1 from rod B to rod C
Move disk 3 from rod A to rod B
Move disk 1 from rod C to rod A
Move disk 2 from rod C to rod B
Move disk 1 from rod A to rod B */
