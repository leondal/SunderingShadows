//bard_anhur.c - Bard of Anhur reward for Nereid Riddle Quest.  Circe 5/23/08
#include <std.h>
#include "../../nereid.h"

inherit ANGERDETECT;

void create(){
    ::create();
//    set_name("anhur instrument");
    set_id(({"drum","battle drum","worn battle drum","instrument"}));
    set_short("%^RESET%^%^ORANGE%^A worn battle drum%^RESET%^");
    set_long(
      "%^ORANGE%^This simple drum is fitted with a %^BOLD%^%^BLACK%^"+
      "leather strap %^RESET%^%^ORANGE%^designed to be worn over the "+
      "shoulder and across the chest, allowing the drum itself to "+
      "rest against the hip.  The circular drum case is lacquered "+
      "%^BOLD%^%^RED%^bright red%^RESET%^%^ORANGE%^ and decorated "+
      "with %^YELLOW%^golden %^RESET%^%^ORANGE%^trim.  The taut "+
      "%^RESET%^drumhead %^ORANGE%^is a pale tan in color and "+
      "painted with the symbol of the %^BOLD%^%^BLUE%^Falcon "+
      "%^WHITE%^of %^RED%^War%^RESET%^%^ORANGE%^.  Circling around "+
      "the outer edge of the drumhead is a message you might "+
      "%^BOLD%^%^WHITE%^read%^RESET%^%^ORANGE%^.  The drum may "+
      "be played with either fingertips or drumsticks, and its "+
      "music often accompanies the righteous on the battlefield.%^RESET%^");
    set_read("%^BOLD%^%^WHITE%^May the might of the righteous lead "+
      "you to victory.  You may use this drum to call on the fury "+
      "of war to %^BLUE%^<%^RED%^anger%^BLUE%^> %^WHITE%^those who impede you or "+
       "%^BLUE%^<%^RED%^play%^BLUE%^> %^WHITE%^to detect magic around you.%^RESET%^");
    set_weight(8);
    set_value(0);
    set_lore("These drums are created by the faithful of Anhur, "+
      "and each is blessed by a high cleric before being "+
      "commissioned for use in battle.  It is widely believed "+
      "that no battle has been lost while the music of the "+
      "Anhurran drums raged.  Whether or not this myth is true, "+
      "those who follow the Falcon of War are always heartened "+
      "whenever they hear the distinctive sound produced by "+
      "one of these drums.");
    set_property("lore difficulty",12);
}
