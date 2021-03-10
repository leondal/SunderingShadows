#include <std.h>
#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short(
    "Balcony overlooking a park"
  );
  set_long(
    "  This balcony overlooks Torm's town park."
    "  The white wood structure has many gilded braces and an iron railing runs around its edge."
    "  Butterflies flit up from the park below along the sounds of Torm's citizens and visitors during the day."
  );
  set_exits(([
  "east":TCITY+"c136",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
