# Netflicks

My main contributions are in anish-steven branch of https://github.com/nlewxxs/information-not-processing.

The system is a game called Netflicks which uses a DE10 lite board FPGA, a computer and server. The game is a two-player rhythm game where arrows come down the screen and need to be caught by flicking the FPGA at the correct time. There are 3 levels, with the speed of arrows dictating the difficulty. There are 4 types of arrows corresponding to up, down, right and left FPGA flicks.

There are 3 possible outcomes of an FPGA flick: perfect catch, good catch, and miss. FPGA functionality requirements include hardware filtering,
movement detection, and formatting the 7seg display. The game is multiplayer using an AWS server for communication, synchronizing game start, displaying the other player’s score, and interactive power-ups. Score data is stored in a DynamoDB on the server to produce a top-10 leaderboard.


![image](https://github.com/anish-narain/Netflicks/assets/69715492/fc509658-33bb-4b6a-948b-79ebaa7492f9)




