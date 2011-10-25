public Fib {
	public static void main( String[] args ) {
		Fib bif = new Fib();
		int res = bif.fib( 12 );
		System.out.println( res );
	}
	
	/* assert n >= 0 */
	int fib( int n ) {
		if( n <= 1 )
			return/*f(0)=0, f(1)=1*/n;
		return fib( n - 2 ) + fib(n - 1);
	}
}