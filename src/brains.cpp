////////////////////////////////////////////////////////////////////////////////
// file: brains.cpp
// author: Radim Rehurek
// last update: 25.09.04
//
// specification of top-level agent behavior
//////////////////////////////////////////////////////////////////////////////////

#include <cstdio>

#include "ie.h"
#include "agent.h"
#include "agentbrainlib.h"
#include "prey.h"
#include "predator.h"

//////////////////////////////////////////////////////////////////////////////////
// predator's brain
IE_START (CPredator)

	GOAL (Wander)
		IF (SeesEnemy)   GOTO (Chase)

	GOAL (Chase)
		IF (Caught)     GOTO (Eat)
		IF (Exhausted)  GOTO (Replenish)

	GOAL (Eat)
		IF (Done)		GOTO (Wander)

	GOAL (Replenish)
		IF (Done)		GOTO (Wander);

IE_END
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
// prey's brain
IE_START (CPrey)

	GOAL (Graze)
		IF (SeesEnemy)	GOSUB (Flee)

	GOAL (Flee)
		IF (Done)		RETURN

IE_END
//////////////////////////////////////////////////////////////////////////////////
