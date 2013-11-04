
#include <FileReader.hh>
#include <fstream>
#include <sstream>
#include <iostream>
#include <fstream>

void FileReader::registerIntParameter(const std::string &key, int init)
{
   _intParameters[key] = init;
}

void FileReader::registerRealParameter(const std::string &key, real init)
{
   _realParameters[key] = init;
}

void FileReader::registerStringParameter(const std::string &key, const std::string &init)
{
   _stringParameters[key] = init;
}

void FileReader::setParameter(const std::string &key, const std::string &in)
{
   _stringParameters[key] = in;
}

void FileReader::setParameter(const std::string &key, real in)
{
   _realParameters[key] = in;
}

void FileReader::setParameter(const std::string &key, int in)
{
   _intParameters[key] = in;
}


bool FileReader::readFile(const std::string &name)
{
   std::ifstream infile(name.c_str());
  if (infile.good()){
      while (!infile.eof()){
	std::string line, param;
	std::stringstream ss;
	getline(infile,line);
	line.assign(line.substr(0,line.find('#')));
	ss<<line;
	ss>>param;
	
	if(_intParameters.find(param) != _intParameters.end())
	{
	  ss >> _intParameters[param];
	}
	else if(_realParameters.find(param) != _realParameters.end())
	{
	  ss >> _realParameters[param];
	}
	else if(_stringParameters.find(param) != _stringParameters.end())
	{
	  ss >> _stringParameters[param];
	}
      }
      infile.close();
  }
  else{
      std::cerr<<"Error reading '"<<name<<"'"<<std::endl;
      return 0;
  }
  return true;
}



void FileReader::printParameters() const
{
   for(auto it = _intParameters.begin(); it != _intParameters.end(); ++it)
   {
     std::cout << it->first << "  " << it->second << std::endl;
   }
   for(auto it = _realParameters.begin(); it != _realParameters.end(); ++it)
   {
     std::cout << it->first << "  " << it->second << std::endl;
   }
   for(auto it = _stringParameters.begin(); it != _stringParameters.end(); ++it)
   {
     std::cout << it->first << "  " << it->second << std::endl;
   }
}


