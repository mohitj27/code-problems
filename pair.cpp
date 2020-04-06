#include <bits/stdc++.h>
using namespace std;

// A job has a start time, finish time and profit.
struct Activitiy
{
    int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activitiy s1, Activitiy s2)
{
    return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
int printMaxActivities(Activitiy arr[], int n)
{   int ans=1;
    // Sort jobs according to finish time
    sort(arr, arr+n, activityCompare);

    // The first activity always gets selected
    int i = 0;

    // Consider rest of the activities
    for (int j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (arr[j].start >= arr[i].finish)
      {

          i = j;
          ans++;
      }
    }
    return ans;
}

// Driver program
int main()
{    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      Activitiy *arr = new Activitiy[n];

    for(int i = 0; i < n; i++) {
        cin>>arr[i].start>>arr[i].finish;
    }
 int result = printMaxActivities(arr, n);
      cout<<result<<endl;
    }
    return 0;
}
