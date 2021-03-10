#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
   "Hallway on the second floor of Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This hall wall turns west to a flight of stairs and south towards the center of the building."
  "  A large picture window on the northwall overlooks a patio outside the building."
  "  Double doors on the other side of the hallway from the staircase lead to a bedroom."
  );
  set_exits(([
  "west":TCITY+"c137",
  "east":TCITY+"c139",
  "south":TCITY+"c141",
  ]));
  set_items(([
  "windor":"It overlooks a patio on the north side of the building just under this window.",
  "double doors":"They stand open and lead to the west.",
  "doors":"They stand open and lead to the west.",
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
      (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
