#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";

void create(){
   ::create();
   set_id(({"dagger","ghoul's dagger","Dagger of the Ghoul's Touch"}));
   set_name("dagger");
   set_obvious_short("dagger");
   set_short("%^BOLD%^%^RED%^D%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^gger of the Gh%^BOLD%^%^YELLOW%^o%^BOLD%^%^RED%^ul's %^BOLD%^%^RED%^Touch%^RESET%^");
   set_long(
      "This dagger appears to be crafted from a very sturdy metal. It has no "+ 
      "scratches, nor any other mark that would appear as if it was ever used. "+ 
      "On the hilt are inset three gems. Two rubies on the ends of the hilt, "+ 
      "and a sizeable garnet in the center which seems to glow slightly."
   );
   set_lore(
      "This dagger was created by the lich known as Zanl'dal for the demon known"+
      " as grimtooth. Grimtooth lost the dagger when he was banished from the"+
      " prime material plane by the bladesinger Arvanariel Clearskies."
   );
   set_value(10000);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_hit((:TO,"hit_func":));
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
}

int wield_func(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"You can't get a proper grip on the weapon.");
     return 0;
   }
   tell_object(ETO,"The blade of the dagger becomes translucent, and you feel it drain your life slightly.");
   return 1;
}

int unwield_func(){
   tell_object(ETO,"The blade of the dagger fades back into existance as you release your hold, and you feel stronger.");
   return 1;
}

int hit_func(object targ){
        if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 200){
      switch(random(1000)){
         case 0..300:
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" stabs "+targ->QCN+" and the flesh around the wound turns deathly pale .",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^You stab "+targ->QCN+" and the flesh around the wound turns deathly pale!");
            tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" stabs you and the flesh around the wound turns deathly pale! ");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 301..600:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+"'s dagger flickers as passes through "+targ->QCN+"'s flesh!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^Your blade flickers as you cut into "+targ->QCN+"'s flesh!");
            tell_object(targ,"%^BOLD%^%^BLACK%^"+ETOQCN+"'s blade flickers as it passes through your flesh!");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 601..800:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ and they attack in unison!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^Your dagger creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ of you, and you both attack in unison!");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" creates a %^BOLD%^%^CYAN%^mirror image%^BOLD%^%^RED%^ and they attack in unison!");
            ETO->execute_attack();
            ETO->execute_attack();
            return 1;
            break;
         case 801..998:
            tell_room(environment(query_wielded()),"%^BOLD%^%^GREEN%^"+ETOQCN+" arcs the dagger and the blade fizzles into a green mist to lash out!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^GREEN%^Your blade fizzles into a green mist as you arc it to lash out at "+targ->QCN+"!");
            tell_object(targ,"%^BOLD%^%^GREEN%^"+ETOQCN+"'s blade fizzles into a green mist and lashes out at you!");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 999:
            tell_room(environment(query_wielded()),"%^RESET%^%^RED%^"+ETOQCN+"'s eyes glaze over...",({ETO,targ}));
            tell_object(ETO,"%^RESET%^%^RED%^You feel a spirit over take you... %^BOLD%^%^CYAN%^Grimtooth whispers to you%^RESET%^: I got it from here!");
            tell_object(targ,"%^BOLD%^%^CYAN%^Someone whispers to you%^RESET%^: The best assassins leave no marks!");
            set_property("magic",1);
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^RED%^You feel a stabbing sensation in your head!");
            targ->do_damage("torso",roll_dice(3,10));
            remove_property("magic");
            break;
            }
       }
}