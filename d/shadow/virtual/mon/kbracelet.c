// New description by Lurue! Nienne, 05/08.
// str bonus changed to work on new stat system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("hemp bracelet");
   set_id(({"bracelet","hemp bracelet","woven band","band","band of koboldkin","woven band of koboldkin","moldy bracelet","mold covered bracelet"}));
   set_short("%^BOLD%^%^GREEN%^W%^RESET%^%^ORANGE%^o%^RESET%^v%^GREEN%^e%^BOLD%^n B%^RESET%^%^ORANGE%^a%^RESET%^n%^BOLD%^%^GREEN%^d of K%^RESET%^o%^ORANGE%^b%^GREEN%^o%^BOLD%^l%^BLACK%^d%^RESET%^%^GREEN%^k%^ORANGE%^i%^BOLD%^%^GREEN%^n%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^a %^BOLD%^m%^RESET%^%^CYAN%^o%^GREEN%^l%^BOLD%^d %^RESET%^%^GREEN%^covered %^BOLD%^h%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^m%^GREEN%^p %^RESET%^%^GREEN%^bracelet%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Five thick bands of hemp have been meticulously bound together in a series of "
"%^BOLD%^%^BLACK%^knots%^RESET%^%^GREEN%^, %^ORANGE%^braids %^GREEN%^and %^CYAN%^loops%^GREEN%^.  Mixed in "
"with these rough strands are tiny %^WHITE%^bones%^GREEN%^, %^BOLD%^%^WHITE%^teeth %^RESET%^%^GREEN%^and "
"%^BOLD%^scales%^RESET%^%^GREEN%^ etched with strange %^BOLD%^%^BLACK%^sigils %^RESET%^%^GREEN%^that are "
"difficult to make out.  Though not what you would call well made, the item does have a curious %^CYAN%^"
"attraction%^GREEN%^ to it, despite being covered in a thin layer of %^BOLD%^mold%^RESET%^%^GREEN%^.%^RESET%^");
   set_lore("These bands are created by the kobold shamans during rituals centered around worshipping the "
"ancestors.  Once believed to be made from the sinew of actual dragons, slain by adventurers, the lack of both "
"dragons and kobold courage have led the bone-shakers to using easier to obtain materials such as hemp.  Most "
"kobolds will claim that the bones, teeth and scales are still taken from dragons, though their size seems to "
"oppose this notion.  Despite these discrepancies, the bands are awarded only to the most honored of kobold "
"heroes and are said to carry the essence of dragonkind within them, making them highly prized as status "
"symbols amongst the small scaly creatures.");
   set_property("lore difficulty",8);
   set_ac(0);
   set_size(1);
   set_wear((:TO,"wear_me":));
   set_weight(3);
   set_value(350);
   set_type("clothing");
   set_property("enchantment",1);
   set_limbs(({"right arm","left arm"}));
}

int wear_me(){
   if(TP->query_level() < 9) {
      notify_fail("You are not experienced enough to utilize this equipment.");
      return 0;
   }
   if((string)ETO->query_race() != "kobold") {
     set_item_bonus("charisma",0);
     tell_object(ETO,"%^GREEN%^You settle the ill-fitted bracelet awkwardly into place.");
     return 0;
   }
   set_item_bonus("charisma",2); //changed to 2 - Odin 8/19
   tell_object(ETO,"%^GREEN%^You feel more powerful .. like a king.");
   return 1;
}
