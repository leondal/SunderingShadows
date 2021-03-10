#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
inherit TOWN;
#define LIST "torm_official_position_list"
void create(){
  ::create();
  set_short(
  "Guard room"
  );
  set_property("indoors",1);
  set_long(
  "  This hallway leading west to the town hall and east to the barracks ussually has a few of the Torm city guard standing here at attention."
  "  Tapestries line the walls and a door to the south leads out onto the steps at the front of the hall."
  );
  set_exits(([
  "east":TCITY+"c129",
  "west":TCITY+"c127",
  "south":TCITY+"c131",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
  set_pre_exit_functions(({"east"}),({"block"}));
}
void reset(){
  ::reset();
  if(!present("guard")) new(MON+"guard2")->move(TO);
  if(!present("guard 2")) new(MON+"guard4")->move(TO);
  }
int block(){
  if(avatarp(TP))return 1;
  if(present("torm guard") 
  && member_array(TPQN,SAVE_D->query_array(LIST)) == -1){
  tell_room(this_object(),"The guard stands in front of the east doors");
  return 0;
}
  return 1;
}
