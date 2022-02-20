#include <iostream>
using namespace std;

class ArrayOperations//Declaring a class
{
public:
    int *array, size, lenght;
    void reverse_arrayM1();//Member functions
    void reverse_arrayM2();
    void display_array();
    int is_sorted_or_not();
    void arranging_elements();
};

void ArrayOperations::display_array()//This will display the all elements
{
    for (int i = 0; i < lenght; i++)
    {
        cout << array[i] << "  ";
    }
    cout<<endl;
}

void ArrayOperations::reverse_arrayM1()//Reversing the array by auxilary array mathod
{
    int *auxilary_array = new int[lenght];//Declaring the auxilary array
    for (int i = lenght - 1, j = 0; i >= 0; i--, j++)// i is the initial index of the main array and j is the final index of the auxilary array
    {
        auxilary_array[j] = array[i];//Coping the elements
    }

    for (int i = 0; i < lenght; i++)//coping the elements again but now of the same index
    {
        array[i] = auxilary_array[i];//Coping the elements from auxilary array to main array
    }
}

void ArrayOperations::reverse_arrayM2()//Mathod two for reversing the elements 
{
    for (int i = 0, j = lenght - 1; i < j; i++, j--)//Here i is the very 1st element of the array and the j is the last element in the array and this loop will run untill the i is less then the j
    {
        int temp = array[i];//And then the swapping bigins
        array[i] = array[j];
        array[j] = temp;
    }
}

int ArrayOperations::is_sorted_or_not()// To check whether the array is sorted or not
{
    for(int i=0;i<lenght-1;i++)
    {
        if(array[i]>array[i+1])//If the present element greater then the next element then the array is not sorted
        return false;//Return 0
    }
    return true;//If the array is sorted then this condition will met
}

void ArrayOperations::arranging_elements()//This member function will run to arrange the elements in the correct order that all -ive elements will be on left side
{/* For that the 1st i will the very 1st index in the array and j will the last element index in the array and the i will shift every time 
to the right side in the and j will go to left side in the array and if the i and j met with some - ive or + ive value then swap them */
    int i=0;
    int j=lenght-1;
    while(i<j)
    {
        while(array[i]<0)//i will check if any of the element is positive or not
        {
            i++;//if i is not met with any positive numebr then increament the i
        }
         while(array[j]>=0)//j will check if any of the element is negative or not
        {
            j--;//if j is not met with any negative numebr then increament the j
        }
        if(i<j)//This condition only for if i is less then only
        {
         swap(array[i],array[j]); //Then swap them          
        }

    }
}

int main()
{
    ArrayOperations ao;
    int number_of_elements;
    cout << "Enter the size of the array" << endl;
    cin >> ao.size;
    ao.array = new int[ao.size];
    cout << "Enter the number of elements that you want to enter " << endl;
    cin >> number_of_elements;
    ao.lenght = number_of_elements;

    cout << "Enter the elemets one by one " << endl;
    for (int i = 0; i < ao.lenght; i++)
    {
        cin >> ao.array[i];
    }
    cout << "The elements that you have enter are :" << endl;
    ao.display_array();

    cout << "The roted array after reversing the array is :" << endl;

    ao.reverse_arrayM1();
    ao.display_array();

    cout << "The roted array after reversing the array is :" << endl;

    ao.reverse_arrayM2();
    ao.display_array();

    cout<<"The array is sorted : "<< ao.is_sorted_or_not()<< endl;

    ao.arranging_elements();

    ao.display_array();

    return 0;
}
