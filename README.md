# What is fillit? @ <a href = "https://www.42.us.org/">42 Sillicon Valley</a>
This is a project where you are given a file that contains a "set" of tetris pieces called tetriminos and you must re-arrange them into the smallest square possible given the set.
# How do you make tetriminos in C??
It's pretty simple first we will represent a tetrimino in a 4 x 4 grid of empty spaces that look like '.' and the blocks of tetriminos will look like this '#'. A vallid set of tetriminos will look like this:

    ....      ..#.    .###      ....      ..##
    .###  or  ..#.    ...#  or  .##.      .##.  in any position!!
    ..#.      ..#. or ....      .##.  or  ....  
    ....      ..#.    ....      ....      ....
 
# How do I fillit?
It's quite simple just run this command in the terminal. 

    ./fillit testfiles/test
# I want to test my own set of tetriminos!!
Head over to testfile and write the tetriminos in the custom file in the same format as the ones above. This program can solve up to 26 tetriminos but the time it takes to find an answer will increase exponentially with each tetrimino. Make sure to inclue a newline between each tetrimino like this:

    .##.
    .##.
    ....
    ....
          <--- newline
    ...#
    ...#
    ...#
    ...#
