// str bonus changed to work on new stat system. Nienne, 09/07. Redesigned desc/lore.
// str bonus changeed to do to work with new item bonuses.  Odin 8/19.
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("goblin girdle");
   set_id(({"girdle","goblin girdle","trinket covered girdle","trinket-covered girdle"}));
   set_short("%^RESET%^%^RED%^Go%^ORANGE%^b%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^RED%^n Girdle%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^tr%^BOLD%^%^BLACK%^ink%^RESET%^%^RED%^e%^ORANGE%^t-c%^YELLOW%^o%^BLACK%^ve%^RESET%^%^ORANGE%^r%^RESET%^e%^ORANGE%^d %^RED%^girdle%^RESET%^");
   set_long("This broad piece of %^ORANGE%^tough cloth %^RESET%^has obviously been scavenged from somewhere, "
"torn along the edges and frayed from long use.  It has been tied at the back to form some kind of thick belt"
", like a girdle, though it would only fit a small body.  All along its length are varied kinds of trinkets "
"and trophies, ranging from %^BOLD%^%^WHITE%^bones %^RESET%^and %^RED%^teeth %^RESET%^down to more gory "
"remains, one of which looks like a %^ORANGE%^human finger%^RESET%^.  It seems someone has been making quite a "
"collection.\n");
   set_lore("Such a collection of savage trophies is prized highly among goblinkind, as a show of their "
"victories and prowess.  Holding as many as this would gain a goblin high respect in their society, and any "
"among them would be proud to carry it.  Despite some scholars believing the actual girdle's design makes "
"them appear more attractive to others of their kin, this is a false rumor - it is only the number and source "
"of the trinkets upon it that award it any value among goblinkind.");
   set_property("lore difficulty",15);
   set_wear((:TO,"wear_me":));
   set_weight(3);
   set_size(1);
   set_value(350);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_property("enchantment",1);
}

int wear_me(){
   if(TP->query_level() < 9) {
      notify_fail("You are not experienced enough to utilize this equipment.");
      return 0;
   }
   if((string)ETO->query_race() != "goblin") {
     set_item_bonus("strength",0);
     tell_object(ETO,"%^RESET%^%^GREEN%^You feel a little uneasy wearing the scavenged girdle.%^RESET%^");
     return 1;
   }
   set_item_bonus("strength",2);
   tell_object(ETO,"%^RESET%^%^GREEN%^The memory of your many victories fills you with pride.%^RESET%^");
   return 1;
}
