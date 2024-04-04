# Push Swap

<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/push_swapm.png" alt="Push Swap Achievement" width="200" height="200">
  <img src="https://res.cloudinary.com/dfjub9qt4/image/upload/v1712254907/push_swap_42.png" alt="Push Swap Square" width="200" height="200">
</p>

## Introduction
Push Swap is a project aimed at sorting a stack of integers using a limited set of instructions on two stacks named 'a' and 'b'. This project focuses on implementing efficient sorting algorithms in C and optimizing the number of operations needed to sort the stack.

## Compilation
o compile the Push Swap program, simply run make. This will generate the executable file push_swap for the main part. For the bonus part, you will need to run make bonus and will have a checker executable for the bonus.

## Usage (Main Part)
The Push Swap program takes a list of integers as input and displays the smallest list of instructions required to sort the stack 'a', with the smallest number being at the top. Instructions are separated by a newline.
```bash
./push_swap <list_of_integers>
```

## Allowed Movements
In this project, there are a set of allowed movements to be executed, limiting the actions that can be taken to order the stack. The allowed movements are as follows:

sa: Swap the first two elements at the top of stack 'a'.
sb: Swap the first two elements at the top of stack 'b'.
ss: Perform sa and sb simultaneously.
pa: Push the first element at the top of stack 'b' onto stack 'a'.
pb: Push the first element at the top of stack 'a' onto stack 'b'.
ra: Rotate all elements of stack 'a' upwards by one. The first element becomes the last.
rb: Rotate all elements of stack 'b' upwards by one. The first element becomes the last.
rr: Perform ra and rb simultaneously.
rra: Rotate all elements of stack 'a' downwards by one. The last element becomes the first.
rrb: Rotate all elements of stack 'b' downwards by one. The last element becomes the first.
rrr: Perform rra and rrb simultaneously.

## Bonus (Checker)
The project also includes a bonus program named Checker. This program verifies whether the instructions provided correctly sort the stack. If stack 'a' is sorted and stack 'b' is empty after executing the instructions, it displays "OK"; otherwise, it displays "KO". It behaves similarly to checker_linux.

## Usage (Bonus Part)
To use the checker program in interctive mode for the bonus part, follow the syntax:
```bash
./checker <list_of_integers>
```
Example:
```bash
./checker "3 2 4 1"
```
Then, write the movements to be executed. 
```bash
sa
rra
```
After entering the movements, press Ctrl + D to stop and execute them.

Alternatively, you can use a pipe to redirect the output of Push Swap to Checker. For example:
```bash
ARG="1 2 10 9 8 5 6"; ./push_swap $ARG | ./checker $ARG
```
After entering the movements, press Ctrl + D to stop and execute them.

## Error Handling

In case of errors, such as invalid input, both Push Swap and Checker will display "Error" followed by a newline on the standard error.

