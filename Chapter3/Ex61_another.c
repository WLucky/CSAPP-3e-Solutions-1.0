long cread_alt(long *xp)
{
	long test = !xp;
	static long i = 0;
	long *p = &i;
	if(test)
		p = xp;

	return *p;
}
