# Part 1

## Video Demo

Please provide the YouTube link to your [Video Demo](https://youtube.com).

## Minimum Requirements

### Completed

List all the features completed.

1. Board Creation
2. Reset Trails
3. Change Direction of Arrows
4. Getting Help

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Alien turn
2. Damage Zombies
3. Discovering pod
4. discovering health
5. Attack Alien
6. Zombie Move

## Additional Features

1. PowerUps - represented with u
Whenever Alien will discover u it will fire every Alien in its Alien's range will be fired and get damaged

## Contributions

List down the contribution of each group members.

For example:

### farah

1. Generate Board
2. Initialize Board with Random Values
3. Printing Default game settings
4. Updating the game settings on user demand

### athirah

1. Zombie movement and attack behaviour.
2. Show game board with proper row numbers and column numbers
3. Get Closest Zombie
4. Alien is in Zombie's range or not

### ilham

1. Reset Trails
2. Change Arrows
3. Game Over procedure
4. Delete game board

## Problems Encountered & Solutions

1. Columns Numbering Problem:
It was ok with single digit numbers but turned to a big problem for column numbers greater than 9

Solution:
Printed each digit of the number separately using loop

2. Set Random Objects Problem:
Random values created a rare chance for health and pod to appear for the Alien

Solution:
Set 2 values for health as well as for pod so that probabilty for coming these could be doubled

3. Generating random Zombies at locations where already a zombie is present

Solution:
Check everytime when created a zombie, that if it is a valid position to place a zombie. Loop until we find a valid position
