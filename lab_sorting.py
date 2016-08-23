#!/usr/bin/python3

def bubble_sort( sequence ):
    # COMPLETE ME - Green task

    return sequence

def selection_sort( sequence ):
    # COMPLETE ME - Yellow task

    return sequence

def quick_sort( sequence ):
    # COMPLETE ME - Yellow task

    return sequence

def quick_sort_inplace( sequence, start=None, end=None ):
    # COMPLETE ME - Red task

    return sequence

def merge_sort( sequence ):
    # COMPLETE ME - Red task

    return sequence










if __name__ == '__main__':
    import random, copy, sys

    class Test(object):
        def __init__(self, n, f ):
            self.name = n
            self.function = f
            self.success = False

    sortingAlgorithms = [ Test('bubblesort', bubble_sort),
                          Test('selection sort', selection_sort),
                          Test('quicksort', quick_sort),
                          Test('quick inplace', quick_sort_inplace),
                          Test('merge sort', merge_sort)]
    
    # ==============================================
    #    This is the small collection of numbers test
    # ============================================== 
    # generate 10 random numbers between -100 and 100 so we can see that it's working
    smallNumbers = [ random.randint(-100,100) for i in range(10) ]
    
    # print out the small numbers
    print( 'SMALL SEQUENCE TEST' )
    print( 'starting numbers:', smallNumbers )

    # sort the small numbers
    smallCorrect = sorted( smallNumbers )
    print( 'correctly sorted:', smallCorrect )

    for test in sortingAlgorithms:
        result = test.function( copy.copy(smallNumbers) )
        print( '%s:' % test.name.rjust(16), result )

        # record if the test was a success
        test.success = result == smallCorrect

    for test in sortingAlgorithms:
        print( test.name, "worked" if test.success else "failed" )
        
    print()

    # ==============================================
    #    This is the big collection of numbers test
    # ============================================== 
    # generate 5000 random numbers so we can profile our code
    bigNumbers = [ random.random() for i in range(5000) ]

    print( 'BIG SEQUENCE TEST' )

    # sort the big numbers
    bigCorrect = sorted( bigNumbers )

    for test in sortingAlgorithms:
        if not test.success:
            continue

        result = test.function(bigNumbers)

        test.sucess = result == bigCorrect

    for test in sortingAlgorithms:
        print( test.name, "worked" if test.success else "failed" )

    sys.exit( len([ test for test in sortingAlgorithms if test.success ]) )
