/* *************************************************************************************************************** */
/*   MutantStack.hpp                                                                                               */
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

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <vector>

template < typename T >
class MutantStack : public std::stack<T> 
{

public:

	MutantStack ( void ) : std::stack<T>() {}
	MutantStack ( MutantStack const & other ) : std::stack<T>(other) {}
	~MutantStack ( void ) {}
	
	MutantStack & operator= ( MutantStack const & other ) {
		if ( this != &other )
			std::stack<T>::operator=(other);
		return ( *this );
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin ( void ) { return (std::stack<T>::c.begin()); }
	iterator end ( void ) { return (std::stack<T>::c.end()); }
	
	const_iterator begin ( void ) const { return (std::stack<T>::c.begin()); }
	const_iterator end ( void ) const { return (std::stack<T>::c.end()); }

	reverse_iterator rbegin ( void ) { return (std::stack<T>::c.rbegin()); }
	reverse_iterator rend ( void ) { return (std::stack<T>::c.rend()); }

	const_reverse_iterator rbegin ( void ) const { return (std::stack<T>::c.rbegin()); }
	const_reverse_iterator rend ( void ) const { return (std::stack<T>::c.rend()); }
};

// # include "MutantStack.tpp"

#endif