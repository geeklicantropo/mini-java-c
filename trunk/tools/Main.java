import java.io.BufferedWriter;
import java.io.FileWriter;
import java.util.ArrayList;

import org.w3c.dom.Document;


public class Main {
	
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Document doc = XMLParser.readXMLFile("/home/barbara/Desktop/DFA_compiler/TokenAutomaton.xml");
		
		ArrayList<State> al = XMLParser.getStateList(doc);
		
		/** create state enum **/
		String stateEnum = "enum State {\n";
		
		for(int i=0; i<al.size(); i++){
			stateEnum += "\t";
			stateEnum += al.get(i).getName();
			stateEnum += ",\n";
		}
		stateEnum += "\tERR\n};";
		
		/** create list with final states **/
		String fStates = "return ";
		String app = "";
		for(int i=0; i<al.size(); i++){
			if(al.get(i).isAccepting()){
				fStates += app + "state == " + al.get(i).getName();
				app = " || ";
			}
		}
		fStates += ";";
		
		/** starting state **/
		String sState = "return ";
		for(int i=0; i<al.size(); i++){
			if(al.get(i).isStart()){
				sState += "state == Scanner::"+al.get(i).getName()+";";
			}
		}
		
		/** derive transitions **/
		ArrayList<Transition> tl = XMLParser.getTransitionList(doc);
		
		String transitionFunction = "switch (current) {\n";
		
		/** iterate over all states **/
		for(int i=0; i<al.size(); i++){
			String name = al.get(i).getName();
			
			transitionFunction += "\tcase "+name+":\tswitch (c) {\n";
			
			/** compose list of all outgoing transitions from the current state **/
			String alternative = "";
			for(int j=0; j<tl.size(); j++){
				if(tl.get(j).getBegin().equals(name)){
					
					/** ~ represents the default-case **/
					if(tl.get(j).getLabel() == '~') {
						alternative = tl.get(j).getEnd();
					} else if(tl.get(j).getLabel() == 'ü'){
						transitionFunction += "\t\t\t\tcase '\\n':\n\t\t\t\tcase '\\t':\n\t\t\t\tcase '\\r':\n\t\t\t\tcase ' ':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					} else if(tl.get(j).getLabel() == '#'){
						transitionFunction += "\t\t\t\tcase '*':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					} else if(tl.get(j).getLabel() == '"'){
						transitionFunction += "\t\t\t\tcase '+':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					} else if(tl.get(j).getLabel() == '§'){
						transitionFunction += "\t\t\t\tcase '(':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					} else if(tl.get(j).getLabel() == '$'){
						transitionFunction += "\t\t\t\tcase ')':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					} else {
						transitionFunction += "\t\t\t\tcase '"+tl.get(j).getLabel()+"':\treturn Scanner::"+tl.get(j).getEnd()+";\n";
					}
				}
			}
			if(!alternative.equals(""))
				/** alternative is the state that shall be entered in the else-case **/
				transitionFunction += "\t\t\t\tdefault:\treturn Scanner::"+alternative+";\n\t\t\t}; break;\n";
			else {
				transitionFunction += "\t\t\t\tdefault:\treturn Scanner::ERR;\n\t\t\t}; break;\n";
			}
		}
		transitionFunction += "\tdefault:\treturn Scanner::ERR;\n};";
		
		try{
			  // Create file 
			  FileWriter fstream = new FileWriter("TokenAutomaton.txt");
			  BufferedWriter out = new BufferedWriter(fstream);
			  out.write(stateEnum);
			  out.write("\n\n");
			  out.write(fStates);
			  out.write("\n\n");
			  out.write(sState);
			  out.write("\n\n");
			  out.write(transitionFunction);
			  //Close the output stream
			  out.close();
			  }catch (Exception e){//Catch exception if any
			  System.err.println("Error: " + e.getMessage());
			  }

	}

}
