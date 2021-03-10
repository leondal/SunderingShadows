//bones.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("bones");
   set_short("A set of bones");
   set_id(({"bones","set","bone set","set of bones","instrument"}));
   set_long("This set of small wooden blocks actually looks like little darkened "+
      "bones, hence the name.  The set is designed to look like the finger bones "+
      "of a humanoid, complete with a large knuckle at the far end.  The bones are "+
      "all tapered to allow easy insertion between the musician's fingers.  "+
      "This unusual instrument is played by striking various bones together, producing "+
      "a variety of hollow pitches.  The best players usually amaze audiences as much "+
      "with their deft maneuvering of so many pieces as with the music itself.");
   set_weight(3);
   set_value(200);
   set_lore("This type of instrument is a favorite among the savage races, particularly "+
      "kobolds.  They prize it for the grizzly appearance it gives and for the haunting "+
      "tones it produces.  Many warriors have fled in fear at the sound of a kobold horde coming "+
      "with the leading minstrels pounding out their tunes.");
}

