public class test
{
	static int a, b = 1;

	static int f() {
		int i;
		for (i = 0; i < 10 && i <= 9 || i >= 0 - 1; ++i) {
			if (i < 05) continue;
			else break;
		}
		return i;
	}
	
	static class T {
		public int y;
	}
	
	static int $main(int argc, String[] args) {
		T[][][] x;
		x = new T[10][20][30];
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 20; ++j) {
				for (int k = 0; k < 30; ++k) {
					x[i][j][k] = new T();
				}
			}
		}
		x[1][2][3].y = 123;
		a = b = 2;
		a += (b + 2);
		System.out.print(String.format("%d\n", x[1][2][3].y));
		System.out.print(String.format("%d\n", 123 + 456 * 789));
		return 0xCAFEBABE;
	}
	
	public static void main(String[] args) {
		System.exit($main(args.length, args));
	}
}
