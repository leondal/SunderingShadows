#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Hallway on the second floor of Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
    "  The hallway leads north from here towards the center of Torm's townhall."
   "  There are open doorways to the east and west here and a large window is set in the south wall."
  );
  set_exits(([
  "west":TCITY+"c143",
  "north":TCITY+"c141",
  "east":TCITY+"c145",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
   "window":"This window over looks the front of the mansion's grounds and into the marketplace to the south.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
