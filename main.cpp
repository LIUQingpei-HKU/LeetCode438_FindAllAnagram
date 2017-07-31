#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;

        int pfreq[256] = {0};
        for(int i=0;i<p.size();i++)
            pfreq[p[i]]++;

        int sfreq[256] = {0};
        int cnt = 0;

        int l=0,r=-1; //slide window [l...r]
        while(l<s.size()){
            if(r+1<s.size()&&sfreq[s[r+1]]<pfreq[s[r+1]]){
                r++;
                sfreq[s[r]]++;
                cnt++;
            }else{
                sfreq[s[l]]--;
                l++;
                cnt--;
            }

            if(cnt==p.size())
                res.push_back(l);
        }
        return res;
    }
};

void printVector( const vector<int> &vec){

    for( int i = 0 ; i < vec.size() ; i ++ )
        cout<<vec[i]<<" ";
    cout<<endl;

    return;
}

class Solution2 {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;

        int pfreq[256] = {0};
        for( int i = 0 ; i < p.size() ; i ++ )
            pfreq[p[i]] ++;

        int sfreq[256] = {0};
        int cnt = 0;

        int l = 0, r= -1;
        while( l < s.size() ){
            if( r + 1 < s.size() && sfreq[s[r+1]] + 1 <= pfreq[s[r+1]]){
                sfreq[s[++r]] ++;
                cnt ++;
            }
            else{
                sfreq[s[l++]] --;
                cnt --;
            }

            if( cnt == p.size() )
                res.push_back( l );
        }

        return res;
    }
};



int main() {
    vector<int> res1 = Solution().findAnagrams("cbaebabacd", "abc");
    printVector( res1 );
    vector<int> res2 = Solution().findAnagrams("abab", "ab");
    printVector( res2 );
    return 0;
}