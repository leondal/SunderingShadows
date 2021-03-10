#include <std.h>

inherit "/std/food.c";

void create(){
   ::create();
   set_name("orange");
   set_id(({"orange","juicy orange","ripe orange","food"}));
   set_strength(5);
   set_weight(1);
   set_short("%^RESET%^%^ORANGE%^A juicy ripe orange%^RESET%^");
   set_destroy();
   set_long("%^ORANGE%^This is a plump, juicy orange that looks "+
      "healthy and delicious.  A small stem with a %^GREEN%^leaf "+
      "%^ORANGE%^is still attached, attesting to the freshness "+
      "of this fruit.%^RESET%^");
   set_my_mess("You peel the orange and enjoy the fresh, juicy slices.");
   set_your_mess("peels and eats a juicy orange.");
}
