# Filler

It's Tuesday 12:03 and you're barely starting the project.

Let's fucking do this. 

Learn a valuable lesson on why you shouldn't code when you're absolutely exhausted in the early morning. 

Done at 3:14! But I have a small error causing me to segfault, time to find out where that is... 

I guess it's time for a redo due to many core misunderstandings

1. All the input is read from STDIN
2. The exec w/ the player's number is only sent once
3. You have to constantly read from STDIN until it's time to "stop", ie. when no more pieces can be placed? But how
would you stop after every single turn and wait for more input? The tricky part is handling GNL, apparently. 
4. Create a function to free everything that needs to be freed. 
5. Update the map, revise the token everytime, and do whatever needs to be done.

This is much more tricky than you initially expected-- let's study other people's code and see how it's done. 
