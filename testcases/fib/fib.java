import java.util.*;

public class fib
{
	static Scanner in = new Scanner(System.in);
	static int mat[] = {0, 1, 1, 1};
	static int n;
	static int MOD = 10007;
	static int solve (int x)  {
		int p, q, r, s;
		int ans[] = {0, 1};
		for (; (x) != 0; x >>= 1) {
			if ((x & 1) != 0) {
				p = ans[0] * mat[0] + ans[1] * mat[2];
				q = ans[0] * mat[1] + ans[1] * mat[3];
				ans[0] = p % MOD;
				ans[1] = q % MOD;
			}
			p = mat[0] * mat[0] + mat[1] * mat[2];
			q = mat[0] * mat[1] + mat[1] * mat[3];
			r = mat[2] * mat[0] + mat[3] * mat[2];
			s = mat[1] * mat[2] + mat[3] * mat[3];
			mat[0] = p % MOD;
			mat[1] = q % MOD;
			mat[2] = r % MOD;
			mat[3] = s % MOD;
		}
		return ans[0];
	}
	static int main_(int argc, String[] args)  {
		n = in.nextInt();
		System.out.println(solve(n));
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
