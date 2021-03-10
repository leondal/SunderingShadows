#include <std.h>
inherit "/std/food";

void create()
{
   ::create();
   set_name("strawberries");
   set_short("%^BOLD%^%^RED%^A handful of wild strawberries%^RESET%^");
   set_id(({"strawberries","wild strawberries"}));
   set_long("%^BOLD%^%^RED%^This is a handful of wild strawberries that"+
   " are perfectly ripe. They are small but they smell sweet and there"+
   " are several of them, enough for a good snack even if it won't fill"+
   " you up.");
   set_weight(1);
   set_value(0);
   set_destroy();
   set_strength(5);
   set_my_mess("%^BOLD%^%^RED%^The wild strawberries are sweet and juicy with a slight tarty tang.");
   set_your_mess("eats a handful of wild strawberries.");
}
