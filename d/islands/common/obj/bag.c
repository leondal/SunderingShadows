// coding fixed/cleaned up, and modified to resemble the usual bags of holding. ,) Nienne, 4/05.
#include <std.h>
inherit "/std/bag_logic";

void create() {
   ::create();
   set_id(({"bag","sack","bag of holding"}));
   set_name("bag");
   set_short("%^BLUE%^Bag of permanent holding%^RESET%^");
   set_obvious_short("%^BLUE%^%^BOLD%^A blue bag decorated with %^YELLOW%^r%^WHITE%^u%^YELLOW%^nes%^RESET%^");
   set_weight(5);
   set_long("%^WHITE%^%^BOLD%^This is a small bag that you can put things in, made of some unknown, but quite "
"resiliant, %^BLUE%^cobalt-blue cloth%^WHITE%^.  Around the opening of the bag appear %^YELLOW%^orn%^WHITE%^a"
"%^YELLOW%^te ru%^WHITE%^n%^YELLOW%^es%^WHITE%^ within the cloth, perhaps dyed there.  As you reach you notice "
"there is a lot more space in here than a normal bag of this size.%^RESET%^\nNOTE: This bag is to allow "
"players to carry the same amount of equipment with less sacks. Not for players to abuse.");
   set_lore("%^WHITE%^%^BOLD%^The great archmage Arkhiesan Korr is claimed to have been the first to have "
"found the means by which to make a bag of holding permanent.  Part of the original Brotherhood of the Sixteen "
"Sigils, he continued his research in secret after their group was disbanded.  His completed research, "
"however, was never found or disclosed, as very shortly after the discovery, he was reputed to have been eaten "
"by a great red wyrm.%^RESET%^");
   set_property("lore difficulty",14);
   set_value(10000);
//   set_value(1);
   set_property("no animate",1);
   set_max_internal_encumbrance(100);
}

int isMagic(){
   int x;
   x = ::isMagic();
   x = x+1;
   return x;
}
