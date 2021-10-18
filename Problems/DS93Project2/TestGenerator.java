import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Random;

public class Test1Generator {
	public static void main(String[] args) {
		int n= 100 * 1000;
		int m= 5000;
		Random rand= new Random();
		final int INT_LIMIT= 1000 * 1000 * 1000;
		boolean numbers[]= new boolean[INT_LIMIT];
		
		int theArray[]= new int[n];
		for( int i=0; i<n; i++ ){
			int r= rand.nextInt(INT_LIMIT);
			while( numbers[r]==true )
				r= rand.nextInt(INT_LIMIT);
			numbers[r]= true;
			theArray[i]= r;
		}
		
		PrintWriter writer= null;
		try {
			writer = new PrintWriter("C:\\Users\\Aria\\Desktop\\Project2\\Test1.txt", "UTF-8");
			writer.write(n + " " + m + "\r\n");
			for( int i=0; i<n; i++ )
				writer.write(theArray[i] + " ");
			writer.write("\r\n");
			for( int i=0; i<m; i++ ){
				int b= rand.nextInt(n);
				int e= rand.nextInt(n-b)+b;
				int k= rand.nextInt(e-b+1);
				writer.write(b + " " + e + " " + k + "\r\n");
			}
			writer.flush();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
}
