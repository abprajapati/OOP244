
#ifndef LBlShape_H_
#define LBlShape_H_

#include <iostream>
#include "Shape.h"

namespace sdds{

	class LblShape : public Shape
	{
		char* m_label = nullptr;

	protected:

	   char* label()const;

	public:

		LblShape();
		LblShape(const char*);
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream&);

	};
}
#endif // !LBlShape_H_
