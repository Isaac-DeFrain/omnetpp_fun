# Scheduler

A valid scheduling algorithm will not send more than `NrOfChannels` packets per scheduling cycle

## Ideas

- scheduler parameter `NrOfChannels`
  - decide number of packets to send from each queue, `total < NrOfChannels`
  - this number must be communicated to each queue
  - set parameter to the "cmd" message
  - `MyQ` reads this parameter, extracts that number of messages, and sends them to the sink
