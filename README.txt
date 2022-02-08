How to Run:
1. Navigate to project folder
2. Run "make"
3. Invoke program using "./chain -p #" where '#' is the number of processes

Git Repository: https://github.com/Netsaken/UMSL-CS-4760-Project

Observations:
1. Some of the processes have a Parent ID of 1. The last two processes are sometimes in
reverse order when I run 30 processes.
2.
    25303 -> 25304 -> 25305 -> 25306
3. (Adopted) / (# of Processes): 
    1/10, 5/30, 8/50, 25/75, 9/75 12/100, 15/100
    75 / 440 = 17.05% of Processes adopted by Init