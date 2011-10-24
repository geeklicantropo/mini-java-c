class Bottles {
	public static void main(String[] arg){
		int i = 99;
		while( i > 0 ){
			/*i bottles of beer on the wall, take one down ...*/
			System.out.println(-i*-1);
			/* 'parse' it around ... */
			i = i + (-1);
			/*... well, i bottles of beer on the wall ...*/
		}
	}
}