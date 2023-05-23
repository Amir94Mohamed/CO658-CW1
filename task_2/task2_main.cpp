#include <iostream>
#include"fstream"
#include"node_link.cpp"
using namespace std;
int main()
{
		// Task2 Started
		cout << "\t\t\t\t...........Task2 Started ..........." <<endl<<endl;
		
	string file;
	cout<<"Please enter file name ( with extension such as 'foo.txt'):\n> ";
    cin>>file;
	char x;					
	string flfile="";
	ifstream ifile;								
	int count=0;
	
	// Open the file for reading
	ifile.open(file);
	
	// Check if the file was opened successfully
	if(ifile) 
	{
	   	cout<<"\t*File loaded successfully*"<<endl;
	    
	    // Read characters from the file until the end of the file is reached
	    while (!ifile.eof() )
		{
			// Read a character from the file
			ifile.get(x);
			
			// Ignore newline characters
			if(x!='\n')
			{
				flfile=flfile+x;
			}
			
			// Increment the count of characters
	   		count=count+1;
		}
	}
	else {
	      cout<<"\t*File loading failed*";
	      return 0;
	}
	
	// Set the last character of the string to null character
	flfile[count-1]='\0';
	
	// Close the file
    ifile.close();
	
	// Create an instance of the Linked_List_Tree class
	Linked_List_Tree obj;
	
	// Insert characters from the file into the linked list tree
	for (int i=0; flfile[i] !='\0';i++)
	{
		if(flfile[i] && flfile[i] !='\n' && flfile[i] !='\0')
		{
			obj.insert(flfile[i]);
		}
	}
	
	// Sort the linked list tree based on character frequencies
	obj.sort();
	
    string str;
    int all_frequency=obj.overall_frequenncy();
    
    // Generate the Huffman code
    obj.Huffman();
    
    cout<<"> The Optimal Huffman Code is:\n";
    
    // Print the Huffman codes
    obj.encoding(obj.head , str);
    
    // Traverse the tree in-order to calculate the compression ratio
    obj.inorder(obj.head);
    
    cout<<"> The Compression Ratio is: \n> ";
    cout<<com/all_frequency<<endl;
    cout<<"> Total Number of nodes In Queue: \n> ";
    cout<<cnt<<endl;
    
    // Task2 Optimal Huffman code generated Successfully
    cout << "\t\t\t\t\t....................Task2 Optimal Huffman code generated Successfully...................." << endl<<endl;
    
    return 0;
}

