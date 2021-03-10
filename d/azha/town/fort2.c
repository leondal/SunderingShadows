// Fortress Street, Azha
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
	set_short("Fortress Street, Azha");
  set_long(
@AZHA
%^BOLD%^Fortress Street%^RESET%^
You are walking on Fortress Street which follows the north wall of the
town of Azha.  The street continues to the east and west.
  To the north, you can see the barred windows of the Azha Town Gaol.
AZHA
    );
	set_exits(([
	"west" : "/d/azha/town/fort1",     
	"east" : "/d/azha/town/fort3",
  ] ));     
	set_smell("default","Something smells terrible to the north of you.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
