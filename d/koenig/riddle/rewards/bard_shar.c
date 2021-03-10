//bard_shar.c - Bard of Shar reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERDARK;

void create(){
    ::create();
//    set_name("shar instrument");
    set_id(({"darkwood lyre","lyre","instrument"}));
    set_short("%^BOLD%^%^BLACK%^A darkwood lyre%^RESET%^");
    set_long(
      "%^BOLD%^%^BLACK%^Simply carved from the deep black darkwood, this "+
      "lyre possesses a graceful elegance.  The round body is smooth and polished "+
      "but seems somehow to absorb, rather than reflect, %^YELLOW%^light%^BLACK%^.  The arms and "+
      "crossbar are made of jet as black as the %^BLUE%^abyss%^BLACK%^, and "+
      "the strings seem made of %^BLUE%^night %^BLACK%^itself.  The only "+
      "embellishment on this lyre is a ring of scrollwork carved around the "+
      "edge of the body.  Looking closer, it seems that the 'scrollwork' is a "+
      "series of interlocked kukris and chakram.  A message is also concealed "+
      "within this deadly decoration."
    );
    set_read("%^BLUE%^May the power of the night flow through you to spread "+
       "malice and loss to the world.  You may use this lyre to "+
       "%^WHITE%^<%^BLUE%^anger%^WHITE%^> %^BLUE%^the foolish into attacking you, or "+
       "%^WHITE%^<%^BLUE%^play%^WHITE%^> %^BLUE%^to create an orb of darkness.");
    set_weight(8);
    set_value(0);
    set_lore("Created from the stuff of the night by the Lady of Loss herself, "+
       "these lyres are granted to only her most faithful.  Bards of the Dark "+
       "Goddess are rare, but she understands the fantastic addition they can "+
       "make.  This instrument is one of the few boons granted her followers, "+
       "who endure loss as well as spread it to others.  It is said that Shar "+
       "uses her own essence to create these lyres, and no mortal has been able "+
       "to reproduce the effect.");
    set_property("lore difficulty",12);
}
