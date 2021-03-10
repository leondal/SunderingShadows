#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("gold bracelet");
   set_short("%^YELLOW%^Gold Bracelet%^RESET%^");
   set_id(({"bracelet","gold bracelet"}));
   set_long("%^YELLOW%^This is an exquisite bracelet made out of solid gold."+
   " It is quite thick and rather heavy for a bracelet. It lays flat against"+
   " your wrist, and is about an inch and a half wide. This is obviously"+
   " something worn by the rich to flaunt their wealth.");
   set_weight(2);
   set_type("ring");
   set_limbs(({"right arm"}));
   set_value(750);
   set_wear("%^YELLOW%^You slip the golden bracelet over your wrist.");
   set_size(random(3)+1);
}
