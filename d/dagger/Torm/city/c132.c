#include <std.h>
#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Barracks in the Torm town hall"
  );
  set_property("indoors",1);
  set_long(
  "  Lines of bunk beds are arranged along the walls here and stretch off to the north."
  "  Armor and weapons are neatly placed on racks between the bunks that have occupants with empty ones showing the ones on duty now."+
  "  Everything is kept neat and tidy in here."
  );
  set_exits(([
  "north":TCITY+"c129",
  ]));
  set_items(([
  ({"beds","bunks","bunk beds"}) : "There are several bunk beds here,"+
  " some of them filled by sleeping guards, and others are empty.",
  "racks" : "There are neat racks that contain the guard's armor and"+
  " weapons.",
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
void reset(){
  ::reset();
  if(!present("guard")) new(MON+"guard2")->move(TO);
  if(!present("guard 2")) new(MON+"guard4")->move(TO);
  }
