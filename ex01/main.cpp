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
	std::srand(time(NULL));
	
	span a(5);
	try {
		for (int i = 0; i < 5; i++)
			a.addNumber(rand() % 20);
		std::cout << _WHITE << a;
		std::cout << _WHITE << "The min is : " << _CYAN << *std::min_element(a.getBeginIterator(), a.getEndIterator()) << "\n";
		std::cout << _WHITE << "The max is : " << _CYAN << *std::max_element(a.getBeginIterator(), a.getEndIterator()) << "\n";
		std::cout << _WHITE << "The biggest span is : " << _CYAN << a.longestSpan() << "\n"; 
		std::cout << _WHITE << "The shortest span is : " << _CYAN << a.shortestSpan() << "\n";

		/* Error handling */

		std::cout << _WHITE << "Adding a 6th number : ";
		a.addNumber(rand() % 20);
	}
	catch (std::runtime_error & e) {
		std::cout << _RED << "Exception : " << e.what() << std::endl;
	}

	span b(1);
	try {
		std::cout << _WHITE << "Longest span of 1 value vector : " <<b.longestSpan() << "\n";
	}
	catch (std::runtime_error & e) {
		std::cout << _RED << "Exception : " << e.what() << std::endl;
	}

	std::cout << "\n";

	int	big_size = 10000;
	span chonky(big_size);
	try {
		for (int i = 0; i < big_size; i++) {
			chonky.addNumber(rand());
		}
		std::cout << _WHITE << "The biggest span of the big chonky vector is : " << _CYAN << chonky.longestSpan() << "\n";
		std::cout << _WHITE << "The smallest span of the big chonky vector is : " << _CYAN << chonky.shortestSpan() << "\n";
	}
	catch (std::exception & e) {
		std::cout << _RED << "Exception : " << e.what() << _RESET << std::endl;
	}
}