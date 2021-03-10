//bard_istishia.c - Bard of Istishia reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit CALMLIGHT;

void create(){
    ::create();
//    set_name("istishia instrument");
    set_id(({"seashell lyre","lyre","instrument"}));
    set_short("%^BOLD%^%^CYAN%^A seashell lyre%^RESET%^");
    set_long(
      "%^BOLD%^%^CYAN%^A wide %^WHITE%^seashell %^CYAN%^the color of "+
      "the %^BLUE%^deep s%^GREEN%^e%^BLUE%^a %^CYAN%^forms the body "+
      "of this beautiful lyre.  The crossbar and arms are %^WHITE%^bone "+
      "colored%^CYAN%^, and the strings are soft and a fluid %^BLUE%^blue%^CYAN%^.  "+
      "Upon closer examination, the strings look to be made of %^BLUE%^water"+
      "%^CYAN%^ flowing in slender lines from the crossbar to the shell.  "+
      "No artificial decoration adorns the harp, and it pays fitting "+
      "tribute to the waterways of the world.  Carved along the crossbar "+
      "is a simple, flowing script."
    );
    set_read("%^BOLD%^%^WHITE%^May the light within this lyre serve "+
       "to brighten the dark ways of the sea, allowing you to see your "+
       "path clearly, and may the power of the music calm the vicious waves "+
       "rising against you.  You may use the lyre to "+
       "%^CYAN%^<%^WHITE%^calm%^CYAN%^> %^WHITE%^those who attack you or "+
       "%^CYAN%^<%^WHITE%^play%^CYAN%^> %^WHITE%^to create a bright light.");
    set_weight(8);
    set_value(0);
    set_lore("Created entirely by the natural materials of the sea, "+
       "these harps are prized by the followers of the Water Lord, and are "+
       "said to be discovered only by those most faithful to him.  No one "+
       "knows the secret of the enchanted water strings, and many believe "+
       "Ishtishia himself is the only one with the mastery of water "+
       "necessary to make them.");
    set_property("lore difficulty",12);
}
