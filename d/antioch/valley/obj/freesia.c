#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("freesia");
   set_short("A few sprigs of freesia");
   set_id(({"freesia","sprigs of freesia","sprigs","freesia sprigs"}));
   set_long("%^BOLD%^There are a few sprigs of freesia here, they come"+
   " on long dark green stems. The flowers are dainty and white and look"+
   " like they might blow away in a hard breeze.");
   set_weight(1);
   set_value(1);
   set_cointype("copper");
}

void save_me(string file) { return 1; }
 