/* *************************************************************************************************************** */
/*   span.cpp                                                                                                      */
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

span::span ( void ) : size_(0) {}

span::span ( span const & src ) : size_(src.size_) {std::copy(src.array_.begin(), src.array_.end(), array_.begin());}

span::span ( unsigned int N ) : size_(N) {array_.reserve(N);}

span::~span ( void ) {}

span &	span::operator= ( span const & src )
{
	if ( this != &src ) {
		size_ = src.size_;
		std::copy(src.array_.begin(), src.array_.end(), array_.begin());
	}
	return ( *this );
}

int	span::operator[] ( unsigned int index )
{
	if (index > size_)
		throw std::runtime_error("Out of bond index");
	return (array_.at(index));
}

void	span::addNumber ( int const value)
{
	if (array_.size() == size_)
		throw std::runtime_error("Couldn't add another number to vector");
	array_.push_back(value);
}

int span::get_size ( void ) const {return (size_);}

int	span::get_n_element ( int n ) const {return (array_.at(n));}

std::vector<int>::iterator	span::getBeginIterator ( void )
{return (array_.begin());}

std::vector<int>::iterator	span::getEndIterator ( void )
{return (array_.end());}

int span::longestSpan ( void ) const 
{
	if (size_ < 2)
		throw std::runtime_error("Not enough elements");
	return (*std::max_element(array_.begin(), array_.end()) - *std::min_element(array_.begin(), array_.end()));
}

int span::shortestSpan ( void ) const
{
	if (size_ < 2)
		throw std::runtime_error("Not enough elements");
	
	std::vector<int>			sorted = array_;

	std::sort(sorted.begin(), sorted.end());	

	int							res = MAX_VALUE;
	int							tmp = 0;

	for ( std::vector<int>::iterator itl = sorted.begin(); itl + 1 != sorted.end(); itl++ ) {
		tmp = *(itl + 1) - *itl;
		if ( tmp < res )
			res = tmp;
	}

	return (res);
}

std::ostream &	operator<< ( std::ostream & o, span const & src )
{
	o << _WHITE << "Size is : " << _CYAN << src.get_size() << "\n";
	o << _WHITE << "Elements are : " << _CYAN;
	for (int i = 0; i < src.get_size(); i++)
		o << src.get_n_element(i) << " ";
	o << std::endl;
	return (o);
}