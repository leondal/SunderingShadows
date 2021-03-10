#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "north" : "/d/attaya/base/wall20",
    "southeast" : "/d/attaya/base/wall22",
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
