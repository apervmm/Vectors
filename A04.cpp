// Name : Almas Perneshev 
// SSID : 1712618
// Assignment #: 4
// Submission Date : 4/27/2019
// Description : An integer Vector implementation using a struct//
#include<iostream> 
#include<vector>

using namespace std;

struct Vector {
	int size = 0;
	int capacity = 0;
	int *data = nullptr;
};

//prototypes of functions:

void construct_vector(Vector& v, int size = 0, int initVal = 0);

int size(const Vector & v);

int & at(Vector & v, int i);

int capacity(const Vector & v);

int & front(const Vector & v);

int & back(const Vector & v);

void destroy_vector(Vector & v);

void push_back(Vector & v, int element);

void pop_back(Vector & v);

void clear(Vector & v);

int* data(const Vector & v);

bool empty(Vector & v);

int main()
{
	Vector a, b;
	cout << "Vector a, b" << endl;
	cout << "construct_vector (a ,5 ,0)" << endl << endl;
	construct_vector(a, 5, 0);                          //construct vector a
	cout << "a= ";
	for (int i = 0; i < size(a); i++)        //all elements 
	{
		std::cout << at(a, i) << " ";
	}
	cout << endl;
	cout << "size (a) is " << size(a) << endl;        //check size
	cout << "capacity (a) is " << capacity(a) << endl << endl;   //check capacity

	at(a, 0) = 10;         // assign value 10 at point a[0]
	at(a, 3) = 5;		   // assign value 5 at point a[3]
	cout << "at(a ,0) = 10" << endl;
	cout << "at(a ,3) = 5" << endl;

	cout << "a = ";
	for (int i = 0; i < size(a); i++)
	{
		cout << at(a, i) << " ";
	}cout << endl << endl;

	int& vFront = front(a);               // First element
	cout << "front (a) = " << vFront;
	cout << endl;

	int& vBack = back(a);					// Last element
	cout << "back (a) = " << vBack << endl << endl;

	destroy_vector(a);							//destroy vector
	cout << "destroy_vector (a)" << endl;
	cout << "size(b)" << " is " << size(a) << endl;  //check size of the destroyed vector(a)
	cout << "capacity(b)" << " is " << capacity(a) << endl; //check the capacity of the destroyed vector(a)


	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

	cout << "construct_vector (b)" << endl;
	construct_vector(b);								// construct vector b
	cout << "size(b)" << " is " << size(b) << endl;  //check size
	cout << "capacity(b)" << " is " << capacity(b) << endl << endl;  // check capacity


	cout << "push_back(b,0)  push_back(b,1)" << endl;
	cout << "push_back(b,2)  push_back(b,3)" << endl << endl;
	push_back(b, 0);									// push_back the (b, element) to the end
	push_back(b, 1);
	push_back(b, 2);
	push_back(b, 3);

	cout << "b= ";
	for (int i = 0; i < size(b); i++)  // all elements
	{
		cout << at(b, i) << " ";
	}cout << endl;


	cout << "size (b) is " << size(b) << endl;      //check size
	cout << "capacity (b) is " << capacity(b) << endl << endl;   // check capacity

	cout << "at(b,1) is " << at(b, 1) << endl;      // the element at position [1]
	cout << "at(b,1) = 88" << endl;
	at(b, 1) = 88;                             // assign value 88 to b[1]

	cout << "b= ";
	for (int i = 0; i < size(b); i++)      // all elements
	{
		std::cout << at(b, i) << " ";
	}cout << endl << endl;

	cout << "pop_back(b)" << endl;
	pop_back(b);                     //deletes last element 
	cout << "b= ";
	for (int i = 0; i < size(b); i++)
	{
		cout << at(b, i) << " ";
	} cout << endl << endl;


	cout << "push_back(b,55)  push_back(b,75)" << endl;
	push_back(b, 55);     //add element
	push_back(b, 75);
	cout << "b= ";
	for (int i = 0; i < size(b); i++)
	{
		std::cout << at(b, i) << " ";
	}cout << endl << endl;

	cout << "clear(b) " << endl;
	clear(b);
	cout << "size(b) is " << size(b) << endl;
	cout << "capacity(b) is " << capacity(b) << endl;
	cout << "epmty(b): ";
	if (empty(b) == 0)
	{
		cout << "true" << endl << endl;;
	}
	else
	{
		cout << "false" << endl << endl;
	}

	cout << "push_back(b,10) push_back(b,20)" << endl;
	cout << "push_back(b,30) push_back(b,40)" << endl;
	cout << "push_back(b,70) push_back(b,60)" << endl << endl;
	push_back(b, 10);                         // push_back the (b, element) to the end
	push_back(b, 20);
	push_back(b, 30);
	push_back(b, 40);
	push_back(b, 50);
	push_back(b, 60);


	cout << "size(b) is " << size(b) << endl;          // check the size
	cout << "capacity(b) is " << capacity(b) << endl << endl; //check the capacity 

	cout << "int* ptr = data(b)" << endl;
	int *ptr = data(b);
	cout << "b= ";
	for (int i = 0; i < b.size; i++)
	{
		cout << ptr[i] << " ";
	}cout << endl << endl;

	cout << "destroy_vector(b)" << endl;
	destroy_vector(b);
	cout << "size(b) is " << size(b) << endl;
	cout << "capacity(b) is " << capacity(b) << endl << endl;


	system("pause");
	return 0;
}

void construct_vector(Vector& v, int size, int initVal)  //creats vectors
{
	v.capacity = size;
	v.size = size;
	v.data = new int[size];
	for (int i = 0; i < size; i++)
	{
		v.data[i] = initVal;
	}
}

int size(const Vector & v)  // returns the size
{
	return v.size;
}

int & at(Vector & v, int i) //returns the data at some point
{
	return v.data[i];
}

int capacity(const Vector & v)  // return the capacity
{
	return v.capacity;
}

int & front(const Vector & v) //throw (std::out_of_range)
{
	return v.data[0];
}

int & back(const Vector & v) //throw (std::out_of_range)
{
	return v.data[v.size - 1];
}

void destroy_vector(Vector & v) 
{
	v.size = 0;
	delete[] v.data;
	v.capacity = 0;
}

void push_back(Vector & v, int element) 
{
	if (empty(v)) {																// empty(v) - reads the functioon "bool empty()", when the size is 0
		v.capacity = 3;
		v.data = new int[v.capacity];
		v.data[0] = element;
		v.size++;
	}
	else if (v.size + 1 < v.capacity)			//if the capacity larger than size
	{
		v.data[v.size++] = element;
	}
	else
	{
		int *newArr = new int[v.capacity + 1];
		for (int i = 0; i < v.size; i++)
		{
			newArr[i] = v.data[i];
		}
		newArr[v.size++] = element;
		v.capacity++;
		delete[] v.data;
		v.data = newArr;
	}
}

void pop_back(Vector & v)  
{
	v.size--;
	int *newArray = new int[v.capacity];
	for (int i = 0; i < v.size; i++)
	{
		newArray[i] = v.data[i];
	}
	delete[] v.data;
	v.data = newArray;
}

void clear(Vector & v)
{
	v.size = 0;
	int *Arrclear = new int[v.capacity];
	for (int i = 0; i < v.size; i++)
	{
		Arrclear[i] = v.data[i];
	}
	delete v.data;
	v.data = Arrclear;
}

bool empty(Vector & v)
{
	return v.data == nullptr;
}

int * data(const Vector & v)
{
	return v.data;
}
