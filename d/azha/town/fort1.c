// Fortress Street, Azha, near the West Wall
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
	set_short("Fortress Street, Azha, near the West Wall");
  set_long(
@AZHA
%^BOLD%^Fortress Street%^RESET%^
  You are at the west end of Fortress Street, the northern east-west
road in Azha.  The defensive works prevent you from moving westward,
but the street stretches out to the east of you. 
  There is a building to the north with a sign that reads: Imperial
Customs Office, Azha Province.
AZHA
    );
	set_exits(([
	"east" : "/d/azha/town/fort2",
	"north" : "/d/azha/town/customs",
	"south" : "/d/azha/town/west1",
  ] ));     
}
reset() {
	::reset();
	AOVER->setup_monsters(TO, "intersection");
}
