
public class JArray{
	private native int sumArray(int []arr);
	private native void chgArray(int []arr);
	public static void main(String[] args){
		JArray ja = new JArray();

		int []arr = new int[10];
		for(int i = 0; i < 10; i++){
			arr[i] = i + 1;
		}

		int sum = ja.sumArray(arr);

		System.out.println("JNI Sum = " + sum);

		for(int i = 0; i < 10; i++){
			System.out.print(" " + arr[i]);
		}
		System.out.println();
		
	}

	static{
		System.loadLibrary("jarray");
	}
}