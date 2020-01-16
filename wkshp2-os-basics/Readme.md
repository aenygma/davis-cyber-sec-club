Let's review OS basics, by looking at our restaurant example.

Let's take this simple layout for our restaurant.  

    +-----------------------+
    |                 Lobby/|
    |            Dining Area|
    |                       |
    |                       |
    |                       |
    |                       |
    +-----------------------+
    |  Service              |
    |  Counter              |
    +-----------------------+
    |                       |
    |                       |
    |                Kitchen|
    +-----------------------+

---

      +       ^
   +-----------------------+
   |  |       |      Lobby/|
   |  |       | Dining Area|
   |  |       |            |
   |  |       |            |
   |  |       |            |
   |  |1      | 4          |
   +--v-------+------------+
   |  Service              |
   |  Counter              |
   +----+------------------+
   |    |      ^3          |
   |    |      |           |
   |    v 2    |    Kitchen|
   +----+------+-----------+

1. Customer walks to Service counter and orders
2. Worker takes order, goes to kitchen, starts prep.
3. Worker finishes and returns with order
4. Customer receives order. Transaction finished.


