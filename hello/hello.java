public class hello{

	public native void print();
	public static void main(String[] args){
		new hello().print();
	}
	static{
		System.loadLibrary("hellojni");
	}
}