#include <std.h>
#include <objects.h>

inherit "/d/dragon/sewer/sewer_room.c";

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Sewers under Sanctuary");
    set_long("%^RED%^%^BOLD%^
To the north, the tunnel slopes upward somewhat steeply.  Flanking the
tunnel here, are a pair of very large statues of human warriors. Looking
deeper into the tunnel, you notice more statues at irregular intervals.
In addition, the tunnel is faintly illuminated by lichen that clings to
the walls and ceiling.
    ");
    set_exits(([
       "up" : "/d/dragon/sewer/sewer33",
       "south" : "/d/dragon/sewer/sewer35"
    ] ));
    set_items(([
       "statues":"These two stone statues are made of stone.  Each appear\n"+
                 "to have been alive once by looking at their facial expression."
    ] ));
    set_property("no teleport", 1);
}
