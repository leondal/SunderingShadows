// South Street, Azha, intersecting West Street
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
        set_short("South Street, Azha, intersecting West Street");
  set_long(
@AZHA
%^BOLD%^South Street%^RESET%^
  You are walking on South Street, near the west wall of the town. You can
see lines of wagons are travelling straight through the town making their
way along the street towards the south gate of the city, towards the rich
cities of the southern realms.  Citizens, soldiers and travellers make
this area very congested.  You also notice that there is a street that
intersects this one, going north-south along the west wall.  South Street
continues to the east. 
AZHA
    );
        set_exits(([
        "east" : "/d/azha/town/south2",
        "north" : "/d/azha/town/west4",
  ] ));
        set_smell("default","The stench of horses, sweaty people and other smells assault your nose.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}


