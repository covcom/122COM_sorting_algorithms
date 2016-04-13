#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <sstream>
#include <set>
using namespace std;

vector<int> bubble_sort( vector<int> sequence )
{
    // COMPLETE ME

    return sequence;
}

vector<int> selection_sort( vector<int> sequence )
{
    // COMPLETE ME

    return sequence;
}

vector<int> quick_sort( vector<int> sequence )
{
    // COMPLETE ME

    return sequence;
}

void _quick_sort_inplace( vector<int>& sequence, int start, int end )
{
    // COMPLETE ME
}

vector<int> quick_sort_inplace( vector<int> sequence )
{
    _quick_sort_inplace( sequence, 0, sequence.size()-1 );
    return sequence;
}

vector<int> merge_sort( vector<int> sequence )
{
    // COMPLETE ME

    return sequence;
}






template<typename T>
string vec_to_str( vector<T>& sequence )
{
    stringstream ss;
    for( T i : sequence )
        ss << i << ", ";
    
    return ss.str();
}

int main()
{
    vector< pair< string, vector<int>(*)(vector<int>) > > sortingAlgorithms { 
            make_pair("bubblesort", &bubble_sort ),
            make_pair("selection sort", &selection_sort ),
            make_pair("quicksort", &quick_sort ),
            make_pair("quick inplace", &quick_sort_inplace ),
            make_pair("merge", &merge_sort ) };

    set<string> working;
    for( auto i : sortingAlgorithms ) { working.insert( i.first ); }

    /* ==============================================
         This is the small collection of numbers test
       ============================================== */
    // generate 10 random numbers between -100 and 100 so we can see that it's working
    vector<int> smallNumbers, smallCorrect;
    smallNumbers.resize(10);
    for( int& i : smallNumbers )
    {
        i = rand() % 200 -100;
    }
    
    // print out the small numbers
    cout << "SMALL SEQUENCE TEST" << endl;
    cout << setw(16) << "starting numbers: " << vec_to_str( smallNumbers ) << endl;

    // sort the small numbers
    smallCorrect = smallNumbers;
    sort( smallCorrect.begin(), smallCorrect.end() );
    cout << setw(16) << "correctly sorted: " << vec_to_str( smallCorrect ) << endl;    

    for( auto i : sortingAlgorithms )
    {
        vector<int>result = i.second( smallNumbers );

        cout << setw(16) << i.first << ": " << vec_to_str( result ) << endl;

        /* we're going to remove the names of the ones that don't work rather than 
            add the ones that do work in case it fails the first test but passes the
            second */
        if( result != smallCorrect )
        {
            working.erase( i.first );    
        }
    }

    for( auto i : sortingAlgorithms )
    {
        if( working.find(i.first) != working.end() )
        {
            cout << i.first << " worked" << endl;
        }
        else
        {
            cout << i.first << " failed" << endl;
        }
    }

    cout << endl;

    /* ==============================================
        This is the big collection of numbers test
       ============================================== */
    // generate 5000 random numbers so we can profile our code
    vector<int> bigNumbers, bigCorrect;
    bigNumbers.resize(10000);
    for( int& i : bigNumbers )
    {
        i = rand();
    }

    cout << "BIG SEQUENCE TEST" << endl;

    // sort the big numbers
    bigCorrect = bigNumbers;
    sort( bigCorrect.begin(), bigCorrect.end() );

    for( auto i : sortingAlgorithms )
    {
        vector<int> result = i.second( bigNumbers );

        if( result != bigCorrect )
        {
            working.erase( i.first );
        }
    }

    for( auto i : sortingAlgorithms )
    {
        if( working.find(i.first) != working.end() )
        {
            cout << i.first << " worked" << endl;
        }
        else
        {
            cout << i.first << " failed" << endl;
        }
    }

    return sortingAlgorithms.size() != working.size();
}
