# Filler

Filler is an algorithmic game in which I discovered the basics of writing an AI.
The objective of the project is to write an AI that can beat other players by placing random pieces on a map in a strategic way to block the opponent and and take over the map.

Each turn, the current player has to put his piece on the map with the aim to eventually have the most pieces on the map.
To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).-

## Algorithm

On the beginning of each turn, I create a Heat Map to determine where to place my next piece.
Values are assigned on each case of the map. It starts from the position of the enemy and is incremented until it reaches the board edges.

![alt text](https://github.com/mdubus/filler/blob/master/img/heat-map.png)

Then, the algorithm tries to put the piece on each position of the map and calculates the score on each position.
The smaller the score is, the better it is, because it will get closer to the enemy. Eventually I will surround the enemy with this algorithm, thus prohibiting him to put any more pieces on the map.

![alt text](https://github.com/mdubus/filler/blob/master/img/calculate-score.png)

## Example 

![alt text](https://github.com/mdubus/filler/blob/master/img/mdubus-filler-ecole-42.gif)


## Installation

`make`

## Run

Standard mode : 

`./filler_vm -f [map] -p1 [player1] -p2 [player2]`
