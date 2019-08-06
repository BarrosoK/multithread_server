/*
 * Author: pedrito.
 * Date: 06/08/19
 */

#ifndef SERVERinstance_H
#define SERVERinstance_H

#include <iostream>

template <typename T>
class Singleton
{
	protected:
		Singleton () { }
		~Singleton () { std::cout << "destroying singleton." << std::endl; }

	public:
		static T *getInstance ()
		{
			if (NULL == instance)
			{
				instance = new T;
			}
			return (static_cast<T*> (instance));
		}

		static void kill ()
		{
			if (NULL != instance)
			{
				delete instance;
				instance = NULL;
			}
		}

	private:
		static T *instance;
};

template <typename T>
T *Singleton<T>::instance = NULL;

#endif //SERVERinstance_H
