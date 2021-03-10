#include <std.h>
inherit ARMOUR;

int charges;

void create() {
   ::create();
   set_name("silver ring");
   set_id(({"ring","silver ring","silver chrysoprase ring","chrysoprase ring","ring of invisibility","lesser ring of invisibility"}));
   set_short("%^BOLD%^%^WHITE%^Les%^RESET%^s%^BOLD%^%^WHITE%^er Ring of %^RESET%^%^CYAN%^Inv%^BOLD%^i%^RESET%^%^CYAN%^sibi%^BOLD%^l%^RESET%^%^CYAN%^ity%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^silver %^GREEN%^chr%^RESET%^%^GREEN%^y%^BOLD%^soprase %^WHITE%^ring%^RESET%^");
   set_long("This ring is rather simplistic in design, shaped as a single "
"circle of polished %^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^lv"
"%^RESET%^e%^BOLD%^%^WHITE%^r%^RESET%^ metal.  Set within it is a single "
"chrysoprase, %^CYAN%^translu%^BOLD%^c%^RESET%^%^CYAN%^ent %^RESET%^and a "
"pale %^BOLD%^%^GREEN%^app%^RESET%^%^GREEN%^l%^BOLD%^e-green %^RESET%^in "
"color.  The gemstone is cabochon cut with a glossy surface, and is held "
"between two raised ridges atop the ring itself. Upon the underside are a "
"few %^RED%^el%^MAGENTA%^eg%^RED%^a%^MAGENTA%^nt%^RED%^ly %^RESET%^etched "
"letters.\n");
   set_lore("Rings such as these, while relatively simple to craft as far "
"as magical items go, are more commonly found and prized by drowkind than "
"most other races.  For a race that lives by stealth and trickery, such "
"rings are commonplace.  Chrysoprase, a type of chalcedony, is commonly "
"used in the creation of items which provide invisibility, and is usually "
"cut cabochon to better show its pale color.\n");
   set_property("lore difficulty",6);
   set_read("~ simply %^YELLOW%^use%^RESET%^ this ring to hide ~\n");
   set_language("drow");
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(650);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   charges = random(4)+5;
}

void init(){
   ::init();
   add_action("hide_me","use");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 10) {
     tell_object(ETO,"You cannot use this item yet.");
     return 0;
   }
   return 1;
}

int hide_me(string str) {
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!str) {
     notify_fail("Use what?\n");
     return 0;
   }
   if(member_array(str,TO->query_id()) == -1) {
     notify_fail("You can't use that.\n");
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
   tell_object(TP,"Your invoke the enchantments within the ring.");
   new("/cmds/spells/i/_invisibility")->use_spell(TP,0,20,100,"mage");
   charges--;
   return 1;
}

int resetme() {
   charges = random(4)+5;
   return 1;
}
