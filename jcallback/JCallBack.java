/*
*call back java method in c
*/

public class JCallBack{
	private native void callMethod();

	private String str;
	private void callInJava(){
		System.out.println("Method in Java");
	}

	public String getStr(){
		return this.str;
	}
	public void setStr(String str){
		this.str = str;
	}
	public JCallBack(){}
	public JCallBack(String str){
		this.str = str;
	}

	public static int callStaticMethod(int k){
		System.out.println("Static method with parameter value " + k);
		return ++k;
	}

	public static void main(String[] args){
		JCallBack jc = new JCallBack();
		jc.callMethod();
	}

	static{
		System.loadLibrary("jcall");
	}
}