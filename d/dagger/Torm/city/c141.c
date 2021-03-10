#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Hallway on the second floor of Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This hallway goes north and south, and opens into a door to the west through which you can smell fresh baked bread.  The walls are covered"+
   " in paintings and tapestries, and the marble floor is clean and"+
   " polished."
  );
  set_exits(([
  "north":TCITY+"c138",
  "west":TCITY+"c140",
  "south":TCITY+"c144",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
