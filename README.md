# Example 1:
sudo ./other-task 0 FOO &
sudo ./other-task 0 BAR &
sudo ./other-task 0 QUX &

# Example 2:
sudo ./rr-task 1 FOO &
sudo ./rr-task 1 BAR &
sudo ./rr-task 1 QUX &

# Example 3:
sudo ./fifo-task 1 FOO &
sudo ./fifo-task 1 BAR &

# Example 4:
sudo ./rr-task 1 FOO &
sudo ./other-task 0 BAR &

# chrt usage:
sudo chrt --rr -p 2  
sudo chrt --fifo -p 2

