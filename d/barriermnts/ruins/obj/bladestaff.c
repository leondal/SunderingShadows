#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/double_bladed_sword.c";

void create() {
   ::create();
   set_id(({ "bladestaff","Bladestaff","double-bladed staff","double bladed staff","double-bladed sword","double bladed sword","two bladed sword","two-bladed sword","megil'ehalaer","Megil'ehalaer","megilehalaer" }));
   set_name("bladestaff");
   set_short("%^BLACK%^%^BOLD%^Me%^RESET%^%^WHITE%^g%^ORANGE%^i%^WHITE%^l'%^BLACK%^%^BOLD%^eh%^RESET%^%^WHITE%^a%^ORANGE%^l%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^er%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^ada%^RESET%^%^WHITE%^m%^WHITE%^%^BOLD%^an%^RESET%^%^WHITE%^t%^BOLD%^ium bl%^RESET%^%^WHITE%^a%^WHITE%^%^BOLD%^des%^RESET%^%^WHITE%^t%^WHITE%^%^BOLD%^aff%^RESET%^");
   set_long("%^BLACK%^%^BOLD%^This %^RESET%^%^MAGENTA%^e%^RED%^x%^ORANGE%^ot%^RED%^i%^MAGENTA%^c "
"%^BLACK%^%^BOLD%^weapon looks as though it would need a great deal of skill just to wield. The "
"midsection of the weapon is %^RESET%^%^ORANGE%^solid wood%^BLACK%^%^BOLD%^, allowing the weapon to be "
"held much in the manner of a thick staff. However, at each end of the wood has been carefully attached "
"with a crosspiece of the same wood, and set with a "
"%^WHITE%^sh%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^n%^RESET%^%^WHITE%^i%^BOLD%^ng%^BLACK%^, curved blade of "
"adamantium. The weapon would effectively give a wielder not one, but two weapons in combat.%^RESET%^\n");
   set_weight(8);
   set_value(1500);
   set_lore("%^WHITE%^%^BOLD%^This unique style of two-ended sword was an ancient elven artifact, only "
"created within a small region of villages north of the Dagger Mountains.  It was a weapon granted only "
"to the most skilled of their kin, used by village scouts with high expertise in the complex weapon's "
"useage.  It was known as a bladestaff, 'megil'ehalaer' in the elven tongue.  The particular difference "
"from normal two-ended swords, was that these 'megil'ehalaer' weapons were crafted with ability to split "
"in half, becoming two separate blades.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_read("%^BOLD%^%^WHITE%^Part the twin blades with a simple %^CYAN%^twist%^WHITE%^,\n"
"And %^CYAN%^socket%^WHITE%^ them together with a flick of the wrist.\n");
   set_language("elven");
   set_weight(8);
   set_property("enchantment",3);
   set_item_bonus("armor bonus",2);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

void init() {
    ::init();
    if(living(ETO)) {
      add_action("twist_fun","twist");
    }
}

int wield_fun() {
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^WHITE%^%^BOLD%^" + ETOQCN + " grasps the midsection of the bladestaff securely, ready "
            "for combat!%^RESET%^", ETO);
        tell_object(ETO, "%^WHITE%^%^BOLD%^You grasp the midsection of the bladestaff, ready for "
            "combat!%^RESET%^");
    }
   return 1;
}

int unwield_fun() {
    if (!ETO->query_property("silent_wield")) {
        tell_room(EETO, "%^WHITE%^%^BOLD%^" + ETOQCN + " spins the bladestaff once and releases it.%^RESET%^", ETO);
        tell_object(ETO, "%^WHITE%^%^BOLD%^You spin the bladestaff once, and release your hold.%^RESET%^");
    }
   return 1;
}

