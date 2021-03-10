#include <std.h>
#include "../derrodefs.h"

inherit ROOM;
int flag;

void create(){
  ::create();
   set_terrain(BUILT_CAVE);
   set_travel(FRESH_BLAZE);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_name("pit trap");
  set_short("%^RED%^Pit trap%^");
  set_long(  "%^RED%^Pit trap%^RESET%^\n"
  "  You are at the bottom of a pit trap that is lined with spikes."
  "  It is about 50 feet back up but the walls are lined with cracks and crevices to make going up a easy climb."
  "  Looks like someone didn't have as much luck as you with the spikes and a corpse is suspended above the floor on them."
  );
  set_smell("default", "The scent of blood is strong." );
  set_listen("default", "You can hear nothing but the occasional chirp of a rat somewhere in the distance.");
  set_items(([
  "floor":"The floor is stained with blood from the corpse suspended on the spikes.",
  "walls":"Cracked and chipped with hasty construction they offer easy access back up.",

  "globes":"These magic globes are set in the ceiling far from the ground and seem enchanted to emit a dim red glow.",
  "spikes":"  10 feet tall metal spikes are mortared into the floor.   You would suppose a fall from the top would kill you instantly if you had landed on them.  A corpse hangs suspended on the spikes.",
  "corpse":"Looks like that of a human knight.   His mail and plate are rent and torn by the spikes and his fall.",
  "ceiling":"Damn near 25 feet at the peak from the floor almost making it seem as if you're not actually far underground.  There is a red globe mounted in the center of the ceiling."
  ]));
  set_search("corpse", (: TO, "search_corpse" :) );
  set_search("default", "Perhaps that corpse still has something of value intact after all?");
  set_exits(([
  "up":ROOMS"c34",
  ]));
}
void init(){
  ::init();
//  add_action("search_corpse","search");
}

void reset() {
  ::reset();
  if(!random(4))  flag = 0;
}

int search_corpse(string str){
  object ob;
  if(str=="corpse") {
    if(flag==1) {
      write("Nothing else of value on it.\n");
      return 1;
    }
    write("You search the knight and find some unbroken healing potions in his ripped pack and realize his tunic is undamaged from the fall as well.");
    tell_room(TO, TPQCN+" searches the corpse and seems to find something.", TP);
  new(OBJ"tunic")->move(TO);
   ob = new("/d/common/obj/potion/healing");
  ob->move(TO);
  ob->set_uses(random(30)+15);
  flag=1;
  return 1;
  }
  write("Perhaps you need to be more specific about your search?\n");
  return 1;
}
