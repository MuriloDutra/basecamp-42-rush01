void	ft_putchar(char c);

void	print(char matrix[4][4])
{
	int	line;
	int	column;

	line = 0;
	while(line <= 3)
	{
		column = 0;
		while(column <= 3)
		{
			ft_putchar(matrix[line][column]);
			ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		line++;
	}
}