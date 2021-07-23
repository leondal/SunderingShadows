#include <std.h>
inherit "/d/common/obj/weapon/scourge";

//9 sep 2012, Ergo
//Changed __ActuallyUnwield() to reflect 
//a new clone order so the object won't 
//vape if the player's inventory is full

void create() {
   ::create();
   set_name("chain whip");
   set_id(({"whip","lash","torments lash","torment's lash","onyx whip","onyx lash","chain whip of onyx","chain whip of onyx links"}));
   set_short("%^BLACK%^%^BOLD%^Tor%^RESET%^%^WHITE%^m%^BLACK%^%^BOLD%^ent's L%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^sh%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^a cha%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^n whip of on%^RESET%^%^WHITE%^y%^BLACK%^%^BOLD%^x links%^RESET%^");
   set_long("%^MAGENTA%^Smooth, flawless links of %^BLACK%^%^BOLD%^on%^RESET%^%^WHITE%^y%^BLACK%^%^BOLD%^x "
"stone%^RESET%^%^MAGENTA%^ have been joined together to form this chain whip.  Despite the usual manner of "
"such gems to be easily chipped, this substance seems uncommonly resiliant, strengthened by some unknown "
"means.  The whip has no handle, but because of its extended length, it is probably designed to wrap the end "
"around the wielder's hand to grip it.  A carved tip is attached to the end, of a %^BLACK%^%^BOLD%^jet-black "
"feline%^RESET%^%^MAGENTA%^ crouching upon its belly, with both paws outstretched and%^RED%^%^BOLD%^ "
"fiendishly sharp tips%^RESET%^%^MAGENTA%^ to the claws extended from them.  It has obviously been designed as "
"quite a unique weapon, to give the wielder quite an impressive appearance in combat, as well as being a "
"rather dangerous weapon.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This whip was said not to be made by human hands, but rather was a divine gift "
"to the priestess Anshara, by the Maiden of Pain herself.  It was a blessing upon the half-drow priestess, "
"during the ceremony of her ascendance to the position of Truescar within the faith, reportedly one that "
"could be of equal use as a %^YELLOW%^weapon%^WHITE%^ as an accessory.  That same half-drow was also said to "
"be the path to Loviatar's eventual destruction, as the guardian of the Orb of Torment which, some tell, was "
"stolen by Durias and instrumental to his ascension over the Maiden to demi-godhood.%^RESET%^\n");
   set_property("lore difficulty",25);
   set_weight(3);
   set_value(0);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun() {
   if(!ETO->query_invis()) {
     tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" smiles malevolently as "+ETO->QO+" wraps the end of the chain "
"around "+ETO->QP+" hand, giving the whip an experimental lash.%^RESET%^",ETO);
   }
   else {
     tell_room(EETO,"%^MAGENTA%^You hear the slight clink of chain links against each other.%^RESET%^",ETO);
   }
   tell_object(ETO,"%^MAGENTA%^You wrap the end of the chain around your hand, giving the whip an experimental "
"lash.%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" releases "+ETO->QP+" grip on the chain whip and uncoils it from "
"around "+ETO->QP+" hand.%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^You release your grip on the chain whip and uncoil it from around your "
"hand.%^RESET%^");
   return 1;
}

void __ActuallyUnwield() {
   object ob,*names,loc;
   int i;
   ::__ActuallyUnwield();
   ob = new("/d/token_hunt/obj/mid/belt1");
   loc = ETO;
   TO->move("/d/shadowgate/void");
   ob->move(loc);
   while((int)ob->query_property("enchantment") != 3) {
     ob->remove_property("enchantment");
     ob->set_property("enchantment",3);
   }
   if (TO->query_identified()) {
     names = TO->query_identified();
     for (i=0;i<sizeof(names);i++) {
       ob->add_identified(names[i]);
     }
   }
   if(TO->query_property("soulbound")) ob->set_property("soulbound",1);
   ob->set_overallStatus((int)TO->query_overallStatus());
   TO->remove();
}

int hit_fun(object target) {
   if(!random(5)) {
     switch(random(10)) {
       case 0..4:
       tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" lashes out at "+target->QCN+" with the carved tip of the "
"chain, leaving deep scratches along "+target->QP+" skin from the feline's claws!%^RESET%^",({ETO,target}));
       tell_object(ETO,"%^RED%^%^BOLD%^You lash out at "+target->QCN+" with the carved tip of the chain, leaving deep scratches along "+target->QP+" skin from the feline's claws!%^RESET%^");
       tell_object(target,"%^RED%^%^BOLD%^"+ETOQCN+" lashes out at you with the carved tip of the chain, "
"leaving deep scratches along your skin from the feline's claws!%^RESET%^");
       return 5;
       break;

       case 5..7:
       tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" spins the whip with deadly precision, striking "
+target->QCN+" several times in quick succession!%^RESET%^",({ETO,target}));
       tell_object(ETO,"%^BLACK%^%^BOLD%^You spin the whip with deadly precision, striking "+target->QCN+
" several times in quick succession!%^RESET%^");
       tell_object(target,"%^BLACK%^%^BOLD%^"+ETOQCN+" spins the whip with deadly precision, striking you "
"several times in quick succession!%^RESET%^");
       target->cause_typed_damage(target, target->return_target_limb(), roll_dice(1, 4) + 7, "slashing");
       target->cause_typed_damage(target, target->return_target_limb(), roll_dice(1, 4) + 7, "slashing");
       return 1;
       break;

       case 8..9:
       tell_room(EETO,"%^MAGENTA%^"+ETOQCN+" flings the whip around in a circle, catching "+target->QCN+"'s leg and pulling "+target->QO+" off balance!%^RESET%^",({ETO,target}));
       tell_object(ETO,"%^MAGENTA%^You fling the whip around in a circle, catching "+target->QCN+"'s leg and pulling "+target->QO+" off balance!%^RESET%^");
       tell_object(target,"%^MAGENTA%^"+ETOQCN+" flings the whip around in a circle, catching your leg and pulling you off balance!%^RESET%^");
       target->set_paralyzed(random(8)+8,"You're trying to get your balance!");
       return 0;
       break;
     }
   }
}
