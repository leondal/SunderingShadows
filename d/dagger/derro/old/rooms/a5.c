#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
  set_property("light",2);
  set_short( "Southern clearing"  );
  set_long(
  "%^RESET%^%^BOLD%^Southern clearing. \n%^RESET%^"+
  "  This clearing only has a opening through the bush and rocks to the north."
  "  Something glitters on the rocks.\n" );
  set_smell("default", "The smell of sulfur covers everything." );
  set_listen("default", "Something bubbles far off to the north." );
  set_items(([
  "brush":"Small patches of scrubby vegetation make passage difficult off the path.",
  "mountains":"Foreboding looking mountains overshadow this little clearing.",
  "rocks":"Someone seems to have left some gold coins on the ground.",
  "coins":"Maybe you could retrieve them?",
  ]));
  set_exits(([
  "north":ROOMS+"a4"
  ]));
}
void init(){
  ::init();
  add_action("retrieve_coins","retrieve");
}

int retrieve_coins(string str){
  object *capture;
  int i,j;
  if(!str) return notify_fail("retrieve what?");
  if(lower_case(str) !="coins") return notify_fail("try retrieve coins");
  if(TP->query_highest_level()<19)return notify_fail("The coins are worthless and you hear a scurrying about the bush but nothing happens.   Maybe you are to weak to be noticed here?\n");
  write("You reach down and pick up the coins.  You suddenly start to feel weak as you hear a hissing noise!"
  "\n%^BOLD%^%^WHITE%^You drop to your knees and then fall on your face as everything goes dark!");
  say((string)TP->query_cap_name() +" reaches down and picks the gold coins up, looks confused and then slumps to the ground.  Small shapes appear from the underbrush armed with loaded crossbows and fire at you!.");
  TP->move(ROOMS"a5-capture");
  capture=all_living(TO);
  j=sizeof(capture);
  for(i=0;i<j;i++){
  if((!TP->query_paralyzed()) || (!TP->query_bound()) || (!TP->query_unconscious())){
  if((int)capture[i]->query_highest_level()>19){
  tell_object(capture[i],"%^BOLD%^You try to avoid the bolts but one scratches you and you suddenly feel weak and then everything goes dark!");
  tell_room(environment(capture[i]),""+capture[i]->query_cap_name()+" is hit by a crossbow bolt, staggers then slumps to the ground where the diminutive shapes grab him.!",capture[i]);
  capture[i]->move_player(ROOMS"a5-capture");
  } else {
  tell_object(capture[i],"%^BOLD%^You dive for cover as the crossbows click and as you look up the diminutive figures have gathered the fallen and disappeared back into the brush!");
  tell_room(environment(capture[i]),"%^BOLD%^"+capture[i]->query_cap_name()+" dives for cover and the poisoned bolts miss "+capture[i]->query_possessive()+"!",capture[i]);
  }
  }
  }
  return 1;
}
