#pragma once
#include <memory>

template <typename T> class superptr
{
private:
	std::shared_ptr<std::unique_ptr<T>> data;
public:
	superptr<T>(const std::shared_ptr<std::unique_ptr<T>>& ptr)
	{
		data = ptr;
	}
	superptr<T>(std::nullptr_t null)
	{
		data = null;
	}
	superptr<T>()
	{
		data = nullptr;
	}	
	T& operator*()
	{
		return **data;
	}
	std::unique_ptr<T>& operator->()
	{
		return *data;
	}
	void reset(T* t)
	{
		(*data).reset(t);
	}
	std::shared_ptr<std::unique_ptr<T>> get() const
	{
		return data;
	}
	bool operator==(const superptr<T>& t)
	{
		return *data == *t;
	}
	bool operator!=(const superptr<T>& t)
	{
		return !(operator==(t));
	}
	bool operator==(std::nullptr_t t)
	{
		return (data == t);
	}
	bool operator!=(std::nullptr_t t)
	{
		return !(data == t);
	}
	superptr<T>& operator=(std::nullptr_t t)
	{
		data = nullptr;
		return *this;
	}
	superptr<T>& operator=(const superptr<T>& t)
	{
		data = t.get();
		return *this;
	}
	superptr<T>& operator=(const std::shared_ptr<T>& t) = delete;
};