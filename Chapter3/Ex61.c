
long cread_alt(long *xp)
{
	static long tmp = 0;
	if(xp == 0)
	{
		xp = &tmp;
	}
	return *xp;
}
/*use -O3 Optimization level */
