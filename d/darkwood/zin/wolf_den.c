//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "Something really smells bad here.");
    set_listen("default", "The wind whistles slowly through the trees.");
    set_property("indoors", 1);
    set_property("light", 1);
    set("short", "Inside a Dire Wolf den");
    set("long", "You have foolishly wandered into the den of a Dire "+
        "Wolf.  The bones of may dinners lie scattered about the small "+
        "den which crunch as you walk around.  The smell of foul beasts "+
        "overwelms you and causes you to gag and cover your mouth and "+
        "nose.  It is very small and cramped causing you to walk on your "+
        "hand and knees are crouch and woddle like a sitting duck.");
    set_items( ([
        "dinners": "There is a wide variety scattered about.",
        "bones": "They have been picked and eaten clean.",
    ]) );
    set_exits( ([
        "out": ROOM_DIR+"forest7",
    ]) );
}

void reset() {
    int i;
    ::reset();
    if(!present("wolf")){
    for(i=0;i<random(5)+1;i++){
      new(MON_DIR+"cub")->move(TO);
      new(MON_DIR+"dire")->move(TO);
      new(MON_DIR+"dire")->move(TO);
    }
  }
}
