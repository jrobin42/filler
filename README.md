# Filler

This project is a little game where two players are fighting on a map.<br />
They play turn by turn **putting a piece** - *given by the vm* - on the **map**.<br />
The **game ends** when the map is **full**.<br />
The **winner** will be the one which has put **the most of pieces**.<br />
<br />
My role in this project was to code a better player than the others - *which are in the `players` repository* -.<br />
I did a **heat map** to find the better place where put my piece.<br />

### Install and compile 

#### Steps
1. `git clone https://github.com/jrobin42/filler.git ~/filler`<br />
2. `cd ~/filler`<br />
3. `git submodule init libft && git submodule update && make`

Now everything is ready to **play** !<br />

### Usage of the program

`./filler_vm -f {MAP} -p1 {FIRST_PLAYER} -p2 {SECOND_PLAYER}`<br />
<br />
*Note that all of the players has the `.filler` extension.*

### Example of launch

You will see that there is a repository of `maps` and an other of `players`.<br />
The one I coded is named jrobin.filler.<br />
<br />
To test it - *against `abanlin`'s player for example on the map named `map01`* -, run the vm this way :<br />
`./filler_vm -f maps/map01 -p1 players/jrobin.filler -p2 players/abanlin.filler`<br />
<br />
First player will be the one with **O** pieces and the second with **X** pieces.<br />
<br />
At the end of the display on the terminal you will have this :
``` 
== O fin: {NUMBER OF BLOCKS}
== X fin: {NUMBER OF BLOCKS}
```

The **winner** is the one with the higher number of blocks.

### Enjoy !
