#include <std.h>
#include "../derrodefs.h"

inherit ROOM;
object snake,snake2;
int searched;

void create(){
  ::create();
   set_terrain(BARREN);
   set_travel(FRESH_BLAZE);
  set_property("no teleport",1);
  set_property("light",2);
  set_name("Sea of lava");
  set_property("indoors",1);
  set_short("%^RED%^Swimming in the lava sea!%^RESET%^");
  set_long(  "%^RED%^Swimming in the lava sea!%^RESET%^" "\n"
  "  You struggle to stay on top of the hardened lava crust but the heat is overwhelming!"
  "  The slick walls of the path are near by.  Hopefully you can find a way back up!\n"
  );
  set_smell("default","Your clothes start to catch fire!");
  set_listen("default","The lava burns you!");
  set_items(([
  ({"face", "walls", "wall"}):"As you look closer you see some cracks that might allow you to go up!",
  "cracks":"Something glitters dully from their depths.",
  "lava":"It leads right up to the path's face.",
   "path":"It's up above you and the slick glassy face looks impossible to climb!",
  ]));
  set_exits(([
  "up":(ROOMS"c15"),
  ]));
  set_search("cracks", (: TO, "search_cracks" :) );
  set_pre_exit_functions(({"up"}),({"go_up"}));
  set_invis_exits(({"up"}));
  set_heart_beat(3);
  set_property("continue heartbeat",1);
}

void heart_beat(){
  object *heat;
  int i, j;
  ::heart_beat();
  if(!random(4))  // too spammy and also too much stamina drain
	return;
  heat=all_living(TO);
  if(present("fire snake",TO)) {
  snake=(present("fire snake",TO));
  snake2=(present("fire snake 2",TO));
  }
  heat-=({snake,snake2});
  j=sizeof(heat);
  for(i=0;i<j;i++) {
	if(!objectp(heat[i])) continue;
    if(heat[i]->query_true_invis())  continue;  
    if(!objectp(TO)) { continue; }

    tell_object(heat[i],"%^BOLD%^%^RED%^The heat sears you!");
    heat[i]->do_damage(heat[i]->return_target_limb(),roll_dice(3,10));
    heat[i]->add_attacker(TO);
    heat[i]->continue_attack();
    if(!objectp(heat[i])) { continue; }
    heat[i]->remove_attacker(TO);
  }
}

int go_up()  {
  if(present("fire snake")){
     write("The firesnakes won't let you leave!");
     tell_room(TO, "The firesnakes won't let "+TPQCN+" leave!", TP);
     return 0;
  } 
  return 1;
}

void init(){
  ::init();
//  add_action("search","search");
}

int search_cracks(string str){
  if(!str) return notify_fail("Search what?\n");
  if(str=="cracks") {
    if(searched){
      write("It's already been searched!");
      tell_room(TO, TPQCN+" pokes around the cracks but doesn't find anything.");
      return 0;
    }
    write("You find some blackened chains!");
    tell_room(TO, TPQCN+" pokes around and finds something!", TP);
    new(OBJ"chain")->move(TO);
    searched=1;
    return 1;
  }
}

void reset() {
  ::reset();
  if(!random(5))  searched = 0;
  if(!present("fire snake")){
     new(MON"firesnake")->move(TO);
     new(MON"firesnake")->move(TO);
  }
}
