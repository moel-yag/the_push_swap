#include "../push_swap.h"

// Function to check if a string is a valid integer
static int is_valid_number(char *str)
{
  int i;

  i = 0;
  if (str[i] == '-' || str[i] == '+')
    i++;
  if (!str[i])
    return (0); // Empty string after sign
  while (str[i])
  {
    if (!ft_isdigit(str[i]))
      return (0); // Non-digit character
    i++;
  }
  return (1);
}

// Function to check for duplicate numbers in the stack
static int has_duplicates(t_stack *stack, int num)
{
  while (stack)
  {
    if (stack->content == num)
      return (1); // Duplicate found
    stack = stack->next;
  }
  return (0); // No duplicates
}

static void	del(void *content)
{
	(void)content;
}

// Function to add a number to the stack
static void add_to_stack(t_stack **stack, int num)
{
  t_stack *new_node;

  new_node = ft_lstnew(num);
  if (!new_node)
  {
    ft_lstclear(stack, del);
    ft_error("Error: Memory allocation failed");
  }
  ft_lstadd_back(stack, new_node);
}

// Function to parse a single string of numbers
static void parse_single_string(t_stack **stack, char *str)
{
  char **numbers;
  int i;
  long num;

  numbers = ft_split(str, ' ');
  if (!numbers)
    ft_error("Error: Memory allocation failed");
  i = 0;
  while (numbers[i])
  {
    if (!is_valid_number(numbers[i]))
      ft_error("Error: Invalid number");
    num = ft_atol(numbers[i]);
    if (num < INT_MIN || num > INT_MAX)
      ft_error("Error: Number out of range");
    if (has_duplicates(*stack, (int)num))
      ft_error("Error: Duplicate number");
    add_to_stack(stack, (int)num);
    i++;
  }
  ft_free_split(numbers);
}

// Function to parse multiple arguments
static void parse_multiple_args(t_stack **stack, int argc, char **argv)
{
  int i;
  long num;

  i = 1;
  while (i < argc)
  {
    if (!is_valid_number(argv[i]))
      ft_error("Error: Invalid number");
    num = ft_atol(argv[i]);
    if (num < INT_MIN || num > INT_MAX)
      ft_error("Error: Number out of range");
    if (has_duplicates(*stack, (int)num))
      ft_error("Error: Duplicate number");
    add_to_stack(stack, (int)num);
    i++;
  }
}

// Main parsing function
void parse_input(t_stack **stack, int argc, char **argv)
{
  if (argc == 2)
    parse_single_string(stack, argv[1]); // Single string input
  else
    parse_multiple_args(stack, argc, argv); // Multiple arguments
}