import java.util.*;

public class queen
{
	static Scanner in = new Scanner(System.in);
	static int n;
	static int ans = 0;
	static int [] b;
	static { b = new int[20]; }
	static int [] l;
	static { l = new int[40]; }
	static int [] r;
	static { r = new int[40]; }
	static int dfs (int x)  {
		int i;
		if ((x == n)) {
			++ans;
			return 0;		}
		for (i = 0; (i < n); ++i) {
			if ((b[i] == 0 && l[i + x] == 0 && r[i - x + n - 1] == 0)) {
				b[i] = 1;
				l[i + x] = 1;
				r[i - x + n - 1] = 1;
				dfs(x + 1);
				b[i] = 0;
				l[i + x] = 0;
				r[i - x + n - 1] = 0;
			}
		}
		return 0;
	}
	static int main_(int argc, String[] args)  {
		n = in.nextInt();
		if ((n > 16)) {
			System.out.println(-1);
		}
		else {
			dfs(0);
			System.out.println(ans);
		}
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
