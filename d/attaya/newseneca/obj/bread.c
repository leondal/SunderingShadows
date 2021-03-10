//bread.c - Bread for the mage tower of new Seneca
//~Circe~ 1/3/07
inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
   set_name("bread");
   set_id(({"bread","loaf","golden loaf","golden bread","golden loaf of bread","food"}));
   set_strength(15);
   set_weight(1);
   set_short("%^RESET%^%^ORANGE%^A golden loaf of bread%^RESET%^");
   set_destroy();
   set_long("%^RESET%^%^ORANGE%^This beautiful loaf is "+
      "crusty and heavy, though the inside is filled with "+
      "soft %^BOLD%^%^WHITE%^white bread%^RESET%^%^ORANGE%^.  "+
      "Several pats of %^YELLOW%^butter %^RESET%^%^ORANGE%^"+
      "are provided alongside the bread, and it seems almost "+
      "large enough to make a meal in itself.%^RESET%^");
   set_my_mess("The warm bread has a delicious softness with just a hint of butter.");
   set_your_mess("enjoys a soft loaf of bread.");
}
