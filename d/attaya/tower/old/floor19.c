
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Southern wall");
        set_long("
    This is the southern part of the large room.  The walls are plaster cast and carved about half way up, and brick the rest of the way to the ceiling.  This is true of the west wall, east wall, and north wall, but the south wall is a blank gray surface.  It looks like very smoothed out plaster, but is a blue-gray in color.
    The floor and ceiling are a similiar, but not exactly matching color of blue-gray.  They are both made of painted tiles.
");
       set_exits(([
       "north" : "/d/attaya/tower/floor17",
       "south" : "/d/attaya/tower/floor24",
]));
  set_invis_exits( ({"south"}) );
       set_items(([
    "wall" : "The southern wall seems wrong somehow.  It neither reflects light, or holds shadow.  It seems to be magical, but you can't place how exactly by its appearance.",
    "south wall" : "The southern wall seems wrong somehow.  It neither reflects light or holds shadow.  It seems to be magical, but you can't place how exactly by its appearance.",
    "ceiling" : "Blue-gray tiles make up the ceiling.",
    "floor" : "Blue-gray tiles make up the floor.",
    "walls" : "Molded plaster rises half way up the brick walls.",
    "intruder" : "You are not sure if your mind is playing tricks on you.",
]));
	
}
void init() {
  ::init();
   add_action("push", "push");
}
int push(string str) {
  if(str=="wall") {
 write("%^BOLD%^You reach out to push against the wall, but your hand goes right through it.",TP);
  say((string)this_player()->query_cap_name()+" tries pushing on the wall and discovers something.\n");
    return 1;
}
    return 0;
}
