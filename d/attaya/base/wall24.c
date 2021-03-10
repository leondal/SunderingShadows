#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "northwest" : "/d/attaya/base/wall23",
    "east" : "/d/attaya/base/wall1",
        ]) );
}
void reset(){
   object mon;
   ::reset();

    if(!present("archer")) {
         mon = new("/d/attaya/mon/archer");
	mon->set_id( ({"archer", "guard"}) );
	mon->move(this_object());
   }

}
