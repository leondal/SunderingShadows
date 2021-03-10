// East Street, Azha, near Fortress Street
// Thorn@ShadowGate
// 961014
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
	set_short("East Street, Azha");
  set_long(
@AZHA
%^BOLD%^East Street%^RESET%^
East Street runs along the eastern wall of the Town of Azha.
Looking up at the walls, you can see the guards patrolling some
of the towers rising above the palisade.  To the west appears
to be some sort of official-looking stone building with the
%^GREEN%^banner%^RESET%^ of Azha Province flying overhead.
 
East Street continues to the north and south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/fort5",
	"south" : "/d/azha/town/east2",    
	"west" : "/d/azha/town/townhall"    
  ] ));     
	set_smell("default","You wrinkle your nose at the scent of refuse being dumped from above.");
	set_items(([
		"building" : "The building seems to be the Town Hall from the official-looking activity around it.",
	] ));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
