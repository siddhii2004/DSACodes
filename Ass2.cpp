#include<iostream>
using namespace std;
class Set
{
    int a[100], cnt, no;
    public:
    Set()
    {
        cnt=0;
    }
    void add();
    void display();
    int search(int);
    Set unionof(Set);
    Set intersection(Set);
    Set minus(Set);
    void remove();
    void subset(Set);
    void diff(Set);
};
void Set::add()
{
    cout<<"\nEnter no. of elemets to be added : ";
    cin>>no;
    for(int i=0; i<no; i++)
    {
    cout<<"\nEnter data : ";
    cin>>a[cnt++];
    }
}
void Set::display()
{
    for(int i=0; i<cnt; i++)
    {
        cout<<a[i]<<" ";
    }
}

/*Set Set::unionof(Set B)
{
    Set temp;//A temporary set object temp is declared to store the result of the union operation.
    for(int i=0; i<cnt; i++)//Copying Elements from the Current Set to Temporary Set
    {
        temp.a[i] = a[i];
        temp.cnt++;
    }
    for(int i=0; i<B.cnt; i++)
    {
        if(!temp.search(B.a[i]))
        {
            temp.a[temp.cnt++]=B.a[i];
        }
    }
    return temp;
}*/
int Set::search(int s)
{
    for(int i=0; i<cnt; i++)
    {
        if(s==a[i])
        {
            return 1;
        }
    }
    return 0;
}
Set Set::intersection(Set B)
{
    Set temp;
    for(int i=0; i<cnt; i++)
    {
        for(int j=0; j<B.cnt; j++)
        {
            if(a[i]==B.a[j])
            {
                temp.a[temp.cnt]=a[i];
                temp.cnt++;
            }
        }
    }
    return temp;
}
Set Set::minus(Set B)
{
    Set temp;
    int flag;
    for(int i=0; i<cnt; i++)
    {
        flag=B.search(a[i]);
        if(flag==0)
        {
            temp.a[temp.cnt++]=a[i];
        }
    }
    return temp;
}
void Set::remove()
{
    int dnum;
    int k=-1;
    cout<<"\nEnter no. to be deleted : ";
    cin>>dnum;
    for(int i=0; i<cnt; i++)
    {
        if(a[i]==dnum)
        {
            k=i;
            break;
        }
    }
    for(int j=k; j<cnt; j++)
    {
        a[j]=a[j+1];
    }
    cnt--;
}
void Set::subset(Set B)
{
    int i;
    for(i=0; i<B.cnt; i++)
    {
        if(!search(B.a[i]))
        {
            cout<<"\nB is not subset of A";
            break;
        }
    }
    if(i==B.cnt)
    {
        cout<<"\nB is subset of A";
    }
}
void Set::diff(Set B)
{
    Set temp;
    int i;
    
    for(i = 0; i < cnt; i++)
    {
        if(!B.search(a[i]))
        {
            temp.a[temp.cnt++] = a[i];
        }
    }
    // Copy elements from temp back to the current set
    for(i = 0; i < temp.cnt; i++)
    {
        a[cnt++] = temp.a[i];
    }
}

int main()
{
    Set obj;
    Set B;
    Set C;
    Set D;
    int choice, snum, ans;
    do{
        cout<<"MENU  1.Add in Set A  2. Add in Set B  3.Display  4.Union  5.Intersection  6.Search   7.Minus  8.Remove  9.Subset  10.Exit";
        cout<<"\nEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: obj.add();
            break;
            
            case 2: B.add();
            break;
            
            case 3: cout<<"Set A : ";
            obj.display();
            cout<<"Set B : ";
            B.display();
            break;
            
            /*case 4: cout<<"\nUnion of Both sets : ";
            C=obj.unionof(B);
            C.display();
            break;*/
            
            case 5: cout<<"\nIntersection of Sets : ";
            D=obj.intersection(B);
            D.display();
            break;
            
            case 6: cout<<"\nEnter element to be searched : ";
            cin>>snum;
            ans=(obj.search(snum)||B.search(snum));
            if(ans==1)
            {
                cout<<"\nElement Found ";
                break;
            }
            else
            {
                cout<<"\nElement not Found ";
                break;
            }
            
            case 7: cout<<"\nSet A - Set B";
            C=obj.minus(B);
            C.display();
            break;
            
            case 8:obj.remove();
            B.remove();
            break;
            
            case 9:
            obj.subset(B);
            break;
            
            case 10:
            D=obj.diff(B);
            D.display();
            break;
            
        }
    }while(choice!=11);
    return 0;
}
