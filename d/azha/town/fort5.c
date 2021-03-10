// Fortress Street, Azha, by the Keep Gate
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
	set_short("Fortress Street, Azha, by the Keep Gate");
  set_long(
@AZHA
%^BOLD%^Fortress Street, Azha, by the Keep Gate%^RESET%^
  You are standing in front of the walls around the inner keep of 
Azha Fortress.  Looking up at the keep itself, you notice the Imperial
Standard flying beside the %^GREEN%^green%^RESET%^ and %^BOLD%^silver%^RESET%^ banner of the Imperial
Governor of Azha Province.  To the east is the gate to the keep,
which appears to be well guarded.
  To the south, you notice that East Street follows the east walls to
the town to the south.
  At the side of the road, it looks as though a vast building has been
recently cleared, with only fragments of stone set about a vacant lot.
The only distinctive item that remains is a large statue of a %^RED%^war 
hound%^RESET%^, standing eternal vigil over a mighty hammer.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/fort/gate",     
	"west" : "/d/azha/town/fort4",     
	"south" : "/d/azha/town/east1",
  ] ));     
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}
