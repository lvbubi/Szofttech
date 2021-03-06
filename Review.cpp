#include "Review.h"

string Review::getName() const
{
    return name;
}

string Review::getLabel() const
{
    return label;
}

string Review::getComment() const
{
    return comment;
}

void Review::print()
{
    cout<<label<<" - "<<name<<endl;
    cout<<comment<<endl;
}

Review::Review(const string &name, const string &label, const string &comment)
    :name(name),label(label),comment(comment)
{

}

bool Review::getChecked() {
	return this->checked;
}

void Review::setChecked(bool checked) {
	this->checked = checked;
}
