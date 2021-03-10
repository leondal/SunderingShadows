
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Hallway of arches");
        set_long("
    The hallway curves gently to the south and east from here.  White wooden planks that start at the floor run up the walls, parallel with the hall.  They start to bend over the roof about twelve feet above, and the ceiling's highest point is about sixteen feet above you. 
    A strange metal panel on the wall catches your eye.
    On the northwest wall, at the center of the curving wall is a small painting.
");
       set_exits(([
       "east" : "/d/attaya/tower/hallb12",
       "south" : "/d/attaya/tower/hallb14",
]));
       set_items(([
    "ceiling" : "The same wooden planks that make up the walls follow the curvature of the arches and wrap over the hallway, continuously to the other side!",
    "floor" : "The floor here is made up of dark gray polished marble tiles.",
      "panel" : "A metal panel, perhaps a ventilation shaft that has been covered, is set high into the north wall.",
    "arches" : "The arches hold up a curved ceiling of long white wooden planks.  They protrude from the wall to a distance of about six inches.",
    "painting" : "%^GREEN%^Intruder is crumpled over in pain here and from his body another spirit is emerging and flexing its muscles as it shrieks upwards towards the heavens.",
    "planks" : "The white wooden planks run from arch to arch parallel to the floor.  Their ends are hidden behind the arches, giving the illusion that they are continuous in length.",
    "tiles" : "They are marble tiles, dark gray in color.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
   add_action("open", "open");
}
int open(string str) {
  if(str=="panel") {
 write("You try desperately to pry the panel open, but it won't budge.",TP);
  say((string)this_player()->query_cap_name()+" tries opening the panel by prying it, but is unable.\n");
    return 1;
}
    return 0;
}
