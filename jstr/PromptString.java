public class PromptString{
	private static String str;
	public native void printStr(String str);
	public native String getStr();
	public static void main(String[] args){
		PromptString pstr =  new PromptString() ;
		pstr.printStr(new String("I from java"));
		str = pstr.getStr();
		System.out.println(str);
	}
	static{
		System.loadLibrary("strjni");
	}
}