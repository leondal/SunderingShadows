//hautbois.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("hautbois");
   set_short("A slender hautbois");
   set_id(({"hautbois","slender hautbois","instrument"}));
   set_long("This slender wooden instrument looks to be a far more intricate version "+
      "of the recorder flute.  It has a complex system of 18 fingerholes, some of which "+
      "are covered by cleverly-designed pads that close when a lever is pressed.  The "+
      "instrument ends in a small bell-shaped opening that gives the wind instrument a soft, resonant "+
      "sound.  The mouthpiece of the hautbois uses very narrow reeds.");
   set_weight(3);
   set_value(450);
   set_lore("The hautbois is a softer-toned variant of the shawm.  Both instruments "+
      "are highly prized by well-to-do humans, and the ability to play one grants "+
      "the musician with a certain amoung of prestige among nobles.  Many young "+
      "aristocrats have taken up the shawm or the hautbois.");
}

