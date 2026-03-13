/* *************************************************************************************************************** */
/*   main.cpp                                                                                                      */
/*   By: lvan-bre                                                                   .,                             */
/*                                                                                 okxl                            */
/*                                                                                xkddo                            */
/*                                                                               kkxddo                            */
/*                                                                              lxxddol                            */
/*                                                                              xxdolol.                           */
/*                                                                             :kxdddddl                 .ox,      */
/*                                                                       ..,cdkOOkkkxdddd'      ;o.     ckkd,      */
/*                                                               .,:coxOOOkkkkkkkxxxxxddddo:...lxdl.   ckkxd.      */
/*                                                           ;oxOOOOkkxxkxxxxxxxxxxdddddodddxxxkkxxxdlckkxdd.      */
/*                                                        ,oOOOkkkkxxxdddxdddddddddddddoooooodooddddooooddooc      */
/*                                                      ;kkkkkxxxxxddoooooooooooooooooooooooooollooooooololll      */
/*                                                     oxodddddoooooolllllllolooooollloooollllolllllloooolccl;     */
/*                                                    'x:::cclccllllccccccccccclllclllllllllllllllll     .;;cl;    */
/*                                                    d;c::cc:cc:::;::c:c:cccccclccc:cccclllllll,         .:cl.    */
/*                                                      c;,;:;;::::;;::::c..,cccllcc:c;;:lloodk.                   */
/*                                                        'ooooooooodddxxkkkOOOkOOOOOOc:cclllloo'                  */
/*                                                           .XXXXXXXKKXXXXXXXXXXXXXXXkcccclcccllo                 */
/*                                                                 ,KKKKKXXXXXXXXXXXXK0.  .:ccllclll;.             */
/*                                                                                           .ccccccllc,.          */
/*                                                                                                 :::cl:          */
/*                                                                                                                 */
/* *************************************************************************************************************** */

#include "include.hpp"

int main ( void )
{
	using	std::cout;
	
	std::srand(time(NULL));
	
	span a(5);
	try {
		for (int i = 0; i < 5; i++)
			a.addNumber(rand() % 20);
		cout << a;
		cout << _WHITE << "The smallest number is : " << _CYAN << *std::min_element(a.getBeginIterator(), a.getEndIterator()) << "\n";
		cout << _WHITE << "The biggest number is : " << _CYAN << *std::max_element(a.getBeginIterator(), a.getEndIterator()) << "\n";
		cout << _WHITE << "The biggest span is : " << _CYAN << a.longestSpan() << "\n"; 
		cout << _WHITE << "The shortest span is : " << _CYAN << a.shortestSpan() << "\n\n";

		/* Error handling */

		cout << _WHITE << "Now testing error handling :\n\n";

		cout << _WHITE << "Adding a 6th number : ";
		a.addNumber(rand() % 20);
	}
	catch (std::runtime_error & e) {
		cout << _RED << "Exception : " << e.what() << std::endl;
	}

	span b(1);
	try {
		cout << _WHITE << "Longest span of 1 value vector : " <<b.longestSpan() << "\n";
	}
	catch (std::runtime_error & e) {
		cout << _RED << "Exception : " << e.what() << std::endl;
	}

	cout << "\n";

	cout << _WHITE << "Testing big_size spans (it's over 9000 !!!) :\n\n";

	int	big_size = 10000;
	span chonky(big_size);
	std::vector<int> buf;

	try {
		for (int i = 0; i < big_size; i++) {
			buf.push_back(rand());
		}
		chonky.addArray(buf.begin(), buf.end());
		cout << _WHITE << "The smallest number of the big chonky vector is : " 
			<< _CYAN << *std::min_element(chonky.getBeginIterator(), chonky.getEndIterator()) << "\n";
		cout << _WHITE << "The biggest number of the big chonky vector is : " 
			<< _CYAN << *std::max_element(chonky.getBeginIterator(), chonky.getEndIterator()) << "\n";
		cout << _WHITE << "The biggest span of the big chonky vector is : " << _CYAN << chonky.longestSpan() << "\n";
		cout << _WHITE << "The smallest span of the big chonky vector is : " << _CYAN << chonky.shortestSpan() << "\n";
	}
	catch (std::exception & e) {
		cout << _RED << "Exception : " << e.what() << _RESET << std::endl;
	}
}