#include "room.h"
#include "defs.h"
#include "player.h"
#include "entity.h"
#include "optiontypes.h"

#include <memory>

#define MAX_ROOMS 200

using namespace e_std;

static bool g_running;

static Entity* g_inigo;
static Entity* g_agnes;
static Entity* g_wallace;
static Entity* g_darcy;
static Entity* g_iva; 

static Entity* g_guard;

static Room* g_cell_hall_1;
static Room* g_cell_room_1;

static player_t g_player;

static InspectPerson* g_inspect_inigo;

static InspectRoom* g_inspect_cell_room_1;
static InspectRoom* g_inspect_cell_hall_1;

static MoveOption* g_cell_room_1_to_cell_hall_1;
static MoveOption* g_cell_hall_1_to_cell_room_1;

void initGlobals()
{
	g_running = true;

	g_inigo = new Entity("Inigo", "Technomancer", INIGO_ID);
	g_agnes = new Entity("Agnes", "Sparklight", AGNES_ID);
	g_wallace = new Entity("Wallace", "Warpstar", WALLACE_ID);
	g_darcy = new Entity("Darcy", "Heatwave", DARCY_ID);
	g_iva = new Entity("Iva", "Spectra", IVA_ID);

	g_guard = new Entity("Guard", "Guard", GUARD_ID);

	g_player.addMember(g_inigo);
	
	g_cell_room_1 = new Room(CELL_ROOM_1, &g_player);
	g_cell_hall_1 = new Room(CELL_HALL_1, &g_player);

	g_inspect_inigo = new InspectPerson(*g_inigo);

	//Inspects
	g_inspect_cell_room_1 = new InspectRoom(*g_cell_room_1);
	g_inspect_cell_hall_1 = new InspectRoom(*g_cell_hall_1);

	//Move Connections
	g_cell_room_1_to_cell_hall_1 = new MoveOption(g_player, *g_cell_hall_1);
	g_cell_hall_1_to_cell_room_1 = new MoveOption(g_player, *g_cell_room_1);

	//Add  options
	g_cell_room_1->addOption(0, g_inspect_cell_room_1);
	g_cell_room_1->addOption(1, g_inspect_inigo);
	g_cell_room_1->addOption(2, g_cell_room_1_to_cell_hall_1);

	g_cell_hall_1->addOption(0, g_inspect_cell_hall_1);
	g_cell_hall_1->addOption(1, g_cell_hall_1_to_cell_room_1);

	g_player.m_curr_room = g_cell_room_1;

	//Set stats
	g_inigo->setDefence(PHYS, 2);
}

void releaseGlobals()
{
	delete g_inigo;
	delete g_agnes;
	delete g_wallace;
	delete g_darcy;
	delete g_iva;

	delete g_guard;

	delete g_cell_room_1;
	delete g_cell_hall_1;

	delete g_inspect_inigo;
	delete g_inspect_cell_room_1;

	delete g_cell_hall_1;

	delete g_cell_room_1_to_cell_hall_1;
	delete g_cell_hall_1_to_cell_room_1;
}

int main(int argc, char* argv[])
{
	initGlobals();

	while(g_running)
	{
		if(g_player.m_curr_room != NULL) g_player.m_curr_room->update();
	}

	releaseGlobals();
	return 0;
}

