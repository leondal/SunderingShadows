#include <std.h>
#include <move.h>
#include "../inherit/ruins.h"
inherit PARMOUR;

#define HUES ({"%^RED%^da%^BOLD%^r%^RESET%^%^RED%^k cri%^BOLD%^m%^RESET%^%^RED%^son","%^ORANGE%^pale am%^BOLD%^b%^RESET%^%^ORANGE%^er","%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p vi%^BOLD%^o%^RESET%^%^MAGENTA%^let","%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald gre%^BOLD%^e%^RESET%^%^GREEN%^n","%^BLUE%^co%^BOLD%^b%^RESET%^%^BLUE%^alt bl%^BOLD%^u%^RESET%^%^BLUE%^e","%^BLACK%^%^BOLD%^dus%^RESET%^%^WHITE%^k%^BLACK%^%^BOLD%^y gr%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^y"})

int i;
string article;

void create(){
   ::create();
   i = random(sizeof(HUES));
     if(HUES[i] == "%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald gre%^BOLD%^e%^RESET%^%^GREEN%^n") { article = "An"; }
     else { article = "A"; }
   set_name("%^RESET%^"+article+" "+HUES[i]+"%^RESET%^ silken sash");
   set_id(({"sash","silken sash",""+HUES[i]+"%^RESET%^ sash",""+HUES[i]+" silken sash"}));
   set_obvious_short("%^RESET%^"+article+" "+HUES[i]+"%^RESET%^ silken sash");
   set_short("%^RESET%^"+article+" "+HUES[i]+"%^RESET%^ sash of %^CYAN%^con%^BOLD%^c%^RESET%^%^CYAN%^eal%^BOLD%^m%^RESET%^%^CYAN%^ent%^RESET%^");
   set_long("%^CYAN%^This long, flowing sash is formed of "+HUES[i]+"%^RESET%^%^CYAN%^ silk, "
"obviously crafted by the highest of sewing skill.  It would be easy to %^BOLD%^adjust%^RESET%^%^CYAN%^, "
"to be comfortable for a wearer of any size.  It is incredibly soft to the touch, and when worn forms "
"into several layers of overlapping folds.%^RESET%^\n");
   set_type("clothing");
   set_ac(0);
   set_weight(5);
   set_size(2);
   set_value(200+random(100));
   set_limbs(({"waist"}));
   set_property("enchantment",2);
   set_lore("%^WHITE%^%^BOLD%^Sashes of this style were worn by all members of the now-destroyed cult "
"known only in legend as 'the Faithful of the True Voice'.  They were created by the most skilled of "
"tailors, in varied dark hues denoting the rank of the wearer.  More than just ornamental, they were "
"created in a particular fashion, to allow the wearer to conceal a small bladed weapon upon their "
"person.%^RESET%^\n");
   set_property("lore difficulty",13);
   set_max_internal_encumbrance(10);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO, "remove_fun":));
}

void init() {
   ::init();
   add_action("adjust_fun","adjust");
}

int wear_fun() {
   if(ETO->is_monster()){
     return 1;
   }
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this item!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^The sash doesn't seem to fit "+ETO->QCN+".",ETO);
     return 0;
   }
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" wraps the silken sash around "+ETO->QP+" waist easily, "
"as if it were made to fit.",ETO);
   if (!random(5)) { tell_object(ETO,"%^WHITE%^%^BOLD%^You wrap the perfectly-fitted silken sash around "
"your waist, and realise you could probably hide something within its folds!"); }
   else { tell_object(ETO,"%^WHITE%^%^BOLD%^You wrap the perfectly-fitted silken sash around your "
"waist."); }
   return 1;
}

int remove_fun() {
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" slips the sash free from around "+ETO->QP+" waist.",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You slip easily free of the silken sash.");
   return 1;
}

int adjust_fun(string str) {
   if (!str) {
     notify_fail("Adjust what?\n");
     return 0;
   }
   if (str != "sash" && str != "silken sash" && str != "silk sash") {
     notify_fail("You can't adjust that!\n");
     return 0;
   }
   if (TO->query_worn()) {
     notify_fail("You can't adjust that while you're wearing it!\n");
     return 0;
   }
   tell_object(ETO,"%^WHITE%^%^BOLD%^You carefully adjust the sash, making it just the right size to fit "
"you.");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" adjusts the sash to fit "+ETO->QO+"self.",ETO);
   TO->remove_size();
   TO->set_size(ETO->query_size());
   return 1;
}

int item_allowed(object item) {
   if(!item->is_weapon()) {
     write("This is meant for daggers only.\n");
     return 0;
   }
   if(sizeof(all_inventory(TO)) > 0) {
     write("There's already a blade hidden within the sash's folds.\n");
     return 0;
   }
   if(item->query_size() > 1 || !item->id("dagger")) {
     write("That's too large, the sash could only hold a small dagger.\n");
     return 0;
   }
   return 1;
}
