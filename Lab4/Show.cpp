#include "Show.h"

Show::Show() :
	title("Show Title"),
	description("Show Description")
{
}

Show::Show(std::string title, std::string description) :
	title(title), description(description) {}

std::string Show::getTitle() {
	return this->title;
}

void Show::setTitle(std::string title) {
	this->title = title;
}

std::string Show::getDescription() {
	return this->description;
}

void Show::setDescription(std::string description) {
	this->description = description;
}

void Show::info() {
	std::cout << this->getTitle() << std::endl;
}

void Show::details() {
	std::cout << this->getTitle() << " - " << this->getDescription() << std::endl;
}

void Show::play()
{
}
