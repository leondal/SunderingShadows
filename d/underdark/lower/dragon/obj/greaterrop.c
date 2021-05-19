// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
inherit ARMOUR;

int OWNED;
string *owners;

void create() {
   ::create();
   set_name("adamantite ring");
   set_id(({"greater ring of protection","ring","rop","adamantite ring","ring of protection","ring of adamantite","glittering ring"}));
   set_short("%^BOLD%^%^WHITE%^Gre%^CYAN%^a%^WHITE%^ter Ring of "
"Prote%^CYAN%^c%^WHITE%^tion%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^gl%^RESET%^i%^BOLD%^%^WHITE%^tte"
"%^RESET%^r%^BOLD%^%^WHITE%^ing ring of adaman%^CYAN%^t%^WHITE%^ite%^RESET%^");
   set_long("Crafted from what appears to be pure %^BOLD%^%^WHITE%^adaman"
"%^CYAN%^t%^WHITE%^ite%^RESET%^, this ring seems utterly immune to "
"%^RED%^he%^MAGENTA%^a%^RED%^t %^RESET%^or %^GREEN%^damage%^RESET%^, making "
"you wonder how anyone managed to craft it into shape in the first place. It "
"forms a narrow circle with a flawless surface that has been polished to a "
"%^YELLOW%^br%^RESET%^%^ORANGE%^i%^YELLOW%^lli%^RESET%^%^ORANGE%^a%^YELLOW%^"
"nt %^RESET%^sheen. Upon the underside, invisible when the ring is worn, "
"small %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^u%^BOLD%^n%^RESET%^%^CYAN%^e"
"%^BOLD%^s %^RESET%^have been etched into the underside in smooth lines.");
   set_lore("While rings of protection are vastly common, at least as far as "
"magical items go, ones such as this are incredibly rare. Once crafted by "
"high elven magic before the time of the crown wars, they were one of the "
"greatest creations of sister houses Aryi'thanna and Lirellyn. Between the "
"twin specialties of these houses, in enchantments and fine-wrought metals, "
"so many commonly crafted items and enchantments were raised to new levels "
"of finesse. Sadly, both houses fell from history's pages during the elven "
" crown wars, though it remains unknown whether they were wiped out, or "
"turned beneath the earth as others of their now twisted drow kindred. In "
"either case, it seems the knowledge needed to craft such impressive items "
"is now lost, leaving only a rare few of these artifacts left upon the face "
"of the realms.\n");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_type("ring");
   set_ac(0);
   set_weight(2);
   set_value(25000);
   set_limbs(({"right hand","left hand"}));
   set_property("enchantment",5);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("magic resistance",2);
   set_item_bonus("damage resistance",5);
   set_wear((:TO,"do_wear":));
   set_remove((:TO,"do_remove":));
   owners = ({});
}

int do_wear() {
   object *stuff;
   int i,j, flag;

   stuff = ETO->all_armour();
   j = sizeof(stuff);
   for(i=0;i<j;i++) {
     if(!objectp(stuff[i])) continue;
     if((string)stuff[i]->query_type() == "ring") {
       if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
         flag = 1;
         break;
       }
     }
   }
   if(flag) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^The magic of the ring already worn prevents you from wearing this one!%^RESET%^");
     return 0;
   }
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this jewelry.");
     return 0;
   }
   tell_object(ETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as you slip the ring on.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^The runes upon the ring's underside take on a "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as "+ETO->QCN+" slips the ring on.%^RESET%^",ETO);
   return 1;
}

int do_remove() {
   tell_object(ETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w%^YELLOW%^.%^RESET%^");
   tell_room(EETO,"%^YELLOW%^The runes beneath the ring lose their "
"%^RESET%^%^CYAN%^br%^BOLD%^i%^RESET%^%^CYAN%^ght gl%^BOLD%^o%^RESET%^%^CYAN%^"
"w %^YELLOW%^as "+ETO->QCN+" removes it.%^RESET%^",ETO);
   return 1;
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
