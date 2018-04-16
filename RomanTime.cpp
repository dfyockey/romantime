#include <iostream>
#include <string>
#include <ctime>

/*
MIT License

Copyright (c) 2018 David Yockey

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

// Compilation...
// g++ -o RomanTime RomanTime.cpp

using std::string;

// itor - Distilled from code at https://stackoverflow.com/a/37609217
string itor(int i)
{
    string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    return X[(i%100)/10]+I[(i%10)];
}

int main(int argc, char* argv[])
{
	string rpad, lpad;
	
	time_t timenow = time(0);
	tm* timeparts = localtime(&timenow);
	
	int hours   = timeparts->tm_hour;
	int minutes = timeparts->tm_min;
	
	if(hours>12)
		hours-=12;
	else if(hours==0)
		hours=12;
	
	string rHours	= itor(hours);
	string rMinutes = itor(minutes);
	
	// Padding to keep hour/minute seperator (i.e. ":")
	// stationary in right-justified display...
	rpad = string( 7-rMinutes.length(), ' ' );
	
	// Padding to keep hour/minute seperator (i.e. ":")
	// stationary in left-justified display...
	lpad = string( 4-rHours.length(), ' ' );
	
	std::cout << lpad << rHours << ":" << rMinutes << rpad << std::endl;
	
	return 0;
}
