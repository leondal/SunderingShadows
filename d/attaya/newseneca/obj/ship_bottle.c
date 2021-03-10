//~Circe~ 10/31/07
#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_name("ship in a bottle");
   set_short("%^RESET%^%^CYAN%^a tiny %^BOLD%^%^WHITE%^ship "+
      "%^RESET%^%^CYAN%^in a %^BOLD%^bottle%^RESET%^");
   set_id(({"bottle","ship in a bottle","bottle ship","tiny ship","tiny ship in a bottle","ship"}));
   set_long("%^RESET%^%^CYAN%^This neat little trinket is a bottle "+
      "made of %^BOLD%^glass %^RESET%^%^CYAN%^showing very "+
      "few imperfections.  An impossibly narrow bottle neck "+
      "has been caped with %^ORANGE%^cork%^CYAN%^, sealing "+
      "a detailed tiny %^BOLD%^%^WHITE%^ship %^RESET%^%^CYAN%^"+
      "inside!  Studying the ship, you see that every little "+
      "detail has been included, from %^RESET%^fabric sails "+
      "%^CYAN%^to a long %^ORANGE%^beak%^CYAN%^, identifying "+
      "this ship as a galleon.  For a finishing touch, the "+
      "bottom of the bottle is filled with some sort of "+
      "clear, solid material that looks exactly like "+
      "%^BOLD%^%^BLUE%^water%^RESET%^%^CYAN%^.  How did someone "+
      "ever get such a perfect little construction inside a bottle "+
      "with a neck that narrow?%^RESET%^");
   set_lore("The ship inside this small bottle is a galleon "+
      "of Tormish design.  Contrary to popular belief, this "+
      "ship was actually partially assembled before it was "+
      "placed in the bottle - not constructed inside it.  "+
      "By clever design, the sails collapse onto the ship deck, "+
      "and the hull itself gives a bit, allowing the artist "+
      "to squeeze the mostly completed ship into the bottle "+
      "and then use long-handled tools to raise the sails and "+
      "set everything in place.");
   set_property("lore difficulty",10);
   set_weight(2);
   set_value(850);
}