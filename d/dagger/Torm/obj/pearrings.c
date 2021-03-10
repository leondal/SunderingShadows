#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("pearl earrings");
   set_short("%^BOLD%^%^WHITE%^Pearl Earrings%^RESET%^");
   set_id(({"pearl earrings","earrings"}));
   set_long("%^BOLD%^These are a pair of large white pearl earrings. They"+
   " are set on a silver stud that can't even be seen, the pearl is so"+
   " large. They can be worn through holes in your ears.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"head"}));
   set_value(125);
   set_wear("You slip the studs in your ears, easily fastening the pearl earrings into place.");
   set_remove("You unfasten the studs, taking the pearl earrings out.");
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
