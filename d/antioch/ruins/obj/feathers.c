#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("phoenix feathers");
   set_short("%^BOLD%^%^RED%^Some phoenix feathers%^RESET%^");
   set_id(({"feathers","phoenix feathers"}));
   set_long("%^BOLD%^%^RED%^This is handful of fiery phoenix feathers."+
   " They must be the tail feathers because they are quite long and"+
   " beautiful, mostly red but they have traces of %^CYAN%^blue%^RED%^"+
   " and %^YELLOW%^yellow%^RED%^ in each one. They aren't flaming"+
   " anymore, but they are still quite beautiful.");
   set_weight(7);
   set_value(3000);
   set_property("brazier sacrifice",1);
}
