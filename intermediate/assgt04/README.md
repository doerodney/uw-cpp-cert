# Assignment 4 Notes:
Blew my 10 hour timebox by six hours, and had to go on old mother-in-law duty. (She's actually a hoot, and amazingly sharp at 97.)

## User Notifications:
Implemented the MakeUserNotifications method in class UserNotification:  
* Implemented the callbacks as lambdas that accept void and return void.
* This did not work for notification of the adjacent caves, so I had to hack a separate notification in the Hunter::EnterCave mthod. 

I searched through code and found places where notifications were appropriate and conditions detectable.  That was just a case of search and implement as appropriate.


## Unit Tests of Notifications:
I was hard aground on how to make a unit test see a notification, so here is what I did:
* Add a vector<Notification> to class UserNotification.
* Add method ClearNotificationLog to class UserNotification to clear the log prior to running a unit test.
* Add method HasLoggerNotification to class UserNotification to see if the Notification got logged.
* To add to the safety/confusion, modified the Notifify method to only log notifications if UNITTEST_BUILD is defined.
* Changed the makefile to build a unittests executable and a hunt executable.

All of this was probably not what you had in mind, but it was resourceful.

## Noteworthy
I foolishly decided to take an update to Visual C++ Community Edition when offered.  That took a long time, ran to 99% completion, then stopped.  I had to reboot a few times to get it back on deck.  In the interim, I moved the project onto my trusty Raspberry Pi.

To make things interesting, one key on my Raspberry Pi keyboard suddenly stopped working during login.  Sadly, that key was in my password.  What next - locusts?!  A plague?!  (Wait, just finished that.)  Luckily, I had an extra keyboard in a closet, and only had to dust it off and install new batteries.

 

