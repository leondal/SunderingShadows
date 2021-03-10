#include <std.h>
inherit ROOM;

void create(){
  ::create();
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The Daggerdale Sewers.");
  set("long",
@GIL
%^CYAN%^This is the inside of the sewers under Daggerdale.
The walls are made of small bricks and are covered with muck.
It's very dark here and stinks to high heaven.
Garbage and filth lie all about your feet.
You can hear scratching noises and movement nearby.
The sewers lead East and West from here.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the scent of things you don't wanna name let alone touch!");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear the sounds of rats squeeking.");
  set_items(([
"garbage" : "UH..UH!! No way I'm touching that!",
"filth" : "GEEZ!! Who flushed?? A Troll???",
"muck" : "Ewewewewewwww!!! It looks like Goblin Snot!!!!",
"walls" : "They are made from small granite bricks and are covered completely with the filth of the ages.",
"bricks" : "Granite bricks...tho theres so much muck and filth on them you couldn't hardly tell!",
]));

  set_exits(([
     "west" : "/d/dagger/Daggerdale/sewers/level1/sewer32",
     "east" : "/d/dagger/Daggerdale/sewers/level1/sewer34",
]));
}
      