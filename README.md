# emergencyRoomTriageSim
dominick hera

to run
=
./bin/run


to compile
=
type 'make' to run the makeFile


description
=

- the program is a simulation of an emergency room where the doctors and nurses are required to triage the people in the waiting room and determine who is most important and who should be treated first, this program utilises a minimum heap to achieve these results while also making use of ncurses for a userfriendly menu that was implemented from my previous project considering how well recieved it was by the person who graded my project.


known limitations
=
- heapify function is still pretty wonky and while it does swap around the priorities to be in order for the most part, it seems to skip several numbers anyway.
- meant to implement a prioritize of the children of each parent node to swap them so they are in more order but i ran out of time in part due to work and procrastination so i had to settle for what i currently have.


testing
=
- attempted making a function to return the full name for the symptom code but it kept bugging out so i just resorted to doing a messier if else if in the printing function checking the symptom code stright up
- reheapify algorithm works for the most part but is still very wonky, it'll swap around for the most part but leave every couple of entries. 
- ran provided test data file through program and the heapify funciton is definitely broekn so i need to figure out a way to hotfix this intime for submission
- currently using a switch case and a while loop to simulate a menu system while i get all the other functions working before i proceed to creating a proper and full menu stystem to satisfy extra requirements.
- the heap function is taking up alot more time than anticipated so im moving forward and coming back to that later and proceeding to work on the menu system instead and coming back to the heapify before i submit the entire project
- attempting to repurpose the menu system i had incorporated for the previous assignment because it was really nice and the person grading my project liked it. have to go one step further though to incorporate the cycling through of the patients but it shouldnt be too hard
- fixed parsing so that empty spaces wouldn't cause the program to segfault anymore, now we're working, if the textfile ends with an empty line or has empty lines in the middle, it shouldn't provide any issues anymore.
- got menu entirely working now with the cycling and everything, but im now just realising that I need to figure out how long all these people were waiting for, well that's gonna be unfortunate, im gonna go fix that now
- for the multiple people haivng the same priority, im gonna add another variable to each node of the number in which of that priority number that they come so i can use that later for figuring out how long it'll take for them to be processed
- for the sake of making this easy for me, im going to assume that each person takes 30 minutes to be processed before moving on to the next person.
- cant figure out how to prioritize in time so i'm going to just use the order that the heap is currently organised into and put this issue into my known limitations
- attempted to create an additional node value about how many times there are each priority but i ended up not using it and just using the i time instead multiplied by 30
- my program saves the test files in proper manner, so i need to reset the test files everytime i run them through the project


test files
=
- the test files i provided with the application are sufficient as to what may potentially be entered into the program so that it is able to handle any issues that it faces
- the first test file throws the program a softball in which was originally provided on the assignment specs page with an additional entry that the program should be able to handle with minimal effort.
- the second test file gives the program an actual data file also provided by the professor with many entries which makes use of the starvation method and makes sure that all functions are properly working
- the third test file is similar to the second test file as it provides many lines of data for the program to assess as well as blank lines to see it it'll break the parsing and the program as a whole.
- the fourth test file attempts to test the priority and symptom code entry to make sure that they are properly being interpreted by the program so that it doesnt cause 


priority queue
=
- the priority queue that is used for this project takes the minimum heap function that was written for lab 3 in the same class and attempts to repurpose it into the priority queue that is required by properly reheaping until the smalled value are at the top of the tree and the right and left children of each parent are less than eachother, but then I attempted to use another priority function to reorder any children within the tree to make sure that they are in numerical order despite the fact that they are correctly inserted and swapped around into the tree. This makes sure that the clients are processed according to the priority number that they are given in the data file. 
- I'm not 100% sure if i should be using the heap that i created for the last lab as it doesnt seem to be the most efficient data structure for this assignment seeing as a heap can be satisfied provided that the parent is bigger than both of the children but I'm attempting to make it work as i mentioned in the previous paragraph although im just confused about the choices im making.
