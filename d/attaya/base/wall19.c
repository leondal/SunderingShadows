#include <std.h>
inherit "/d/attaya/base/wall14";

void create() {
    ::create();
    set_exits( ([
    "north" : "/d/attaya/base/wall18",
    "south" : "/d/attaya/base/wall20",
        ]) );
}
void reset(){
   object mon;
   ::reset();

    if(!present("archer")) {
         mon = new("/d/attaya/mon/archer");
	mon->move(this_object());
        mon = new("/d/attaya/mon/archer2");
       mon->move(this_object());
   }

}
