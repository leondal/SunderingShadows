//updated to fix bug when no enchantment is set with activation - Yves 2/26/18
#include <std.h>
inherit "/d/common/obj/armour/bracers";

int keeper;
object claw1,claw2;

void create() {
   ::create();
   set_name("shadowy bracers");
   set_short("%^BOLD%^%^BLACK%^Twil%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^ght Cuffs%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers%^RESET%^");
   set_id(({"bracer","bracers","shadowy bracers","cuffs","twilight cuffs"}));
   set_long("%^BLUE%^These matching pair of bracers seem almost surreal, made of nothing but%^BOLD%^%^BLACK%^ "
"whisps of shadow%^RESET%^%^BLUE%^.  You can see right through the %^WHITE%^dusky haze %^BLUE%^of their form, "
"leaving it to the imagination how they were even crafted in the first place.  The only way to tell where the "
"bracers end and the air begins, is a fine shifting line of %^YELLOW%^gold %^RESET%^%^BLUE%^around either "
"edge, that %^WHITE%^gli%^BOLD%^t%^RESET%^%^WHITE%^ters %^BLUE%^and %^BOLD%^%^WHITE%^sparkl%^YELLOW%^e%^WHITE%^"
"s %^RESET%^%^BLUE%^with a life of its own.%^RESET%^\n");
   set_weight(5);
   set_value(1025);
   set_lore("%^BOLD%^%^WHITE%^Such intriguing bracers as these are renowned as "
"never having been crafted, but instead torn forcibly from the stuff of the "
"plane of Shadows.  They were said to be the possession of the near mythical "
"creature Grimtooth, part drow and part wolfwere, an assassin of legendary "
"renown.  Feared universally across the realms, his time upon the surface left "
"a swathe of dead elven bodies in his wake, until abruptly he vanished from all "
"tales and knowledge.  Noone knows where he has disappeared to, or if someone "
"actually managed to bring his unnatural life to a final closing.  More "
"importantly to you, perhaps, were the tales that he could %^YELLOW%^will "
"the bracers%^WHITE%^ to activate with a thought, bringing forth lethal claws of "
"shadow that could cut through any known substance.%^RESET%^\n");
   set_property("lore difficulty",19);
   TO->set_property("enchantment",6);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   keeper = 0;
}

int is_metal() { return 0; }

void init(){
    ::init();
    if(!objectp(TP)) return;
    if(!objectp(ETO)) return;
    if(TP != ETO) return;
    if(interactive(TP) && !avatarp(TP)) { set_size(TP->query_size()); }
    add_action("activate_fun","will");
}

int check() {
   ::check();
   if(ETO->query_highest_level() < 30) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You haven't the experience to use such a powerful item.%^RESET%^");
     return 0;
   }
   tell_object(ETO,"%^BLUE%^You slide the %^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers "
"%^RESET%^%^BLUE%^over your forearms, and they meld perfectly against your skin.%^RESET%^");
   tell_room(EETO,"%^BLUE%^The %^BOLD%^%^BLACK%^shado%^RESET%^%^WHITE%^w%^BOLD%^%^BLACK%^y bracers %^RESET%^"
"%^BLUE%^meld perfectly against "+ETO->QCN+"'s forearms.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   if(!keeper) {
     tell_object(ETO,"%^BLUE%^The %^BOLD%^%^BLACK%^dusky br%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cers %^RESET%^"
"%^BLUE%^slide loose from your forearms.%^RESET%^");
     tell_room(EETO,"%^BLUE%^The %^BOLD%^%^BLACK%^dusky br%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cers %^RESET%^"
"%^BLUE%^slide loose from "+ETO->QCN+"'s forearms.%^RESET%^",ETO);
   }
   else {
     keeper = 0;
     tell_object(ETO,"%^BLUE%^The shadowy claws disappear again as you remove the bracers.%^RESET%^");
     tell_room(EETO,"%^BLUE%^The shadowy claws disappear as "+ETO->QCN+" removes the bracers.%^RESET%^",ETO);
     if(objectp(claw1)) { claw1->__ActuallyUnwield(); }
   }
   return 1;
}

int activate_fun(string str) {
   object ob,*names;
   int i;
   if (!str) {
     notify_fail("Will what?\n");
     return 0;
   }
   if (str != "bracers" && str != "the bracers") {
     notify_fail("Nothing happens.\n");
     return 0;
   }
   if (!TO->query_worn()) {
     notify_fail("You feel you should be wearing them before you try that.\n");
     return 0;
   }
   if(ETO->query_lowest_level() < 30) {
     notify_fail("Nothing happens.");
     return 0;
   }
   if(keeper > 0) {
     notify_fail("You sense that they are already active.");
     return 0;
   }
   if(sizeof(TP->query_wielded()) > 0) {
     notify_fail("You feel the need to empty your hands first...");
     return 0;
   }
   tell_object(ETO,"%^BLUE%^You will the bracers to activate, and two claws of %^BOLD%^%^BLACK%^pure s%^RESET%^"
"%^WHITE%^h%^BOLD%^%^BLACK%^adow %^RESET%^%^BLUE%^spring forth over the top of your hands!%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETO->QCN+" concentrates, and two claws of %^BOLD%^%^BLACK%^pure s%^RESET%^"
"%^WHITE%^h%^BOLD%^%^BLACK%^adow %^RESET%^%^BLUE%^spring forth over the top of "+ETO->QP+" hands!%^RESET%^",ETO);
   claw1 = new("/d/dagger/marsh/tower/obj/shadowclaws.c");
   claw1->move(ETO);
   claw1->remove_property("enchantment");
   claw1->set_property("enchantment", (ETO->query_level()-3)/5);
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       claw1->add_identified(names[i]);
     }
   }
   ETO->force_me("wield shadowclaw");
   claw2 = new("/d/dagger/marsh/tower/obj/shadowclaws.c");
   claw2->move(ETO);
   claw2->remove_property("enchantment");
   claw2->set_property("enchantment", (ETO->query_level()-3)/5);
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       claw2->add_identified(names[i]);
     }
   }
   ETO->force_me("wield shadowclaw");
   claw1->set_claw(claw2);
   claw2->set_claw(claw1);
   claw1->set_bracer(TO);
   claw2->set_bracer(TO);
   keeper = 1;
   return 1;
}

void do_reset() { keeper = 0; }
int query_status() { return keeper; }

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^BLUE%^The shadowy bracers seem to solidify, just enough to harmlessly deflect "
+target->QCN+"'s attack!%^RESET%^");
     tell_object(target,"%^BLUE%^"+ETO->QCN+"'s shadowy bracers seem to solidify, just enough to harmlessly "
"deflect your attack!%^RESET%^");
     tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s shadowy bracers seem to solidify, just enough to harmlessly "
"deflect "+ETO->QP+"'s attack!%^RESET%^",({ETO,target}));
     return 0;
   }
   return damage;
}
