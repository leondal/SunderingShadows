//bard_talos.c - Bard of Talos reward for Nereid Riddle Quest.  Circe 12/18/03
#include <std.h>
#include "../../nereid.h"

inherit ANGERDARK;

void create(){
    ::create();
//    set_name("talos instrument");
    set_id(({"blackened bongo drums","bongo drums","drums","set","bongos","instrument"}));
    set_short("%^BOLD%^%^BLACK%^A set of blackened bongo drums%^RESET%^");
    set_long(
      "This set of bongo drums has been lacquered a deep shade of "+
      "%^BOLD%^%^BLACK%^black%^RESET%^.  The drumheads are made of "+
      "thin pieces of %^BOLD%^%^BLACK%^blackened leather %^RESET%^left "+
      "jagged around the edges and tied down with %^YELLOW%^golden "+
      "cording %^RESET%^that flashes against the side of the drum like "+
      "%^YELLOW%^lightning%^RESET%^.  The top of the drum appears to have "+
      "a swirling %^BLUE%^thunderstorm %^RESET%^that moves continuously "+
      "across the two drumheads.  When the drummer strikes the head "+
      "particularly hard, the drum produces a %^YELLOW%^flash %^RESET%^"+
      "that illuminates the musician's face, followed by a low, rolling "+
      "peal of %^BLUE%^thunder%^RESET%^.  A message swirls within the "+
      "image of the thunderstorm."
    );
    set_read("%^BOLD%^%^BLUE%^May the fury of the storms overcome your "+
       "foes.  You may use these bongo drums to call on the might of the storms to "+
       "%^YELLOW%^<%^BLUE%^anger%^YELLOW%^> %^BLUE%^those who dare oppose you or "+
       "%^YELLOW%^<%^BLUE%^play%^YELLOW%^> %^BLUE%^to create a globe of darkness.");
    set_weight(8);
    set_value(0);
    set_lore("The first of these bongo drums was gifted to the mad "+
       "cleric of Talos, Ryatham Quicksilver, who dedicated his life "+
       "to spreading the lore and will of the Stormlord.  Legend holds that "+
       "Ryatham was preaching his message one day from a cliff overlooking "+
       "the ocean in the Dagger area when a blinding storm blew up all "+
       "around him.  Nine bolts of lightning struck the ground at his feet, "+
       "electrifying him and turning his hair permanently white.  Ryatham "+
       "considered himself blessed, and sure enough, he awakened to find this "+
       "set of drums at his feet.  No mortal has ever created a set of drums "+
       "quite like these, and their appearance is always taken as a sign of "+
       "the Stormlord's blessing.");
    set_property("lore difficulty",12);
}
