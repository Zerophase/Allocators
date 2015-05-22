//
// Created by zerophase on 5/21/15.
//
#ifndef ALLOCATORS_SINGLETON_H
#define ALLOCATORS_SINGLETON_H

template<typename T>
class Singleton
{
private:
	Singleton(const Singleton<T> &) = delete;
	Singleton &operator=(const Singleton<T> &) = delete;

public:
	Singleton() {}
	~Singleton() {}

	virtual T *Get() = 0;
	virtual void StartUp() = 0;
	virtual void ShutDown() = 0;
};


#endif //ALLOCATORS_SINGLETON_H
