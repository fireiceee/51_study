void Delay(unsigned int t)		//@12.000MHz
{
	unsigned char i, j;
	while(t--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}