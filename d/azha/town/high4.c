// High Street, Azha
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
	set_short("High Street, Azha");
  set_long(
@AZHA
%^BOLD%^High Street%^RESET%^
	You are walking on High Street, west of the center of town.  To the
south of you, you notice a high, crenellated stone wall that seems to
be surrounding something in the center of the city, probably the
trade market. To the north, you see the sides of a few buildings, but
no doors.  High Street continues to the east and west.
AZHA
    );
	set_exits(([
	"west" : "/d/azha/town/high3",     
	"east" : "/d/azha/town/high5",
  ] ));     
	set_smell("default","The stench of horses, sweaty people and other smells assault your nose.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
