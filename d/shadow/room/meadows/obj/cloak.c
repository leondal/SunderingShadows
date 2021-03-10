//updated by Circe with new desc, lore, etc, by Shar 6/7/04
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("red cloak");
   set_obvious_short("%^BOLD%^%^RED%^A red cloak%^RESET%^");
   set_short("%^RESET%^%^RED%^Cape of the %^BOLD%^Ruby%^RESET%^%^RED%^ "+
      "Heart%^RESET%^");
   set_id(({"cloak","red cloak","cape","red cape","cape of the ruby heart"}));
   set_long(
@CIRCE
%^RED%^This rich ruby red silken cape is extremely lightweight.  The cape is cut into a fashion that is called a 'half cape', meaning that it just covers one's back.  Interwoven into the red silk are %^BOLD%^metallic red%^RESET%^%^RED%^ threads that give the cape a sparkle.  A thin %^RESET%^silver chain%^RED%^ serves as the only closure for the cape.  From the chain dangles two heart shapes made of ruby.  One features a tiny %^RESET%^silver dagger%^RED%^ through the heart, while the other is mounted onto a %^RESET%^silver starburst%^RED%^.  The images are quite small, no bigger than the tip of your finger.%^RESET%^
CIRCE
   );
   set_lore(
@CIRCE
The Cape of the Ruby Heart was once rumored to have been an order from the a lost church of hedonists that devoted themselves to the more sensual side of life.  The Church though claims no ties to this rogue cluster of followers in the past.  The Ruby Hearts, as they were called, were wildly known for their healthy appetite for fine food, sensual pleasures and love of wine and liquor.  The followers of dawn though denies any ties to this organization and the excesses they partook in.%^RESET%^
CIRCE
   );
   set_property("lore difficulty",10);
   set_weight(3);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(40);
   if(!random(2)) set_property("enchantment",1);
   set_wear("%^BOLD%^%^RED%^You fasten the chain around your neck and put on the red cloak.");
   set_remove("You undo the chain and slip off the red cloak.");
}
