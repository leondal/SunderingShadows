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
  You are walking on High Street, west of the center of town.  To the
north of you, you notice the outer works of Azha Fortress, as well as
some broken wall fragments that don't seem to belong to anything else
in the town.  In the midst of them appears to be a small mosque or
temple of some form.  The gate to the inner fortress is to the east
of you.
  Fortress Street continues to the east and west.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/church",     
	"west" : "/d/azha/town/fort3",     
	"east" : "/d/azha/town/fort5",
  ] ));     
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}
