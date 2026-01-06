#include <fstream>
#include <iostream>
#include <string>

void checkLine(std::string &line, std::string S1, std::string S2)
{
  size_t f = 0;
  while ((f = line.find(S1, f)) != std::string::npos)
  {
    line.erase(f, S1.length());
    line.insert(f, S2);
  }
}

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    std::cout << "This program takes three parameters in the following order: a filename and two strings." << std::endl;
    return(0);
  }
  std::string S1 = argv[2];
  std::string S2 = argv[3];
  std::string filename = argv[1];
  std::string filepath = "CPP_01/ex04/" + filename;
  std::ifstream ifile(filepath.c_str());
  if (!ifile)
  {
    std::cerr << "Failed to open: " << filename << std::endl;
    return (1);
  }
  std::string replacedFile = "CPP_01/ex04/" +  std::string(argv[1]) + ".replace";

  std::ofstream rfile(replacedFile.c_str());
  
  if (!rfile)
  {
    std::cerr << "Failed to creat: " <<  replacedFile << std::endl;
    ifile.close();
    return (1);
  }
  
  std::string line;
  while (std::getline(ifile, line))
  {
    checkLine(line, S1, S2);
    rfile << line;
    if(!ifile.eof())
      rfile << std::endl;
  }
  ifile.close();
  rfile.close();
}
