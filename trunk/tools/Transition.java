
public class Transition {

	private String begin;
	private String end;
	private char label;
	
	public Transition(String _begin, String _end, char _label){
		this.begin = _begin;
		this.end = _end;
		this.label = _label;
	}
	
	public String getBegin(){
		return begin;
	}
	
	public String getEnd(){
		return end;
	}
	
	public char getLabel(){
		return label;
	}
}
