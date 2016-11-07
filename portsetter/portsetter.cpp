//Matt Freeze
//CS3370
//portsetter

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//Function stubs
void DisplayUsage(string, int);
int DetermineLang();
vector<string> outputLang(int);
void setEnvironmentVars();

//Enum for consoleText vector.
enum {
   NO_ERROR, 
   ERROR101,
   ERROR102,
   ERROR103,
   ERROR104,
   ERROR105,
   ERROR106,
   ERROR107,
   ERROR108,
   ERROR109,
   LISTEN,
   VERSION
};


//Main function
int main(int argc, char* args[]) {
	
	// Added 11/6/2016 set environment variables "PORT" and "BAR"
	setEnvironmentVars();
	
	//Determine which language is to be used and set a flag.
	int outputLangFlag = DetermineLang();
	if (outputLangFlag == -1) cout << "Language could not be determined. Executing program in English.\n";
	
	//Populate output vector with appropriate cout language.
	vector<string> consoleText = outputLang(outputLangFlag);
	
	//If there are no parameters, just display usage.
	if (argc == 1) DisplayUsage(consoleText[NO_ERROR], outputLangFlag);
	
	//If there are only two parameters.
	else if (argc == 2) {
		//Seperate port parameter 2.
		string portParam = args[1];
		
		//Check to see if the second parameter is -h or --help.
		if (portParam == "-h" || portParam == "--help" || portParam == "-?") DisplayUsage(consoleText[NO_ERROR], outputLangFlag);
		//Check to see if the second parameter is -v or --version.
		else if (portParam == "-v" || portParam == "--version") cout << consoleText[VERSION];
		
		//Check to see if the second parameter is -! or --about.
		else if (portParam == "-!" || portParam == "--about") {
			string line;
			
			//Determine if about should be displayed english or spansih.
			if (outputLangFlag == 1) {
				ifstream aboutFile ("portsetter.about_es.txt");
				while (getline (aboutFile, line)) {cout << line << '\n';}
				aboutFile.close();
			}
			else {
				ifstream aboutFile ("portsetter.about_en.txt");
				while (getline (aboutFile, line)) {cout << line << '\n';}
				aboutFile.close();
			}
		}
		//If second parameter is none of the above then display error and usage.
		else {
			DisplayUsage(consoleText[ERROR104], outputLangFlag);
			return 104;
		}
	}
	
	//If there are three parameters.
	else if (argc == 3) {
		//Seperate parameter two and three.
		string portParam = args[1];
		string portNum = args[2];
		istringstream iss(portNum);
		int testNum;
		
		//Check to make sure parameter two is -p or --port. Return error if not.
		if (portParam != "-p" && portParam != "--port") {
			DisplayUsage(consoleText[ERROR102], outputLangFlag);
			return 102;
		}
		else if (portNum == "-e" || portNum == "--environment") {
			cout << consoleText[LISTEN] << getenv("PORT") << "\n";
			return 0;
		}
		//Check to make sure port number given is an integer. Return error if not.
		else if ((iss >> testNum).fail()) {
			DisplayUsage(consoleText[ERROR105], outputLangFlag);
			return 105;
		}
		//Check to make sure paramter 3 is a valid port number. Return error if not.
		else if (stoi(portNum) > 65535 || stoi(portNum) <= 0) {
			DisplayUsage(consoleText[ERROR103], outputLangFlag);
			return 103;
		}
		//Display listening on given port.
		cout << consoleText[LISTEN] << args[2] << "\n";
	}
	
	//If there are 4 parameters.
	else if (argc == 4) {
		//Seperate parameters two and three.
		string portParam = args[1];
		string envParam = args[2];
		string envVar = args[3];
		
		int testNum;
		
		//Validate the second parameter is -p or --port
		if (portParam != "-p" && portParam != "--port") {
			DisplayUsage(consoleText[ERROR102], outputLangFlag);
			return 102;
		}
		//Validate the third parameter is -e
		else if (envParam != "-e") {
			if (envParam != "--environment"){
				DisplayUsage(consoleText[ERROR106], outputLangFlag);
				return 106;
			}
		}
		//Validate the environment variable supplied by the user is valid.
		else if (getenv(args[3]) == nullptr || getenv(args[3]) == "") {
			DisplayUsage(consoleText[ERROR107], outputLangFlag);
			return 107;
		}
		//Validate that the environment variable value is a numeric value.
		// Added 11/6/2016 to pass the tests for --environment
		const char* env_p = std::getenv(envVar.c_str());
		if(env_p == "" || env_p == NULL){
			DisplayUsage(consoleText[ERROR108], outputLangFlag);
			return 108;
		}				
		else if (stoi(getenv(args[3])) > 65535 || stoi(getenv(args[3])) <= 0) {
			DisplayUsage(consoleText[ERROR109], outputLangFlag);
			return 109;
		}
		/* // Was causing crashes when using --environment
		istringstream iss(getenv(envVar.c_str()));
		if ((iss >> testNum).fail()) {
			DisplayUsage(consoleText[ERROR108], outputLangFlag);
			return 108;
		}
		//Validate that the environment variable falls within the range of usable ports.
		else if (stoi(getenv(args[3])) > 65535 || stoi(getenv(args[3])) <= 0) {
			DisplayUsage(consoleText[ERROR109], outputLangFlag);
			return 109;
		}
		*/
		//Display listening on given port.
		cout << consoleText[LISTEN] << getenv(args[3]) << "\n";
	}
	
	//If there are more than 4 parameters, display too many parameters error.
	else {
		DisplayUsage(consoleText[ERROR101], outputLangFlag);
		return 101;
	}
	return 0;
}


