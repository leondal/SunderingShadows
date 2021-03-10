//mage_anhur.c - reward for Riddle Quest.  ~Circe~ 5/27/08
#include <std.h>
#include "../../nereid.h"
inherit MAGEROBES;

void create(){
   ::create();
   set_name("vestments of the righteous storm");
   set_id(({"robe","vestments","vestments of the righteous storm","righteous storm vestments"}));
   set_short("%^RESET%^%^ORANGE%^Vestments of the %^YELLOW%^Ri"+
      "%^BLACK%^g%^YELLOW%^hte%^BLUE%^o%^YELLOW%^us St%^RED%^o"+
      "%^YELLOW%^rm%^RESET%^");
   set_obvious_short("A midnight blue robe trimmed in gold");
   set_long("%^RESET%^%^BLUE%^Crafted from deep blue linen, these "+
      "beautiful robes are embroidered with %^BOLD%^royal blue "+
      "%^RESET%^%^BLUE%^thread picking out images of %^BOLD%^"+
      "hawks %^RESET%^%^BLUE%^clutching glittering %^YELLOW%^"+
      "lightning bolts%^RESET%^%^BLUE%^.  The edges of the robe "+
      "are trimmed with %^YELLOW%^golden satin%^RESET%^%^BLUE%^, "+
      "giving definition and a hint of sophistication to the "+
      "robes.  A huge embroidered %^BOLD%^%^RED%^hawk's head "+
      "%^RESET%^%^BLUE%^with predatory %^YELLOW%^golden eyes "+
      "%^RESET%^%^BLUE%^has been stitched onto the back of the "+
      "robe, while flat satin-lined pockets are cleverly "+
      "hidden along the seams on the wearer's hips.%^RESET%^");
   set_lore("Long crafted deep within the Tsarven empire where "+
      "the worship of Anhur has continued for centuries unbroken, "+
      "these robes have only recently made their appearance into "+
      "the northern reaches of the realms.  Each robe is blessed "+
      "by the high cleric of the local temple of Anhur, making "+
      "each robe a minor relic to be treasured by the one who "+
      "receives it.");
   set_property("lore difficulty",12);
   set_remove((:TO,"remove_func":));
}

int remove_func(){
   tell_object(ETO,"%^BOLD%^%^BLUE%^You relinquish the light "+
      "fabric of the vestments.%^RESET%^");
   return 1;
}
