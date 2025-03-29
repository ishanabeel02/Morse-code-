# include <iostream>
# include <cstdlib>
# include <time.h>
# include <string.h>
# include <windows.h>
using namespace std;
//Morse Code Game
class Morse
{
	private:
		//Morse Code array
	string morseCode[37] = 
	{
     " ", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
	 "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
	"--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..","----."};
	
	//Alphabet array
	char Alphabets[37] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
	'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	
	public:
		
	void deciphermessage(string msg)
	{
	    // Deciphered message storage
	    string deciphered_msg;
	    string c = ""; 
	    int len = msg.length();
	
	    for (int i = 0; i < len; i++)
	    {
	        if (msg[i] != ' ') 
	        {
	            c += msg[i];
	        } 
	        else 
	        {
	            // Convert Morse sequence to text
	            for (int j = 0; j < 36; j++)
	            {
	                if (c == morseCode[j])
	                {
	                    deciphered_msg += Alphabets[j];
	                    break;
	                }
	            }
	            c = ""; // Reset 
	
	            if (i + 1 < len && msg[i + 1] == ' ')
	            {
	                deciphered_msg += " ";
	                i++; // Skip extra space
	            }
	        }
	    }
	

	    if (!c.empty())
	    {
	        for (int j = 0; j < 36; j++)
	        {
	            if (c == morseCode[j])
	            {
	                deciphered_msg += Alphabets[j];
	                break;
	            }
	        }
	    }
	
	    // Display the results
	    cout << "The Original Message is: \n = " << msg << endl;
	    cout << "The Deciphered Message is: \n = " << deciphered_msg << endl;
	}
		string Ciphermessage(string msg)
		{
		
		    //Message to cipher
		    string ciphered_msg;
		    string ciphered_msg_with_blanks;
		   
		    
		    //Find the lenght of string
		    int len = msg.length();
		    
		    //Using loop to covert into Uppercasing
		    for(int i = 0; i < len; i++)
		    {
		        char c = msg[i];
		        
			   	    if(islower(c))
				     	{
				   		msg[i] = toupper(c);
				    	}
			}
			
			//2nd Loop to covert the msg to morse code
			for(int i = 0; i < len; i++)
		    {
		       	char c = msg[i];
				 for(int i = 0; i < 36; i++)
				{   
					if(c == Alphabets[i])
					{
						ciphered_msg_with_blanks += morseCode[i] + " | ";
						ciphered_msg += morseCode[i];
					}
				}
				ciphered_msg += " ";
			}
			
			//Displaying the msg
		 	cout << "The Original Message is: \n =  " << msg << endl;
		 	cout << "The ciphered message is: \n =  " << ciphered_msg << endl;
		 	cout << "The ciphered message with blanks to understand: \n =  " << ciphered_msg_with_blanks << endl;
		 	return ciphered_msg;
		
		}
		void displayBeat(int beatLevel) 
		{
		    cout << "[";
		    for (int i = 0; i < beatLevel; i++) 
			{
		        cout << "#"; // Beat bar
		    }
		    for (int i = beatLevel; i < 20; i++) 
			{
		        cout << " ";
		    }
		    cout << "]" << endl;
		}
		void PlayMorseCode(string morse)
		{
		    for (int i = 0; i < morse.length(); i++)
		    {
		        if (morse[i] == '.')
		        {
		            Beep(1000, 300); // Dot sound
		 			int beat = rand() % 20 + 1;
				    displayBeat(beat);
				    Sleep(200);  
		        }
		        else if (morse[i] == '-')
		        {
		            Beep(1000, 900); // Dash sound
		            int beat = rand() % 20 + 1;
				    displayBeat(beat);
				    Sleep(200); 
		        }
		        Sleep(200); // Small pause between each sound
		    }
		}
		
};

int main()
{
    cout << "\t\t\t==============================================================" << endl;
    cout << "\t\t\t\t    M O R S E    C O D E   C O N V E R T O R" << endl;
    cout << "\t\t\t==============================================================" << endl;

    string message = "";
    string cipher;
    srand(time(0));
    Morse m;
    int option;

    while (true)
    {
        cout << "\n\nPress the corresponding number to make your selection." << endl;
        cout << "\t\t==========================================" << endl;
        cout << "\t\t|| 1. Translate message to Morse code   ||" << endl;
        cout << "\t\t|| 2. Translate Morse code              ||" << endl;
        cout << "\t\t|| 3. Play Morse code                   ||" << endl;
        cout << "\t\t|| 4. Exit                              ||" << endl;
        cout << "\t\t==========================================" << endl;
        cout << "Enter your option: ";
        cin >> option;

        if (option == 4)
        {
            cout << "Exiting the program..." << endl;
            break;
        }
        else if (option == 1)
        {
            cout << "Enter the message you want to cipher: ";
            cin.ignore();
            getline(cin, message);
            cipher = m.Ciphermessage(message);
        }
        else if (option == 3)
        {
            if(message == "")
            {
            	cout << "Enter the message you want to cipher: ";
	            cin.ignore();
	            getline(cin, message);
	            cipher = m.Ciphermessage(message);
			}
			cout << "\n\nPlaying Morse Code Sound..." << endl;
			m.PlayMorseCode(cipher);
        }
        else if (option == 2)
        {
            if(cipher == "")
            {
            	cout << "Enter the message you want to decipher: ";
	            cin.ignore();
	            getline(cin, message);
	            m.deciphermessage(message);
			}
			else
			{
				m.deciphermessage(cipher);
			}		
        }
        else
        {
            cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}
				 

