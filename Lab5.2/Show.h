#ifndef SHOW_H
#define SHOW_H
#include <iostream>
#include <string>

class Show
{
public:
	Show();
	Show(std::string, std::string);
	std::string getTitle();
	void setTitle(std::string);
	std::string getDescription();
	void setDescription(std::string);
	void info();
	void details();
	virtual void play();
private:
	std::string title;
	std::string description;
};
#endif
