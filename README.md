# tschat
A trivial chat program in C

This program has a terrible interface and was written mostly just for me to practice writing multithreaded C code. 

#Description

tschat is composed of the following objects

##Interface

Read() : Returns a line of input from the user. Also displays this line on the screen.

Write() : Writes a line of input to the screen.

##Client

AddMessage() : Passes a message from the UI thread to the client Tx thread.

TxThread() : Client Tx thread blocks on a queue waiting for input from the UI thread. Once input is received it passes this message to the network layer.

##Server

RxThread() : The Rx thread blocks on the network layer and passes any received messages back to the UI thread
