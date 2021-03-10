#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;
 
    room::create();
    set_properties( ([ "light": 2, "indoors": 1 ]) );
    set_short("Entryway to the mines");
    set_long(
@KAYLA
KAYLA    
    );
    set_exits(([
                "north" : "nsquare",
                "up" : "wizroom"
    ]) );
set_items( ([
      "square" :
      "An open area at the centre of Praxis where the locals "
      "gather to do business.  This hall sits at the centre of it." ]) );
}
