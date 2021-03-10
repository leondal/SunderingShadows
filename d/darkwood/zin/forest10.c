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
    set("long", "You are lost deep within clutches of Darkwood Forest.  "+
        "The ancient trees are unnaturally dense which makes passage "+
        "very slow.  High above you, the tree branches are locked in "+
        "a twisted battle of survival effectivly blotting out the sky "+
        "and any light and creating many dark shadows.  The forest floor "+
        "is matted with many rotting leaves, old brittle sticks and "+
        "contains a dark stream which flows from the west and twists "+
        "to the southwest over some sharp rocks.  There appears to be "+
        "a passable gap through the trees to the north and you may "+ 
        "follow the stream to the southwest and east.");
    set_items( ([
        "trees": "They are ancient and knotted with age.",
        "branches": "They are twisted together and block the sun.",
        "shadows": "They dance about...almost watching you...",
        "floor": "It is matted with many leaves and branches.",
        "leaves": "They are rotting and cover the entire ground.",
        "sticks": "The lie scattered about.",
        "stream": "Its dark surface mirrors a twisted version of yourself.",
        "rocks": "The are very sharp and washed clean by the stream.",
    ]) );
    set_exits( ([
        "north": ROOM_DIR+"forest6",
        "southwest": ROOM_DIR+"forest7",
        "east": ROOM_DIR+"forest11",
    ]) );
}

void init(){
  ::init();
  do_random_encounters(({MON_DIR+"nymph",MON_DIR+"dwarf",MON_DIR+"goblin"}),60,4);
}
