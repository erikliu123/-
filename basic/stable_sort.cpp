#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool compare_as_ints(double i, double j)
{
    return (int(i) < int(j));
}

// print container content:
// template <class T> void PrintCont ( T& cont )
// {
//   for (T::iterator it=cont.begin(); it!=cont.end(); ++it)
//     cout << " " << *it;
//   cout << endl;
// }

int main()
{
    double mydoubles[] = {3.14, 1.41, 2.72, 1.42, 4.67, 1.73, 1.32, 1.62, 2.58};

    vector<double> myvector, myvector1;
    vector<double>::iterator it;

    myvector.assign(mydoubles, mydoubles + 9);
    myvector1.assign(mydoubles, mydoubles + 9);

    cout << "using default comparison:";
    stable_sort(myvector.begin(), myvector.end());
    for (it = myvector.begin(); it != myvector.end(); ++it)
        cout << " " << *it;

    myvector.assign(mydoubles, mydoubles + 9);

    cout << "\nusing 'compare_as_ints' :";
    stable_sort(myvector.begin(), myvector.end(), compare_as_ints);
    for (it = myvector.begin(); it != myvector.end(); ++it)
        cout << " " << *it;

    cout << endl;

    cout << "\nunstable sort: ";
    sort(myvector1.begin(), myvector1.end(), compare_as_ints);
    for (it = myvector1.begin(); it != myvector1.end(); ++it)
        cout << " " << *it;

    cout << endl;
    return 0;
}
