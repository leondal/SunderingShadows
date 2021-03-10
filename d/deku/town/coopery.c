#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
  set_terrain(WOOD_BUILDING);
  set_travel(DIRT_ROAD);
    set_short("%^BOLD%^%^RED%^T%^RESET%^%^RED%^he %^BOLD%^C%^RESET%^%^RED%^oopery");
    set_long(
"%^BOLD%^%^RED%^T%^RESET%^%^RED%^he %^BOLD%^C%^RESET%^%^RED%^oopery
%^ORANGE%^This thatched cottage is a Coopery, or barrel maker's workshop. Throughout you see large barrels sitting on the floor. Against the south wall there is a long workbench covered in metal working tools such as chisels, shapers, and vices. Many different pieces of copperware hang from the hooks on the wall. 
"
    );
    set_exits(([
         "south" : "/d/deku/town/road8"
    ] ));
    set_items(([
    ] ));
}
