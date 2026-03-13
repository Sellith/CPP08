/* *************************************************************************************************************** */
/*   main.cpp                                                                                                      */
/*   By: lvan_bre                                                                   .,                             */
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
#include <algorithm>

template < typename T >
static void	printOneValue ( T value )
{std::cout << value << "\n";}

int main ( void )
{
	using	std::cout;

	cout << _YELLOW << "Testing error handling (empty container)\n";
	try {
		std::set<int> emptySet;
		easyfind (emptySet, 3);
	}
	catch (std::runtime_error &e) {
		cout << _RED << "Exception : " << e.what() << "\n";
	}
	cout << "\n";
	std::srand(time(NULL));

	std::set<int> ar;
	cout << _WHITE << ">> Inserting 10 random values between 0 and 10 \n\n";
	for (int i = 0; i < 10; i++) {
		ar.insert(rand() % 10);
	}

	cout << "Printing all inserted values : \n\n" << _CYAN;
	std::for_each(ar.begin(), ar.end(), printOneValue<int>);

	cout << _WHITE << "\nNow testing wich values is in the set :\n\n";
	for (int i = 0; i < 10; i++) {
		try {
			cout << i << " : " << _CYAN << *easyfind( ar, i );
			cout << _GREEN << ", value found." << _WHITE << std::endl;	
		}
		catch (std::runtime_error &e) {
			cout << _RED << e.what() << _WHITE << std::endl;
			}
	}
}