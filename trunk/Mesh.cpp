#include "Mesh.h"
#include "Game.h"

Mesh::Mesh(void)
{
}

Mesh::Mesh(char* filename)
{
}

Mesh::~Mesh(void)
{
}

void Mesh::load(char* filename)
{
	dbLoadMesh(filename,Game::getMeshId());
}