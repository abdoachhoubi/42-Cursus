<div align="center">

```sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    push_swap                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <aachhoub@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02      by aachhoub              #+#    #+#              #
#    Updated: 2023/02/02      by aachhoub             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
```

</div>

# push_swap

This project requires you to sort data on a stack using a limited set of instructions and with the fewest possible moves. To accomplish this task, you will need to manipulate different sorting algorithms and select the optimal solution(s) for efficient data sorting.

## Functions:

- [x] **is_sorted**: Checks if a stack is sorted or not.
- [x] **tiny_sort**: Uses the minimum instructions to sort a stack that has three nodes
- [x] **push_and_save_three**: Pushes all nodes from stack_a to stack_b except 3 nodes amongs the greter half of stack_a
- [x] **sort**: Sorts stack_a using an algorithms depending on the size of stack_a
- [x] **get_cost**: Gets the count of moves that a node requires in order to be moved to the head of a stack
- [x] **cheapest_move**: Decides which set of moves are suitable for a node in order to move it to the top of stack
- [x] **lowest_index_position**: Returns the index of the greater node in a stack (which also had the lowest index)
- [x] **target_position**: Assign the target position to all nodes
- [x] **move**: Performes a set of consecutive instructios to move a node to the head of a stack
- [x] **fill_stack**: Fills the stack_a
- [x] **assign_index**: Assigns an index to all nodes of stack_a from the greatest to the lowest
- [x] **ft_stack_bottom**: Returns the last node of a stack
- [x] **ft_stack_before_bottom**: Return the node before the last one of a stack
- [x] **stack_new**: Creates a new node
- [x] **ft_stack_size**: Returns the count of nodes in a stack
- [x] **ft_stack_add_back**: Adds a new node to the back of a stack
- [x] **free_stack**: Frees all allocated memory for nodes of a stack
- [x] **exit_error**: Exit and desplay an error message
- [x] **valid_input**: Checks if the input is valid
- [x] **do_oper_a (bonus)**: Performs a specific instruction on stack_a
- [x] **do_oper_b (bonus)**: Performs a specific instruction on stack_b

_! Please note that the functions listed above are not an exhaustive list of all the functions available. I have created numerous other functions in previous projects that may also be useful, but they are not included in the list above._

## Author

[Abdo Achhoubi](https://astro.leet.ma)
