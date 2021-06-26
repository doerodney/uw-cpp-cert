# Assignment 05 Comments
Here the steps I took to complete the assignment.

## Exception Handling: User Input
Our esteemed user specifies integer cave identifiers in the Move and 
Shoot commands.  I added a parseInt function that tests if the user-specified 
cave number contains something numeric that can be converted to an integer.  

## Exception Generation:  Missing Data
The only interface point between main and the library is the Dungeon::MakeMove 
method. The only thing a library client can screw up is to fail to provide  
cave identifiers, so I added code to throw a std::runtime_error exception when 
the point vectors are empty.

## Manual Test Process with Console Capture of Execution
Not sure what this is short of creating a test client.  It's too hot for that.

## Extra Credit: Alternative to `assert`
One usually uses `assert` to test assumptions about program state - are the 
code/context what you think they are?

The assert macro is pretty simple.  It just takes an expression as an argument.  
The expression may reference local variables.  An invocation might look like this:

```C
assert(n > 0)
```

This is convenient except when it's not.  If the assertion fails, then the 
program is aborted.  At this point, it may be necessary to comment out/rebuild 
and re-execute to get past a failed assertion.

At the end of the day, the assert macro must invoke abort.  Here is where 
opportunity knocks.

An alternative to `abort` might be to throw a std::logic_error assertion.  In 
lieu of an `abort`, an alternative macro could throw a std::logic error, 
embedding the expression, __FILE__, __LINE__, and a generic explanation into 
the exception `what` attribute.

A single strategically-placed try-catch block could catch all the exceptions, 
and log the messages to, say, the syslog on a Linux machine.

## Extra credit: Win Hunt the Wumpus
This is the first computer game I have played since maybe 1995.  I am acutely 
uninterested in computer games.

Tunnels lead to:  11 18 20
You feel a draft...
Command? m 204
You can't get to 204 from here.
Command? m 20
You've entered cave 20
Tunnels lead to:  13 16 19
Bats nearby...
Command? m 16
You've entered cave 16
Tunnels lead to:  15 17 20
Command? m 15
You've entered cave 15
Tunnels lead to:  14 6 16
Command? m 6
You've entered cave 6
Tunnels lead to:  5 15 7
You smell a horrid stench...
Command? s 5
Aha! You got the Wumpus!
Game over: you won.

