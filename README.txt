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

6. The program runs in an identical way to step 5 if I use "wait;". It will execute with
an n value of 100, but it will not print more than 28 per iteration. 
    If I instead use "wait(NULL);", only a couple of the processes in all iterations are 
printed at a time, based on my sleep time. The iterations are interleaved, but are otherwise 
very uniform; there are no orphaned processes. However, even if I run it with an n of 100, 
each iteration still only shows 28 processes. The iterations are also being printed in
reverse order.

7. The output for this program (with "wait(NULL);") is identical to the output for step 6.
I can easily tell which process generated each part of the output, and there don't seem to
be any differences no matter how many times I run the program. I noticed that setting
n to 1 prints all processes at once, but this likely worked in step 6 as well.