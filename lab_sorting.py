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

def quick_sort_inplace( sequence ):
	# COMPLETE ME - Red task

	return sequence

def merge_sort( sequence ):
	# COMPLETE ME - Red task

	return sequence










if __name__ == '__main__':
	import random, copy

	sortingAlgorithms = {'bubblesort': bubble_sort,
						'selection sort': selection_sort,
						'quicksort': quick_sort,
						'quick inplace': quick_sort_inplace,
						'merge sort': merge_sort}
	worked = set(sortingAlgorithms.keys())

	# ==============================================
	#	This is the small collection of numbers test
	# ============================================== 
	# generate 10 random numbers between -100 and 100 so we can see that it's working
	smallNumbers = [ random.randint(-100,100) for i in range(10) ]
	
	# print out the small numbers
	print( 'SMALL SEQUENCE TEST' )
	print( 'starting numbers:', smallNumbers )

	# sort the small numbers
	smallCorrect = sorted( smallNumbers )
	print( 'correctly sorted:', smallCorrect )

	for name, function in sortingAlgorithms.items():
		result = function( copy.copy(smallNumbers) )
		print( '%s:' % name.rjust(16), result )

		if result != smallCorrect:
			worked.discard( name )

	for name in sortingAlgorithms.keys():
		if name in worked:
			print( '%s worked' % name )
		else:
			print( '%s failed' % name )

	print()

	# ==============================================
	#	This is the big collection of numbers test
	# ============================================== 
	# generate 5000 random numbers so we can profile our code
	bigNumbers = [ random.random() for i in range(5000) ]

	print( 'BIG SEQUENCE TEST' )

	# sort the big numbers
	bigCorrect = sorted( bigNumbers )

	for name, function in sortingAlgorithms.items():
		result = function(bigNumbers)

		if result != bigCorrect:
			worked.discard( name )

	for name in sortingAlgorithms.keys():
		if name in worked:
			print( '%s passed' % name )
		else:
			print( '%s failed' % name )	


