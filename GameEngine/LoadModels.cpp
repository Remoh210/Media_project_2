#include "globalOpenGLStuff.h"
#include "globalStuff.h"		// for g_pRogerRabbit

#include "cVAOMeshManager.h"
#include "cMeshObject.h"


#include <iostream>

// Loading models was moved into this function
void LoadModelTypes( cVAOMeshManager* pTheVAOMeshManager, GLuint shaderProgramID )
{

	sModelDrawInfo chest_bottomInfo;
	chest_bottomInfo.meshFileName = "chest_bottom.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	chest_bottomInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(chest_bottomInfo, shaderProgramID);

	sModelDrawInfo chest_topInfo;
	chest_topInfo.meshFileName = "chest_top.ply";	
	chest_topInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(chest_topInfo, shaderProgramID);

	sModelDrawInfo sphereInfo;
	sphereInfo.meshFileName = "Sphere_320_faces_xyz_n.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(sphereInfo, shaderProgramID);

	sModelDrawInfo roomInfo;
	roomInfo.meshFileName = "room.ply";			// "Sphere_320_faces_xyz.ply";
	pTheVAOMeshManager->LoadModelIntoVAO(roomInfo, shaderProgramID);

	sModelDrawInfo skullInfo;
	skullInfo.meshFileName = "skull.ply";	// "MeshLab_Fractal_Terrain_xyz.ply";
	// Will alow me to update the vertex data in the mesh
	skullInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(skullInfo, shaderProgramID);

	sModelDrawInfo FireInfo;
	FireInfo.meshFileName = "assets/models/fire.ply";	
	FireInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(FireInfo, shaderProgramID);

	sModelDrawInfo SpeakerInfo;
	SpeakerInfo.meshFileName = "assets/models/speaker.ply";
	SpeakerInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(SpeakerInfo, shaderProgramID);

	sModelDrawInfo WolfInfo;
	WolfInfo.meshFileName = "assets/models/wolf.ply";
	WolfInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(WolfInfo, shaderProgramID);

	sModelDrawInfo GramophoneInfo;
	GramophoneInfo.meshFileName = "assets/models/gramophone.ply";	
	GramophoneInfo.bVertexBufferIsDynamic = true;
	pTheVAOMeshManager->LoadModelIntoVAO(GramophoneInfo, shaderProgramID);
	

	// At this point, mesh in in GPU
	std::cout << "Mesh was loaded OK" << std::endl;

	return;
}

	
// Loads the models we are drawing into the vector
void LoadModelsIntoScene( std::vector<cMeshObject*> &vec_pObjectsToDraw )
{


	{
		cMeshObject* pFire = new cMeshObject();
		pFire->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pFire->friendlyName = "bonfire";
		pFire->meshName = "assets/models/fire.ply";
		pFire->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pFire);
	}


	{
		cMeshObject* pSpeaker = new cMeshObject();
		pSpeaker->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pSpeaker->setUniformScale(0.2f);
		pSpeaker->friendlyName = "speaker";
		pSpeaker->meshName = "assets/models/speaker.ply";
		pSpeaker->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pSpeaker);
	}


	{
		cMeshObject* pWolf = new cMeshObject();
		pWolf->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pWolf->setUniformScale(2.0f);
		pWolf->friendlyName = "wolf";
		pWolf->meshName = "assets/models/wolf.ply";
		pWolf->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pWolf);
	}

	{
		cMeshObject* pGram = new cMeshObject();
		pGram->position = glm::vec3(0.0f, 0.0f, 0.0f);
		pGram->setUniformScale(100.0f);
		pGram->friendlyName = "gramophone";
		pGram->meshName = "assets/models/gamophone.ply";
		pGram->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pGram);
	}




	{
		cMeshObject* pSkull = new cMeshObject();
		pSkull->position = glm::vec3(0.0f, 50.0f, 0.0f);
		//pSkull->setSpecularColour(glm::vec3(1.0f, 0.4f, 0.1f));
		pSkull->setDiffuseColour(glm::vec3(1.0f, 0.4f, 0.1f));
		pSkull->setSpecularPower(100.0f);
		pSkull->friendlyName = "skull";
	//	pSkull->bIsInteractable = true;
		pSkull->meshName = "skull.ply";		
		pSkull->setUniformScale(1.5f);
		vec_pObjectsToDraw.push_back(pSkull);
	}





	{
		cMeshObject* pRoom = new cMeshObject();
		pRoom->position = glm::vec3(0.0f, 0.0f, 300.0f);
		//pSpider->postRotation = glm::vec3(0.0f, glm::radians(-20.0f), 0.0f);
	//	pRoom->objColour = glm::vec3(0.74f, 0.86f, 1.0f);
		pRoom->friendlyName = "room";
		pRoom->meshName = "room.ply";
		pRoom->setUniformScale(50.0f);
		pRoom->bIsVisible = true;
		vec_pObjectsToDraw.push_back(pRoom);
	}


	{
		cMeshObject* pChest_b = new cMeshObject();
		pChest_b->position = glm::vec3(-675.0f, -20.0f, 520.0f);
	//	pChest_b->objColour = glm::vec3(85 / 255.0f, 33 / 255.0f, 18 / 255.0f);
		//pChest_b->setUniformScale(0.9f);
		pChest_b->friendlyName = "chest_bottom";
		pChest_b->meshName = "chest_bottom.ply";
		vec_pObjectsToDraw.push_back(pChest_b);
	}

	{
		cMeshObject* pChest_top = new cMeshObject();
		pChest_top->position = glm::vec3(-740.0f, 30.0f, 505.0f);
	//	pChest_top->objColour = glm::vec3(85 / 255.0f, 33 / 255.0f, 18 / 255.0f);
		//pChest_top_b->setUniformScale(0.9f);
		pChest_top->friendlyName = "chest_top";
		pChest_top->meshName = "chest_top.ply";
		vec_pObjectsToDraw.push_back(pChest_top);
	}






	//cMeshObject* pRogerRabbit = NULL;





	{	// This sphere is the tiny little debug sphere
		cMeshObject* pDebugSphere = new cMeshObject();
		pDebugSphere->position = glm::vec3(0.0f, 0.0f, 0.0f);
	//	pDebugSphere->objColour = glm::vec3(0.0f, 1.0f, 0.0f);
		float scale = 30.0f;
		pDebugSphere->friendlyName = "DebugSphere";
		pDebugSphere->nonUniformScale = glm::vec3(scale, scale, scale);
		pDebugSphere->meshName = "Sphere_320_faces_xyz_n.ply";		
		pDebugSphere->bIsWireFrame = true;
		pDebugSphere->bIsVisible = false;

		vec_pObjectsToDraw.push_back(pDebugSphere);
	}


	// ENDOF: Updated physics object





	return;
}