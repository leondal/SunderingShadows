// South Street, Azha, near the South Gate
// Thorn@ShadowGate
// 970507
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
        set_short("South Street, Azha, near the South Gate");
  set_long(
@AZHA
%^BOLD%^South Street, near the South Gate%^RESET%^
  You are walking on South Street, near the south gate of the town. You
can see lines of wagons are travelling straight through the town making
their way south out of the town towards the rich cities of the southern
realms.  Citizens, soldiers and travellers make this area very congested.
South Street continues to the east and west. 

AZHA
    );
        set_exits(([
        "west" : "/d/azha/town/south2",
        "east" : "/d/azha/town/south4",
        "south" : "/d/azha/town/southgate",
  ] ));
        set_smell("default","The stench of horses, sweaty people and other smells assault your nose.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}


