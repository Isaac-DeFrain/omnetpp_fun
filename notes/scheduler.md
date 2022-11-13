# Scheduler

- a valid scheduling algorithm will not send more than `NrOfChannels` packets per scheduling cycle

- current code for scheduler and queue (`MyQ`) are *not valid* because all queues are emptied in each scheduling cycle

- **imagine** and **implement** any valid scheduling algorithm

## Hints

- scheduler knows about `NrOfChannels`
  - decide number of packets to send from each queue
  - this number must be communicated to each queue
  - set parameter to the message "cmd"
  - `MyQ` reads this parameter and extracts that number of messages and sends them to the sink
