#include <std.h>
inherit "/std/vault";
#include "../derrodefs.h"
int FLAG;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_name("The freezer");
  set_short("%^RED%^Freezer%^RESET%^" );
  set_long(  "%^RED%^Freezer%^RESET%^\n"
  "  A curious brown mold covers the walls here and great meathooks hang from the ceiling."
  "  The air is freezing cold in sharp contrast to the other areas under this mountain and the massive metal door to the south is covered in frost."
  "\n"
  );
  set_smell("default","The cold covers the scent of everything."  );
  set_listen("default",  "You can hear nothing but the occasional chirp of a rat somewhere in the distance"  );
  set_items(([
  "floor":"The floor looks carved from the bedrock of the mountains.",
  "walls":"Covered in the brown mold.",
  "meathooks":"Large meathooks hang from the ceiling covered in the ever present mold.",

  "metal door":"Maybe you could unlock it with something.",
  "mold":"Brown mold covers everything and there appears to be lumps under it in the corner marring its uniform surface.",
  "lumps":"It's a corpse of a Derro",
  ({"Derro","derro"}) :"Maybe you could search the corpse?",
  "corpse":"It's partially hidden under the mold but it appears to be that of a "
	"derro who died of the cold in here.  Is that something imbedded in the "
	"mold around his hands?",
  "door":"Maybe you could unlock it with something.",
  ]));
  set_search("corpse", (: TO, "search_mold" :) );
  set_search("derro", (: TO, "search_mold" :) );
  set_search("mold", "You find the corpse of a derro.  Perhaps it's worth a thorough search.");
  set_exits(([
  "south":ROOMS"c23",
  ]));
  set_door("door",ROOMS"c23","south","brown key");
  set_locked("door",1);
  set_string("door","open","The metal door opens quietly despite its size.");
  set_property("continue heartbeat",1);
  set_heart_beat(8);
}
void reset(){
  ::reset();
  if(!present("side of beef")){
    new(OBJ"frcow.c")->move(TO);
  }
  FLAG=0;
set_open("door",0);
  set_locked("door",1);
}
void init(){
  ::init();
//  add_action("search_mold","search");  // changed to use set_search 10/23/02 Styx
}

int search_mold(string str){
  if(FLAG) return notify_fail("You find nothing else.\n");
 if(!str)return notify_fail("You find nothing.");
  if((str!="corpse") && (str !="derro"))
  return notify_fail("nothing there, maybe something else?");
  say((string)TP->query_cap_name() +" searches the mold covered corpse and finds a key, but the mold senses the movement and attacks!");
  FLAG=1;
  write("You search the mold covered corpse and find a key but the mold senses your heat and attacks!");
  new(OBJ"brownkey.c")->move(TO);
  new(MON"mold.c")->move(TO);
  return 1;
}

void heart_beat(){
  object *cold;
  int i, j;
  ::heart_beat();
  cold= all_living(TO);
  j=sizeof(cold);
  for(i=0;i<j;i++){
    if(!objectp(cold[i])) { continue; }
    if(!objectp(TO)) { continue; }
    if(cold[i]->query_true_invis()) continue;  // skip true invis avatars/wizzes
    tell_object(cold[i],"%^BOLD%^%^WHITE%^The cold bites into you.");
    cold[i]->do_damage(cold[i]->return_target_limb(),1);
    cold[i]->add_attacker(TO);
    cold[i]->continue_attack();
    if(!objectp(cold[i])) { continue; }
    cold[i]->remove_attacker(TO);
  }
}
