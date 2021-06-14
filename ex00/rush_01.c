#include <unistd.h>
#include <stdio.h>

void	fill_arrays(char array[]);
void	verify_array(int argc, char **argv);//char ** is a pointer to pointer to char
void	play_the_game(char up[4], char down[4], char left[4], char right[4]);

int	main(int argc, char **argv)
{
	verify_array(argc, argv);
	return (0);
}

void	verify_array(int argc, char **argv)
{
	int		counter;
	int		new_array_counter;
	int		is_valid;
	char	new_array[16];

	is_valid = 1;
	counter = 1;
	new_array_counter = 0;

	while(counter < argc)
	{
		if (*argv[counter] != 32)
		{
			if (*argv[counter] < 49 || *argv[counter] > 52)
				is_valid = 0;
			new_array[new_array_counter] = *argv[counter];
			new_array_counter++;
		}
		counter++;
	}
	//printf("new_array_counter: %d\n", new_array_counter);
	//printf("is_valid: %d\n", is_valid);
	if (new_array_counter == 16 && is_valid == 1)
		fill_arrays(new_array);
	else
		write(1, "Error\n", 6);
}

void	fill_arrays(char array[])
{
	int	counter;
	int	sub_counter;
	char	up[4];
	char	down[4];
	char	left[4];
	char	right[4];

	counter = 0;
	sub_counter = 0;
	while (counter <= 15)
	{
		if (counter >= 0 && counter <= 3)
			up[sub_counter] = array[counter];
		if (counter >= 4 && counter <= 7)
			down[sub_counter] = array[counter];
		if (counter >= 8 && counter <= 11)
			left[sub_counter] = array[counter];
		if (counter >= 12 && counter <= 15)
			right[sub_counter] = array[counter];
		if (sub_counter == 3 || sub_counter == 4 || sub_counter == 8 || sub_counter == 12)
			sub_counter = 0;
		else
			sub_counter++;
		counter++;
	}
	play_the_game(up, down, left, right);
}
