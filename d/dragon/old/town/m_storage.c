inherit "std/room";
#include <std.h>
#include <objects.h>
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short","A storage room for the magic shop.");
    set("long","Items of various degree are stored here.");
   set_exits((["east":"/d/deku/keep/magic"]));
}
void reset() {
::reset();           
        if(!present("heal")) {
                new("/d/deku/keep/potion/heal")->move(this_object());
                new("/d/deku/keep/potion/heal")->move(this_object());
		new("/d/deku/keep/potion/heal")->move(TO);
                new("/d/deku/keep/potion/heal")->move(TO);
                new("/d/deku/keep/potion/heal")->move(TO);
         }
        if(!present("cure_poison")) {
                new("/d/deku/keep/potion/cure_poison")->move(TO);
		new("/d/deku/keep/potion/cure_poison")->move(TO);
       }
        if(!present("extra_heal")) {
		new("/d/deku/keep/potion/extra_heal")->move(TO);
                new("/d/deku/keep/potion/extra_heal")->move(TO);
                new("/d/deku/keep/potion/extra_heal")->move(TO);
		new("/d/deku/keep/potion/extra_heal")->move(TO);
		new("/d/deku/keep/potion/extra_heal.c")->move(TO);
         }
}
