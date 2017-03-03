/*
*JNI object arrry test demo
*/

public class JObjArr{
	private static native int[][] init2DArr(int col, int row);

	public static void main(String[] args){
		int [][] arr = init2DArr(5, 6); // col, row

		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				System.out.print(" " + arr[i][j]);
			}
			System.out.println();
		}
	}

	static {
		System.loadLibrary("objarr");
	}
}
