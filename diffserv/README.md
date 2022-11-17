# DiffServ

## The simulation model

The simulation model consists of the following OMNeT++ modules:

- **user**
  - first stages: implement two *identical* users
  - then consider `k` users, organized in an array
    - each user generates IP packets according to a certain pattern:
      - e.g. at some random time interval
      - or in a file, a file consisting of a random number of IP packets
  - first stages: the IP packets can be considered to have fixed length, i.e. one IP packet = 1500 bytes
  - a user has a certain *priority* (3 or 4 priority levels)
    - 3 levels (in increasing order): `LP` (low priority), `MP` (medium priority), and HP (high priority)
    - 4 levels: non real-time `nrt-LP`, `nrt-HP`, and real-time `rt-LP`, `rt-HP`

- **scheduler**
  - scheduler is in the same Omnet module as the queues
  - queues are *not* per user, but per priority class, i.e. packets from `LP`, `MP`, and `HP` users will be stored in the `LP`, `MP`, and `HP` queues, respectively
  - scheduler reads the lengths of the queues and implements a scheduling algorithm that determines which queue will send data
  - sending a packet takes a time equal to its *length* divided by the *line rate* (i.e. 1500 bytes / 1 Mega bit per second)
    - scheduler cannot send another packet during this time interval.

- **sink**
  - models the destination of the data
  - when the data (IP packets) created by an user arrive to the sink module
    - the sink simply deletes the OMNeT++ messages representing the data packets
  - the sink is also used to collect statistics about the simulation
    - statistics can be for each user, for each priority group, and/or for the entire system
    - statistical information can be:
      - the number of data packets that arrive to the sink
      - the mean, minimum, and maximum delay of the data packets
      - etc

## Basic/minimal requirements

Implement the simulation model described above

- scheduling algorithm is not important in this stage
  - simple round robin: each nonempty queue sends a data packet
  - priority queueing: a queue is not served until there are non-empty higher priority queues

Two alternatives to improve the scheduling algorithm:

1. Priority queueing (a lower priority queue is served if and only if all higher priority queues are empty)

2. A weighted round robin
  - an action takes place every time there are resources available
  - winner of the action will be served
  - criteria for the action
    - firstly, the time elapsed since the user was served last
    - then, improve the algorithm by introducing weights (positive numbers > 1)
      - the time elapsed since the user was last served is multiplied with user's weight
      - a user with a higher weight will be served more often
    - compare the performance (i.e. average delay, minimum and maximum delay) of the implemented algorithms
