#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Top of a staircase in Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
  "  There is a broad set of stairs here that lead down towards the town hall."
    "  Large stained glass windows on the wall oposite you, far above the stairs, cast prisms of light across the staircase."
  "  There is a large tapestry at the top of the stairs on the north wall wile a hall way goes east."
  );
  set_exits(([
  "stairs":TCITY+"c122",
  "east":TCITY+"c138",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
  "stairs":"These wide marble stairs lead up to the second story of the mansion.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
  "tapestries":"Ornate gulded tapestries cover the marble walls.",
    "tapestry":"This large tapestry shows a group of adventures standing over a great bowl-shaped depression where the remains of some great spherical many eyed creature lies."
  ]));
  set_pre_exit_functions(({"east"}),({"block"}));
}
void reset(){
  ::reset();
  if(!present("torm city guard")) new(MON+"guard2")->move(this_object());
}
int block(){
  if(avatarp(this_player())) return 1;
  if(present("torm guard")){
  tell_room(this_object(),"The guard moves to block the hallway.");
  return 0;
  }
  return 1;
}
