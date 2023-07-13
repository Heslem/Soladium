#pragma once

// ������������ ������ ������ ������.
#define SINGLETON(klass) klass();\
	klass(const klass&) = delete;\
	void operator=(const klass&) = delete;\
	public:\
	static klass& getInstance()\
	{ \
		static klass instance;\
		return instance;\
	}\
	~klass();\
	private: