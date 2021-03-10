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
  set_short(  "%^RED%^Chest room%^RESET%^"  );
  set_long(
  "%^RED%^Chest room%^RESET%^\n"
  "  This massive room is empty save for an exit to the west and a huge chest in the middle of the room."
  "  The floor is clean of dust and the walls are lined with stoneworking marks."
  );
  set_smell("default",  "This room feels cooler than the others in the area."  );
  set_listen("default",
  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"
  );
  set_search("default","You don't find much just aimlessly milling around the room.");
  set_search("walls","You find a section of wall that pivots leading west.");
  set_search("chest","It looks like you might be able to open it if you try.");
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Reworked these walls are made from huge stone blocks that line the walls.",
  "chest":"A massive steel chest that could hold anything.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_exits(([
  "east":ROOMS"c34",
  "west":ROOMS"c36",
  ]));
  set_invis_exits(({"west"}));
  set_pre_exit_functions(({"east"}),({"go_east"}));
  set_pre_exit_functions(({"west"}),({"go_west"}));
}

void init(){
  ::init();
  add_action("open","open");
}

int open(string str){
  if(!str) return notify_fail("\nOpen what?\n");
  if(str=="chest"){
  if(flag==1) return notify_fail("It's already open!");
  write("You reach up and open the chest, but as your hand gets closer suddenly the top blows open!");
  write("A funnel cloud appears out of the chest and the temperature suddenly drops!");
  tell_room(TO, TPQCN+" reaches for the lid to the massive chest but it blows open before "+TP->query_subjective()+" can touch it, releasing a massive funnel cloud to the room!", TP);
  tell_room(TO, "The temperature suddenly drops as hail and lightning shoot from the angry elemental!", TP);
  new(MON"funnel.c")->move(TO);
  flag=1;
  return 1;
  }
}

int go_west(){
  if(present("funnel cloud")){
  write("Winds lash at you and blow you back across the room!");
  tell_room(TO, TPQCN+" tries to get to the secret door but the funnel cloud "
     "blows "+TP->query_objective()+" back!");
  return 0;
  }
  return 1;
}

int go_east(){
  if(present("funnel cloud")){
  if(!random(5)){
  tell_room(ETO,"%^CYAN%^Winds just up and blow "+TP->query_cap_name()+" back away from the door and escape!",TP);
  tell_object(TP,"%^CYAN%^Winds gust up at you forcing you away from the door!");
  return 0;
  }
  return 1;
  }
  return 1;
}
