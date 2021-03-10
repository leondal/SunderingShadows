#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_name("trapped room");
  set_short(  "%^RED%^Great hallway%^RESET%^"  );
  set_long(
  "%^RED%^Great hallway%^RESET%^\n"
  "  This end of the hallway doesn't seem as well traveled as the other corridors that you've been going through."
  "  The walls here look a lot like those just to the east."
  "  The same globes adorn the ceiling however bathing the room in the same red glow as everywhere else."
  "  The floor here seems clean of dust."
  );
  set_search("default","You search around and find a pressure plate in the floor.");
  set_search("floor","You search around and find a pressure plate in the floor.");
  set_search("walls","A long, nearly invisible metal cord runs between the walls.");
  set_smell("default",  "You smell fresh blood."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor is stained with fresh blood on the ground to the east but to the west seems clear of all dust.",
  (({"pressure plate","plate"})):"A large section of stone about 25 feet across and stretching to both walls.   Maybe you could trigger it by throwing something heavy at it?",
  "slit":"As you go to look closer you notice a thin metal cord stretched across the passage way that leads into the slit in the wall.",
  (({"cord","thin metal cord","metal cord"})):"A metal cord that stretches across the passageway leading to a slit in the wall.  Looks like you could probably crawl under it.",
  "walls":"The walls here look like they've been refinished instead of being just carved from the bedrock.  There is a slit in the wall were the joints of the blocks don't look properly sealed.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c3",
  "west":ROOMS"c35",
  ]));
  set_trap_functions(({"east"}),({"scythe_him"}),({"east"}));
  set_trap_functions(({"west"}),({"fall_him"}),({"west"}));
}

int scythe_him(){
  write("As you walk west you bump a thin wire mounted at waist level.");
  tell_room(TO, TPQCN+" stumbles into something as "+TP->query_subjective()+" walks west!", TP);
  toggle_trap("east");
  call_out("scythe",1,TP);
  return 1;
}

void reset(){
  ::reset();
  if(!trapped("east")) toggle_trap("east");
  if(!trapped("west")) toggle_trap("west");
}
void scythe(object targ){
  int dam;
  object ob;
  if(objectp(targ)){
    if(present(targ->query_name())){
  tell_room(TO, "%^BOLD%^You hear a click in the wall.");
  write("%^BOLD%^Before you can react a spring loaded blade scythes from the wall at you!");
   write("%^BOLD%^It appears that on a giant 18 feet tall it would be aimed at his legs but for you it's aimed at your neck!");
  write("%^BOLD%^The massive blade slashes into you!");
  tell_room(TO, "Before "+targ->query_cap_name()+" can react, a massive blade springs out of the wall and slashes into "+targ->query_possessive()+" neck!", targ);
  dam=random(100)+10;
  set_name("scythe trap");
  targ->do_damage("torso",dam);
  targ->add_attacker(TO);
  targ->continue_attack();
   // adding check for objectp(targ) in case they die in the continue_attack() *Styx* 11/15/03, last change showed 11/28/03 but that must have been from when the dates were screwed up on the server
  if(!objectp(targ))  
	return;
  targ->remove_attacker(TO);
  return;
  }
}
}

void init(){
  ::init();
  add_action("crawl","crawl");
  add_action("throw","throw");
}
int crawl(string str){
  write("You get down on your hands and knees and crawl across the passageway to the east.");
  tell_room(TO, TPQCN+"  gets down on "+TP->query_possessive()+" hands and knees and crawls off to the east.", TP);
  TP->move_player(ROOMS"c3");
  return 1;
}
int throw(string str){
  object ob;
  if(!str)return notify_fail("\nThrow what?\n");
  if((str=="stone at pressure plate")||(str=="stone at plate")||(str=="large stone at plate")||(str =="large stone at pressure plate")){
  if(!present("stone",TP))return notify_fail("\nYou don't have that!\n");
  ob=(present("stone",TP));
  ob->remove();
  toggle_trap("west");
  add_exit(ROOMS"c38","down");
  tell_room(TO, TPQCN+" throws a large stone at the pressure plate and the whole floor suddenly shudders and falls open into a pit blocking the west!", TP);
  write("The stone lands on the pressure plate and suddenly the floor gives way to the west and opens into a deep pit!");
  set_long("%^RED%^Great hallway%^RESET%^\n"
  "  This end of the hallway doesn't seem traveled as the other corridors that you've been going through."
  "  The walls here are the same as those just to the east.   The floor to the west has given way leading down into a deep pit, with a thin ledge around its edge giving access to the west exit."
  );
  return 1;
}
  if(str=="stone")return notify_fail("\nThrow stone at what?\n");
  if((str !="powder")||(str !="javelin")||(str !="dart"))return notify_fail("\nDon't think that would work.\n");
  return 1;
}

int fall_him(){
  toggle_trap("west");
  set_long("%^RED%^Great hallway%^RESET%^\n"
  "  This end of the hallway doesn't seem traveled as the other corridors that you've been going through."
  "  The walls here are the same as those just to the east.   The floor to the west had given way leading down into a deep pit, with a thin ledge around its edge giving access to the west exit."
  );
  write("As you try to walk west you step on a plate that grates under your feet.");
  write("The floor suddenly shifts under your weight!");
  tell_room(TO, "As "+TPQCN+" walks west the floor suddenly shifts under them!",TP);
  tell_room(TO, TPQCN+" disappears from sight as a pit opens up!", TP);
  write("A pit opens beneath you and you fall into the darkness!");
  TP->move_player(ROOMS"c38");
  set_name("Pit trap");
  TP->add_attacker(TO);
  TP->do_damage("torso",random(100)+10);
  add_exit(ROOMS"c38","down");
  if(!objectp(TP)) return 1;
  TP->continue_attack();
  TP->remove_attacker(TO);
  return 1;
}
