import java.util.*;

public class euclid
{
	static Scanner in = new Scanner(System.in);
	static int a, b;
	static int gcd (int x, int y)  {
		if ((y) == 0) {
			return x;		}
		return gcd(y, x % y);
	}
	static int main_(int argc, String[] args)  {
		a = in.nextInt();
		b = in.nextInt();
		System.out.println(gcd(a, b));
		return 0;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
