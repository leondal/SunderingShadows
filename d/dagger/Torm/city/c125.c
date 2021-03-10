#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
#include <daemons.h>
inherit TOWN;
#define LIST "torm_official_position_list"
void create(){
  ::create();
  set_short(
    "Barracks in Torm's Town Hall"
  );
  set_property("indoors",1);
  set_long(
  "  There are two cots here partition away from a rack of arms and armor."  
  "  A desk with a few papers on it sits against a far wall beside a rack of spears, and a barred door leads to some stairs down."
  );
  set_exits(([
  "west":TCITY+"c124",
  "stairs":TCITY+"c151",
  "south":TCITY+"c129",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
  set_pre_exit_functions(({"stairs"}),({"block"}));
}
void reset(){
  ::reset();
  if(!present("sergeant")) new(MON+"guardse")->move(TO);
  if(!present("sergeant 2")) new(MON+"guardse")->move(TO);
  }
int block(){
  if(avatarp(this_player())) return 1;
  if(present("torm guard")
  && member_array(TPQN,SAVE_D->query_array(LIST)) == -1) {
  tell_room(this_object(),"The sergeant moves to block the stairs.");
  return 0;
  }
  return 1;
}
