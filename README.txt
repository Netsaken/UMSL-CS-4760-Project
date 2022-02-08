How to Run:
1. Navigate to project folder
2. Run "make"
3. Invoke program using "./chain -p # -s # -i #" 
    The # after -p should be the number of processes you want to run
    The # after -s should be the time to sleep between iterations, in seconds
    The # after -i should be the number of iterations you want to run

Git Repository: https://github.com/Netsaken/UMSL-CS-4760-Project

Observations:
1. Some of the processes have a Parent ID of 1. The last two processes are sometimes in
reverse order when I run 30 processes.

2.
    25303 -> 25304 -> 25305 -> 25306

3. (Adopted) / (# of Processes): 
    1/10, 5/30, 8/50, 25/75, 9/75 12/100, 15/100
    75 / 440 = 17.05% of Processes adopted by Init

4. I can't chain more than 28 processes if I use Sleep(10).
    3/28, 4/28, 7/27, 5/28, 6/28, 2/28, 5/28, 2/28, 5/28
    39 / 251 = 15.54% of Processes adopted by Init

5. Every time it prints out the processes, it's printing them out in a slightly
different order each time. Only the last iteration prints out PPIDs of '1'.