#include <iostream>
#include <cstring>
#include<fstream>
#include <stack> 
using namespace std;
int cnt=0;
static float com;
class Node
{
    public:
        int data;
        char charachter;
        string node_name;
        string code="";
        Node* next=NULL;
        Node* parent=NULL;
        Node* right=NULL;
        Node* left=NULL;
        
            	// Default constructor

    	Node()
    	{
    		data=0;
    		charachter ='\0';
    		code="";
            Node* next=NULL;
            Node* parent=NULL;
            Node* right=NULL;
            Node* left=NULL;
    	}		
    	    	// Parameterized constructor

    	Node(char val)
    	{
    		data=1;
    		node_name="";
    		code="";
    		charachter =val;
            Node* next=NULL;
            Node* parent=NULL;
            Node* right=NULL;
            Node* left=NULL;
    	}
        
};
class Linked_List_Tree
{
    public:
        Node* head=NULL;
            	// Insert a character into the linked list tree

    	void insert(char val)
    	{
    		Node *temp = new Node(val);
    		if (head==NULL)
    		{
    			head = temp;
    			cnt+=1;
    		}	
    		else
    		{
    			int boolean=0;
    			Node*p=head;
    			while(p->next!=NULL)
    			{
    				if(temp->charachter==p->charachter)
    				{
    					p->data+=1;
    					boolean=1;
    					break;
    				}
    				p=p->next;
    			}
    			if (boolean==0)
    			{
    				if(temp->charachter==p->charachter)
    				{
    					p->data+=1;
    					boolean=1;		
    				}
    				
    				if (boolean==0)
    				{
    					p->next = temp;
    					cnt+=1;
    				}
    				
    			}
    		}
    				
    	}
    	    	// Sort the linked list tree based on character frequencies

	 void sort()
        {
    		char tmp_data;
    		int tmp_count;
            string  g;    		
    			for (int i=0;i<cnt;i++)
    			{
    				Node*p=head;
    				while(p->next!=NULL)
    				{
    					if(p->data > p->next->data)
    					{
    						tmp_data=p->charachter;
    						tmp_count=p->data;
                            g=p->node_name;
    						p->charachter=p->next->charachter;
    						p->data=p->next->data;
    						p->node_name=p->next->node_name;
    						p->next->charachter=tmp_data;
    						p->next->data=tmp_count;
    						p->next->node_name=g;
    					}
    					p=p->next;
    				}
    			}
    	}
            	// Insert a node into the linked list tree
        void normal_insert(Node*a)
        {
            Node* temp=new Node;
            temp->data=a->data;
            temp->charachter=a->charachter;
            temp->code=a->code;
            temp->node_name=a->node_name;
            temp->next=a->next;
            temp->parent=a->parent;
            temp->right=a->right;
            temp->left=a->left;
            if(head==NULL)
            {
                head=temp;
            }
            
            else
            {
                Node*p=head;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p->next=temp;
            }
            cnt+=1;
        }
                // Print the linked list tree
        void print_List()
        {
            Node*p=head;
            while(p)
                {
                    cout<<"Charachter: "<<p->charachter;
                    if(p->node_name.length()>0)
                        cout<<p->node_name;
                    cout<<"  Frequency: "<<p->data<<endl;
                    p=p->next;
                }
        }
                // Delete a node from the linked list tree
        void delete_node(Node* a)
        {
            cnt-=1;
            Node* temp = head;
            Node* prev = NULL;
             
            if (temp != NULL && temp->charachter == a->charachter)
            {
                head = temp->next; // Changed head
                delete temp;            // free old head
                return;
            }
            else
            {
            while (temp != NULL && temp->charachter != a->charachter)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout<<endl<<"NO NODE EXISTS"<<endl;
                cnt+=1;
                return;
            }
            prev->next = temp->next;
            delete temp;
            }            
        }
        
                // Delete two nodes and create a new node in the linked list tree
        void delete_nm_tree(Node* a,Node* b)
        {
            if(a==NULL)
            {
                return;
            }            
            if(b==NULL)
            {
                return;
            }            

            static int i=1;
            
            Node* t=new Node;
            
            
            Node* temp=new Node;
            temp->data=a->data;
            temp->code=a->code;
            temp->charachter=a->charachter;
            temp->node_name=a->node_name;
            temp->next=NULL;
            temp->parent=t->parent;
            temp->right=a->right;
            temp->left=a->left;
            
            
            Node* temp1=new Node;
            temp1->data=b->data;
            temp1->code=b->code;
            temp1->charachter=b->charachter;
            temp1->node_name=a->node_name;
            temp1->next=NULL;
            temp1->parent=t->parent;
            temp1->right=b->right;
            temp1->left=b->left;
            
            int dsa=0;
            dsa=a->data+b->data;
            t->data=dsa;
            t->code=a->code+b->code;
            t->charachter='\n';
            t->node_name=to_string(i);
            i+=1;
            t->next=NULL;
            t->parent=NULL;
            if(a->data>b->data)
            {
                t->right=temp;
                t->left=temp1;
            }
            else if(a->data<b->data)
            {
                t->right=temp1;
                t->left=temp;
            }
            else if(a->data==b->data)
            {
                    t->right=temp;
                    t->left=temp1;

            }
            
            delete_node(a);
            delete_node(b);
            normal_insert(t);
        	sort();

            return;
        }
                // Generate the Huffman tree

        void Huffman()
        {
            if(head->next==NULL)
                return;
            delete_nm_tree(head,head->next);
            // print_List(); 
            // cout<<endl<<endl;
            Huffman();
        }
                // Perform in-order traversal of the tree and calculate compression ratio

        void inorder(Node *head)
        {
            if (head == NULL)
                return;
            inorder(head->left);
            
                        // Calculate compression ratio
            if(head->charachter!='\n')
            {
                com+=head->data * head->code.length();
            }   
            inorder(head->right);
        }
        
                // Perform encoding of the tree nodes

        void encoding(Node*root , string codes)
        {
           if(root==NULL)
           {
               return;
           }
        	if ((root->charachter!='\n' && root->charachter!='\0')   || root->charachter==' ') 
        	{
        	    cout<<"> "<< root->charachter <<" ";
        		root->code=codes;
        		cout<<codes;
        		cout<<endl;
        	}
        	if (root->left)
        	{
        		encoding(root->left,codes+ "0");
        	}
        	if (root->right)
        	{
                codes += "1";
        		encoding(root->right,codes);
        	}
        }
                // Calculate the overall frequency of all nodes in the tree
        int overall_frequenncy()
        {
            Node*hea=head;
        	int all_frequency=0;
        	while(hea!=NULL)
        	{
        	    all_frequency+=hea->data;
        	    hea=hea->next;
        	}
            return all_frequency;            
        }
    
};




