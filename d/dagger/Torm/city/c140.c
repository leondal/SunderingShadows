#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Kitchen in Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This small kitchen looks like it was moved up here when the bottom floor was renovated and turned into the town hall from the mansion it used to be."
    "  It's very neat and everything is in its place.  There is a large"+
    " stove on one end, and there are several cabinets of pots, pans,"+
    " dishes, and silverware."+
    "  There is a small table here for the staff, while the rest of the house hold up here must take their meals elsewhere."
  );
  set_exits(([
  "east":TCITY+"c141",
  ]));
  set_items(([
   "stove" : "There is a very large stove in one corner of the small"+
   " kitchen. It is kept very clean.",
   "table" : "There is a small table for the staff to eat at while"+
   " they are busy preparing everyone else's meals.",
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "table":"It's a sturdy wooden table, with 4 simple wooden chairs around it.",
    "chairs":"Backless three legged chairs, almost stools, but sturdy enough.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
