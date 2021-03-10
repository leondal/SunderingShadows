#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create(){
        ::create();
        set_name("bracelet of blessings");
        set_id(({ "bracelet","Bracelet","platinum bracelet","cat's eye bracelet","bracelet of blessings","blessed bracelet","priest bracelet","cleric bracelet" }));
        set_short("%^BLACK%^%^BOLD%^B%^RESET%^%^WHITE%^r%^BOLD%^a%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^e%^RESET%^%^WHITE%^l%^BOLD%^e%^RESET%^%^WHITE%^t %^BLACK%^%^BOLD%^o%^RESET%^%^WHITE%^f %^BOLD%^b%^RESET%^%^WHITE%^l%^BLACK%^%^BOLD%^e%^RESET%^%^WHITE%^s%^BOLD%^s%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^n%^RESET%^%^WHITE%^g%^BOLD%^s%^RESET%^");
        set_obvious_short("%^BLACK%^%^BOLD%^gem-set %^RESET%^%^WHITE%^pl%^BOLD%^a%^RESET%^%^WHITE%^ti%^BOLD%^n%^RESET%^%^WHITE%^um brac%^BOLD%^e%^RESET%^%^WHITE%^let%^RESET%^");
        set_long("%^ORANGE%^This bracelet seems nearly too perfect to have been crafted by mortal hands. "
" A flawless band of %^WHITE%^po%^BOLD%^l%^RESET%^%^WHITE%^is%^BOLD%^h%^RESET%^%^WHITE%^ed "
"pl%^BOLD%^a%^RESET%^%^WHITE%^ti%^BOLD%^n%^RESET%^%^WHITE%^um%^ORANGE%^ forms the base of the bracelet, "
"held with a complex clasp at the underside of the wrist.  Upon the upper surface, delicate filigree "
"borders a single %^BLACK%^%^BOLD%^dark-gray%^RESET%^%^ORANGE%^ gem, with a line of pure "
"%^WHITE%^white%^ORANGE%^ down its centre - a chrysoberyl stone, known commonly as a cat's "
"eye.  Upon the underside of the bracelet is a written engraving.%^RESET%^\n");
        set_size(2);
        set_weight(3);
        set_value(3000);
        set_ac(0);
        set_property("enchantment",0);
        set_type("ring");
        set_limbs(({"left arm"}));
        set_lore("%^WHITE%^%^BOLD%^This bracelet once belonged to the Kelemvorite priestess, Sionne of "
"the Ashes.  Many rumours exist concerning how she came to possess such an item; some that claim she was "
"granted it by the Lord of the Dead himself, as a gift for her unwavering faith."
"It was rumored that she could retain a spell within the bracelet, to save her from harm when she could not do so herself.%^RESET%^\n");
        set_property("lore difficulty",15);
        set_read("%^BOLD%^%^CYAN%^Instill%^WHITE%^ within me a spell to mind\n"
"%^BOLD%^%^WHITE%^And tell me %^CYAN%^when%^WHITE%^ to use it\n"
"%^BOLD%^%^WHITE%^Just %^CYAN%^ask%^WHITE%^ of me what spell I bind\n"
"%^BOLD%^%^WHITE%^Or %^CYAN%^remove%^WHITE%^ me to diffuse it\n");
        set_wear((:TO,"wear_fun":));
        set_remove((:TO,"remove_fun":));
}

void init() {
   ::init();
   add_action("instill_fun","instill");
   add_action("ask_fun","ask");
   add_action("now_fun","when");
}

int wear_fun(){
   if(TP->is_class("cleric")) {
     if((int)ETO->query_lowest_level() < 18) {
       tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this bracelet!");
       tell_room(EETO,"%^BOLD%^%^WHITE%^The bracelet doesn't seem to fit "+ETO->QCN+".",ETO);
       return 0;
     }
     tell_room(EETO,"%^WHITE%^%^BOLD%^A soft glow appears around the bracelet as "+ETO->QCN+" slides it "
"around "+ETO->QP+" wrist.%^RESET%^",ETO);
     tell_object(ETO,"%^WHITE%^%^BOLD%^A feeling of reassurance fills your mind as you slide the bracelet "
"around your wrist.%^RESET%^");
     return 1;
   }
   else {
     tell_room(EETO,"%^WHITE%^%^BOLD%^The bracelet seems forcibly repelled away from "+ETO->QCN+"'s "
"arm.%^RESET%^",ETO);
     tell_object(ETO,"%^WHITE%^%^BOLD%^No matter how you try to force it, the bracelet seems repelled "
"from your arm.%^RESET%^");
   return 0;
   }
}

