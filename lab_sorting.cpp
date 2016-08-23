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
    struct Test
    {
        string name;
        vector<int>(*function)(vector<int>);
        bool success;
    };

    vector< Test > sortingAlgorithms {
            {"bubblesort", &bubble_sort, false },
            {"selection sort", &selection_sort, false },
            {"quicksort", &quick_sort, false },
            {"quick inplace", &quick_sort_inplace, false },
            {"merge sort", &merge_sort, false }};

    /* ==============================================
         This is the small collection of numbers test
       ============================================== */
    // generate 10 random numbers between -100 and 100 so we can see that it's working
    vector<int> smallNumbers(10), smallCorrect;
    generate( smallNumbers.begin(), smallNumbers.end(), []{ return rand()%200-100; } );
    
    // print out the small numbers
    cout << "SMALL SEQUENCE TEST" << endl;
    cout << setw(16) << "starting numbers: " << vec_to_str( smallNumbers ) << endl;

    // sort the small numbers
    smallCorrect = smallNumbers;
    sort( smallCorrect.begin(), smallCorrect.end() );
    cout << setw(16) << "correctly sorted: " << vec_to_str( smallCorrect ) << endl;    

    for( Test &t : sortingAlgorithms )
    {
        // run our test numbers through the sorting algorithm and save the results
        vector<int>result = t.function( smallNumbers );

        // print the results
        cout << setw(16) << t.name << ": " << vec_to_str( result ) << endl;

        // record if the test was a successs
        t.success = result == smallCorrect;
    }

    // print which tests passed and which failed
    for( Test &t : sortingAlgorithms )
    {
        cout << t.name << ( t.success ? " worked" : " failed" ) << endl;
    }

    cout << endl;

    /* ==============================================
        This is the big collection of numbers test
       ============================================== */
    // generate 10000 random numbers so we can profile our code
    vector<int> bigNumbers(10000), bigCorrect;
    generate( bigNumbers.begin(), bigNumbers.end(), rand );

    cout << "BIG SEQUENCE TEST" << endl;

    // sort the big numbers
    bigCorrect = bigNumbers;
    sort( bigCorrect.begin(), bigCorrect.end() );

    for( Test &t : sortingAlgorithms )
    {
        if( !t.success )
            continue; 

        vector<int> result = t.function( bigNumbers );

        t.success = result == bigCorrect;
    }

    for( Test &t : sortingAlgorithms )
    {
        cout << t.name << ( t.success ? " worked" : " failed" ) << endl;
    }

    return count_if( sortingAlgorithms.begin(), sortingAlgorithms.end(), [](Test &t){ return !t.success; } );
}
