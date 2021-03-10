// High Street, Azha, outside Market Square
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
	set_short("High Street, Azha, outside Market Square");
  set_long(
"%^BOLD%^High Street, outside Market Square%^RESET%^
%^ORANGE%^You are in the center of the town of Azha, on High Street. To thesouth, you notice, wagons turning to enter the walled trade market ofthe town. Guards inspect licences and wagons carefully to preventthe entrance of contraband or black marketeers. An official collectsthe market fees of the licenced traders. To the north, you see aroad leading straight out of the market gate, probably towards thetaverns and town offices. High Street continues to the east andwest."
    );
	set_exits(([
	"west" : "/d/azha/town/high2",
  "south" : "/d/azha/town/market5",
	"east" : "/d/azha/town/high4",
	"north" : "/d/azha/town/center2"
   ]));
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
	AOVER->add_monster(TO, AMONDIR+"alghazi",1);
}
