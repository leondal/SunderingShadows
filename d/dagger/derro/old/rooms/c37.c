#include <std.h>
#include "../derrodefs.h"

  int flag;
inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_no_clean(1);
  set_short(  "%^RED%^Treasure room%^RESET%^"  );
   set_long(
  "%^RED%^Treasure room%^RESET%^\n"
   "  At last you have gained entrance to the giants' treasure room!"
   "  But what's this?   Seems someone's already looted it."
   "  A few scattered coins cover the floor along with the diminutive tracks of "
   "Derro leading back east in the dust."
   "  Sigh, maybe you can track down that Derro and maybe he's long gone."
  );
  set_smell("default",  "The cool air of the room chills you."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"Carved from the bedrock of the mountains.",
   (({"scattered coins","coins"})):"Numerous silver coins are scattered about the floor apparently not enough for someone else to gather.",
  "walls":"Carved from the roots of the world with a careful eye and a strong arm.",
  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling.",
  ]));
  set_exits(([
  "east":ROOMS"c36"
  ]));
    set_invis_exits( ({"east"}) );
}
void init(){
  ::init();
  add_action("gather","gather");
}


int gather(string str){
  if(flag==1)   return notify_fail("\nThey've already been cleaned out\n");
   write("You gather as many of the coins as you can and realize that whoever looted this place must of thought they were leaving silver, but it's actually platinum!");
  tell_room(TO,TPQCN+" gathers up the scattered coins.", TP);
  remove_item("coins");
  flag=1;
  set_long("%^RED%^Treasure room%^RESET%^\n"
   "   At last you have gained entrance to the giants' treasure room!"
   "  But what's this?  Seems someone has already looted it and nothing remains but bare stone.  You can't help but notice the diminutive tracks of Derro leading back east in the dust.  Sigh, maybe you can track down that Derro and maybe he's long gone."
  );
  TP->add_money("platinum",random(300)+100);
  return 1;
}
