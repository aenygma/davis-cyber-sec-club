# Workshop Agenda
* Tree search
* DFS 
* Stack

Topics Covered: Stack, Trees

The goal here is to deepen the idea of where some of the foundations of subroutines and subfunctions arise and the intuition behind why the data structures are used.


## Tree traversal

         
                               +----+
                               |root|
                               +-+--+
                                 |
                   +-------------+-------------+
                   |                           |
                 +-+-+                       +-+-+
                 | C |                       | F |
                 +-+-+                       +-+-+
                   |                           |
             +-----+----+                +-----+----+
             |          |                |          |
           +-+-+      +-+-+            +-+-+      +-+-+
           | B |      | D |            | G |      | I |
           +-+-+      +---+            +-+-+      +-+-+
             |                           |          |
       +-----+                     +-----+    +-----+----+
       |                           |          |          |
     +-+-+                       +-+-+      +-+-+      +-+-+
     | A |                       | H |      | J |      | K |
     +---+                       +---+      +---+      +---+

How should we traverse and discover the tree here?

---

## DFS
How about Depth First Search?  
**X** will denote where we currently are.  
We'll need to use a method of keep track of where we've been and where we need to go.   


                               +-X--+
                               |root|
                               +-+--+
                                 |
                   +-------------+-------------+
                   |                           |
                 +-+-+                       +-+-+
                 | C |                       | F |
                 +-+-+                       +-+-+
                   |                           |
             +-----+----+                +-----+----+
             |          |                |          |
           +-+-+      +-+-+            +-+-+      +-+-+
           | B |      | D |            | G |      | I |
           +-+-+      +---+            +-+-+      +-+-+
             |                           |          |
       +-----+                     +-----+    +-----+----+
       |                           |          |          |
     +-+-+                       +-+-+      +-+-+      +-+-+
     | A |                       | H |      | J |      | K |
     +---+                       +---+      +---+      +---+


