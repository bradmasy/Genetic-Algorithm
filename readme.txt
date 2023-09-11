Names:     Ravinder Shokar    Brad Masciotra
Student#:  A01184672          A01247718

100% Complete

Notes:
- notes on the dynamic memory use in function "reproduction":

in our code we utilize the copy constructor and "new" keyword to create our cities to add to our child tour. Originally
when we set out to do this assignment we had tried using re-assignment of pointers, yet we found that if the memory
addresses stored were the same of those in the master list we would generate tours of either all the same routes, or
glitches in tours with irregular amounts of cities. One solution that was favourable and found perfect results was
passing new pointers of cities to the tours through copy constructors. This allowed the new tours to have a fresh set
of pointers that would not be mistaken or duplicated in any way. All the dynamic memory created is treated properly and
is taken care of elsewhere in the program(we do not delete in reproduction as the data is needed in the tour etc.).
I hope this paragraph clarifies our approach to the usage, and we did as a group to overcome a difficult circumstance.


-descriptions

all code is commented thoroughly to help in understanding and if you would like to play with the values present as
statics in the singleton facade class.