//harmonica.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("harmonica");
   set_short("A metal harmonica");
   set_id(({"harmonica","metal harmonica","instrument"}));
   set_long("A refinement of the wooden pan pipes, this metal instrument is "+
      "small and rectangular in shape.  Many small metal tubes are inclosed within "+
      "a thin metal box, and the musician simply blows air through one side while covering "+
      "various parts of the other side with his hand.  The music produced is rustic and "+
      "sometimes discordant.");
   set_weight(1);
   set_value(150);
   set_lore("The high, buzzing noises of the harmonica make it a delight among halflings "+
      "and gnomes.  Commoners and other humans living in rural areas also find the music "+
      "of the harmonica much to their liking, and it is often a favorite among the minstrels "+
      "there.");
}

