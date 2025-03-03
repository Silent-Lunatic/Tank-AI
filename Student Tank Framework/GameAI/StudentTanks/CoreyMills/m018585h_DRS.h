//------------------------------------------------------------------------
//  Author: Paul Roberts (2019)
//------------------------------------------------------------------------
#ifndef _M018585H_DRS_H
#define _M018585H_DRS_H

#include <SDL.h>
#include "m018585hCommons.h"
#include <vector>

//--------------------------------------------------------------------------------------------------

class m018585h_DRS
{
//--------------------------------------------------------------------------------------------------
public:
	m018585h_DRS(SDL_Renderer* renderer, TileType map[kMapWidth][kMapHeight]);
	~m018585h_DRS();

	bool FindPath(const Vector2D startPosition, const Vector2D endPosition, vector<Vector2D>* path);

//--------------------------------------------------------------------------------------------------
private:
	bool Search(Vector2D currentPosition, Vector2D targetPosition, bool orderOfRotation, vector<Vector2D>* path);
	vector<Vector2D>* EnhancePath(vector<Vector2D>* tempPathData);
	vector<Vector2D>* RefinePath(vector<Vector2D>* pathDataEnhanced);

	//return true if no obstruction
	bool Raycast(Vector2D startPos, Vector2D endPos);

	bool IsCellValid(Vector2D currentPosition);

	bool IsPositionInMapBounds(Vector2D position);
	bool IsMoveAllowed(Vector2D fromPos, Vector2D toPos);
	void SetMaxCost();
	void OutputCosts(Vector2D startPosition, Vector2D endPosition);

	void ResetCostArray();
	void ResetCollisionMap();
	void ResetCostArrayAndCollisionMap();

//--------------------------------------------------------------------------------------------------
private:
	SDL_Renderer*		mRenderer;
	float				mMapCosts[kMapWidth][kMapHeight];
	TileType			mMap[kMapWidth][kMapHeight];

	float				mLengthOfSearchSq;
	float				mSearchLength;
	float				mRefineLength;
	float				mRotationInDegrees;
	double				mStepSize;					//step size is the radians to rotate for each explosion.
	double				mRadian180;

	Vector2D			mMovedPos;
	Vector2D			mPositionToTry;
	Vector2D			mPolarAsCart;

	float				mMaxCost;
};
//--------------------------------------------------------------------------------------------------

#endif _PATHFINDER_DRS_H