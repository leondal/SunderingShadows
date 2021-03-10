#include <std.h>
inherit ARMOUR;

int owned;
string owner;

void create(){
   ::create();
   set_name("carved ring");
   set_id(({"ring","carved ring","wooden ring","wood ring","carved wooden ring"}));
   set_short("%^RESET%^%^ORANGE%^car%^RED%^v%^ORANGE%^ed wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^den ring%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^car%^RED%^v%^ORANGE%^ed wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^den ring%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Carved from a single piece of %^RESET%^%^ORANGE%^r%^RED%^a%^ORANGE%^w t%^BOLD%^%^BLACK%^im%^RESET%^%^ORANGE%^b"
"%^RED%^e%^ORANGE%^r %^BOLD%^%^WHITE%^with its edges rubbed to a %^RESET%^%^MAGENTA%^sm%^RED%^oo%^MAGENTA%^th %^BOLD%^%^WHITE%^finish, this "
"ring bears none of the hallmarks of fine jewelry, yet is a striking work nonetheless. Its character comes primarily from the remarkably "
"detailed carvings that run the full circuit of its outer edge, marking out a series of %^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^v"
"%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^, %^RESET%^%^GREEN%^l%^YELLOW%^e%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^v%^CYAN%^e%^GREEN%^s"
"%^BOLD%^%^WHITE%^, swirls of %^RESET%^c%^CYAN%^lo%^RESET%^u%^CYAN%^d %^BOLD%^%^WHITE%^and %^BOLD%^%^BLACK%^mo%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^nt"
"%^RESET%^%^ORANGE%^ai%^BOLD%^%^BLACK%^n %^BOLD%^%^WHITE%^ridges.%^RESET%^\n");
   set_lore("This ring bears hallmark carved patterning that is common to beastman craftwork. Such creatures favor natural "
"materials to create their homes and belongings, and decorate them with imagery of the world around them. Often, symbolism "
"is used to represent or invoke a concept - for example, boots may be marked with a deer or hare to represent speed, while a "
"bear may be called upon for its strength. Shamans of the tribe channel this through their spellcraft, bestowing blessing in "
"the name of creatures and elements.\n");
   set_property("lore difficulty",20);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_size(-1);
   set_value(300);
   set_property("magic nonstacking",1); // these are magical equipment for the non-rop ring slot!
}

void init() {
   ::init();
   if(!owned) {       
     if(userp(ETO) && !ETO->query_true_invis()) {
       owned = 1;
       owner = (string)ETO->query_name();
     }
   }
}

int isMagic(){ return 1; }

set_mylong(string str) {
   set_long("%^BOLD%^%^WHITE%^Carved from a single piece of %^RESET%^%^ORANGE%^r%^RED%^a%^ORANGE%^w t%^BOLD%^%^BLACK%^im%^RESET%^%^ORANGE%^b"
"%^RED%^e%^ORANGE%^r %^BOLD%^%^WHITE%^with its edges rubbed to a %^RESET%^%^MAGENTA%^sm%^RED%^oo%^MAGENTA%^th %^BOLD%^%^WHITE%^finish, this "
"ring bears none of the hallmarks of fine jewelry, yet is a striking work nonetheless. Its character comes primarily from the remarkably "
"detailed carvings that run the full circuit of its outer edge, marking out a series of %^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^v"
"%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^s%^BOLD%^%^WHITE%^, %^RESET%^%^GREEN%^l%^YELLOW%^e%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^v%^CYAN%^e%^GREEN%^s"
"%^BOLD%^%^WHITE%^, swirls of %^RESET%^c%^CYAN%^lo%^RESET%^u%^CYAN%^d %^BOLD%^%^WHITE%^and %^BOLD%^%^BLACK%^mo%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^nt"
"%^RESET%^%^ORANGE%^ai%^BOLD%^%^BLACK%^n %^BOLD%^%^WHITE%^ridges. In the centre is a widened face, upon which is carved the rustic outline of "
"a %^RESET%^%^CYAN%^"+str+"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

set_mylore(string str) {
   set_lore("This ring bears hallmark carved patterning that is common to beastman craftwork. Such creatures favor natural "
"materials to create their homes and belongings, and decorate them with imagery of the world around them. Often, symbolism "
"is used to represent or invoke a concept - for example, boots may be marked with a deer or hare to represent speed, while a "
"bear may be called upon for its strength. Shamans of the tribe channel this through their spellcraft, bestowing blessing in "
"the name of creatures and elements. This particular ring is marked with the image of a "+str+".\n");
}