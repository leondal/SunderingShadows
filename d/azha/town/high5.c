// High Street, Azha, by the East Walls
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("High Street, Azha, by the East Walls");
  set_long(
@AZHA
%^BOLD%^High Street, by the East Walls%^RESET%^
	You have found yourself facing the east walls of the town of Azha. The
timbers of the wall end High Street here, while East Street follows
the walls to the north and south of here.  To the west, High Street
leads back into the center of town.
AZHA
    );
	set_exits(([
	"west" : "/d/azha/town/high4",     
	"north" : "/d/azha/town/east2",
	"south" : "/d/azha/town/east3",
  ] ));     
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}
