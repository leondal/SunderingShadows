// Readjusted commands since the lighting functions were breaking stuff, and tuned it down
// (+3 instead of +5 vision). Also set it to only 10MR, already v. powerful. N, 11/06.
// Changed sight bonus back to +5 as +3 didn't seem to make any difference in sight, and the item is difficult to get. - Tsera
#include <std.h>
inherit "/d/common/obj/clothing/hat.c";
int FLAG;

void create() {
    ::create();
    FLAG = 0;
    set_name("mask");
    set_id(({"mask","kinnesaruden mask","kinnesaruden"}));
    set_short("%^BOLD%^%^CYAN%^Kinnesaruden Mask%^RESET%^");
    set_obvious_short("an ancient mask");
    set_long("%^RED%^This mask is made of %^BOLD%^%^WHITE%^stainless %^CYAN%^titanium"
"%^RESET%^%^RED%^. The mask is in the shape of an expressionless face. There are no "
"openings in the mask. Where the eyes on the mask are, two %^BOLD%^%^BLACK%^obsidian "
"%^RESET%^%^RED%^gems sit. On the inside of the mask there is some small writing. You do "
"not understand how the wearer of the mask is supposed to see through it, much less "
"put it on.");
    set_lore("This mask was created by two of the realms most powerful wizards about 250 "
"years ago. The Crystal Tower's elite wizard, %^BOLD%^%^MAGENTA%^The Magus Prime%^RESET%^ "
"worked with the %^BOLD%^%^RED%^Lord Mage Elseroad %^RESET%^to create this powerful mask. "
"After the former lovers had a rather vicious falling out the %^BOLD%^%^RED%^Lord Mage "
"Elseroad %^RESET%^took the mask and went to live in the caves he created for himself "
"under the city of Seneca.");
    set_weight(10);
    set_value(1800);
//    set_type("mask");
    set_limbs(({"head"}));
//    set_ac(0);
    set_read("The words, %^YELLOW%^lighten%^RESET%^, %^RED%^darken%^RESET%^, and "
"%^BOLD%^%^WHITE%^normalize %^RESET%^are written on the inside of the mask.");
    set_property("enchantment",4);
    set_item_bonus("magic resistance",2);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}

void init() {
   ::init();
   add_action("dark_func","darken");
   add_action("light_func","lighten");
   add_action("norm_func","normalize");
}

int norm_func() {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) {
     notify_fail("You should wear that first.\n");
     return 0;
   }
   if(FLAG == 0) {
     notify_fail("The mask is already normalized.\n");
     return 0;
   }
   if(FLAG == 1) {
     tell_object(ETO,"%^BOLD%^%^RED%^From your eyes the room seems%^YELLOW%^ "
"brighter%^RED%^.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^RED%^The mask's eye's return from %^RESET%^%^RED%^red "
"%^BOLD%^to %^BLACK%^black%^RED%^.%^RESET%^",ETO);     
   ETO->add_sight_bonus(5);
     FLAG = 0;
     return 1;         
   }
   else if(FLAG == 2) {
     tell_object(ETO,"%^BOLD%^%^RED%^From your eyes the room seems%^BLACK%^ "
"darker%^RED%^.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^RED%^The mask's eye's return from %^YELLOW%^yellow%^RED%^ "
"to %^BLACK%^black%^RED%^.%^RESET%^",ETO);   
    ETO->add_sight_bonus(-5);
     FLAG = 0;
     return 1;
   }
   else {
     tell_object(ETO,"Nothing happens.");
     return 1;
   }
}

int dark_func() {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) {
     notify_fail("You should wear that first.\n");
     return 0;
   }
   if(FLAG == 2) {
     notify_fail("The mask is already lightened, you should normalize first.\n");
     return 0;
   }
   if(FLAG == 0) {
     tell_object(ETO,"%^BOLD%^%^RED%^The room seems darker from your eyes.%^RESET%^");
     tell_room(EETO, "%^BOLD%^%^RED%^"+ETOQCN+"'s eyes glow%^RESET%^%^RED%^ "
"red%^BOLD%^.%^RESET%^",ETO);  
   ETO->add_sight_bonus(-5);
     FLAG = 1;
     return 1;
   }
   else {
     tell_object(ETO,"Nothing happens.");
     return 1;
   }
}

int light_func() {
   if(!objectp(ETO)) return 0;
   if(!userp(ETO)) return 0;
   if(!TO->query_worn()) {
     notify_fail("You should wear that first.\n");
     return 0;
   }
   if(FLAG == 1) {
     notify_fail("The mask is already darkened, you should normalize first.\n");
     return 0;
   }
   if(FLAG == 0) {
     tell_object(ETO,"%^BOLD%^%^RED%^The room seems brighter from your eyes.%^RESET%^");
     tell_room(EETO, "%^BOLD%^%^RED%^"+ETOQCN+"'s eyes glow%^YELLOW%^ "
"yellow%^RED%^.%^RESET%^",ETO);   
   ETO->add_sight_bonus(5);
     FLAG = 2;
     return 1;
   }
   else {
     tell_object(ETO,"Nothing happens."); 
     return 1;
   }
}

int wearit() {
    FLAG = 0;
    if((int)ETO->query_highest_level() < 25) {  
      tell_object(ETO,"%^BOLD%^%^RED%^This mask refuses to bind to your face.%^RESET%^");
      return 0;
    }
    tell_object(ETO,"%^BOLD%^%^RED%^The ancient mask binds to your face.%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" places an ancient mask upon "+ETO->QP+
" face.%^RESET%^",ETO);   
    return 1;
}

int removeit() {
   if(FLAG == 1) {
     tell_object(ETO,"%^BOLD%^%^RED%^From your eyes the room seems%^YELLOW%^ "
"brighter%^RED%^.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^RED%^The mask's eye's return from %^RESET%^%^RED%^red "
"%^BOLD%^to %^BLACK%^black%^RED%^.%^RESET%^",ETO);     
   ETO->add_sight_bonus(5);
     FLAG = 0;
   }
   else if(FLAG == 2) {
     tell_object(ETO,"%^BOLD%^%^RED%^From your eyes the room seems%^BLACK%^ "
"darker%^RED%^.%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^RED%^The mask's eye's return from %^YELLOW%^yellow%^RED%^ "
"to %^BLACK%^black%^RED%^.%^RESET%^",ETO);   
   ETO->add_sight_bonus(-5);
     FLAG = 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^The mask lets go of your face and you remove "
"it.%^RESET%^");
   tell_room(EETO, "%^BOLD%^%^RED%^"+ETOQCN+" removes "+ETO->QP+" anicent mask and looks "
"around disoriented.%^RESET%^",ETO);
    FLAG = 0;
    return 1;
}

int query_size(){
   if(!objectp(ETO) || !living(ETO)) return 2;
   return ETO->query_size();
}
