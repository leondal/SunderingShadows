//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/06/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "It smells of decay and horrid death.");
    set_listen("default", "The wind whistles slowly through the trees.");
    set_property("indoors", 0);
    set_property("light", 1);
    set("short", "Darkwood Forest");
    set("long", "You are standing within the edge of Darkwood forest.  "+
        "Already the trees are very dense which makes passage very "+
        "slow.  High above you, the tree branches are locked in a "+
        "twisted battle of survival effectivly blotting out the sky "+
        "and any light it provides.  Yet, even without the light from "+
        "above, many dark shadows dance about causing a feeling like "+
        "you are being watched.  The forest floor is matted with many "+
        "rotting leaves and old brittle sticks.  There appears to be "+
        "gaps through the trees to the east and southeast.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "break": "A few streams of light filters through.",
    ]) );
    set_exits( ([
        "east": ROOM_DIR+"forest2",
        "southeast": ROOM_DIR+"forest4b"
    ]) );
}

void init(){
  ::init();
  do_random_encounters(({MON_DIR+"nymph",MON_DIR+"dwarf",MON_DIR+"goblin"}),60,4);
}
