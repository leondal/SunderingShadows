#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
    set_room_type("tbarracks");
    set_property("light", 2);
    set_property("indoors", 1);
   set_short("Troopers' barracks");
    set_long(
      "You are in a rather large room filled with bunkbeds.  This is one of the many barracks used for the common footsoldiers of the Tonovi army, able to easily hold 50 men preparing for combat."
    );
    set_items( ([
      "bunks" : "All the bunks are empty.  The troops must be out training.",
    ]) );
    set_exits( ([
      "down" : RPATH "brcks-b1",
      "south" : RPATH "brcks-b3",
    ]) );
}
