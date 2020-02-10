#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "drawable.hpp"

/*! \class Object
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Object : public Drawable
{
public:
	Object( int x, int y );
	virtual ~Object();

protected:
};

#endif //OBJECT_HPP
