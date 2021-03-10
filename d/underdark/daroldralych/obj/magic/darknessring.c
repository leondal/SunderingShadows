#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int tracker, uses;

void create() {
   ::create();
   set_name("onyx band");
   set_id(({"band","onyx band","solid band","solid onyx band","ring","ring of darkness"}));
   set_short("%^BOLD%^%^BLACK%^Ri%^RESET%^n%^BOLD%^%^BLACK%^g of Dark%^RESET%^n%^BOLD%^%^BLACK%^ess%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^solid o%^RESET%^n%^BOLD%^%^BLACK%^yx band%^RESET%^");
   set_long("This band is plain in design, consisting of a single thick, "
"solid stone circle.  It is shaped from a single piece of %^BOLD%^"
"%^BLACK%^o%^RESET%^n%^BOLD%^%^BLACK%^yx %^RESET%^that gleams as its "
"smooth surface catches the %^BOLD%^%^WHITE%^lig%^YELLOW%^h%^WHITE%^t"
"%^RESET%^.  No veins or discolorations mar its flawless shape, but upon "
"the underside have been etched several elegant %^CYAN%^r%^BOLD%^u"
"%^RESET%^%^CYAN%^n%^BOLD%^e%^RESET%^%^CYAN%^s%^RESET%^.\n");
   set_lore("Rings such as these, while relatively simple to craft as far "
"as magical items go, are more commonly found and prized by drowkind than "
"most other races.  For a race that lives in eternal darkness, any kind "
"of bright light is anathema to them, and so they often carry trinkets "
"that afford them a means to darken their surrounds. These particular "
"rings have a limited set of uses each day, before they need time to "
"recharge.\n");
   set_property("lore difficulty",6);
   set_read("%^RESET%^~ simply %^YELLOW%^use %^RESET%^this ring to call the darkness ~\n");
   set_language("drow");
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(450);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   tracker = 0;
   uses = 0;
}

void init(){
   ::init();
   add_action("darken_fun","use");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 10) {
     tell_object(ETO,"You cannot use this item yet.");
     return 0;
   }
   return 1;
}

int darken_fun(string str) {
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
   if(tracker > time()) {
     tell_object(TP,"The ring cannot be used again today.");
     return 1;
   }
   if(uses == 2) {
     tracker = time() + 28800;
     uses = 0;
   }
   else {
     uses++;
     tell_object(TP,"Your invoke the enchantments within the ring.");
     new("/cmds/spells/d/_darkness")->use_spell(TP,TP,20,100,"mage");
   }
   return 1;
}

int resetme() {
   tracker = 0;
   uses = 0;
   return 1;
}
