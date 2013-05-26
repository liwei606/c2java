int mat[4]={0,1,1,1};
int n;
int MOD=10007;

int solve(int x)
{
	int p,q,r,s;
	int ans[2]={0,1};
	for(;x;x>>=1)
	{
		if(x&1)
		{
			p=ans[0]*mat[0]+ans[1]*mat[2];
			q=ans[0]*mat[1]+ans[1]*mat[3];
			ans[0]=p%MOD;;
			ans[1]=q%MOD;
		}
		p=mat[0]*mat[0]+mat[1]*mat[2];
		q=mat[0]*mat[1]+mat[1]*mat[3];
		r=mat[2]*mat[0]+mat[3]*mat[2];
		s=mat[1]*mat[2]+mat[3]*mat[3];
		mat[0]=p%MOD;
		mat[1]=q%MOD;
		mat[2]=r%MOD;
		mat[3]=s%MOD;
	}
	return ans[0];
}

int main()
{
	read(n);
	write(solve(n));
	return 0;
}

