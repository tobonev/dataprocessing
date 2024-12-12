# Data Processing
Extra Credit Assignment for Enterprise Software Engineering

In this assignment, I created an in-memory key-value database in C++. This was done using
a database class which contained a map of the keys (which are strings) and the values (ints).

# Walkthrough of Functions
**Database()** -> a Database constructor which simply defines the transaction to be inactive.

**begin_transaction()** -> This function checks whether a transaction is active. If it is,
an exception is thrown, as only one transaction can occur at a time. Else, it begins a transaction by setting the
transactionActive boolean to true, and assigning the data map to a tempData map.

**put(key, value)** -> This function checks whether a transaction is active. If it is, we are able to 
update the tempData map. If not, we throw an exception.

**get(key)** -> This function checks whether the key is present within the map. If it is, the value from the 
data map is returned. Otherwise, we return -1 to signify that the given key doesn't exist in the map.

**commit()** This functions first ensures that there is a transaction active, as a commit can only occur
when there is a transaction. If there isn't a transaction active, an exception is thrown. If there is a 
transaction active, we set the main data map to the tempData map which was edited throughout the transaction
using the put function, and then we clear the tempData map and end the transaction by setting the transactionActive
boolean to false.

**rollback()** This functions first ensures that there is a transaction active, as a rollback can only occur
when there is a transaction. If there isn't a transaction active, an exception is thrown. If there is a 
transaction active, we clear the tempData map as we are not using any of these changes that occurred during the transaction
and end the transaction by setting the transactionActive boolean to false.

# How to Run Code
The code should simply be able to be ran by debugging the program, and the main utilizes the example found in the assignment
document to test the functionality. There are various print statements which appear on the terminal and confirm that the output
matches the example output from the assignment document.

# How the Assignment Could be Modified
One way in which this assignment could be modified to become an official assignment in the future is to require students to include
some sort of testing within their code, whether it be implementing the assignment document example functions and ensuring the output matches, or 
writing their own test and providing comments with the expected output and making sure this matches the actual output. One way that the assignment can
be restructured is to allow for the get() function to return the most current value at the key, as one thought which was going through my mind while coding
the assignment was that I wasn't checking to see if the account balance was enough. Also, we can modify the parameters for the put function to contain a
senderKey, receiverKey, and the value being sent/received. Within the put() function, we would do a get() on the senderKey to ensure that the value is greater 
than the value being sent, and then we would update the value at senderKey by subtracting the value sent. For the receiverKey, we would first check whether the
key already exists in the map. If it doesn't, then we can simply set the value equal to the key in the map. If it does exist, we have to add the value to the existing value for the key.


