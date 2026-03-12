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
	
	srand(time(NULL));

	MutantStack<int> a;
	for (int i = 0; i < 10; i++)
		a.push(rand() % 300);
	cout << _WHITE << "10 random numbers " << _CYAN;
	for (MutantStack<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	cout << "\n";

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << _WHITE << "Mstack top : " << _CYAN << mstack.top() << std::endl; // SHOULD PRINT 17
	mstack.pop();
	std::cout << _WHITE << "Mstack size : " << _CYAN << mstack.size() << std::endl; // SHOULD PRINT 1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	cout << _WHITE << "Mstack content : " << _CYAN;
	while (it != ite) // SHOULD PRINT 5 3 5 737 0 
	{
	std::cout << *it << " ";
	++it;
	}
	cout << std::endl;
	
	const MutantStack<int> b(mstack);
	MutantStack<int>::const_reverse_iterator rcit = b.rbegin();
	cout << _WHITE << "Mstack const reverse iterators : " << _CYAN;
	while (rcit != b.rend()) {
		cout << *rcit << " ";
		rcit++;
	}
	cout << "\n";
	cout << _PURPLE << "MutantStack inherits from std::stack so std::stack<int> s(mstack) works !" << std::endl;
	std::stack<int> s(mstack);
	return 0;
}