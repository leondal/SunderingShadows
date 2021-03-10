#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("pansies");
   set_short("A handful of pansies");
   set_id(({"pansies","handful of pansies"}));
   set_long("This is a rather large handful of many multi-hued pansies."+
   " They are all two-toned with combinations of %^MAGENTA%^purple%^RESET%^,"+
   " %^BLUE%^blue%^RESET%^, %^YELLOW%^yellow%^RESET%^ and %^BOLD%^white%^RESET%^.");
   set_weight(1);
   set_value(5);
   set_cointype("silver");
}

void save_me(string file) { return 1; }
