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
  set_name("scythe trap");
  set_short(  "%^RED%^Great hallway%^RESET%^"  );
  set_long(
  "%^RED%^Great hallway%^RESET%^\n"
  "  This end of the hallway doesn't seem as well traveled as the other corridors that you've been going through."
  "  The floor is dusty in places and well worn in others and the walls here are different from the ones just to the east."
  "  The same globes adorn the ceiling however bathing the room in the same red glow as everywhere else."
  );
  set_smell("default",  "You smell fresh blood."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_items(([
  "floor":"The floor is stained with fresh blood and the dust here seems disturbed by odd marks.",
  (({"dust","marks"})):"Looks like smaller people were crawling while the giants footsteps all look like they stepped over a certain area.",
  "slit":"As you go to look closer you notice a thin metal cord stretched across the passage way that leads into the slit in the wall.",
  (({"cord","thin metal cord","metal cord"})):"A metal cord that stretches across the passageway leading to a slit in the wall.  Looks like you could probably crawl under it.",
  "walls":"The walls here look like they've been refinished instead of being just carved from the bedrock.  There is a slit in the wall were the joints of the blocks don't look properly sealed.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c4",
  "west":ROOMS"c34",
  ]));
    set_trap_functions(({"west"}),({"scythe_him"}),({"west"}));
  set_search("walls","A long near invisible metal cord run between the walls.");
  set_search("default","Hmm, something is odd, wonder what you should search next?");
}
int scythe_him(){
  write("As you walk west you bump a thin wire mounted at waist level.");
  say(""+TPQCN+" stumbles into something as "+TP->query_subjective()+" walks west!");
  toggle_trap("west");
  call_out("scythe",1,TP);
  return 1;
}
void reset(){
  ::reset();
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
}
int crawl(string str){
  write("You get down on your hands and knees and crawl across the passageway to the west.");
  tell_room(TO, TPQCN+" gets down on hands and knees and crawls off to the west.", TP);
  TP->move_player(ROOMS"c34");
  return 1;
}
