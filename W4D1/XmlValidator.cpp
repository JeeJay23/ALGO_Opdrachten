#include "XmlValidator.h"
#include <sstream>
#include "StringStack.h"

XmlValidator::XmlValidator()
{
}

void XmlValidator::processTag(std::string toAdd)
{
	// check if string is entered
	if (toAdd.compare(stack.peek()) == 0) {
		// string are equal, remove item from stack
		stack.pop();
	}
	else {
		stack.push(toAdd);
	}
}

bool XmlValidator::validate(std::string xmlStr)
{
    std::stringstream stream(xmlStr);

    /* heel handig! maar wou hem toch op mijn eigen manier doen :)
    std::string sCopy = xmlStr;
    std::string sItem;
    int posLeft, posRight = 0;

    posLeft = sCopy.find("<", posRight);
    if (posLeft != -1)
        posRight = sCopy.find(">", posLeft);
    sItem = sCopy.substr(posLeft, posRight - posLeft + 1);
    */

    char c;
    while (stream >> c){
        if (c == '<'){
            // convert tag to string
            char buf[20];
            stream.get(buf, 20, '>');
            std::string toAdd(buf);
            if (buf[0] == '/')
                toAdd.erase(0, 1);

            processTag(toAdd);
        }
    }
    return stack.isEmpty();
}
