# philosophers

  This project teaches the basics of threading a process. Fun times operating the threads and discovering mutexes 🔒

## The problem 

  The dining philosophers problem was originally formulated in 1965 by Edsger Dijkstra. It is an illustrative example of a common computing problem in concurrency: 

```
  N amount of philosophers sit at a round table.
  Every philosopher has a bowl of spaghetti in front of them and 1 chopstick to their right.
  Important to keep on mind: there are as many chopsticks as philosophers.
  Set or unset amount of times philosophers take turns to think, eat and sleep.
  They have to take turns, because in order to eat they need 2 chopsticks.
  Each chopstick may be used only by someone 1 at a time.
  The one who has a chopstick in the hand may set it down.
  The one who doesn't have chopstick may pick it up if it's not taken yet.
  Only having both chopsticks (their and their neighbours) they may start eating.
  Each philosopher can perform one action at a time.
  The order goes like: eat->sleep->think.
  Given to programm input sets the time to eat, sleep, think, die + (optional) times_to_eat
  If a philosopher doesn't eat withing set time to die, it dies.
  The process finishes with someone's death or when times_to_eat is fulfilled (in case it was set).
  That may also happen that the programm runs infinitely which in some cases is logical and right.

```
  The goal is to let philosophers live as long as they possibly could. 

## Illustration

<img src = "https://res.cloudinary.com/practicaldev/image/fetch/s--eqcyI4o8--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://dev-to-uploads.s3.amazonaws.com/uploads/articles/xuhgni9ifz9d1uo1red2.png">

