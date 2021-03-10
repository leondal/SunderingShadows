//bard_lathander.c - Bard of Lathander reward for Nereid Riddle Quest.  Circe 12/10/03
#include <std.h>
#include "../../nereid.h"

inherit RALLYLIGHT;

void create(){
    ::create();
//    set_name("lathander instrument");
    set_id(({"golden lap-harp","lap-harp","harp","instrument"}));
    set_short("%^YELLOW%^A golden lap-harp%^RESET%^");
    set_long(
      "%^BOLD%^%^WHITE%^This small lap-harp is made of highly polished %^YELLOW%^gold "+
      "%^WHITE%^that shimmers in the light.  The harp is about two "+
      "and a half feet tall and a little over a foot wide.  The slender harp "+
      "is carved with images of the rising sun, and the seventeen wires strung "+
      "across the frame are magically colored in shades of %^RED%^red%^WHITE%^, "+
      "%^MAGENTA%^rose%^WHITE%^,%^RESET%^%^ORANGE%^ orange%^BOLD%^%^WHITE%^, "+
      "and %^YELLOW%^yellow%^WHITE%^.  The top of the harp is fitted with a "+
      "multi-faceted %^MAGENTA%^rose quartz %^WHITE%^that reflects the light "+
      "of the sun.  There is a message engraved along the inside of the harp."
    );
    set_read("%^YELLOW%^May this harp bring you light to brighten your path "+
       "and strength to withstand the darkness.  You may use the harp to "+
       "%^MAGENTA%^<%^YELLOW%^rally%^MAGENTA%^> %^YELLOW%^your companions or "+
       "%^MAGENTA%^<%^YELLOW%^play%^MAGENTA%^> %^YELLOW%^to create a bright light.");
    set_weight(8);
    set_value(0);
    set_lore("This beautiful lap-harp has been dedicated to produce melodic "+
       "music in reverence to the Morninglord.  It is said that only his most "+
       "faithful will find this legendary instrument, and it is a sign of his "+
       "blessing.  The creation of these instruments are unknown, and it is "+
       "rumored in hushed tones that Lathander himself crafts them from sunbeams.");
    set_property("lore difficulty",12);
}
