// High Street, Azha, near the West Gate
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  object ob;

  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);
	set_short("High Street, Azha, near the West Gate");
  set_long(
@AZHA
%^BOLD%^High Street%^RESET%^
	You are walking on High Street, near the West Gate of the town. You
can see lines of wagons that have recently been let into the town
making their way along the street towards the center of the city,
probably towards the markets.  Citizens, soldiers and travellers make
this area very congested.  You also notice that there is a street that
intersects this one, going north-south along the west wall.  High
Street continues to the east.
AZHA
    );
	set_exits(([
	"west" : "/d/azha/town/westgate",
	"east" : "/d/azha/town/high2",
	"north" : "/d/azha/town/west2",
	"south" : "/d/azha/town/west3",
  ] ));
	set_smell("default","The stench of horses, sweaty people and other smells assault your nose.\n");
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "azha board" }) );
    ob->set_board_id("union_board");
    ob->set_queue();
    ob->set_max_posts(30);
    ob->set_location("/d/azha/town/high1");
    ob->set("short", "Azha Arcane Board Board");
    ob->set("long", "Announcements from and about the Provincial "
        "Government are posted here.\n");
}

reset() {
        ::reset();
        AOVER->setup_monsters(TO, "intersection");
}
