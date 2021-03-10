#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
This is a wider section of tunnel under the city of Sanctuary.  This
tunnel is dry compared to the other tunnels in these sewers.  Faintly
luminescent lichen clings to the dark walls, reflecting lightly off
the water that occasionally drip from the ceiling to the tunnel.  The
tunnel contines to the south into a larger, more luminate room.
    ");
    set_exits(([
       "north" : "/d/dragon/sewer/sewer31",
       "down" : "/d/dragon/sewer/sewer34"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_smell("default","The rotting smell of waste is very strong in these tunnels.");
    set_property("no teleport", 1);
}
