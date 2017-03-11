#include "ObjectManager.hpp"

#include <algorithm>

ObjectManager::ObjectManager()
{
	BaseEntity *null = new BaseEntity();

	num_entities += 1;
	null->m_id = num_entities;

	entities.push_back(null);
	selected = entities[0];

	logger::SILENT("ObjectManager constructed.");
}

ObjectManager::~ObjectManager()
{
	// this breaks things. don't do it.
	//for (size_t i = 0; i < entities.size(); i++)
		//delete &entities[i];

	logger::SILENT("ObjectManager deconstructed.");
}

void ObjectManager::createObject()
{
	BaseEntity *newEnt = new BaseEntity();
	num_entities += 1;
	newEnt->m_id = num_entities;

	entities.push_back(newEnt); // add it to the stack
	selectObject(entities.back());

	logger::DEBUG("creating new entity");
}

void ObjectManager::deleteObject(BaseEntity *ent)
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		if (ent == entities[i])
		{
			entities.erase(std::remove(entities.begin(), entities.end(), ent), entities.end());

			break;
		}
	}

	num_entities -= 1;
	selected = entities.front();

	logger::DEBUG("deleted entity");
}

inline void ObjectManager::selectObject(BaseEntity *ent)
{
	selected = ent;
}
