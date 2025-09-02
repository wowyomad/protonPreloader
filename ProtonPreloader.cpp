#include <string>
#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    std::string s(argv[0]);
    std::string config = "config.bat";
    std::string path = config;
    std::size_t pos = s.rfind('\\');

    if (pos != std::string::npos)
        path = '"' + s.substr(0,pos+1) + config + '"';

    for (int i=1; i<argc; i++)
        path+=" "+std::string(argv[i]);

    std::string command = "start \"Launcher\" cmd /c "+path;
    int result = system(command.c_str());
    if (result != 0)
    {
	std::cerr << "Command failed with code " << result << std::endl;
    }
    return 0;
}
