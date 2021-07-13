// updated bonuses to meet current standards. N, 24/1/20.
#include <std.h>
inherit "/d/common/obj/armour/studded";

int OWNED;
string *owners;

void create(){
   ::create();
   set_id(({"leather","studded","studded leather","mottled studded","mottled leather","mantle","mantle of the shadowdancer"}));
   set_short("%^BOLD%^%^BLACK%^Ma%^RESET%^%^ORANGE%^nt%^BOLD%^%^BLACK%^le of the Sh%^RESET%^a%^BOLD%^%^BLACK%^dowd%^RESET%^a%^BOLD%^%^BLACK%^ncer%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^dar%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ly m%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ed studded leather%^RESET%^");
   set_long("From a distance, this leather suit looks rather %^CYAN%^mu"
"%^GREEN%^n%^CYAN%^da%^GREEN%^n%^CYAN%^e%^RESET%^, colored as it is in "
"%^BOLD%^%^BLACK%^dar%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ly m%^RESET%^"
"%^ORANGE%^o%^BOLD%^%^BLACK%^tt%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^ed "
"%^RESET%^shades of %^BOLD%^%^BLACK%^gray %^RESET%^and %^ORANGE%^brown"
"%^RESET%^. %^BLUE%^Pale metal studs %^RESET%^have been placed at even "
"intervals across its surface, dulled so as not to reflect any %^BOLD%^"
"%^WHITE%^lig%^YELLOW%^h%^WHITE%^t%^RESET%^. A closer look reveals it to be "
"deliberately patterned in these dark shades, to perfectly %^GREEN%^b%^BOLD%^l"
"%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^d %^RESET%^into any %^BOLD%^"
"%^BLACK%^shadow %^RESET%^or %^BLUE%^darkened corner%^RESET%^. The suit "
"itself is quite sturdy, and would protect a wearer well, although it seems a "
"little %^MAGENTA%^lighter %^RESET%^in weight than its appearance would "
"suggest.\n");
   set_lore("A similar item as this is recorded in ancient high elven lore, "
"as a precious magical item gifted to Ellarion Darmyr. As leader of a "
"specialized unit of elven scouts, he often led these skilled elves in "
"dangerous missions to protect his home city. For many decades he was "
"renowned to be unmatched in skill at blades, though the tales say that he "
"was lost to underdark on one such mission, and never returned.");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_size(2);
   set_weight(20);
   set_value(6500);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("stealth",4);
   set_item_bonus("athletics",4);
   set_item_bonus("reflex",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   owners = ({});
}

int wear_fun() {
/*
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
*/
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this armor.");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" slips the suit of l%^RESET%^"
"%^ORANGE%^e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r on "
"with a look of confidence.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the suit of l%^RESET%^%^ORANGE%^"
"e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r on, already "
"feeling more secure in its concealments.%^RESET%^");
    ETO->setenv("MINVIS","%^BOLD%^%^BLACK%^$N disappears into the shadows "
"right before your eyes.%^RESET%^");
   ETO->setenv("MVIS","%^BOLD%^%^BLACK%^$N suddenly appears beside "
"you.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes the l%^RESET%^"
"%^ORANGE%^e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r armor "
"and looks around cautiously.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the l%^RESET%^%^ORANGE%^"
"e%^BOLD%^%^BLACK%^ath%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r armor, already "
"feeling revealed and vulnerable without it.%^RESET%^");
   ETO->setenv("MINVIS","$N seems to disappear.");
   ETO->setenv("MVIS","$N appears out of the corner of your eye.");
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(4)){
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to %^RESET%^%^CYAN%^"
"va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^as "+who->QCN+" strikes at "
+ETO->QO+", only to reappear beside "+who->QO+" and launch another "
"attack!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^BLACK%^You slip into the shadows to %^RESET%^"
"%^CYAN%^va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^from view as "+who->QCN+
" strikes at you, and launch another surprise attack!%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^"+ETOQCN+" seems to %^RESET%^%^CYAN%^"
"va%^RESET%^n%^CYAN%^ish %^BOLD%^%^BLACK%^as you strike at "+ETO->QO+", only "
"to reappear beside you and launch another attack!%^RESET%^");
     ETO->execute_attack();
     return 0;
   }
   return damage;
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}