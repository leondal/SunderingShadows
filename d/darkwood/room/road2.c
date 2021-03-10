//	The Royal Southern Road
//	Thorn@Shadowgate
//	9/28/94
//	Darkwood forest
//	road2
/*updated 10/4/03 by Circe.  Added room name and updated code to current standards.  Changed road to use inherits*/

#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_indoors(0);
    set_name("Magistrate's Southern Road");
    set_short("%^RESET%^%^ORANGE%^M%^GREEN%^a%^ORANGE%^gist%^GREEN%^r%^ORANGE%^ate'%^GREEN%^s %^ORANGE%^So%^GREEN%^u%^GREEN%^t%^ORANGE%^hern %^ORANGE%^Road%^RESET%^");
    set_long(
"%^RESET%^%^ORANGE%^M%^GREEN%^a%^ORANGE%^gist%^GREEN%^r%^ORANGE%^ate'%^GREEN%^s %^ORANGE%^So%^GREEN%^u%^GREEN%^t%^ORANGE%^hern %^ORANGE%^Road%^RESET%^
%^RESET%^%^GREEN%^You are on the road that crosses countryside between Shadow and Tharis. Some trees grow around here, peasants work in the fields. To the north is the great city of Shadow. To the south, you can see the edge of a dark forest in the far distance. The road itself appears dusty and well-travelled.%^RESET%^
"
);
   set_listen("default","The road is quiet except for the occasional sounds of travelers.");
   set_smell("default","The clean fragrance of the %^BOLD%^%^GREEN%^forest%^RESET%^%^ORANGE%^ mixes with the stale air of the city.");
    set_exits(
              (["north" : "/d/darkwood/room/road1",
                "south" : "/d/darkwood/room/road3"]) );
}
