class GCD
{
	public static void main(String[] argv)
	{
		int a = 1337;
		int b =  666;
		
		while (a != b)
		{
			if (a > b)
				a = a - b;
			else
				b = b - a;
		}
		
		System.out.println(a);
	}
}