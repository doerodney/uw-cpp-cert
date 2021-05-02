# Notes on Assignment 1
This contains some notes on:
* Getting support for C++ 20 on Linux.
* How the assignment was completed.

## Support for C++20
I have been Windows-less since no employer I have worked for in the last five years (Nordstrom, Apkudo) uses Windows in production.  Nordstrom actually deprecated Windows.

I did the Intro course on the Linux container that is now available on Chromebooks.  It implements a Debian Linux, but Debian does not support C++20.

This assignment was completed on a Raspberry Pi 4 (8 GB RAM, 128 GB SD storage).  It was the only machine in my arsenal that could support the C++20 (or as g++ refers to it, c++2a).  This was formerly a headless Pi, and I added an $80 monitor and finally got things ship shape.  

I wish I had more time to prepare to support this standard.  In the Intro class, we used C++17.

I found Visual Studio Code to be surprisingly good to use on the Pi, even though getting it installed was non-trivial.  The Intellisense gives a fair amount of false positives - red squiggles that are not actually problems.  I was initially delighted to use the SSH-Remote feature, then discovered that it was not quite ready for prime time.  

NOTE:  Two weekends from now, when the next assignment is due, I will be on the East Coast.  I will not have my Pi with me, so I may have to request a delay so that I can compile/clean up code when I get home Tuesday May 18th.  I can code the assignment roughly while on the plane.  Hopefully, I can complete the assignment before I depart.

## Completion of the Assignment
I tried to use your `Makefile`, and it was turning out to be more work than I had time for, so I set it aside.

I have included a shell script `gen_makefile.sh`, that gives me a simple, tidy `makefile`.  I used that in lieu of the one provided.  As they say in Texas, "Dance with the one what brung ya."

I have implemented simple stubs for most of the methods in the Denizen derivatives.  I shoved as much of the implementation into the Denizen base class as possible.  Hopefully, that was a good idea.
