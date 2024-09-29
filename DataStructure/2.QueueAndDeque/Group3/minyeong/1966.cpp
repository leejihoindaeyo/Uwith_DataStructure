#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void)
{
    int testn;
    int n,m;
    int importance;
    int count;

    cin >> testn;

    for (int i=0; i < testn; i++)
    {   
        count =0;
        cin >> n >> m;
        queue<pair<int,int>>q;
        vector<int>import(n);

        for (int j=0; j < n; j++)
        {
            cin >> importance;
            q.push({importance,j});
            import[j] = importance;
        }
        while(!q.empty())
        {
            auto current = q.front();
            q.pop();

            bool high_importance = false;

             queue<pair<int, int>> temp_queue;
            while (!q.empty()) 
            {
                if (q.front().first > current.first) 
                {
                    high_importance = true; 
                }
                temp_queue.push(q.front()); 
                q.pop(); 
            }

            
            while (!temp_queue.empty()) 
            {
                q.push(temp_queue.front());
                temp_queue.pop();
            }

            if (high_importance)
                q.push(current); 
            else 
            {
                count++; 
                if (current.second == m)
                    break;
                
            }
        }
        cout << count << "\n";
    }
    return 0;
}