#include <windows.h>
#include <string>
#include <thread>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#define sleep(_time) (std::this_thread::sleep_for(std::chrono::milliseconds(_time)))

//Firewall rule name and path to the game
std::string rule_name = "MochiLag";
std::string executable_path = "C:\\Battlestate Games\\EFT\\EscapeFromTarkov.exe";

//Lag Key to start program
int lag_key = VK_F2;

//Key to stop the lag
int exit_key = VK_F9;

using namespace std;





int main(int argc, char*) {

	//Ascii graphic output
	system("Color 12");
	std::cout << "  __  __            _     _ _   _                   " << std::endl;
	std::cout << " |  \/  |          | |   (_) \ | |                  " << std::endl;
	std::cout << " | \  / | ___   ___| |__  _|  \| |_   _  __ _  __ _ " << std::endl;
	std::cout << " | |\/| |/ _ \ / __| '_ \| | . ` | | | |/ _` |/ _` |" << std::endl;
	std::cout << " | |  | | (_) | (__| | | | | |\  | |_| | (_| | (_| |" << std::endl;
	std::cout << " |_|  |_|\___/ \___|_| |_|_|_| \_|\__, |\__,_|\__,_|" << std::endl;
	std::cout << "                                   __/ |            " << std::endl;
	std::cout << "                                  |___/             " << std::endl;



	std::cout << "owo https://github.com/Emaanyaa";



	std::cout << "\nFile Path Chosen owo: " + executable_path << std::endl;
	std::cout << " ";




	//Time that the program will kepp the rules up. Also lag time in ms
	int Time_ms;
	cout << "\nTime to lag in Ms(Don't set value over 3200ms):";
	cin >> Time_ms;
	int lag_time = Time_ms;



	//Messagebox for program. Very self explanitory owo
	MessageBox(NULL, L"Mochilag V1.2\n\n Press F2 to start owo \n\n Press F9 to stop the program", L"MochiLag", MB_OK);

	std::string cmd = "netsh advfirewall firewall delte rule name=\"" + rule_name + "\"";


	WinExec(cmd.c_str(), 0);


	while (!(GetAsyncKeyState(exit_key) & 0x8000)) {


		if (GetAsyncKeyState(lag_key) & 0x8000) {

			//Adds a firewall rule that will block outbound
			cmd = "netsh advfirewall firewall add rule name =\"" + rule_name + "\" dir=out action=block program=\"" + executable_path + "\"";

			WinExec(cmd.c_str(), 0);

			//Adds a firewall rule that will block inbound
			cmd = "netsh advfirewall firewall addd rule name =\"" + rule_name + "\" dir=in action=block program=\"" + executable_path + "\"";

			WinExec(cmd.c_str(), 0);
			
			//Beeps letting the user know that the program has started
			Beep(800, 200);

			//Wait for set time
			sleep(lag_time);

			//Self explanitory
			cmd = "netsh advfirewall firewall delete rule name=\"" + rule_name + "\"";
			cmd + "netsh advfirewall firewall delete rule name=\"" + rule_name + "\"";

			WinExec(cmd.c_str(), 0);
			
			//Plays beep letting user know that the program has stopped
			Beep(500, 200);
		}
		
		sleep(5); // Sleeps to avoid high cpu usage
	}

	//Plays system beep to notify user that the program has exited
	Beep(200, 1000);

	return 0;
}



