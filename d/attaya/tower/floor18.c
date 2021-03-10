
#include <std.h>

inherit "/d/attaya/tower/spec/tower";


void create(){
      ::create();
	set_property("light",3);
	set_property("indoors",1);
   set_property("no teleport",1);
       set_short("Nearing eternity");
        set_long("%^BOLD%^%^BLACK%^Ne%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^r%^RESET%^%^CYAN%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^ter%^RESET%^%^CYAN%^n%^CYAN%^i%^BOLD%^%^BLACK%^ty%^RESET%^
%^CYAN%^There is a feeling of dread that hangs heavy in this room. For the most part, this is a safe seeming room. The %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^l%^RESET%^%^CYAN%^l%^CYAN%^s%^CYAN%^ are plaster cast and carved about half way up with brick the rest of the way to the %^BOLD%^%^BLACK%^c%^RESET%^%^BLUE%^ei%^BOLD%^%^BLACK%^l%^BLACK%^i%^RESET%^%^BLUE%^ng.%^CYAN%^ This is true of the west wall, east wall, and south wall, but the %^BOLD%^%^BLACK%^n%^RESET%^%^CYAN%^o%^BOLD%^%^BLACK%^rth %^BLACK%^w%^BLACK%^a%^BLACK%^l%^RESET%^%^BLUE%^l%^CYAN%^ is a blank gray surface. It looks like very smoothed out plaster, but is a blue-gray in color. The %^BOLD%^%^BLACK%^f%^RESET%^%^BLUE%^lo%^BOLD%^%^BLACK%^o%^BLACK%^r%^RESET%^%^CYAN%^ and ceiling are a similiar, but not exactly matching color of blue-gray. They are both made of painted tiles.
");
       set_exits(([
       "north" : "/d/attaya/tower/floor20",
       "south" : "/d/attaya/tower/floor17",
]));
  set_invis_exits( ({"north"}) );
       set_items(([
    "wall" : "The northern wall seems wrong somehow.  It neither reflects light, or holds shadow.  It seems to be magical, but you can't place how exactly by its appearance.",
    "north wall" : "The northern wall seems wrong somehow.  It neither reflects light or holds shadow.  It seems to be magical, but can't place how exactly by its appearance.",
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
