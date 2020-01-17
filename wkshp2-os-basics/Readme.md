Let's review OS basics, by looking at our restaurant example.

Let's take this simple layout for our fast-food restaurant.  

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
    +--|-------|------------+
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
    |                       |                |  (Oven, Fridge, Mixer |
    |                       |                |   Storeroom)          |
    |                       |                |                       |
    +-----------------------+                +-----------------------+

---

But it's missing couple things...   
In an OS, the user brings input and asks the Kernel for resources...   
So, let's change our restaurant a little bit.   

__Now__, the customers can bring a recipe on how to make a meal.    
The Chef (Kernel) uses the recipe (Program) to assemble the meal (output).  
(We can even imagine the customer bringing some special ingredients of their own as well.)  

---
Two Customers come with two recipes.   

    +-----------------------+                +-----------------------+
    |                       |                |                       | 
    |   Recipe: Pasta       |                |   Recipe: Burgers     |
    |   =============       |                |   ===============     | 
    +-----------------------+                +-----------------------+
    |                       |                |                       | 
    | Thread 1:             |                | Thread 1:             |
    | ---------             |                | ---------             |
    | Boil Water            |                | Add Meat, Spices      |
    | Add Pasta             |                | Mix                   |
    | Cook 10 minutes       |                | Mold Patties          |
    | Wash under cold water |                | Grill 5 minutes       |
    |                       |                | Add Tomato, Lettuce,  |
    | Thread 2:             |                |  Onions, Cheese       |
    | ---------             |                |  to Buns              | 
    | Cook Tomatoes         |                | Place Patty on Bun    | 
    | Add Meat              |                |                       | 
    | Add Spices            |                |                       | 
    | Cook 10 minutes       |                |                       |     
    |                       |                |                       | 
    | Add Sauce to Pasta    |                |                       | 
    +-----------------------+                +-----------------------+




