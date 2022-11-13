# Scheduler

A valid scheduling algorithm will not send more than `NrOfChannels` packets per scheduling cycle

## Hints

- scheduler knows about `NrOfChannels`
  - decide number of packets to send from each queue
  - this number must be communicated to each queue
  - set parameter to the message "cmd"
  - `MyQ` reads this parameter, extracts that number of messages, and sends them to the sink
