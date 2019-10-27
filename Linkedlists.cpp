
#include <iostream>


using std::cin;
using std::cout;
using std::endl;


class Link
{
public:	
	int data;
	Link* next;
};
std::ostream& operator << (std::ostream &out, Link* data )
{
	out<< "[ ";
	while ( data->next != 0)
	{
		out << data->data<< " ";
		data=data->next;
	}
	out << data->data<<" ]";
	return out;
}
class Linkedlists
{
public:
	Link* current;
	Linkedlists()
	{
		current= new Link();	
	};
	void queue(int data)
	{
		if (current->data== 0)
		{
			current->data=data;
		}
		else
		{
			Link* temp = new Link();
			temp->data = data;
			Link* temp2=current;
			while(temp2->next != 0)
				{
				temp2=temp2->next;
				}
			temp2->next = temp;
		}
	};
	void stack(int data)
	{
		if (current->data ==0)
		{
			current->data=data;
		}
		else
		{
			Link* temp = new Link();
			temp->data = data;
			temp->next=current;
			current=temp;		}
	};
	int peek()
	{
		return current->data;
	};
	int pop()
	{
		int popped;
		popped = current->data;
		current=current->next;
		return popped;
	};
	Link* add(Link* other)
	{
		Link* rlink=current;
		if( other != 0 && rlink!=0)
		{
			while( other->next != 0 && rlink->next !=0)
			{	
			rlink->data+= other->data;
			rlink=rlink->next;
			other=other->next;
			}
			rlink->data+= other->data;
		};
		rlink=current;
		while(rlink !=0)
		{
			if (rlink->data>9)
			{
				if (rlink->next==0)
				{
					Link* temp=new Link();
					temp->data=0;
					rlink->next=temp;
				}
				rlink->next->data+=1;
				rlink->data=rlink->data%10;
			}
			rlink=rlink->next;
		}
		return current;
	};
	Link* reverse()
	{
			Link* rlink=current;
			Linkedlists returnlink;
			while(rlink !=0)
			{
			returnlink.stack(rlink->data);
			rlink=rlink->next;	
			}
			return returnlink.current;
	}
};
	



int main(){

int mayday;
Linkedlists Zelda;
Zelda.queue(4);
Zelda.queue(4);
Zelda.stack(4);
Linkedlists Lonk;
Lonk.queue(5);
Lonk.queue(6);
Lonk.queue(5);
Lonk.stack(2);
Lonk.stack(2);
cout<<Lonk.current<<endl;
cout<<Lonk.reverse()<<endl;
return 1;
};


