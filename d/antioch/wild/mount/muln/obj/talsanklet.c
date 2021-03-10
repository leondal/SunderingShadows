#include <std.h>
inherit "/d/common/obj/jewelry/anklet";



void create(){
   ::create();
   set_name("talcalen's anklet");
   set_id(({"anklet","talcalen anklet", "tals anklet","seashell","seashells"}));
   set_short("%^BOLD%^%^BLUE%^T%^GREEN%^a%^BLUE%^lc%^GREEN%^a%^BLUE%^l%^GREEN%^e%^BLUE%^n's An%^GREEN%^kl%^BLUE%^et%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^Small ch%^RESET%^%^CYAN%^ai%^BOLD%^%^BLUE%^ned s%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^sh%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^lls%^RESET%^");
   set_long("%^BOLD%^%^BLUE%^Many small s%^RESET%^%^CYAN%^e%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^she%^BOLD%^%^BLUE%^lls are linked together by tiny" 
   "%^BOLD%^%^WHITE%^ slivers%^BLUE%^ of m%^CYAN%^i%^BLUE%^thr%^CYAN%^i%^BLUE%^l. The seashells are a rough, deep %^RESET%^%^GREEN%^greenish-%^BOLD%^%^CYAN%^blue%^BLUE%^."
   " A %^BOLD%^%^BLACK%^s%^RESET%^i%^BOLD%^%^BLACK%^lv%^RESET%^e%^BOLD%^%^BLACK%^r%^BLUE%^ tint can be seen streaking through each seashell,"
   " which resembles %^RESET%^%^ORANGE%^light%^BOLD%^%^BLUE%^ dancing on open %^RESET%^%^CYAN%^waters %^BOLD%^%^BLUE%^"
   "when struck by %^BOLD%^%^YELLOW%^d%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^yl%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^ght%^BLUE%^. A closer look at the shells reveals that they"
   " aren't seashells at all, but tiny fragments of a %^RESET%^%^GREEN%^turtle's shell%^BOLD%^%^BLUE%^.%^RESET%^\n");
   set_lore("%^BOLD%^%^BLUE%^Pirates, Istishians, Sailors and any seafarer who is worth his salt, can tell you the story of Talcalen."
    " He was a fairly inept man who was mesmerized by dragon turtles. It is said that Talcalen searched for a majority of his life and paid every copper piece he had in his quest." 
    " Years went by and Talcalen never found anything, until the faithful day that he happened upon a travelling caravan of Shaundakulian merchants. They were selling all sorts of"
    " trinkets and wares. He supposedly found an anklet composed of dragon turtle fragments from one of the merchants. After that day Talcalen was legendary for arm-wrestling and" 
    " bare-knuckle brawling.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_weight(4);
   set_size(-1);
   set_value(2500); 
   set_property("enchantment",4);
   set_item_bonus("armor bonus",1);
   set_item_bonus("strength",2);
   set_item_bonus("cold resistance",25);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
}     


int check() {
   tell_room(EETO,"%^BOLD%^%^BLUE%^You hear waves in the distance as "+ETO->QCN+" wears "+TO->query_short()+".%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLUE%^You hear w%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^ves crashing against a %^BOLD%^%^YELLOW%^sh%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^re%^BLUE%^.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLUE%^The sound of waves fade as "+ETO->QCN+" removes "+TO->query_short()+".%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLUE%^The sound of crashing waves recedes from your ear.%^RESET%^");
   return 1;
}

