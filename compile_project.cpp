#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;
int main(){
    char* env_var = "GDK";
    char* env_val;
    env_val = getenv(env_var);
    if(env_val==NULL){
        cout<<"Error! SGDK Directory was not detected!"<<endl;
        cout<<"Variable 'GDK' was not found in environment variables list!"<<endl;
        cout<<"You need to create an environment variable called GDK and set it to 'YOUR_SGDK_PATH'"<<endl;
        cout<<"For example: C:\\sgdk"<<endl;
        exit(-1);
    }
    cout<<"Detected SGDK Directory: "<<env_val<<endl;
    cout<<"Generating Build command..."<<endl;

    string command = (string)env_val+"\\bin\\make -f "+(string)env_val+"\\makefile.gen"+'\0';
    cout<<"Generated comand: "<<command;
    WinExec(command.c_str(), 1);
    system("pause");
    return 0;
}
