#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",0);
     set_short("Eastern pines");
    set_long("%^BLUE%^%^BOLD%^
These are the great eastern pines, with their branches looming high 
above, almost completely blocking your view of the gray sky above.  Beneath
the sweeping branches, the trail winds among the trunks of the trees.
Two immense oak doors stand wide open, allowing all to enter the city of
%^RED%^Sanctuary%^BLUE%^.  High above you looms an iron portcullis, covered with
layers of rust.
    ");
    set_exits(([
       "east" : "/d/dragon/forest/forest02",
       "enter" : "/d/dragon/town/roadE4"
    ] ));
    set_items(([
       "path":"A small path through the huge trees of the northern pine.",
       "forest":"The northern pines.  It is not a very well traveled place."
    ] ));
}
