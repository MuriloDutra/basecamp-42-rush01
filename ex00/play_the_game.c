void	handle_4(char (*matrix)[4][4], int position, char side);
void	print(char matrix[4][4]);
void	fill_matrix_position(int line, int column, char (*matrix)[4][4]);

//up, down, left, right

void	play_the_game(char up[4], char down[4], char left[4], char right[4])
{
	char	matrix[4][4];
	int		counter;
	int		line;
	int		column;

	// ============= FILL THE MATRIX WITH 'A's =============
	line = 0;
	while(line <= 3)
	{
		column = 0;
		while(column <= 3)
		{
			matrix[line][column] = 'A';
			column++;
		}
		line++;
	}
	// ============= FILL THE MATRIX WITH 'A's =============

	while (counter <= 3)
	{
		if (up[counter] == '4')
			handle_4(&matrix, counter, 'u');
		if (down[counter] == '4')
			handle_4(&matrix, counter, 'd');
		if (left[counter] == '4')
			handle_4(&matrix, counter, 'l');
		if (right[counter] == '4')
			handle_4(&matrix, counter, 'r');
		counter++;
	}
	print(matrix);
}

void	handle_4(char (*matrix)[4][4], int position, char side)
{
	int	counter;

	if(side == 'u' || side == 'l')
	{
		counter = 0;
	}
	if(side == 'd' || side == 'r')
	{
		counter = 3;
	}
	while(counter <= 3)
	{
		if(side == 'u' || side == 'd')
		{
			/*(*matrix)[counter][position] = '1';
			(*matrix)[counter][position] = '2';
			(*matrix)[counter][position] = '3';
			(*matrix)[counter][position] = '4';*/
			fill_matrix_position(counter, position, matrix);
		}
		if(side == 'l' || side == 'r')
		{
			/*(*matrix)[position][counter] = '1';
			(*matrix)[position][counter] = '2';
			(*matrix)[position][counter] = '3';
			(*matrix)[position][counter] = '4';*/
			fill_matrix_position(position, counter, matrix);
		}
		if(side == 'u' || side == 'l')
			counter++;
		else if(side == 'd' || side == 'r')
			counter--;
	}

	/*if (side == 'u')
	{
		(*matrix)[0][position] = '1';
		(*matrix)[1][position] = '2';
		(*matrix)[2][position] = '3';
		(*matrix)[3][position] = '4';
	}
	if(side == 'l')
	{
		(*matrix)[position][0] = '1';
		(*matrix)[position][1] = '2';
		(*matrix)[position][2] = '3';
		(*matrix)[position][3] = '4';
	}
	if(side == 'd')
	{
		(*matrix)[3][position] = '1';
		(*matrix)[2][position] = '2';
		(*matrix)[1][position] = '3';
		(*matrix)[0][position] = '4';
	}
	if(side == 'r')
	{
		(*matrix)[position][3] = '1';
		(*matrix)[position][2] = '2';
		(*matrix)[position][1] = '3';
		(*matrix)[position][0] = '4';
	}*/
}

void	fill_matrix_position(int line, int column, char (*matrix)[4][4])
{
	(*matrix)[line][column] = '1';
}