// Fortress Street, Azha, intersecting Center Street
// Thorn@ShadowGate
// 4/8/95
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
	set_short("Fortress Street, Azha, intersecting Center Street");
  set_long(
@AZHA
%^BOLD%^Fortress Street, intersecting Center Street%^RESET%^
  You are in the center of the town of Azha, on Fortress Street.  To 
the south, you notice that Center Street proceeds towards Market
Square and the heart of the town.  Fortress Street continues to the
east and west.
	To the north of you is the entrance to the Azha Town Watch Office
and Gaol.  You can clearly make out the outer walls of Azha
Fortress to the east of you.
AZHA
    );
	set_exits(([
	"west" : "/d/azha/town/fort2",     
	"east" : "/d/azha/town/fort4",
	"north" : "/d/azha/town/police",
	"south" : "/d/azha/town/center1",
  ] ));     
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}
