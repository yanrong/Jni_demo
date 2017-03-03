/*
*Access java field member in c/c++
*/

public class JFieldMember{
	private String str;

	private native void accessField();
	public static void main(String args[]){
		JFieldMember fm = new JFieldMember();
		fm.str = new String("string field from java");
		fm.accessField();
		System.out.println("In Java fm.s = \" " + fm.str + "\"" );
	}

	static{
		System.loadLibrary("accessfield");
	}
}