// South Street, Azha
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
        set_short("South Street, Azha");
  set_long(
@AZHA
%^BOLD%^South Street%^RESET%^
  You are walking on South Street, along the south wall of the town. You
can see lines of wagons are travelling straight through the town making
their way along the street towards the south gate of the city, towards the
rich cities of the southern realms.  Citizens, soldiers and travellers
make this area very congested.  South Street continues to the east and
west. 

AZHA
    );
        set_exits(([
        "west" : "/d/azha/town/south1",
        "east" : "/d/azha/town/south3",
  ] ));
        set_smell("default","The stench of horses, sweaty people and other smells assault your nose.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "street");
}


