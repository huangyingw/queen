import java.util.ArrayList;

public class Queen {
	public static void main(String[] args) {
		Queen que = new Queen(8);
		ArrayList<Integer[][]> result = que.qu(0);
		for (Integer[][] nav : result) {
			for (int i = 0; i < que.count; i++) {
				for (int j = 0; j < que.count; j++) {
					if (nav[i][j] == 0)
						System.out.print('O');
					else
						System.out.print('@');
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	private int[] col;
	private int count;
	private Integer[][] data;
	private int[] principalDiagonal;

	private int[] slaveDiagonal;

	public Queen(int count) {
		super();
		this.count = count;
		init();
	}

	public void init() {
		data = new Integer[count][count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				data[i][j] = 0;
			}
		}
		col = new int[count];
		for (int i = 0; i < count; i++) {
			col[i] = 0;
		}

		principalDiagonal = new int[2 * count - 1];
		for (int i = 0; i < 2 * count - 1; i++) {
			principalDiagonal[i] = 0;
		}
		slaveDiagonal = new int[2 * count - 1];
		for (int i = 0; i < 2 * count - 1; i++) {
			slaveDiagonal[i] = 0;
		}
	}

	public void print() {
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if (data[i][j] == 0)
					System.out.print('O');
				else
					System.out.print('@');
			}
			System.out.println();
		}
		System.out.println();
	}

	public void qu() {
		qu(0);
	}

	public ArrayList<Integer[][]> qu(int row) {
		ArrayList<Integer[][]> result = new ArrayList<Integer[][]>();
		for (int i = 0; i < count; i++) {
			if (col[i] != 1 && principalDiagonal[i - row + count - 1] != 1
					&& slaveDiagonal[row + i] != 1) {
				data[row][i] = 1;
				col[i] = 1;
				principalDiagonal[i - row + count - 1] = 1;
				slaveDiagonal[row + i] = 1;
				if (row < count - 1)
					result.addAll(qu(row + 1));
				else {
					result.add(data);
					print();
					return result;
				}
				// undo
				data[row][i] = 0;
				col[i] = 0;
				principalDiagonal[i - row + count - 1] = 0;
				slaveDiagonal[row + i] = 0;
			}
		}
		return result;
	}
}
