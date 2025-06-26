#pragma once
#include <unordered_map> 
#include <vector>
// 연관 컨테이너 앞template T 뒤 Value  find탐색이 효율적임, 양이 많음 
// unordered무작위로 들어감
#include <string>
#include "Singleton.h"

template <typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;

protected:
	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		for (auto pair : resources)
		{
			delete pair.second;
		}
		resources.clear();
	}

	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr* operator=(const ResourceMgr&) = delete;

	std::unordered_map<std::string, T*> resources;

	static T Empty;

public:
	// 로딩 실패경우를 위해 bool
	bool Load(const std::string& id)
	{
		auto it = resources.find(id);
		if (it != resources.end())
		{
			std::cout << "test11" << std::endl;
			return false;
		}

		T* res = new T();
		bool success = res->loadFromFile(id);
		if (!success)
		{
			return false;
		}

		resources.insert({ id, res });

		return true;
	}

	void Load(const std::vector<std::string>& ids)
	{
		for (auto id : ids)
		{
			Load(id);
		}
	}

	bool Unload(const std::string& id)
	{
		auto it = resources.find(id);
		// find 에 t 값을 넣으면 찾을 수 있다.
		if (it == resources.end())
		{
			return false;

		}
		delete it->second;
		//Load의 new T를 지우는 것
		resources.erase(it);
		//컨테이너에서 지우는 것
		return true;
	}

	void Unload(const std::vector<std::string>& ids)
	{
		for (auto id : ids)
		{
			Unload(id);
		}
	}


	T& Get(const std::string& id)
	{
		auto it = resources.find(id);
		if (it == resources.end())
		{
			return Empty;
			//예외 발생 사용가능
		}
		return *(it->second);
	}
	//&로 받는 이유 그대로 사용하기 위해, 파일경로

};

template<typename T>
T ResourceMgr<T>::Empty;

