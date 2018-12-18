char check_num(char *num)
{
	unsigned int i;

	for(i = 0; num[i] != '\0'; i++)
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
	}
	return (1);
}
