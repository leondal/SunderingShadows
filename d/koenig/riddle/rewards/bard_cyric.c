//bard_cyric.c - Bard of cyric reward for Nereid Riddle Quest.  Circe 1/22/04
#include <std.h>
#include "../../nereid.h"

inherit ANGERDARK;

void create(){
    ::create();
//    set_name("cyric instrument");
    set_id(({"set of ivory bones","bones","set of bones","ivory bones","instrument"}));
    set_obvious_short("A set of ivory bones");
    set_short("%^BOLD%^%^WHITE%^Bones of %^RESET%^%^MAGENTA%^Madness%^RESET%^");
    set_long(
@CIRCE
%^BOLD%^%^WHITE%^A pair of ivory bone make up this odd instrument.  The bones were a common percussion instrument of the past, but few find a use for them now days.  The bones have been bleached a bright ivory shade and are set with %^RESET%^%^MAGENTA%^deep purple%^BOLD%^%^WHITE%^ runes that one could read.  The bones are struck against each other and produce a wild and chaotic sound that tends to drive most sane people crazy when having to hear it over and over and over again.
CIRCE
    );
    set_read("%^MAGENTA%^May these bones aid you in your deceptions and drive "+
       "your enemies mad.  You may use the bones to "+
       "%^WHITE%^<%^MAGENTA%^anger%^WHITE%^> %^MAGENTA%^those around you for no reason or "+
       "%^WHITE%^<%^MAGENTA%^play%^WHITE%^> %^MAGENTA%^to create a "+
       "darkness to hide the truth from them.");
    set_weight(8);
    set_value(0);
    set_lore("These ivory bones seem to have been taken from an elf, and "+
       "indeed, the legend surrounding them says they are the shinbones of "+
       "a discontented elf who refused to call out to the Prince of Lies.  "+
       "The Dark Sun showed him visions of the terror that was befalling his "+
       "village, but the elf refused to believe the illusions.  In the end, the "+
       "elf's valor brought about only the village's destruction and his own "+
       "murder - although a piece of him does live on in this gruesome instrument "+
       "highly sought after by minstrels in the Dark Sun's service.");
    set_property("lore difficulty",12);
}
