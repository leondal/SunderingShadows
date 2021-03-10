#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("whalebone choker");
   set_short("Whalebone choker");
   set_id(({"choker","whalebone choker","whale bone choker"}));
   set_long("This choker is made from the bones of a whale that have been"+
   " carefully cut and the edges smoothed. The choker consists of two"+
   " layers of whalebone that are slightly longer in the front and narrow"+
   " as it reaches the back. An adjustable steel clasp is in the back.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear("You adjust the whalebone choker to fit around your neck.");
   set_remove("You undo the clasp and remove the choker.");
   set_value(250);
}

int query_size()
{
   if(!objectp(ETO)) return 2;
   return ETO->query_size();
}
