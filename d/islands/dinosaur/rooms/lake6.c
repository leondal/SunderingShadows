#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit LAKEF;

void create(){
    ::create();
    set_short("%^CYAN%^On the lake's edge.");
    set_long(
      "Here in the middle of the jungle you have been wandering around in there is a fairly large lake.  here at the edge of the lake where you are standing it is fairly marshy, and you can see huge footprints in the mud, but you can also see that when the lake does start to deepen, it gets deeper fast.  In the middle of the lake there is an island."
    );
    set_smell("default", "Around the lake it smells much like a swamp.");
    set_listen("default", "Mosquitios buzz around your head.");
    set_items( ([
      "footprints" : "These footprints are huge semi-circular prints, with bumps where the toes would have been.  Whatever made thes is very large, and very heavy.",
      "lake" : "The water of the lake looks rather clear.  There is an island in the middle of the lake.",
      "island" : "The island looks to be deserted.",
    ]) );
    set_exits( ([
      "east" : RPATH "lake5",
      "northeast" : RPATH "jung69",
      "west" : RPATH "lake7",
    ]) );
}
