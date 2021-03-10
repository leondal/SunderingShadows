#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit JUNGI;

void create(){
    ::create();
    set_short("%^GREEN%^A thick jungle");
    set_long(
      "%^GREEN%^You are in a strange and thickly wooded jungle.  Hot and humid, the foreign ferns and trees create a small shell all around you.  You can barely make out the path you are on.  Rain falls almost constantly on your head, yet you cannot tell if it is from the trees, or from actual clouds."
    );
    set_smell("default", "It smells like fresh rain in a jungle.");
    set_listen("default", "Animal calls. bellows, and roars unlike any you have heard before echo throughout the jungle.");
    set_items( ([
      "ferns" : "The green ferns are much larger than any you remember.",
      "path" : "The path here seems to be made by large reptillian feet.",
    ]) );
    set_exits( ([
      "southeast" : RPATH "jung19",
      "northeast" : RPATH "jung21",
      "northwest" : RPATH "jung26",
      "southwest" : RPATH "jung16",
    ]) );
}
