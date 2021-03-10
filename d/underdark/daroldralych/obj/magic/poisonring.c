#include <std.h>
inherit ARMOUR;

int charges;

void create() {
   ::create();
   set_name("jasper ring");
   set_id(({"ring","ring of antivenom","jasper ring","veined jasper ring","black veined jasper ring","black-veined jasper ring","veined ring","black veined ring","black-veined ring"}));
   set_short("%^BOLD%^%^BLACK%^Ring of %^GREEN%^An%^RESET%^%^GREEN%^t%^BOLD%^ive%^RESET%^%^GREEN%^n%^BOLD%^om%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^bl%^RESET%^a%^RED%^c%^BOLD%^%^BLACK%^k-%^RESET%^%^ORANGE%^v%^BOLD%^%^BLACK%^ei%^RESET%^n%^BOLD%^%^RED%^e%^BLACK%^d %^RESET%^%^RED%^jasper ring%^RESET%^");
   set_long("Simple in design but elegant in appearance, this ring forms "
"a perfectly cut sphere of solid jasper.  Its opaque surface bears the "
"hue of %^RED%^viv%^BOLD%^i%^RESET%^%^RED%^d cr%^BOLD%^i%^RESET%^%^RED%^"
"mson%^RESET%^, shot through with jagged veins and whorls of darker "
"%^BOLD%^%^BLACK%^g%^RESET%^ra%^BOLD%^%^BLACK%^y %^RESET%^and %^BOLD%^"
"%^BLACK%^black%^RESET%^.  A series of chaotic-looking %^GREEN%^r%^BOLD%^"
"u%^CYAN%^n%^RESET%^%^CYAN%^e%^MAGENTA%^s %^RESET%^are etched along the "
"underside of the jewelry.\n");
   set_lore("Rings such as these, while relatively simple to craft as far "
"as magical items go, are more commonly found and prized by drowkind than "
"most other races.  Drow are known for their myriad and vicious, usually "
"fatal, poisons, and so these are prized by many of their kindred to "
"protect themselves against potential assassination attempts.\n");
   set_property("lore difficulty",6);
   set_read("~ %^YELLOW%^purify %^RESET%^poisons from your blood ~\n");
   set_language("drow");
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(450);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   charges = random(4)+8;
}

void init(){
   ::init();
   add_action("cleanse_me","purify");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 10) {
     tell_object(ETO,"You cannot use this item yet.");
     return 0;
   }
   return 1;
}

int cleanse_me(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(str) {
     notify_fail("What?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You have to wear the ring first.\n");
     return 0;
   }
   if(!charges) {
     notify_fail("The ring has used up all of its magic.\n");
     return 0;
   }
   if(!TP->query_poisoning() && !TP->query_intox()) {
     tell_object(TP,"Your invoke the enchantments within the ring, but "
"nothing happens.");
     return 1;
   }
   tell_object(TP,"Your invoke the enchantments within the ring, and a "
"feeling of vitality runs through your body.");
   TP->add_poisoning(-1*(int)TP->query_poisoning());
   TP->add_intox(-1*(int)TP->query_intox());
   charges--;
   return 1;
}

int resetme() {
   charges = random(4)+8;
   return 1;
}