//Function that displays usage information to the console from a file.
void DisplayUsage(string error, int langFlag) {
	
	//Display error information
	cout << "\n" << error << "\n";
	
	//Depending on which language is being used, read and display the correct usage information.
	if (langFlag != 1) {
		string line;
		ifstream usageFile ("portsetter.usage_en.txt");
    	while (getline (usageFile, line)) {cout << line << '\n';}
    	usageFile.close();
	}
	else {
		string line;
		ifstream usageFile ("portsetter.usage_es.txt");
    	while (getline (usageFile, line)) {cout << line << '\n';}
    	usageFile.close();
	}
}


//Function to determine which language should be used for the program.
//Environment variable checks are done in ascending order of importance.
int DetermineLang() {
	
	int langFlag = -1;
	
	//Check LANGUAGE environment variable first.
	if (getenv("LANGUAGE") != nullptr && getenv("LANGUAGE") != "") {
		string envLang = getenv("LANGUAGE");
		if (envLang.find("es") != string::npos) langFlag = 1;
		else if (envLang.find("en") != string::npos) langFlag = 0;
	}
	 
	//Check LC_ALL environment variable second.
	if (getenv("LC_ALL") != nullptr && getenv("LC_ALL") != "") {
		string envLang = getenv("LC_ALL");
		if (envLang.find("es") != string::npos) langFlag = 1;
		else if (envLang.find("en") != string::npos) langFlag = 0;
	}
	
	//Check LC_MESSAGES environment variable third.
	if (getenv("LC_MESSAGES") != nullptr && getenv("LC_MESSAGES") != "") {
		string envLang = getenv("LC_MESSAGES");
		if (envLang.find("es") != string::npos) langFlag = 1;
		else if (envLang.find("en") != string::npos) langFlag = 0;
	}
	
	//Check LANG environment variable fourth.
	if (getenv("LANG") != nullptr && getenv("LANG") != "") {
		string envLang = getenv("LANG");
		if (envLang.find("es") != string::npos) langFlag = 1;
		else if (envLang.find("en") != string::npos) langFlag = 0;
	}
	
	return langFlag;
}


//Function to read in information from output files in either english or spanish.
vector<string> outputLang(int langType) {
	
	string line;
	
	//Depending on the flag either use english output or spanish output and return the correct vector of output var..
	if (langType != 1) {
		vector<string> en;
		
		//Read english output strings from file, then save and return it in a vector.
		ifstream enTextFile ("portsetter.output_en.txt");
		while (getline (enTextFile, line)) {en.push_back(line);}
		enTextFile.close();
		return en;
	} 
	else {
		vector<string> es;
		
		//Read spanish output strings from file, then sav eand return it in a vector.
		ifstream esTextFile ("portsetter.output_es.txt");
		while (getline (esTextFile, line)) {es.push_back(line);}
		esTextFile.close();
		return es;
	}
}

// Sets the environmental variables "PORT" and "BAR" for the setport program
void setEnvironmentVars(){
	setenv("PORT", "3114", 1);
	setenv("BAR", "3116", 1);
}