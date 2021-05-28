#include "Error.h"

Error::Error()
{
	messaage = "";
}

Error::Error(string m)
{
	messaage = m;
}

Error::~Error()
{
}

string Error::what()
{
	return messaage;
}

