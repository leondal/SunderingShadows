// Main Passageway of Azha Keep
// Thorn@ShadowGate
// 12/18/95
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
	set_light(2);
	set_indoors(1);    
	set_short("Main Passageway of Azha Keep.");
  set_long(
@AZHA
	Looking around at the weapons stacked along the walls and the
numerous soldiers around out of uniform, you decide that this is
probably a barracks for the keep garrison. There are two open doors
to the north and south leading to the barracks.  The corridor
proceeds to the east and west.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/barracks1",     
	"south" : "/d/azha/fort/barracks2",     
        "west" : "/d/azha/fort/passage4",
        "east" : "/d/azha/fort/passage2",
  ] ));     
	set_smell("default","This part of the hall smells of dust, dirt and "+
	"the other things that accompany a frontier soldier.");
	set_listen("default","You hear the sounds of soldiers talking and moving"+
	" around in their quarters");
	set_items(([
		"weapons" : "Numerous weapons are stacked in cases against the wall, "+
		"properly stowed and locked up.",
		] ));
}
