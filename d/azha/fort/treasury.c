// Provincial Treasury
// Thorn@ShadowGate
// 1/1/96
// Azha Fort

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

int chestOpen;

inherit ROOM;

void create() {
  room::create();
	set_light(1);
	set_indoors(1);    
	set_short("Provincial Treasury");
  set_long(
@AZHA
  You have somehow stumbled on the treasury room of the Keep.  A number 
of bags of gold sit on the shelves, as well as some trade goods and 
rolled sheets of parchment.  This room is poorly-lit with only one or
two torches burning on the walls.  In addition to all of this, you 
notice a huge chest on the floor across the room from the door.  The
only exit to this room is the stout oaken door to the south.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/fort/passage1",     
  ] ));     
	set_smell("default","The room smells musty and dank.");
	set_items(([
		"bags" : wrap("These bags represent the taxes due to the Empire "+
		"from this province."),
		"torches" : wrap("There is a line of lit torches along the wall."),
		"chest" : "A large iron banded chest, very stout and very locked",
	] ));
	chestOpen = 0;
}

