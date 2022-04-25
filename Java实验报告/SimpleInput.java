package chapter4;
import java.io.*;
public class SimpleInput {
	public static String readString() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in),1);
		String string="";
		try {
			string = br.readLine();
		}catch(IOException ex) {
			System.out.println(ex);
		}
		return string;
	}
	public static int readInt() {
		return Integer.parseInt(readString());
	}
	public static double readDouble() {
		return Double.parseDouble(readString());
	}
	public static byte readByte() {
		return Byte.parseByte(readString());
	}
	public static short readShort() {
		return Short.parseShort(readString());
	}
	public static long readLong() {
		return Long.parseLong(readString());
	}
	public static float readFloat() {
		return Float.parseFloat(readString());
	}
}
