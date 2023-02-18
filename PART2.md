# Part 2

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Board Creation and Display
2. Reset Trails
3. Change Direction of Arrows
4. Getting Help
5. Alien turn
6. Damage Zombies
7. Discovering pod
8. discovering health


## Additional Features

1. PowerUps - represented with u
Whenever Alien will discover u it will fire every Alien in its Alien's range will be fired and get damaged

## Contributions

List down the contribution of each group members.

For example:

### Farah 

1. Make a Game Board specifying the row and column number
2. Initialize Board with Random Values
3. Placing pods, Zombies, powerups, arrows, and rocks randomly
4. Zombie movement
5. Attacking the Alien if it is in range


### Athirah


1. Printing Default game settings
2. Updating the game settings on user demand
3. Alien move
4. Alien collecting powerups, pods
5. Alien hitting the rock

### Ilham

1. Reset Trails after completing the Alien move
2. Change Arrows on demand
3. Get the Closest Zombie
4. Game Over procedure and Delete the game board
5. Save and Load the game using File

## Problems Encountered & Solutions

1. Columns Numbering Problem:
It was ok with single-digit numbers but turned into a big problem for column numbers greater than 9

Solution:
Printed each digit of the number separately using a loop

2. Set Random Objects Problem:
Random values created a rare chance for health and pod to appear for the Alien

Solution:
Set 2 values for health as well as for pod so that the probability for coming these could be doubled

3. Generating random Zombies at locations where already a zombie is present

Solution:
Check whenever created a zombie, that if it is a valid position to place a zombie. Loop until we find a valid position

4. Input handling: It was difficult to ensure the correct input from the user

Solution:
Applied checks everywhere in the program where we have to take input from the user allowing a user to input gain and notifying the user about the wrong input 

5. Alien Turn Problem:
Faced difficulty in moving Alien along different directions based on arrows

Solution:
Applied a loop and take variable directions. Every time it gets an arrow variable is updated and the Alien moves in that direction and the loop continues until it is hit by a wall or rock
