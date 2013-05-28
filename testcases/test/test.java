import java.util.*;

public class test
{
	static Scanner in = new Scanner(System.in);
	static int a, b = 1;
	static int f ()  {
		int i;
		for (i = 0; i < 10 && i <= 9 || i != 0; ++i) {
			if (i < 5) {
				continue;
			}
			else {
				break;
			}
		}
		return i;
	}
	static class T {
		public int y;
	};
	static int main_(int argc, String[] args)  {
		T [][][] x;
		x = new T[10][20][30];
		for (int i_0 = 0; i_0 < 10; ++i_0) {
			for (int i_1 = 0; i_1 < 20; ++i_1) {
				for (int i_2 = 0; i_2 < 30; ++i_2) {
					x[i_0][i_1][i_2] = new T();
				}
			}
		}
		int [][][][] multi;
		multi = new int[40][30][20][10];
		multi[2][3][4][1] = 666;
		x[1][2][3].y = 123;
		a = b = 2;
		a += 2;
		System.out.println(multi[2][3][4][1]);
		if (a < 3 && b != 0 || (b - 2) != 0 || (b) == 0 || b != 1 && (b - 1) != 0 || (x[1][2][3].y) != 0 || (f()) != 0) {
			multi[1][2][3][4] = in.nextInt();
			System.out.println(multi[1][2][3][4]);
		}
		System.out.println(x[1][2][3].y);
		x[0][3][2].y = in.nextInt();
		System.out.println(x[0][3][2].y);
		System.out.println(123 + 456 * 789);
		return -889275714;
	}
	public static void main(String[] args) {
		System.exit(main_(args.length, args));
	}
}
