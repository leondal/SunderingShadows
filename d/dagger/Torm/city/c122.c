#include "../tormdefs.h"
#include <std.h>
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Grand stairs",
  );
  set_property("indoors",1);
  set_long(
 "  These wide ornate stairs lead up onto a balcony where a guard is usually posted and then circle from there to end up facing almost directly above you."
  "  Paintings and tapestries line the marble walls and there are bright gleams from the gilding on the trim of nearly everything, from the edge of the stairs to the banisters and light fixtures."
  );
  set_exits(([
  "east":TCITY+"c123",
  "stairs":TCITY+"c137",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
  "stairs":"These wide marble stairs lead up to the second story of the mansion.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
  set_pre_exit_functions(({"stairs"}),({"block"}));
}
void reset(){
  ::reset();
  if(!present("torm city guard")) new(MON+"guard2")->move(TO);
  }
int block(){
  if(avatarp(TP))return 1;
  if(present("torm guard")){
  tell_room(TO,"The guard moves to block the stairs.");
  return 0;
}
  return 1;
}
