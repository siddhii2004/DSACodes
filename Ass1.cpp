#include<iostream>
using namespace std;
class hashing
{
    long int mob, hash_table[10];
    public:
    hashing()
    {
        for(int i=0; i<10; i++)
        {
            hash_table[i]=-1;
        }
    }
    void linear_prob();
    void quad_prob();
    void display();
};
void hashing::linear_prob()
{
    int index;
    cout << "\nEnter Your Mobile No. : ";
    cin >> mob;
    index = mob % 10;
    if (hash_table[index] == -1) 
    {
        hash_table[index] = mob;
    }
    else
    {
        while (hash_table[index] != -1) 
        {
            cout << "Testing " << index;
            if (index == 9)
            {
                index = 0;
            }
            else
            {
                index++;
            }
        }
        hash_table[index] = mob;
    }
}
void hashing::quad_prob()
{
    int index, a;
    cout<<"\nEnter Your Mobile No. :";
    cin>>mob;
    index=mob%10;
    int j=1;
    if(hash_table[index]==-1)
    {
        hash_table[index]=mob;
    }
    else
    {
        a=index%10;
        while(j<10)
        {
            index=(a+(j*j)%10);
            if(hash_table[index]==-1)
            {
                hash_table[index]=mob;
                break;
            }
            else
            {
                j++;
            }
        }
    }
}
void hashing::display()
{
    for(int i=0; i<10; i++)
    {
        cout<<i<<" "<<hash_table[i]<<endl;
    }
}
int main()
{
    hashing obj;
    int ch, index;
    do{
        cout<<"MENU";
        cout<<" 1. Linear Probing";
        cout<<" 2. Quadratic Probing";
        cout<<" 3. Display";
        cout<<" 4. Exit";
        cout<<" Enter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: obj.linear_prob();
            //obj.display();
            break;
            
            case 2: obj.quad_prob();
            obj.display();
            break;
            
            case 3: obj.display();
            break;
            
            case 4: cout<<"EXIT";
            break;
            
        }
    }while(ch!=4);
    return 0;
}
