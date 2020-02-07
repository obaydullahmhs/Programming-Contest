#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
        mp::cpp_int n;
        cin>>n;
        mp::cpp_int ans=1;
        for(int i=2;i<=n;i++) ans*=i;
        cout<<ans<<'\n';
    }


}
