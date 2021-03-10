// East Street, Azha, along the East Wall
// Thorn@ShadowGate
// 961014
// Town of Azha
//Additions by Cythera to reflect Desert Sun Theater 3/05

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
	set_short("East Street, Azha");
  set_long(
@AZHA
%^BOLD%^East Street%^RESET%^
East Street runs along the eastern wall of the Town of Azha.
Looking up at the walls, you can see the guards patrolling some
of the towers rising above the palisade.  Some wooden houses
have been built directly abutting the walls of the town, even
overhanging.  In the case of a seige, the occupants of that
house can easily flee the city, or get food from the outside
even when the gates are closed. To the west of you is a sturdy-
looking crenellated stone wall which seems to be guarding
something on the inside of the town. A hole in the eastern"+
" wall offers access to an older section of Azha.
 
East Street continues to the north and south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/east3",
	"south" : "/d/azha/town/south5",
	"east" : "/d/azha/theater/rooms/calim1", 
  ] ));     
	set_smell("default","You wrinkle your nose at the scent of refuse being dumped from above.");
	set_items(([
/*		"tower" : "Ya know, if you had some climbing tools or were a thief, you could climb into that tower.", */
		"wall" : "The wall appears to be sturdy and very smooth, no way in that way.\n",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
