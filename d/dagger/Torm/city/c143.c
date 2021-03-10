#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Servants' quarters in Torm's Townhall"
  );
  set_property("indoors",1);
  set_long(
    "  These are the servants' quarters in the townhall."
    "  There are a few partitions walling off the individual bunks, and it's obvious this room was not meant for such use when it was designed."+
    "  There is really not much room here at all, you can't imagine"+
    " anyone actually living here for any length of time."
  );
  set_exits(([
  "east":TCITY+"c144",
  ]));
  set_items(([
  "walls":"The marble walls are covered in paintings and tapestries.",
    "floor":"The marble floor shows signs of much travel recently.  It's clean and polished but cracked and needing repairs in places.",
    (({"ceiling","roof"})):"The ceiling holds globes that give a soft continous light that accents the gilding on the decorations and tapestries on the walls.",
    "bunks":"There aren't many personal effects here, the staff must have homes in the city as well.",
  "partitions":"There are makeshift walls inbetween the bunks to affort a small measure of privacy.",
    "tapestries":"Ornate gilded tapestries cover the marble walls."
  ]));
}
void reset(){
  ::reset();
  if(!present("maid")) new(MON+"maid")->move(this_object());
}
