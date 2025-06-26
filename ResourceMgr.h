#pragma once
#include <unordered_map> 
#include <vector>
// ���� �����̳� ��template T �� Value  findŽ���� ȿ������, ���� ���� 
// unordered�������� ��
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
	// �ε� ���а�츦 ���� bool
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
		// find �� t ���� ������ ã�� �� �ִ�.
		if (it == resources.end())
		{
			return false;

		}
		delete it->second;
		//Load�� new T�� ����� ��
		resources.erase(it);
		//�����̳ʿ��� ����� ��
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
			//���� �߻� ��밡��
		}
		return *(it->second);
	}
	//&�� �޴� ���� �״�� ����ϱ� ����, ���ϰ��

};

template<typename T>
T ResourceMgr<T>::Empty;

