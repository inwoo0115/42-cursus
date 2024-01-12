#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::ofstream	outfile;
	std::ifstream	infile;
	std::string		line;

	//예외 처리
	if (ac != 4 || std::strlen(av[1]) == 0 || std::strlen(av[2]) == 0)// || std::strlen(av[3]) == 0) 
	{
		std::cout << "Wrong arguments" << std::endl;
		return (0);
	}
	const	std::string	search_str(av[2]);
	const	std::string	replace_str(av[3]);
	std::string 		newfile(av[1]);
	newfile.append(".replace");

	infile.open(av[1]);
	if (!infile.is_open()) {
		std::cout << "Wrong file" << std::endl;
		return (0);
	}
	outfile.open(newfile);
	if (!outfile.is_open()) {
		std::cout << "Opne error" << std::endl;
		return (0);
	}
	while (1) {
		size_t	i = 0;
		std::getline(infile, line);
		if (infile.fail())
			break;
		else if (!infile.eof())
			line.append("\n");
		while (1) {
			i = line.find(search_str, i);
			if (i == std::string::npos)
				break;
			line.erase(i, search_str.length());
			line.insert(i, replace_str);
			i += replace_str.length();
		}
		outfile << line;
	}
	return (0);
}