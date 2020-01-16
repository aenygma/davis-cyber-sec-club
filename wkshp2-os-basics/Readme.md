Let's review OS basics, by looking at our restaurant example.

Let's take this simple layout for our restaurant.  

    +-----------------------+
    |                Dining |
    |                 Area  |
    |                       |
    |                       |
    +-----------------------+
    |               Service |
    |               Counter |
    |                       |
    |                       |
    +-----------------------+
    |               Kitchen |
    |                       |
    |                       |
    |                       |
    +-----------------------+

---

       +       ^
    +-----------------------+
    |  |       |     Dining |       1. Customer walks to Service counter and places order.
    |  |       |       Area |       2. Worker takes order, goes to kitchen, starts prep.
    |  |       |            |       3. Worker finishes and returns with order.
    |  |1      | 4          |       4. Customer receives order. Transaction finished.
    +--v-------+------------+
    |               Service |
    |               Counter |
    |                       |
    |                       |
    +----+------^-----------+
    |    |      |   Kitchen |
    |    |      |3          |
    |    |      |           |
    |    v 2    |           |
    +----+------+-----------+


---

_This is a great, but why are we doing this??_   
Because, this maps to our OS model of syscalls.

    +-----------------------+                +-----------------------+
    |             Userspace |                |                Dining |
    |                       |                |                  Area |
    |                       |                |                       |
    |                       |                |                       |
    +-----------------------+                +-----------------------+
    |                Kernel |                |               Service |
    |                       |     ======     |               Counter |
    |                       |                |                       |
    |                       |     ======     |                       |
    +-----------------------+                +-----------------------+
    |              Hardware |                |               Kitchen |
    |                       |                |                       |
    |                       |                |                       |
    |                       |                |                       |
    +-----------------------+                +-----------------------+

---

But it's missing couple things...   
In an OS, the user brings input and asks the Kernel to do something...   
So, let's change our restaurant a little bit.   

 __Now__, customers can bring their own ingredients, and request a meal.   
---


