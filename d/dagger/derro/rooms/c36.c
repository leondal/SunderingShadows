#include <std.h>
#include "../derrodefs.h"
inherit ROOM;

int flag;
void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_heart_beat(8);
  set_name("Lighting trap");
  set_short(  "%^RED%^Another empty room%^RESET%^"  );
  set_long(
  "%^RED%^Another empty room%^RESET%^\n"
  "  This large room is empty as well except for a large stone dragon head that's mounted in the center of the room."
  "  The walls are lined again with stonework and the floor is dustless."
  );
  set_smell("default", "This room is cool and moist, bringing you a chill"  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_search("throat","You find a small catch!");
  set_search("default","You don't find anything.  Maybe you need to be a little more specific in what you search?");
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Reworked and covered in stone blocks, the walls could hold anything.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "mouth":"The dragons mouth gapes wide and steam rises from within its throat.",
  "throat":"Something glitters from its depths.",
  "catch":"Looks like it could be pulled.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c35",
  ]));
  new(OBJ"dragonhead")->move(TO);
  set_property("continue heartbeat",1);
}
void init(){
  ::init();
  add_action("pull","pull");
}

int pull(string str){
  if(str!=("catch")) 	return notify_fail("\nPull what?\n");
  if(flag==1)   	return notify_fail("It's already been pulled!");
  write("\nYou reach down into the dragon's mouth and pull at the small catch!\n");
  write("You hear a click and a door that was hidden in the west wall swings open!");
  tell_room(TO,TPQCN+" reaches down the stone dragon's mouth and fiddles with something.",TP);
  tell_room(TO,"A secret door pops open in the west wall!", TP);
  flag=1;
  add_exit(ROOMS"c37","west");
  return 1;
}

void reset() {
  ::reset();
  if(flag==1) {
     tell_room(TO,"You hear a grinding as the secret door closes and the dragon head pivots towards you!");
     remove_exit("west");
  }
}

void heart_beat(){
  object *targ;
  int i,j;
  ::heart_beat();
  targ=all_living(TO);
  if(flag==1) 	return;
  j=sizeof(targ);
  for(i=0;i<j;i++){
  if(targ[i]->query_true_invis())   continue;
  tell_object(targ[i],"\n%^BOLD%^%^YELLOW%^Sheets of lightning arc through the room from the dragons mouth!%^RESET%^\n");
  targ[i]->do_damage(targ[i]->return_target_limb(),10);
  targ[i]->add_attacker(TO);
  targ[i]->continue_attack();
  targ[i]->remove_attacker(TO);
  }
}
