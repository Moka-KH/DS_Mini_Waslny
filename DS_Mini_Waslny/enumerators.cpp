#pragma once

enum addRoad_enum
{
	noCity1 = 1,
	noCity2 = 2,
	updatedRoad = 3,
	addedRoad = 4,

	success = updatedRoad || addedRoad,
	failure = noCity1 || noCity2
};