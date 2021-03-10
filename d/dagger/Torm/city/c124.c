#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Captain's room"
  );
  set_property("indoors",1);
  set_long(
  "  This room looks as though there was some attempt to make it elegant, but has since been converted into what appears to be a war room."
  "  Charts of the surrounding country side line the walls and there are ledgers on the two large desks in the room with troop numbers and orders."
  "  A small cot is almost lost in the back of the room behind an armor stand and a beat-up practice dummy."
  );
  set_exits(([
  "east":TCITY+"c125",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
void reset(){
  ::reset();
  if(!present("captain")) new(MON+"guardca")->move(this_object());
}
