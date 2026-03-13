/* *************************************************************************************************************** */
/*   span.hpp                                                                                                      */
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

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

# define MAX_VALUE 2147483647

class span 
{

public:

	span ( void );
	span ( span const & );
	span ( unsigned int );
	~span ( void );

	span &	operator= ( span const & );
	int		operator[] ( unsigned int );

	int							get_size ( void ) const;
	int							get_n_element ( int ) const;
	std::vector<int>::iterator	getBeginIterator ( void );
	std::vector<int>::iterator	getEndIterator ( void );

	void						addNumber ( int const );
	void						addArray ( std::vector<int>::iterator, 
		std::vector<int>::iterator );
	int							shortestSpan ( void ) const;
	int							longestSpan ( void ) const;

private:

	unsigned int		size_;
	std::vector<int>	array_;

};

std::ostream & operator<< ( std::ostream & , span const & );

#endif