#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
	::create();
	set_name("red dragon");
	set_id(({ "sword", "red dragon sword", "long sword", "weapon" }));
	set_obvious_short("An %^RESET%^%^RED%^or%^BOLD%^%^WHITE%^nat%^RESET%^%^RED%^e %^RESET%^long sword");
	set_short("%^BOLD%^%^RED%^Sraveliegn, the red dragon%^RESET%^");
	set_long(
@AVATAR
This ornately crafted long sword is in near perfect condition. The %^BOLD%^%^WHITE%^adamantite %^RESET%^blade has a %^BOLD%^%^RED%^glowing red %^RESET%^hue about it, tracing up the razor sharp edges. The hilt of the blade looks to be two %^BOLD%^%^RED%^dragon %^RESET%^claws sitting apart from one another in a clutched grip. The handle of the blade is made of a set of flat %^BOLD%^%^RED%^rubies %^RESET%^that are layered in such a way to seem like you are gripping the scales of a dragon. The heavy pommel is made of dense %^BOLD%^%^BLACK%^volcanic %^RESET%^rock, shaped into a eerily dark sphere.

AVATAR
	);
	set_value(10000);
	set_lore(
@AVATAR
Crafted by the great Artificer, Carcascus, the dragon blades were a tribute to the fourth King of Asgard, Stararach, nearly six centuries ago. The swords were rumored to have the power to control dragons of a specific type as well as slay them. After the collapse of the kings reign, Stararach's precious weapons were lost to history.

AVATAR
	);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
	set_wield((:TO,"wield_func":));
      set_hit((:TO,"hit":));
	set_unwield((:TO,"unwield_func":));
}

int wield_func(){
   if(ETO->is_monster()){
     return 1;
   }
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"You can't get a proper grip on the weapon.");
     return 0;
   }
	tell_room(environment(ETO),""+ETOQCN+" wields the weapon and "+ETOQCN+"'s pupils glow %^BOLD%^%^RED%^red%^RESET%^ for a moment.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^A surge of pride fills your heart but quickly fades, leaving a distant thirst for power in your mind.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),""+ETOQCN+" struggles to unwield the weapon but finally succeeds.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^Grudgingly you free the sword of your grip. The thirst for power leaves your mind, though you remember the taste.");
	return 1;
}

int hit(object targ){
        if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    	if(random(1000) < 200){
      switch(random(1000)){
         case 0..300:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^A streak of fire licks up the length of the blade and %^BOLD%^%^YELLOW%^engulfs %^BOLD%^%^RED%^"+targ->QCN+" in flames.",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^A streak of fire licks up the length of the sword and engulfs your target!");
            tell_object(targ,"%^BOLD%^%^RED%^A flame erupts from "+ETOQCN+"'s weapon and engulfs you in horrible flames! ");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 301..600:
            tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+"'s eyes glow a moment.",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^You feel a burst of strength!");
            tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+"'s eyes glow a moment.");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 601..800:
            tell_room(environment(query_wielded()),"%^BOLD%^%^YELLOW%^A flash of light erupts and "+targ->QCN+" screams out loudly.",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^YELLOW%^A flash of light erupts and "+targ->QCN+" screams out loudly and looks stunned only for a second.");
            if(!"/daemon/saving_d"->saving_throw(targ,"spell",-1)) {
            tell_object(targ,"%^BOLD%^%^YELLOW%^A flash of light blinds you!");
            targ->set_blind(1);
            return 1;
            }
            tell_object(targ,"Nothing happens.");
            break;
         case 801..998:
            tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^"+ETOQCN+" spins and slaps the blade against "+targ->QCN+"'s head!",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^You slap your blade against "+targ->QCN+"'s head!");
            tell_object(targ,""+ETOQCN+" slaps the blade against your head, concussing you!");
            targ->do_damage("torso",roll_dice(3,10));
            break;
         case 999:
            tell_room(environment(query_wielded()),"%^BOLD%^%^BLACK%^"+ETOQCN+" lets out a roar that brings forth thoughts of a %^BOLD%^%^RED%^mighty beast%^BOLD%^%^BLACK%^!%^RESET%^",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^You feel the power of the beast from within and strike out at your opponent with an ancient, immense, and all consuming %^BOLD%^%^RED%^force%^BOLD%^%^BLACK%^!%^RESET%^");
            tell_object(targ,"%^BOLD%^%^BLACK%^You make eye contact with your opponent and feel as if you are staring down the face of a %^BOLD%^%^RED%^red dragon%^BOLD%^%^BLACK%^ as you are struck down with a crippling and fatal blow!%^RESET%^");
            set_property("magic",1);            
            if(!targ->query_property("no death") && !FEATS_D->usable_feat(targ,"death ward"))  { targ->do_damage("torso",roll_dice(1,10)+1000); }
            else { targ->do_damage("torso",roll_dice(20,20)); } 
            remove_property("magic");            
            break;
            }
       }
}