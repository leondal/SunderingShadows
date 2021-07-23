#include <std.h>
inherit "/d/common/obj/weapon/hammer_lg";

void create() {
   ::create();
   set_name("mithril hammer");
   set_id(({"hammer","mithril hammer","thick hammer","thick mithril hammer","stonebreaker"}));
   set_short("%^RESET%^%^ORANGE%^Sto%^RESET%^n%^ORANGE%^e%^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^rea%^RESET%^k%^ORANGE%^er%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^thick %^WHITE%^m%^BOLD%^i%^RESET%^%^WHITE%^th%^BOLD%^r%^RESET%^%^WHITE%^il %^ORANGE%^hammer%^RESET%^");
   set_long("%^RED%^This bulky hammer looks as if it would deal quite an "
"impressive blow. Crafted from %^BOLD%^%^WHITE%^sh%^RESET%^in%^BOLD%^in"
"%^RESET%^g m%^BOLD%^it%^RESET%^hr%^BOLD%^il%^RESET%^%^RED%^, it could only "
"have been crafted by a master smith, judging by the precision of its lines "
"and its perfect balance. A thick head with a flattened, polished surface "
"forms one side, enhanced with precise lines of %^ORANGE%^g%^YELLOW%^o"
"%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^RED%^, and a smaller spiked "
"counterweight holds it in perfect balance on the opposite side. Ornate "
"%^BOLD%^%^CYAN%^r%^BLUE%^u%^CYAN%^n%^BLUE%^e%^CYAN%^s %^RESET%^%^RED%^have "
"been etched upon the thick mounting in the middle, which leads down through "
"%^ORANGE%^g%^YELLOW%^o%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^%^RED%^-traced "
"patterns to the %^ORANGE%^le%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^ther-"
"wrap%^BOLD%^%^BLACK%^p%^RESET%^%^ORANGE%^ed %^RED%^handle, which despite its "
"probable age seems untouched by time or damage.%^RESET%^");
   set_lore("Known to be dwarven in origins, this hammer was made many "
"centuries ago by a dwarven smith whose name has been lost to the ages. It "
"was imbued with blessings by powerful dwarven priests, and then given as a "
"gift to the king of Faern Endar, a small dwarven settlement to the west. "
"Over the centuries it was handed down through successors of the royal line "
"as a family heirloom. It was only about sixty years previous that the same "
"city was destroyed by a drow raid, and both the royal line and the hammer "
"itself were lost to history's pages.");
   set_property("lore difficulty",35);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("constitution",2);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_func(){
   if(ETO->query_level() < 31) {
     tell_object(ETO,"%^ORANGE%^You try to lift the hammer, but find it is "
"too heavy for you.  Perhaps more training is in order?%^RESET%^");
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" seems unable to lift the thick "
"hammer.%^RESET%^",ETO);
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^Lig%^YELLOW%^h%^WHITE%^t %^RESET%^"
"%^ORANGE%^glints off the perfectly-shaped head of the hammer as you lift it."
"%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^WHITE%^Lig%^YELLOW%^h%^WHITE%^t %^RESET%^"
"%^ORANGE%^glints off the perfectly-shaped head of the hammer as "+ETO->QCN+
" lifts it.%^RESET%^",ETO);
   return 1;
}

int unwield_func(){
   tell_object(ETO,"%^ORANGE%^You lower the thick hammer, giving your arms a "
"rest.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" lowers the thick hammer to give "
+ETO->QP+" arms a rest.%^RESET%^",ETO);
   return 1;
}

int hit_func(object targ){
   int skinned;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   targ = ETO->query_current_attacker();
   if((skinned = (int)targ->query_stoneSkinned()) && !random(3)) {
     tell_room(EETO,"%^BOLD%^%^BLACK%^Shards of magical protection shatter "
"and fall from "+targ->QCN+"'s skin under the force of "+ETOQCN+"'s mighty "
"hammer!%^RESET%^",({ETO,targ}));
     tell_object(ETO,"%^BOLD%^%^BLACK%^Shards of magical protection shatter "
"and fall from "+targ->QCN+"'s skin under the force of your mighty hammer!"
"%^RESET%^");
     tell_object(targ,"%^BOLD%^%^BLACK%^Shards of magical protection shatter "
"and fall from your skin under the force of "+ETOQCN+"'s mighty hammer!"
"%^RESET%^");
     if (skinned > 5) targ->set_stoneSkinned(skinned - 5);
     else targ->set_stoneSkinned(0);
     return 1;
   }
   if(random(1000) < 200){
     switch(random(6)){
       case 0..1:
         tell_room(EETO,"%^RED%^"+ETOQCN+" smashes "+ETO->QP+" hammer into "
+targ->QCN+" with a powerful blow!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^RED%^You smash your hammer into "+targ->QCN+
" with a powerful blow!%^RESET%^");
         tell_object(targ,"%^RED%^"+ETOQCN+" smashes "+ETO->QP+" hammer into "
"you with a powerful blow!%^RESET%^");
         return roll_dice(2,4);
       break;
       case 2:
         tell_room(EETO,"%^ORANGE%^"+ETOQCN+" staggers "+targ->QCN+" with a "
"bone-jarring hit from "+ETO->QP+" hammer!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^ORANGE%^You stagger "+targ->QCN+" with a bone-"
"jarring hit from your hammer!%^RESET%^");
         tell_object(targ,"%^ORANGE%^"+ETOQCN+" staggers you with a bone-"
"jarring hit from "+ETO->QP+" hammer!%^RESET%^");
         targ->set_paralyzed(7,"You're still trying to regain your feet!");
         return roll_dice(1,4);
       break;
       case 3..4:
         tell_room(EETO,"%^BOLD%^%^RED%^Reversing the swing of the hammer, "
+ETO->QCN+" impales "+targ->QCN+" with the sharpened counterweight!"
"%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^RED%^Reversing the swing of the hammer, "
"you impale "+targ->QCN+" with the sharpened counterweight!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^RED%^Reversing the swing of the hammer, "
+ETO->QCN+" impales you with the sharpened counterweight!%^RESET%^");
         return roll_dice(3,4)+-2;
         break;
       case 5:
         tell_room(EETO,"%^BOLD%^%^WHITE%^The golden tracery on "+ETOQCN+"'s "
"hammer takes on a %^YELLOW%^brilliant glow %^WHITE%^as it hits "
+targ->QCN+"!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^WHITE%^The golden tracery on your hammer "
"takes on a %^YELLOW%^brilliant glow %^WHITE%^as it hits "+targ->QCN+"!"
"%^RESET%^");
         tell_object(targ,"%^BOLD%^%^WHITE%^The golden tracery on "
+ETOQCN+"'s hammer takes on a %^YELLOW%^brilliant glow %^WHITE%^as it hits "
"you!%^RESET%^");
         ETO->add_hp(random(10)+10);
         return random(10)+10;
       break;
     }
   return 0;
   }
}