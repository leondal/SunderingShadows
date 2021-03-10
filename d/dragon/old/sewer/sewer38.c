#include <std.h>
#include <objects.h>

inherit "/d/dragon/sewer/sewer_room.c";

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Sewers under Sanctuary");
    set_long("%^RED%^%^BOLD%^
This is a oval tunnel, being supported by some massive round columns.
The tunnel is faintly illuminated by lichen that clings to the walls,
columns. and ceiling.
    ");
    set_exits(([
      "east" : "/d/dragon/sewer/sewer39",
       "north" : "/d/dragon/sewer/sewer36"
    ] ));
    set_items(([
    ] ));
    set_property("no teleport", 1);
}
