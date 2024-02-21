# Self-Evaluation

## Name(s): Nicolas Gioanni & Sandesh Rai

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes - The program does compile and run to completion.

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0 - All public functions have been implemented.

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0 - No compilation warnings.

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0 - No clang-tidy warnings.

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0 - No clang-format warnings.

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0 - No memory leaks.

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0 - Yes, follows assignments directions with the last test using data4commands.txt, data4movies.txt and data4customers.txt files.

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0 - 100%, all code is in .h and .cpp files.

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: The function where the information can be found is runTransactions() in the business.cpp file.

invalid movie type: The function where the information can be found is runTransactions() in the business.cpp file.

invalid customer ID: The function where the information can be found is runTransactions() in the business.cpp file.
 
invalid movie: The function where the information can be found is runTransactions() in the business.cpp file.

factory classes: The information about factory classes can be found in the createInventory() function in the business.cpp file.

hashtable: hashtable.cpp - This hashtable is used for storing all the customers in a customer array object, using the implementation of the hashtable.
The hash value of the customers is represented by their 4-digit id and the index is calculated according to the hash value.

container used for comedy movies: The binary search tree in the Inventory class or inventory.cpp is used as a container for storing movies, including comedy movies.

function for sorting comedy movies: The overloading operators <, >, !=, == in Comedy.cpp.

function where comedy movies are sorted: There is no specific sort function however, insert() & helperInsert() in inventory.cpp is used to insert AND sort all movies, including comedy movies. 

functions called when retrieving a comedy movie based on title and year: The function where the information can be found is retrieve() in the inventory.cpp file.

functions called for retrieving and printing customer history: The functions called for retrieving and printing customer history are showHistory() in the customer.cpp file and process() in the history.cpp file.

container used for customer history: The container used for customer history is the cusHistory vector in the customer.cpp file.

functions called when borrowing a movie: The functions called when borrowing a movie are process() in the borrow.cpp file and reduceStock() in the movie.cpp file.

explain borrowing a movie that does not exist: In the Borrow class defined in the borrow.cpp file, the process function handles the borrowing of a movie. If the movie passed as a parameter is nullptr, it means the movie does not exist. If the movie does not exist, the function returns false to indicate that the borrowing process failed. The calling code can then handle this failure appropriately. The message "Invalid Movie Request: <movie title> not found" may be displayed in the calling code to inform the user about the non-existent movie. This logic is specific to the Borrow class and is used to prevent borrowing movies that are not present in the inventory. The function is called when processing a borrowing transaction for a customer.

explain borrowing a movie that has 0 stock: In the Borrow class defined in the borrow.cpp file, the process function also handles the borrowing of a movie. If the movie's stock is less than or equal to 0, it means the movie is not available for borrowing. In this case, the function returns false to indicate that the borrowing process failed. The calling code can handle this failure and display an appropriate message to the user, such as "Movie <movie title> is not in stock." This logic is again specific to the Borrow class and ensures that movies with no available stock cannot be borrowed by customers.

explain returning a movie that customer has not checked out: In this case, there is a error as you cannot return a borrowed movie. Therefore, print to the console to inform the user that an error has occurred, and they are unable to return the movie.

any static_cast or dynamic_cast used: Yes, there are static_cast and dynamic_cast used in the provided .cpp files. They are used for casting between different types of Movie objects in the comparison operators. For example, in the operator<, operator>, operator==, and operator!= functions of the Comedy and Drama classes, static_cast is used to cast the Movie object to a specific subclass (Comedy or Drama) to access their specific attributes.


Q: Total points: 25