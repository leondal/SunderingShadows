#include <std.h>
inherit "/d/magic/symbols/holy_symbol.c";

void create(){
   ::create();
   set_id(({"holy symbol","symbol","the_faceless_one_holy_symbol","ring","black ring","dark ring"}));
   set_name("holy symbol");
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   ::init();
   set_limbs(({"left hand","right hand"}));
   set_name("ring");
   set_short("%^RESET%^A ring set with a %^BOLD%^%^BLACK%^black stone%^RESET%^");
   set_long((:TO, "long_desc":)); 
}


string long_desc() {
   if(!objectp(ETO)) return("Borked!");
   if(TP == ETO) {
     return("%^RESET%^This is a %^BOLD%^%^WHITE%^platinum ring%^RESET%^ with a perfect %^BOLD%^%^BLACK%^black stone "
"%^RESET%^set in its top.  The stone has glimmers of faint light dancing through it. It gives off a cold "
"%^BOLD%^%^BLUE%^aura%^RESET%^ that chills you to the bone.  Upon its inner surface, hidden from all but the one "
"that holds it, three %^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d-r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d %^RESET%^teardrops "
"have been marked in the bright metal.");
   }
   return("%^RESET%^This is a %^BOLD%^%^WHITE%^platinum ring%^RESET%^ with a perfect %^BOLD%^%^BLACK%^black stone "
"%^RESET%^set in its top.  The stone has glimmers of faint light dancing through it. It gives off a cold "
"%^BOLD%^%^BLUE%^aura%^RESET%^ that chills you to the bone.");
}