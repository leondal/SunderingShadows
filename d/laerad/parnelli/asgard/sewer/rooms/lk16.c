#include <std.h>
#include "../lizard.h"
inherit VAULT;
void create(){
::create();
set_name("Dry Caves");
set("short","Dry well lit cavern.");
set("long","%^ORANGE%^While this room is larger than the others you cannot help but also notice "+
   "that it room seems more ornate than the rest.  Crude tribal paintings and glyphs cover "+
   "the walls.  A crude throne is set against the south wall and is of enormous size.  "+
   "Torches also line the walls and this area is very well lit.  %^RESET%^");
set_property("indoors",1);
set_property("no teleport",1);
set_property("light",2);
set_terrain(NAT_CAVE);
set_travel(DIRT_ROAD);
set_smell("default","The room smells dusty and dry.");
set_listen("default","It is very quiet in these rooms save for the sounds you make.");
set_items(([
   ({"drawings","paintings"}):"Very primitive looking, they seem to depict battles and show humanoid creatures with tails standing over ones without.",
   "glyphs":"Very primitive looking as well, they seem to be drawn with burnt sticks.",
   "throne":"Made of logs and rope, the chair is large enough for something the size of a small giant. There seems to be a knob on the wall behind the chair.",
   ({"wall","walls"}):"Much like what you would expect cave walls to be like, hard, dry and cool to the touch.",
   "floor":"Smooth and flat as if from some stoneworking and much usage.",
   ({"torches","torch"}):"Sputtering and flickering, the torches on the walls illuminate the room completely.",
   ]));
  set_search("wall","You discover a small knob.  Perhaps you could turn it?");
  set_search("small knob","You discover a small knob.  Perhaps you could turn it?");
  set_search("knob","You discover a small knob.  Perhaps you could turn it?");
   if(!present("slagruss"))
      new(LMON+"lking")->move(TO);
set_exits(([
   "north":LROOMS+"lk15"
 ]));
}

void init() {
  ::init();
  add_action("turn","turn");
}

void reset() {
   ::reset();
   if(!present("slagruss") && !random(10))
	new(LMON+"lking")->move(TO);
}

int turn(string str) {
    if(!str) {
        tell_object(TP,"Turn what?");
        return 1;
    }
  if((str == "knob") || (str=="small knob")){
     if(present("slagruss")) {
            tell_object(TP,"The huge lizardman moves to block your way!");
            tell_room(ETP,""+TPQCN+" tries to turn the small knob, but the huge lizardman blocks the way.\n",TP);
            return 1;
            }
      if(member_array("south",TO->query_exits()) != -1) {
        tell_object(TP,"The knob turns freely, but nothing else happens!.");
            return 1;
            }
     tell_object(TP,"You turn the knob and it moves freely!  \n");
     tell_room(ETP,""+TPQCN+" turns the small knob and a section of the south wall opens up.\n",TP);
     add_exit(LROOMS+"sw1","south");
     tell_room(ETP,"You see a passage leading to the south.  Could it lead to %^BOLD%^%^BLUE%^freedom%^RESET%^ "+
                   "or certain %^BOLD%^%^RED%^death?%^RESET%^ \n");
     return 1;
     }
}