int remove_fun(){
    if (TO->query_property("instilled")){
      TO->remove_property("instilled");
      TO->remove_property("instilledarg");
      write("The spell within the bracelet diffuses harmlessly and is lost.\n");
    }
    tell_room(EETO,"%^WHITE%^%^BOLD%^The bracelet's glow fades as "+ETOQCN+" slips it from "
+ETO->QP+" wrist.%^RESET%^",ETO);
    tell_object(ETO,"%^WHITE%^%^BOLD%^The feeling of confidence leaves you as you remove the "
"bracelet.%^RESET%^");
    return 1;
}

int instill_fun(string str){
   string spell,args;
   if (!str) {
     notify_fail("Instill what?\n");
     return 0;
   }
   if (!TO->query_worn()) {
     notify_fail("You need to be wearing the bracelet first.\n");
     return 0;
   }
   if (!ETP->query_property("blessed") || ETP->query_property("blessed") != TP->query_diety()) {
     notify_fail("Such powerful magic would need the blessings of your god upon your surroundings.\n");
     return 0;
   }
   if(TO->query_property("instilled")){
     notify_fail("The bracelet already has a spell instilled within it.\n");
     return 0;
   }
   if (sscanf(str,"%s to %s",spell,args) != 2) {
     spell = str;
     args = 0;
   }
   if(!TP->query_cl_memorized(spell)){
     notify_fail("You don't have that spell memorized!\n");
     return 0;
   }
   if (spell == "word of power" && args == 0) {
     notify_fail("That spell requires a target.\n");
     return 0;
   }
   TO->set_property("instilled",spell);
   TO->set_property("instilledarg",args);
   TP->set_cl_memorized(spell, -1);
   tell_object(ETO,"%^WHITE%^%^BOLD%^You instill the spell %^CYAN%^"+spell+"%^WHITE%^ into the "
"bracelet!%^RESET%^\n");
   tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" speaks a quiet prayer over the bracelet on "+ETO->QP+ 
"wrist.%^RESET%^\n",ETO);
   return 1;
}

int ask_fun(string str){
   if (!str) {
     notify_fail("Ask what?\n");
     return 0;
   }
   if (str != "bracelet" && str != "sionne's blessing" && str != "platinum bracelet"){
     notify_fail("You can't ask that!\n");
     return 0;
   }
   if (!TO->query_property("instilled")){
     write("%^WHITE%^%^BOLD%^There is currently no spell held within the bracelet.%^RESET%^\n");
     return 1;
   }
   write("%^WHITE%^%^BOLD%^The bracelet is holding the spell "
"%^CYAN%^"+TO->query_property("instilled")+"%^WHITE%^.%^RESET%^\n");
   if (TO->query_property("instilledarg")) {
     write("%^WHITE%^%^BOLD%^The spell's target is "
"%^CYAN%^"+TO->query_property("instilledarg")+"%^WHITE%^.%^RESET%^\n");
   }
   return 1;
}

int now_fun(string str){
   string tocast;
   if (!TO->query_property("instilled")){
     notify_fail("There is currently no spell held within the bracelet.\n");
     return 0;
   }
   if (str){
     write("%^WHITE%^%^BOLD%^Concentrate more clearly: just %^CYAN%^when%^WHITE%^ will activate the "
"spell.");
     return 1;
   }
   tocast = "/cmds/priest/_"+replace_string(TO->query_property("instilled")," ","_")+".c";
   if (TO->query_property("instilledarg") == 0) {
     new(tocast)->use_spell(ETO,ETO->query_name(),ETO->query_level(),100);
   }
   else { new(tocast)->use_spell(ETO,TO->query_property("instilledarg"),ETO->query_level(),100); }
   TO->remove_property("instilled");
   TO->remove_property("instilledarg");
   return 1;
}
