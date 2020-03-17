#include<bits/stdc++.h>
using namespace std;
int main()
{
    int z,m,n,k;
    string s;
    cin>>z;
    for(int i=1; i<=z; i++)
    {
        cin>>m>>n;
        deque<int>mydeque;
        cout<<"Case "<<i<<":"<<endl;
        for(int j=1; j<=n; j++)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>k;
                if(mydeque.size()==m)
                {
                    cout<<"The queue is full"<<endl;
                }
                else
                {
                    cout<<"Pushed in left: "<<k<<endl;
                    mydeque.push_front(k);
                }
            }
            else if(s=="pushRight")
            {
                cin>>k;
                if(mydeque.size()==m)
                {
                    cout<<"The queue is full"<<endl;
                }
                else
                {
                    cout<<"Pushed in right: "<<k<<endl;

                    mydeque.push_back(k);
                }
            }
            else if(s=="popLeft")
            {
                if(mydeque.size()>0)
                {
                    cout<<"Popped from left: "<<mydeque.front()<<endl;
                    mydeque.pop_front();
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }
            }
            else if(s=="popRight")
            {
                if(mydeque.size()>0)
                {
                    cout<<"Popped from right: "<<mydeque.back()<<endl;
                    mydeque.pop_back();
                }
                else
                {
                    cout<<"The queue is empty"<<endl;
                }
            }

        }
    }


    return 0;
}
