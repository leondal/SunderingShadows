//fruit.c - Fruit for the mage tower of new Seneca
//~Circe~ 1/3/07
inherit "/std/food.c";

#include <std.h>

void create(){
   ::create();
   set_name("fruit");
   set_id(({"fruit","fresh fruit","platter","platter of fresh fruit","food"}));
   set_strength(25);
   set_weight(1);
   set_short("%^RESET%^%^GREEN%^A platter of %^BOLD%^%^RED%^f"+
      "%^MAGENTA%^r%^RESET%^%^ORANGE%^e%^RED%^s%^BOLD%^%^MAGENTA%^h "+
      "%^RESET%^%^MAGENTA%^f%^ORANGE%^r%^YELLOW%^u%^RED%^i"+
      "%^MAGENTA%^t%^RESET%^");
   set_destroy();
   set_long("%^RESET%^%^GREEN%^A green platter in the shape of "+
      "a leaf has been piled high with fresh fruit.  A sampling "+
      "of %^BOLD%^%^MAGENTA%^strawberries%^RESET%^%^GREEN%^, %^ORANGE%^"+
      "orange slices%^GREEN%^, %^YELLOW%^pineapple%^RESET%^%^GREEN%^, "+
      "and %^BOLD%^%^RED%^apple slices%^RESET%^%^GREEN%^ are "+
      "arranged around a dollup of %^RESET%^yogurt%^GREEN%^ "+
      "for a sweet meal.%^RESET%^");
   set_my_mess("The fresh fruit melts in your mouth, leaving a hint of sweetness.");
   set_your_mess("eats slices of fruit from a platter.");
}
