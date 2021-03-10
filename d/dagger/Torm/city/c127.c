#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "South end of the Torm Town hall"
  );
  set_property("indoors",1);
  set_long(
    "  Torm's Town hall here is a meeting place for the merchants, nobles and more well to do citizens of Torm."
"  A huge table stretches north from here to the south end of the room, which is lined with countless chairs."
  "  The room is well lit and there are many tapestries on the walls, and a stained glass window in the north wall that sends light glittering across the room in sunlight and moonlight alike."
  );
  set_exits(([
  "west":TCITY+"c126",
  "north":TCITY+"c123",
  "east":TCITY+"c128",
  "south":TCITY+"c130",
  ]));
  set_items(([
  "chairs":"Hard uncomfortable looking chairs line the table.",
   "table":"This long table runs to the north and seems to be made for meetings of the city's government.",
  "window":"This large window has a random design on it but somehow puts you at unease with the way it reflects light through it.",
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
