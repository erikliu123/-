#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/**
 * Welcome to vivo !
 */

typedef struct _node
{
    int num;
    struct _node * next;
}node;

void solution(int N, int M)
{
	// TODO Write your code here 
    vector<int> ans;
    vector<int> people;
    people.push_back(0);
    for(int i=0; i<N; i++)
    {
        people.push_back(i+1);

    }
    int start = M;
    int next = 0;
    while (people.size() > 1)
    {
        int index;
        if(M < people.size())
             index = (M + next)%people.size();
        else 
            index = (M + next - 1)%people.size();
      
        // if(index == people.size()-1)
        //     next = index-1; //- 1);
        if(index < 1){
            next = index;
        }
        else
        {
            next = index-1;
        }
        if()
         ans.push_back(people[index]);
        people.erase(people.begin() + index);
       

    }
    for(int i=0; i<N; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    


}

int main()
{
	int N;
	int M;
	
	string str("");
	getline(cin, str);
	
	char *p;
	const char* strs = str.c_str();
	
	p = strtok((char *)strs, " ");
	N = atoi(p);

	p = strtok(NULL, " ");
	M = atoi(p);
	
	solution(N, M);
	
	return 0;
}