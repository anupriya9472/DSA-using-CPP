#include<iostream>
using namespace std;
class node
{
    public:
    int info;
    node *link;
};
node *ptr,*START;

void create_list();
void display_list();
void insert_beg(int);
void insert_end(int);
node* search_loc(int);
void insert_after(int,int);
void search_item(int);
void del_beg();
void del_end();
void del_after(int);

int main()
{
    int c,item;
    char ch;
    do
    {
    cout<<"1.Create List\n2.Display list\n3.Insert at beginning of list"<<endl;
    cout<<"4.Insert at end of list\n5.Insert after any item in list\n6.Search any item in list"<<endl;
    cout<<"7.Delete beginning item\n8.Delete end item"<<endl;
    cout<<"9.Delete node after any node"<<endl;
    cout<<"Please choose any operation:";
    cin>>c;
    switch(c)
    {
    case 1:
        create_list();
        break;
    case 2:
        display_list();
        break;
    case 3:
        cout<<"Enter item that you want to insert:-";
        cin>>item;
        insert_beg(item);
        break;
    case 4:
        cout<<"Enter item that you want to insert:-";
        cin>>item;
        insert_end(item);
        break;
    case 5:
        int after_item;
        cout<<"Enter item that you want to insert and after which item:-";
        cin>>item>>after_item;
        insert_after(item,after_item);
        break;
    case 6:
        cout<<"Enter item that you want to search:-";
        cin>>item;
        search_item(item);
        break;
    case 7:
        del_beg();
        break;
    case 8:
        del_end();
        break;
    case 9:
        cout<<"Enter item after where you want to delete:-";
        cin>>item;
        del_after(item);
        break;
    default:
        cout<<"Selected option is invalid...";
    }
    cout<<"\nDo you want to do another operation?(press y if yes):-";
    cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}
void create_list()
{
    if(START!=NULL)
    {
        cout<<"List is already exist..."<<endl;
    }
    else
    {
        int item,n;
        cout<<"Enter total nummber of nodes:-";
        cin>>n;
        ptr=new node;
        START=ptr;
        for(int i=1; i<=n; i++)
        {
            cout<<"Enter node number "<<i<<" of list item:-";
            cin>>item;
            ptr->info=item;
            if(i==n)
                ptr->link=NULL;
            else
                ptr->link=new node;
            ptr=ptr->link;
        }
    }
}
void display_list()
{
    ptr=START;
    if(ptr==NULL)
    {
        cout<<"The list is empty...";
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<"\t"<<ptr->info;
            ptr=ptr->link;
        }
    }
}
void insert_beg(int item)
{
    ptr = new node;
    ptr->info=item;
    if(START==NULL)
        ptr->link= NULL;
    else
        ptr->link= START;
    START=ptr;
    return;
}
void insert_end(int item)
{
    node *loc;
    ptr = new node;
    ptr->info=item;
    ptr->link=NULL;
    if(START==NULL)
    {
        START= ptr;
    }
    else
    {
        loc = START;
        while(loc->link != NULL)
        {
            loc = loc->link;
        }
        loc->link=ptr;
    }
    return;
}
node* search_loc(int after_item)
{
    ptr=START;
    if(ptr==NULL)
    {
        return ptr;
    }
    else
    {
        while(ptr->link!=NULL)
        {
            if(ptr->info==after_item)
            {
                return ptr;
            }
            ptr=ptr->link;
        }
    }
    return ptr;
}

void insert_after(int item, int after_item)
{
    node *loc;
    loc = search_loc(after_item);
    if(loc==NULL)
    {
        cout<<"The element is not present after which you want to insert the new item "<<endl;
    }
    else
    {
        ptr=new node;
        ptr->info=item;
        ptr->link= loc->link;
        loc->link=ptr;
    }
}

void search_item(int item)
{
    ptr=START;
    int p=0;
    if(ptr==NULL)
    {
        cout<<"The list is empty...";
    }
    else
    {
        while(ptr!=NULL)
        {
            p++;
            if(ptr->info==item)
            {
                cout<<item<<" is available at position "<<p;
                p=0;
                break;
            }
            ptr=ptr->link;
        }
        if(p!=0)
        {
            cout<<item<<" is not available in this list...";
        }
    }
}
void del_beg()
{
    if(START==NULL)
    {
        cout<<"The list is empty..."<<endl;
        return;
    }
    else
    {
        ptr = START;
        START = START ->link;
        cout<<"The first item "<<ptr->info<<" is deleted"<<endl;
        free(ptr);
        return;
    }
}
void del_end()
{
    node *loc;
    if(START==NULL)
    {
        cout<<"The list is empty..."<<endl;
        return;
    }
    else if(START->link==NULL)
    {
        ptr = START;
        START = NULL;
        cout<<"The node is deleted"<<endl;
        free(ptr);
    }
    else
    {
        loc=START;
        ptr=START->link;
        while(ptr->link!=NULL)
        {
            loc=ptr;
            ptr=ptr->link;
        }
        loc->link = NULL;
        cout<<"The last node is deleted"<<endl;
        return;
    }
}
void del_after(int after_item)
{
    node *loc;
    loc=search_loc(after_item);
    if(loc==NULL)
    {
        cout<<"The item after which you want to delete is not present in the list"<<endl;
        return;
    }
    else
    {
        ptr = loc->link;
        loc->link= ptr->link;;
        free(ptr);
        cout<<"The node is deleted"<<endl;
        return;
    }
}

