#include <iostream>             //I20-2392
#include <fstream>             //UzairAsif
#include <string>             //Stream Cipher A2 Part 2 
#include <ctime>
#include <cmath>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;


int A[93];//Array A

int B[84];//Array B

int C[111];//Array C

int Key[28];

int Count = 0;


//Function For File Reading 
//Returns value in string


string Read_File()
{
    string Text;
    ifstream File("Plaintext.txt");

    if (File.is_open())
    {
        getline(File, Text);//Taking data from fill
    }                       // Storing it in a variable
    else
    {
        cout << "Reading file unsuccessful\n\n";
        
    }

    return Text;

}
string strToBinary(string s)
{
    int n = s.length();
    string bin2 = "";

    for (int i = 0; i <= n; i++)
    {
        // convert each char to
        // ASCII value
        int val = int(s[i]);
        
        // Convert ASCII value to binary
        string bin = "";
        while (val > 0)
        {
            (val % 2) ? bin.push_back('1') :
                bin.push_back('0');
            val /= 2;
        }
        reverse(bin.begin(), bin.end());
        bin2 += bin;
        
        
    }
    return bin2;
}
void intialise()
{
    //Intialisng Array A
    for (int i = 0; i < 93; i++)
    {
        A[i] = 0 + (rand() % 2);
    }
    //Intialisng Array B
    for (int i = 0; i < 84; i++)
    {
        B[i] = 0 + (rand() % 2);
    }
    //Intialisng Array C
    for (int i = 0; i < 111; i++)
    {
        C[i] = 0 + (rand() % 2);
    }

}
int key_generation()
{
    // Implementing Cipher//

    int temp1, temp2, temp3;
    int FF1 = A[90] & A[89];
    temp1 = A[65] ^ FF1 ^ A[92];
    int FF2 = B[82] & B[81];
    temp2 = FF2 ^ B[68] ^ B[83];
    int FF3 = C[108] & C[109];
    temp3 = FF3 ^ C[65] ^ C[110];
    A[0] = temp3 ^ A[68];
    B[0] = temp1 ^ B[77];
    C[0] = temp2 ^ C[86];

    //Key that is to be returned
    int K = ((temp1 ^ temp2) ^ temp3);//Key generated
    //Shifting to Right
    for (int i = 92; i > 0; i--)
    {
        A[i] = A[i - 1]; //Right shift for Register A
    }
    A[0] = temp3 ^ A[68];//Filling Index 0 of A
    for (int i = 83; i > 0; i--)
    {
        B[i] = B[i - 1];//Right shift for Register B
    }
    B[0] = temp1 ^ B[77];//Filling Index 0 of B
    for (int i = 110; i > 0; i--)
    {
        C[i] = C[i - 1];//Right shift for Register C
    }
    C[0] = temp2 ^ C[86];//Filling Index 0 of C
    return K;

}

int main()
{
    // int input_data[288];
    // for (int i = 0; i <= 288; i++)
    // {
    //     input_data[i] = A[i] = 0 + (rand() % 2);
    // }
     //cout << "Reading From File\n";
    
    //cin >> input_data[i]
    string T = Read_File();//Storing Text from fileto variable
    //Run Time:
    //int K_L = T.length();
    if (T != "\0")
    {
    cout << "Plaintext:: " << Read_File() << endl;
    cout << "\nIntialising Cipher.....\n";
    intialise();
    Sleep(2000);
    cout << "\nGenerating Key\n";
    Sleep(2000);
    cout << "\n\nKey Stream :: ";

    //int *Key = new int (K_L);//KEY 


    for (int i = 0; i < T.length(); i++)
    {
        Key[i] = key_generation();
        cout << key_generation();
    }
    //int num;
    //num = std::stoi(T);
    char x[28];
    for (int i = 0; i < T.length(); i++)
    {
        x[i] = T.at(i);
    }
    cout << endl;
    string T2=strToBinary(T);
    string enc = "";
    string dec = "";
    int encrypted[28];
    for (int i = 0; i < 28; i++)
    {
        encrypted[i] = T2[i] ^ Key[i]; //Encrypting plain Key
        enc += encrypted[i];
    }
    Sleep(2000);
   // cout << "\n\nEncrypyted text :: "<<enc;
    cout << "\n\nEncrypyted text :: ";
    for (int i = 0; i < 28; i++)
    {
        char ch = (char)encrypted[i];
        cout << ch;
       
        //cout<<encrypted[i];
    }
    int decrypted[28];
    for (int i = 0; i < 28; i++)
    {
        decrypted[i] = encrypted[i] ^ Key[i];//Decrypting the encrypted text
        dec += decrypted[i];
    }
    Sleep(2000);
    cout << "\n\nDecrypyted text :: ";
    for (int i = 0; i < 28; i++)
    {
        char ch = (char)decrypted[i];
        cout << ch;
        //cout << decrypted[i];
    }
    cout << endl << endl;
    }
    else
    {
        cout << "An Error has occurred\n";
    }

}

