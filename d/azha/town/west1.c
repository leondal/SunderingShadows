// West Street, Azha, near Fortress Street
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
	set_short("West Street, Azha");
  set_long(
@AZHA
%^BOLD%^West Street%^RESET%^
	West Road runs along the western wall of the Town of Azha. Looking
up at the walls, you can see the guards patrolling some of the towers
rising above the palisade.  Some wooden houses have been built
directly abutting the walls of the town, even overhanging.  In the
case of a seige, the occupants of that house can easily flee the
city, or get supplies from the outside even when the gates are
closed.  To the east, it looks like you can enter a building with
sout walls and iron grating over the windows.  Despite its forbidding
look, many richly clothed men are constantly entering and leaving
this place.
	West Street continues to the north and south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/fort1",
	"south" : "/d/azha/town/west2",    
    "east" : "/d/azha/town/bank",
  ] ));     
	set_smell("default","You wrinkle your nose at the scent of refuse being dumped from above.");
	set_items(([
		"building" : "Looking closely at the building, you judge it to be a bank.",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
