#ifndef INCLUDED_CORE_DELETEUTIL_H
#define INCLUDED_CORE_DELETEUTIL_H

template <typename T>
inline void SafeDelete(T*& x)
{
	delete x;
	x = nullptr;
}

template <typename T>
inline void SafeDeleteArray(T*& x)
{
	delete[] x;
	x = nullptr;
}

template <typename T>
inline void SafeRelease(T*& x)
{
	if (x)
	{
		x->Release();
		x = nullptr;
	}
}

#endif // #ifndef !INCLUDED_CORE_DELETEUTIL_H