int hit_fun(object target) {
    if(!random(9)){
      switch(random(10)) {

      case 0..4:
        ETO->execute_attack();
        tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" spins the bladestaff with blinding speed, slashing at "
+target->QCN+" again with the opposing end of "+ETO->QP+" weapon!%^RESET%^",({ETO,target}));
        tell_object(ETO,"%^BLUE%^%^BOLD%^You spin the bladestaff back, slashing at "+target->QCN+" again "
"with the opposing end of your weapon!%^RESET%^");
        tell_object(target,"%^BLUE%^%^BOLD%^"+ETOQCN+" spins the bladestaff with blinding speed, "
"slashing at you again with the opposing end of "+ETO->QP+" weapon!%^RESET%^");
        return 1;
        break;
      case 5:
        tell_room(EETO,"%^BLACK%^%^BOLD%^" +ETOQCN+" takes a sudden step forward, slamming the "
"midsection of the bladestaff directly between "+target->QCN+"'s eyes!%^RESET%^",({ETO,target}));
        tell_object(ETO,"%^BLACK%^%^BOLD%^Taking a quick step forward, you slam the midsection of the "
"bladestaff directly between "+target->QCN+"'s eyes, dazing "+target->QO+"!%^RESET%^");
        tell_object(target,"BLACK%^%^BOLD%^"+ETOQCN+" takes a sudden step toward you and slams the "
"midsection of the bladestaff directly between your eyes!%^RESET%^");
        target->set_paralyzed(random(15)+2,"You are still reeling from the blow!\n");
        break;

      case 6:
        tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" slams the flat of one blade against the side of "
+target->QCN+"'s head, dazing "+target->QO+"!%^RESET%^",({ETO,target}));
        tell_object(ETO,"%^CYAN%^%^BOLD%^You slam the flat of one blade against the side of "
+target->QCN+"'s head, dazing "+target->QO+"!%^RESET%^");
        tell_object(target,"%^CYAN%^%^BOLD%^"+ETOQCN+" slams the flat of one blade against the side of "
"your head, knocking you into a daze!%^RESET%^");
        target->set_paralyzed(random(5)+2,"You are trying to shake off the blow!\n");
        return 1;
        break;

      case 7..9:
        tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" twists the bladestaff, bringing it up to slash "
"painfully at "+target->QCN+"!%^RESET%^",({ETO,target}));
        tell_object(ETO,"%^RED%^%^BOLD%^You twist the bladestaff, bringing it up in a painful slash at "
+target->QCN+"!%^RESET%^");
        tell_object(target,"%^RED%^%^BOLD%^"+ETOQCN+" twists the bladestaff, slashing it painfully at "
"you!%^RESET%^");
        return roll_dice(3,4)*2;
        break;
      }
   }
}

int twist_fun(string str) {
   object ob1,ob2,*names;
   int i;
   if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed()) {
     ETO->send_paralyzed_message("info",ETO);
     return 0;
   }
   if (!str) {
     notify_fail("Twist what?\n");
     return 0;
   }
   if (member_array(str,TO->query_id()) == -1) {
     notify_fail("You can't twist that.\n");
     return 0;
   }
   if ((int)ETO->query_lowest_level() < 15) {
     notify_fail("You can't figure out how to do that.\n");
     return 0;
   }
   if ((int)TO->query_property("enchantment") < 0) {
     notify_fail("The bladestaff refuses to budge.\n");
     return 0;
   }
   if (TO->query_wielded()) { ETO->force_me("unwield bladestaff"); }
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" deftly separates the bladestaff's midsection into two "
"scimitar-like blades!%^RESET%^\n",ETO);
   tell_object(ETO,"%^ORANGE%^With a twist, you deftly separate the bladestaff's midsection into two "
"scimitar-like blades!%^RESET%^");
   ob1 = new(OBJ+"scimitar.c");
   while((int)ob1->query_property("enchantment") != 3) {
     ob1->remove_property("enchantment");
     ob1->set_property("enchantment",3);
   }
   ob2 = new(OBJ+"scimitar.c");
   while((int)ob2->query_property("enchantment") != 3) {
     ob2->remove_property("enchantment");
     ob2->set_property("enchantment",3);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob1->add_identified(names[i]);
       ob2->add_identified(names[i]);
     }
   }
   if(TO->query_property("soulbound")) { ob1->set_property("soulbound",1); ob2->set_property("soulbound"); }
   TO->move("/d/shadowgate/void");
   ob1->move(TP);
   ob2->move(TP);
   TP->force_me("wield scimitar");
   TP->force_me("wield scimitar 2");
   TO->remove();
   return 1;
}
