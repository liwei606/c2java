int a,b;

int gcd(int x,int y)
{
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main()
{
	read(a);
	read(b);
	write(gcd(a,b));
	return 0;
}
