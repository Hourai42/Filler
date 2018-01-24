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

Then after, fork the project and merge with yours when you're ready. 

This might be pretty ugly as you're just going to Frankenstein up a 10 minute solution. 

The issue with read/GNL and stdin is that you're done reading a file, GNL will return a success then read one more time for the "finish read". But if that happens and it's stdin, it'll simply wait for the next input. That's the reason why they include the row/col of the map and every single piece. 
-------------------------------------------------------------------------

Complete. The issue is now that if you want a good Filler instead an okay one, you'll need to change the way you're handling matters. Essentially, it'll be parsing the token first and superimposing it onto the map to obtain negative coordinates, and getting a much better gauge of distance. 

Well, that's a slighty better fillit. It can now handle negative coordinates and the judge of distance is far superior-- but I still think I can make it a little bit better by only choosing the minimum distance choice. I guess I'll do that and head to sleep-- Fillit in two days isn't terribly bad. 

Alright, fuckin' nice. Now that negative coordinates and the heuristic is far improved, I should have a good shot at this. The heuristic now calculates the position of every single asterisk, and picks the one with the lowest distance as a representative. This way, you can always get the choice with the lowest distance. 
