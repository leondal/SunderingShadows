#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("%^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^ol%^MAGENTA%^or%^BOLD%^fu%^RESET%^%^RED%^l b%^ORANGE%^ra%^BOLD%^ce%^RESET%^%^GREEN%^le%^CYAN%^ts%^RESET%^");
   set_id(({"bracelets","bangles","colorful bracelets","colourful bracelets","rainbow bracelets","rainbow bangles"}));
   set_short("%^BOLD%^%^BLUE%^Ra%^RESET%^%^MAGENTA%^in%^RESET%^%^RED%^bo%^ORANGE%^w b%^BOLD%^an%^RESET%^%^GREEN%^gl%^CYAN%^es%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^ol%^MAGENTA%^or%^BOLD%^fu%^RESET%^%^RED%^l b%^ORANGE%^ra%^BOLD%^ce%^RESET%^%^GREEN%^le%^CYAN%^ts%^RESET%^");
   set_long("These pretty "
"%^BLUE%^mu%^MAGENTA%^lt%^RED%^i-%^ORANGE%^co%^BOLD%^lo%^RESET%^%^GREEN%^re"
"%^CYAN%^d%^RESET%^ bracelets are quite small, and would only fit over the hand "
"of someone %^CYAN%^tiny%^RESET%^ - perhaps they were made for a child. They "
"are made from what appears to be %^BOLD%^%^CYAN%^dlarun metal%^RESET%^, "
"lightweight and visually flimsy-looking, but despite this seemingly quite "
"sturdy and resilient to any attempts to bend or break them. Each one has been "
"painted a different "
"%^MAGENTA%^c%^RED%^o%^ORANGE%^l%^YELLOW%^o%^RESET%^%^GREEN%^u%^CYAN%^r%^RESET%^"
", with so many of them that you wonder if you could even give a different name "
"to each new shade. They %^ORANGE%^chime %^RESET%^gently together when they "
"touch, with soft notes that are oddly pleasant upon the ear.\n");
   set_size(-1);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_item_bonus("will",1);
   set_item_bonus("fortitude",1);
   set_item_bonus("reflex",1);
   set_lore("Bracelets such as these are loved by the small folk known as "
"halflings, for their fondness for pretty and brightly-colored items. These "
"particular bracelets, though, were probably crafted by halflings as well as "
"worn by them, since Dlarun metal is rarely used by the larger races. It is "
"prized by halflings for its light weight and resilience, and the secrets of "
"its smithing are rarely passed on to others.\n");
   set_property("lore difficulty",8);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int check(){
   ::check();
   tell_room(EETO,"%^CYAN%^The bracelets %^ORANGE%^ring %^CYAN%^softly together "
"as "+ETO->QCN+" slips them over "+ETO->QP+" arms.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^The bracelets %^ORANGE%^ring %^CYAN%^softly "
"together as you slip them over your arms.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^CYAN%^The bracelets %^ORANGE%^chime %^CYAN%^quietly "
"together as "+ETO->QCN+" pulls them off.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^The bracelets %^ORANGE%^chime %^CYAN%^quietly "
"together as you pull them off.%^RESET%^");
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(5)) {
     tell_object(ETO,"%^CYAN%^Your bracelets %^ORANGE%^chime %^CYAN%^gently as "
"you dodge aside from "+target->QCN+"'s blow!%^RESET%^");
     tell_object(target,"%^CYAN%^"+ETO->QCN+"'s bracelets %^ORANGE%^chime "
"%^CYAN%^gently as "+ETO->QS+" dodges aside from your blow!%^RESET%^");
     tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s bracelets %^ORANGE%^chime "
"%^CYAN%^gently as "+ETO->QS+" dodges aside from "+target->QCN+"'s "
"blow!%^RESET%^",({ETO,target}));
     return 0;
   }
   return damage;
}
