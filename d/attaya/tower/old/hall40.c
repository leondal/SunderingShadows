#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Metal panel in a darkened vent.");
    set_long("
    Light enters the room from cracks in the south wall.  They appear to mark the boundaries of a metal panel.  The panel is about 3 feet wide by 2 feet high.  It is most likely an access panel from somewhere in the fortress to this vent.  All around you is blackness with exception only in the heavenly slivers of light from around the panel.

");

     set_smell("default","%^RESET%^%^BOLD%^Light shines in around a metal panel in the south wall.");
 
    set_exits(([

    "east" : "/d/attaya/tower/hall39",

    ] ));
   set_items(([

    "panel" : "It is a metal vent panel that could probably be pushed.",
    "light" : "It flows into the room from cracks around the metal panel.",
    "rubble" : "Mostly bricks, and various wooden planks, nails, plaster and stone fragments, and metal shards.",
]));
}
void init() {
  ::init();
  add_action("push", "push");
}

int push(string str) {
  if(str=="panel") {
  write("You push on the panel with all your might.\n");
  say((string)this_player()->query_cap_name()+" Pushes on the panel...  %^CYAN%^With a loud snap, the panel flies open briefly.\n");
write("%^GREEN%^The panel flies open suddenly!\n");
  this_player()->move_player("/d/attaya/tower/hallb13");
    write("%^BOLD%^%^GREEN%^You fall from the vent into a long hallway of arches.\n");
  return 1;
}
  return 0;
}
void reset(){
   ::reset();
    if(!present("profile"));
      new("/d/attaya/obj/note")->move(this_object());
}
