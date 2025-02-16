#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include "libft/libft.h"

// Function prototypes
void apply_operations(t_stack **stack_a, t_stack **stack_b, char *operation);
void checker(t_stack **stack_a, t_stack **stack_b);
void read_operations(t_stack **stack_a, t_stack **stack_b);
void del(int content);

#endif