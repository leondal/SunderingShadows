#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("pearl necklace");
   set_short("%^BOLD%^%^WHITE%^Pearl Necklace%^RESET%^");
   set_id(({"pearl necklace","necklace","pearls"}));
   set_long("This is a gorgeous strand of large white pearls. They have"+
   " been carefully strung on the necklace with very little space between"+
   " each pearl. The pearls in the very front of the necklace are slightly"+
   " larger, gradually decreasing in size symmetrically.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_value(500);
   set_wear("%^BOLD%^You slip the pearl necklace around your neck and feel beautiful.");
   set_size(random(3)+1);
}
