
unsigned char rol(unsigned char val)
{
    int hibit;
    if(val & 0x80)
	hibit = 1;
    else
	hibit = 0;

    val <<= 1;
    val |= hibit;

    return val;
}
unsigned char ror(unsigned char val)
{
    int lowbit;
    if(val & 1)
	lowbit = 1;
    else
	lowbit = 0;

    val >>= 1;
    val |= (lowbit << 7);

    return val;
}
