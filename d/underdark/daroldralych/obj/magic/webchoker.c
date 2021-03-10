#include <std.h>
inherit ARMOUR;

int uses;

void create() {
   ::create();
   set_name("choker");
   set_id(({"choker","barbed choker","narrow choker","narrow barbed choker","choker of webs","web choker"}));
   set_short("%^BOLD%^%^BLACK%^Choker of %^RESET%^W%^BOLD%^e%^RESET%^b%^BOLD%^s%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^narrow barbed choker%^RESET%^");
   set_long((:TO,"long_desc":));
   set_lore("This uncommon item tends to be the work of drowkind, prized "
"by their priestesses.  Associated with the faith of Shar in the "
"underdark, the choker hails to their love of spiders.  Each pale bead is "
"charged with an enchantment by the priesthood, that the wearer can throw "
"it to %^YELLOW%^entangle %^RESET%^the target in thick, sticky webbing.  "
"They are considered high fashion among the drow priesthood.\n");
   set_property("lore difficulty",6);
   set_weight(0);
   set_limbs(({"neck"}));
   set_ac(0);
   set_value(1230);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   uses = 9;
}

void init(){ 
  ::init(); 
  set_long((:TO, "long_desc":)); 
   add_action("tangle_me","entangle");
}

string long_desc() {
   return("A fine filament of %^BOLD%^%^BLACK%^black metal %^RESET%^forms "
"the basis of this jewelry, designed to be worn about the throat.  Along "
"its length, branches of the same wire jut out into %^BOLD%^%^WHITE%^s"
"%^RESET%^h%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^p %^RESET%^barbs, "
"pointed outwards so as not to pierce the skin.  Along its length, a "
"total of "+uses+" %^BOLD%^%^BLACK%^pale gray spheres %^RESET%^are "
"attached to the main filament.  It adds the finishing touch to a rather "
"%^CYAN%^un%^GREEN%^i%^CYAN%^que%^RESET%^, if not somewhat strange, piece "
"of jewelry.\n");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"You cannot use this item yet.");
     return 0;
   }
   return 1;
}

int tangle_me(string str) {
   object mytarg;
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(!str) {
     notify_fail("What?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You have to wear the choker first.\n");
     return 0;
   }
   if(!present(str,ETP)) {
     notify_fail("That isn't here.\n");
     return 0;
   }
   if(!uses) {
     notify_fail("The choker has used up all of its magic.\n");
     return 0;
   }
   mytarg = present(str,ETP);
   tell_object(TP,"%^BOLD%^%^BLACK%^You snap one of the spheres from the "
"choker and hurl it at "+str+"!%^RESET%^");
   tell_object(TP,"%^BOLD%^%^BLACK%^"+TP->QCN+" snaps one of the spheres "
"from "+TP->QP+" choker and hurls it at you!%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" snaps one of the spheres "
"from "+TP->QP+" choker and hurls it at "+mytarg->QCN+"!"
"%^RESET%^",({TP,mytarg}));
   new("/cmds/spells/w/_web")->use_spell(TP,mytarg,20,100,"mage");
   uses--;
   return 1;
}

int resetme() {
   uses = 9;
   return 1;
}
