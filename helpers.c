/**
 * check_num - Checks if a string is a number.
 *
 * @num: Pointer to the supposed number string.
 *
 * Return: 0 if the string contains a non-number character, otherwise 1.
 */
char check_num(char *num)
{
	unsigned int i;

	for (i = 0; num[i] != '\0'; i++)
	{
		if (num[i] > '9' || num[i] < '0')
			return (0);
	}
	return (1);
}
