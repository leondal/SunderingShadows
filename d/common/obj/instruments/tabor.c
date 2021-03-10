//tabor.c - For instrument file coded by Circe 11/28/03
#include <std.h>

inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("tabor");
   set_short("A small tabor");
   set_id(({"tabor","small tabor","instrument"}));
   set_long("This specialized drum hangs from a leather strap worn across "+
      "the musician's chest.  The drum is roughly one foot in diameter and about "+
      "two feet long.  Both ends are stretched with tanned skin, and the bottom drum "+
      "head has bands of gut stretched across it, which gives the drum a distinctive "+
      "rattle.  The tabor is light enough to wear comfortably, and it is easily played "+
      "by tapping the top drumhead with the fingers.");
   set_weight(3);
   set_value(100);
   set_lore("Highly prized by dwarves, the tabor is often worn into battle to keep "+
      "lively marching rhythm going.  Dwarves also enjoy the tabor simply for entertainment, "+
      "and many dwarven taverns employ a musician playing the tabor and singing rousing war "+
      "songs.  Other races employ the tabor for battle as well, but none loves it like the dwarves.");
}

