class Fac {

	public static void main( String[] args ) {
		int n = 8;
		int result = 1;
		while( n != 0 ) {
			result = n * result;
			n = n - 1;
		}
		System.out.println( result );
	}
}