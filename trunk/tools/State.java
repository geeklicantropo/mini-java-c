
public class State {
	
	private String name;
	private boolean accepting;
	private boolean start;
	
	public State(String _name, boolean _accepting, boolean _start){
		this.name = _name;
		this.accepting = _accepting; 
		this.start = _start;
	}
	
	public String getName(){
		return name;
	}
	
	public boolean isAccepting(){
		return accepting;
	}
	
	public boolean isStart(){
		return start;
	}
}
