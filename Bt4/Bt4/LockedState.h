#pragma once
#include "StateBase.h"
#include "StateContext.h"
#include "ClosedState.h"
class LockedState : public StateBase
{
public:
	void open(StateContext* sc) override;
	void close(StateContext* sc) override;
	void lock(StateContext* sc) override;
	void unlock(StateContext* sc) override;
};

