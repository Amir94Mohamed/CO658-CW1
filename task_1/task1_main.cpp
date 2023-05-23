#include<iostream>
#include<string>
#include<fstream>
#include"bst.cpp"

using namespace std;

int main()
{
	// Task 1: Loading and Preprocessing File
	cout << "\t\t\t\t...........Task1 Started ..........." <<endl<<endl;
	
	string file;
	cout<<"Please enter file name ( with extension such as 'foo.txt'):\n> ";
	cin>>file;
	
	char x;					
	
	string flfile="";
	        	
	ifstream ifile;								
	int count=0;
	
	// Opening the file
	ifile.open(file);
	
	// Checking if the file is opened successfully
	if(ifile) 
	{
		cout<<"\t*File loaded successfully*";  
		// Reading file character by character
		while (!ifile.eof())
		{
			ifile.get(x);
			if(x!='\n')
			{
				flfile=flfile+x;
			}
			count=count+1;
		}
	}
	else {
		cout<<"\t*File loading failed*";
		return 0;
	}
	
	// Adding null terminator at the end of the file content
	flfile[count-1]='\0';
	ifile.close();
	cout<<endl;

	BST obj;   //BST object
	
	// Task 2: Inserting Characters into BST
	if(flfile[0]>flfile[1])
	{
		big=true;
	}
	
	for (int i=0; flfile[i] !='\0' ;i++)
	{
		if(flfile[i] !='\0')
		{
			obj.insert(flfile[i]);
		}
	}

	// Task 3: Displaying In-order Traversal of BST
	obj.displayInOrder();
	cout<<endl;

	cout << "\t\t\t\t\t....................Task1 Huffman Tree Inserted Successfully...................." << endl<<endl;
	
	return 0;
}

