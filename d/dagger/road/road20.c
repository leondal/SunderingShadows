#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("Road through Dagger.");
    set_long(
      "%^CYAN%^You have reached a bend in this road through dagger.  Here it turns from the southwest to the north, towards Daggerdale.  To the southwest you can still see Torm, and to the west is the Yniam plains."
    );
    set_smell("default", "You can smell the salts of the sea on the cool breeze.");

    set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
    set_items(([
        "cliffs" : "You can see the ocean below the great granite cliffs",
        "sea" : "The great waves crash against the cliffs hundreds of feet below you.",
      ]));
    set_exits(([
        "southwest" : RPATH "road19",
       "north" : RPATH "road21",
      ]));
    if(!present("shopkeeper"))   new("/d/token_hunt/mid_vendor")->move(TO);
    if(!present("dino"))         new("/d/token_hunt/mid_dino")->move(TO);
    if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}

void init(){
    ::init();
    // Calls wandering monster daemon
    RDEMON->startup();
}

void reset()
{
    ::reset();
    if(!present("shopkeeper"))   new("/d/token_hunt/mid_vendor")->move(TO);
    if(!present("dino"))         new("/d/token_hunt/mid_dino")->move(TO);
    if(!present("wagon"))        new("/d/token_hunt/wagon")->move(TO);
}
