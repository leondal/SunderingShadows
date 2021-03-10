#include <std.h>
inherit OBJECT;

void create()
{
   ::create();
   set_name("pasque flower");
   set_short("%^RESET%^%^MAGENTA%^A p%^RESET%^a%^MAGENTA%^sque f%^RESET%^l%^MAGENTA%^ower%^RESET%^");
   set_id(({"flower","pasque","pasque flower"}));
   set_long("%^MAGENTA%^This is a pasque flower.  It has several "+
   "small pedals that range from a %^BOLD%^dark lavender%^RESET%^%^MAGENTA%^ to "+
   "%^RESET%^white%^MAGENTA%^.  The center of the flower is yellow.   "+
   "The stem of the flower covered in silky hairs.%^RESET%^");
   set_weight(1);
   set_value(5);
   set_cointype("silver");
}

void save_me(string file) { return 1; }