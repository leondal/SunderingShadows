#include <std.h>
#include "../undead.h"
#include <daemons.h>
inherit "/d/common/obj/weapon/warhammer.c";
object ob2;
string owner;


create() {
    ::create();
   set_id(({ "wolfhammer","hammer","wolf hammer","Wolf","Hammer","weapon","wolfhand","wolf hand" }));
   set_name("wolfhammer");
   set_short("%^BOLD%^The %^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lf's %^CYAN%^J%^RESET%^%^CYAN%^u%^BOLD%^d%^RESET%^%^CYAN%^g%^BOLD%^e%^RESET%^%^CYAN%^m%^BOLD%^e%^RESET%^%^CYAN%^n%^BOLD%^t%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d %^CYAN%^Warhammer%^RESET%^");
   set_long("%^BOLD%^This is a large and solid %^CYAN%^warhammer %^WHITE%^with an %^RESET%^o%^BOLD%^r%^RESET%^n%^BOLD%^a%^RESET%^m%^BOLD%^e%^RESET%^n%^BOLD%^t%^RESET%^e%^BOLD%^d "+
   "%^BLACK%^m%^RESET%^i%^BOLD%^t%^BLACK%^h%^RESET%^r%^BOLD%^i%^BLACK%^l %^WHITE%^handle. The handle have %^RESET%^%^MAGENTA%^intricate "+
   "%^BOLD%^%^WHITE%^small images of %^GREEN%^owls%^WHITE%^, %^ORANGE%^eagles %^WHITE%^and %^BLACK%^wolves %^WHITE%^from different angles. "+
   "Each animal have small %^MAGENTA%^a%^RESET%^%^MAGENTA%^m%^BOLD%^e%^RESET%^%^MAGENTA%^th%^BOLD%^y%^RESET%^%^MAGENTA%^st%^BOLD%^s "+
   "%^WHITE%^for eyes, and the %^BLACK%^m%^RESET%^i%^BOLD%^t%^BLACK%^h%^RESET%^r%^BOLD%^i%^BLACK%^l %^WHITE%^have been expertly worked "+
   "to create %^BLACK%^shade %^WHITE%^and %^ORANGE%^light%^WHITE%^. But the most noticeable about this %^CYAN%^warhammer%^WHITE%^, is "+
   "the %^BLACK%^massive %^WHITE%^and %^RED%^deadly %^WHITE%^looking %^CYAN%^head%^WHITE%^. The %^CYAN%^head %^WHITE%^is made from solid "+
   "%^BLACK%^m%^WHITE%^i%^RESET%^t%^BOLD%^%^BLACK%^h%^RESET%^r%^BOLD%^i%^BLACK%^l %^WHITE%^and is shaped as the head of a %^BLACK%^wolf%^WHITE%^. "+
   "The mouth is set in a %^RESET%^%^RED%^s%^BOLD%^n%^RESET%^%^RED%^a%^BOLD%^r%^RESET%^%^RED%^l %^BOLD%^%^WHITE%^showing o%^RESET%^f%^BOLD%^f "+
   "%^CYAN%^gleaming %^RESET%^canine teeth %^BOLD%^created in polished %^BLACK%^h%^WHITE%^e%^BLACK%^m%^WHITE%^a%^BLACK%^t%^WHITE%^it%^BLACK%^e%^WHITE%^. "+
   "The eyes %^RESET%^are %^BOLD%^made of %^BLUE%^blue %^WHITE%^d%^CYAN%^i%^WHITE%^am%^CYAN%^o%^WHITE%^nds and seems %^RESET%^t%^BOLD%^o follow "+
   "you everywhere you move and you feel %^BLACK%^j%^CYAN%^u%^BLACK%^d%^CYAN%^g%^BLACK%^e%^CYAN%^d %^WHITE%^by its "+
   "%^CYAN%^st%^RESET%^%^CYAN%^a%^BOLD%^r%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^. The %^CYAN%^hammer %^WHITE%^almost seems to "+
   "%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^l%^RESET%^%^MAGENTA%^s%^BOLD%^e %^WHITE%^from %^CYAN%^m%^RESET%^%^CYAN%^a%^BOLD%^g%^RESET%^%^CYAN%^i%^BOLD%^c%^RESET%^%^CYAN%^a%^BOLD%^l "+
   "%^WHITE%^or %^CYAN%^d%^WHITE%^i%^CYAN%^v%^WHITE%^i%^CYAN%^n%^WHITE%^e energy%^RESET%^");
   set_lore("Looking upon the this weapon, there can be no doubt that this is indeed the fabled '%^BOLD%^%^CYAN%^Wolf's Judgement%^RESET%^'. "+
   "Legends will tell of this weapon as being imbued with the power of the %^BOLD%^%^BLACK%^Great Wolf Fenrir%^RESET%^! A beast so powerful and "+
   "terrifying that it cost %^BOLD%^Tyr %^RESET%^his right hand trying to tame it. When he did tame %^BOLD%^%^BLACK%^Fenrir%^RESET%^. %^BOLD%^Tyr "+
   "%^RESET%^then bound the %^BOLD%^%^BLACK%^Wolfs power %^RESET%^and the the power of his lost sword-hand into one item so that the "+
   "%^BOLD%^%^BLACK%^Great Wolf Fenrir %^RESET%^may never wreck terror on the world again. It is said that only a true follower of Tyr may "+
   "harness the true power within this weapon. %^YELLOW%^But be warned%^RESET%^, %^BOLD%^%^RED%^The great power of Fenrir are not meant for mortal hands and may come with sacrifice!%^RESET%^");
   set_property("lore difficulty",15); 
   set_property("id difficulty",20);
   set_property("enchantment",random(3)+3);
   set_property("sight bonus",1);
   set_property("damage bonus",2);
   set_weight(10);
   set_size(2);
   set("value", 8000);
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_hit((:TO,"hitme":));

}

void init(){
   int num;
   ::init();

    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && !owner) owner = ETO->query_true_name();
   if(!objectp(ETO)) { return; }
   
   
   if(interactive(ETO) && !avatarp(ETO)){
      tell_object(ETO,"%^RED%^The hammer magically shifts to fit "+
	     "perfectly in your hands.%^RESET%^");
      num = (int)ETO->query_size();
      set_size(num);
      set_wc(num,3);
      set_large_wc(num,4);
   }

}


int wieldme() {
	
	if(ETO->query_level() < 25){
		
		tell_object(ETO,"The weapon refuses you.");
		tell_room(EETO,ETO->QCN+" is not able to wield the weapon",({ETO}));
		return 0;
	}
	
	if(ALIGN->is_chaotic(ETO)){
		tell_object(ETO,"%^BOLD%^%^RED%^You feel a terrible wrath as you try to wield the weapon!");
		tell_room(EETO,"%^BOLD%^%^BLACK%^The wolfhammer sink it's teeth into "+ETO->QCN+" before disappearing!",({ETO}));
		ETO->do_damage(ETO->return_target_limb(),roll_dice(10,10)+100);
		tell_object(ETO,"%^BOLD%^%^BLACK%^The wolfhammer sinks its teeth into your arm before disappearing!");
		TO->remove();
		return 0;
	}

	   if(ETO->query_property("master weapon")) { //preventing stack up with other "top" weapons
     tell_object(ETO,"%^BOLD%^%^BLACK%^You sense a primal and terrible anger from the %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d as you draw closer to the weapon. You decide against it!");
     tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETO->QCN+"%^BOLD%^%^BLACK%^ reaches out to grasps the %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d, but withdraw "+ETO->QS+" hand quickly and seem to reconsider.",ETO);
     return 0;
	   }
	
		if(ALIGN->is_lawful(ETO) && (string)ETO->query_diety() == "tyr") {
		set_property("empowered",1);
		set_property("attack bonus",2);
		set_property("able to cast", 1);
		ETO->set_property("master weapon",1);
			tell_object(ETO,"%^BOLD%^%^RED%^You feel the terrible wrath of Fenrir within the Wolfhammer!");
	        tell_room(EETO,ETO->QCN+" %^BOLD%^%^YELLOW%^cry out in horrible pain as the Wolfhammer %^RED%^devours "+ETO->QP+"%^YELLOW%^ hand!",({ETO}));
			tell_object(ETO,"%^BOLD%^%^YELLOW%^You cry out in horror as you realize the %^BLACK%^spirit of Fenrir%^YELLOW%^ has %^RED%^claimed your hand!");
			ETO->do_damage(ETO->return_target_limb(),roll_dice(20,5)+20);
			tell_object(ETO,"%^RESET%^%^CYAN%^As the pain finaly subsides, your hand is gone and a %^BOLD%^%^BLACK%^snarling worlfs head%^RESET%^%^CYAN%^ had takens it's place!");
		return 1;
		}
	
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel a feral power held within the wolfhammer");
	tell_room(EETO,ETO->QCN+" %^BOLD%^%^BLACK%^looks solemly at the wolfhammer, as "+ETO->QS+"%^BOLD%^%^BLACK%^ wields it",({ETO}));
		return 1;
}

int unwieldme() {
	
	
	if(ALIGN->is_lawful(ETO) && (string)ETO->query_diety() == "tyr") {
	 if ((int)ETO->query_hp() < 0) return 1;
    tell_object(TP, "%^CYAN%^The wolfhammer 'is' your hand now, can't unwield your hand!%^RESET%^");
    return 0;
	}
	
	tell_object(ETO,"You feel more yourself as you let go of the mace");
	tell_room(EETO,ETO->QCN+" appears himself again as "+ETO->QS+" lets go of the weapon",({ETO}));
	ETO->remove_property("master weapon",1);
	return 1;
	
}

int drop(){
    if(ALIGN->is_lawful(ETO) && (string)ETO->query_diety() == "tyr" && TO->query_wielded() && !((int)ETO->query_hp() < 0)){
		tell_object(ETO,"%^BOLD%^%^CYAN%^Thats your hand you want to drop? Not happening!");
		tell_room(EETO,ETO->QCN+" %^CYAN%^looks like "+ETO->QS+"%^CYAN%^ is trying to throw away his hand?!",({ETO}));
		return 1;
	}
	if(TO->query_wielded()) {ETO->force_me("unwield wolfhammer");}	
	tell_object(ETO,"you drop wolfhammer");
	tell_room(EETO,ETO->QCN+"drops wolfhammer",({ETO}));
	TO->move(EETO);
	return 1;
}

int hitme(object targi){
	
	targi = ETO->query_current_attacker();
	
	if(!objectp(ETO) || !objectp(targi)) {return 0;}
	
		if(random(1000) < 250){
		
			if(ALIGN->is_lawful(ETO) && (string)ETO->query_diety() == "tyr"){
				
					switch(random(100)){
					case 0..9:
					
						tell_object(ETO,"%^RESET%^%^CYAN%^The %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d %^RESET%^%^CYAN%^and you roar in unison and launches at "+targi->QCN);
						tell_object(targi,ETO->QCN+" and his %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d hand roar in unison as "+ETO->QS+" launches at you");
						tell_room(EETO,ETO->QCN+" and his %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d hand roar in unison as "+ETO->QS+" launches at "+targi->QCN,({ETO,targi}));
						targi->do_damage(targi->return_target_limb(),roll_dice(2,4)+2);
						targi->set_paralyzed(roll_dice(4,5)+5);
						break;
						
					case 10..19:
						
						tell_object(ETO,"%^RESET%^%^MAGENTA%^Your %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ hand howls deep and long, and another wolf responds!");
						tell_room(EETO,ETO->QCN+"%^RESET%^%^MAGENTA%^ raises his %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ in a howl, and a silver fured wolf responds!",({ETO}));	
						ob2=new(MON"tyrwolf.c");
						ob2->move(EETO);
						ob2->force_me("protect "+ETO->query_name());
						ETO->add_follower(ob2);
						ob2->set_property("minion", ETO); 
						break;
						
					case 20..39:
						
						tell_object(ETO,"%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^%^BOLD%^%^RED%^ tears into "+targi->QCN+"'s%^BOLD%^%^RED%^ flesh!");
						tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^%^BOLD%^%^RED%^ hand tears into your flesh!");
						tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^MAGENTA%^ %^BOLD%^%^RED%^hand tears into "+targi->QCN+"'s%^BOLD%^%^RED%^ flesh!",({ETO,targi}));
						set_property("magic",1);
						targi->do_damage(targi->return_target_limb(),roll_dice(4,4)+4);
						ETO->do_damage("torso",roll_dice(4,5)*(-1));
						set_property("magic",-1);
						break;
						
					case 40..59:

						tell_object(ETO,"%^BOLD%^%^WHITE%^Not yet satisfied the %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^BOLD%^%^WHITE%^ snaps at "+targi->QCN+"%^BOLD%^%^WHITE%^ again");
						tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^BOLD%^%^WHITE%^ hand snaps out on it's own!");
						tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^BOLD%^%^WHITE%^ hand snaps out on it's own at "+targi->QCN,({ETO,targi}));
						ETO->execute_attack();
						break;
						
					case 60..97:

						tell_object(ETO,"%^RESET%^%^RED%^ The %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^ snarls ferociously as it's teeths sinks into "+targi->QCN);
						tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%%^RESET%^%^RED%^ hand snarls feociously and sinks it's teeth into you!");
						tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^%^RED%^ hand snarls ferociously and sinks it's teeth into "+targi->QCN,({ETO,targi}));
						set_property("magic",1);
						targi->do_damage(targi->return_target_limb(),roll_dice(2,5)+3);
						set_property("magic",-1);
						break;
						
					case 99:
					
						tell_object(ETO,"The %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET% grabs "+targi->QCN+" by the throath!");
						tell_object(targi,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET% hand got you by the throath!");
						tell_room(EETO,ETO->QCN+"'s %^BOLD%^%^BLACK%^W%^RESET%^o%^BOLD%^%^BLACK%^lfh%^RESET%^ea%^BOLD%^%^BLACK%^d%^RESET%^ hand got "+targi->QCN+" by the throath!");
						if(!"daemon/saving_throw_d"->reflex_save(targi,-25)) { 
						targi->do_damage(targi->return_target_limb(),roll_dice(20,5)+50);
						}
						else
						{
						targi->do_damage(targi->return_target_limb(),roll_dice(5,5)+5);
						}
						break;
			}
			return 1;
		}
		
		
		
			switch(random(20)){
				
				case 0..1:
				
				
				tell_object(ETO,"You hear a low growl from the wolf-hammer as it slams "+targi->QCN);
				tell_object(targi,ETO->QCN+"'s wolf-hammer growls as it slams into you");
				tell_room(EETO,ETO->QCN+"'s wolf-hammer growls as it slams into "+targi->QCN,({ETO,targi}));
				targi->do_damage(targi->return_target_limb(),roll_dice(2,4)+2);
				targi->set_paralyzed(roll_dice(2,4)+2);
					break;
					
				case 2..19:
				
				
				tell_object(ETO,"The hammer lends its own strength to the attack on "+targi->QCN);
				tell_object(targi,ETO->QCN+"lands a powerful attack on you");
				tell_room(EETO,ETO->QCN+"lands a powerful attack on "+targi->QCN,({ETO,targi}));
				targi->do_damage(targi->return_target_limb(),roll_dice(2,4)+2);
				break;
				}
				
				return 1;
}
}


void heart_beat()
{
	 if(!objectp(TO)) { return; }
	 if(!objectp(ETO)) { return; }
	 if(TO->is_weapon()) 
	 { 
		if(!TO->query_wielded()) { return; } 
	 } 
	 if(TO->is_armor())
	 { 
		if(!TO->query_worn()) { return; } 
	 } 
	 if(!interactive(ETO)) { return; } 
	 if(ALIGN->is_lawful(ETO) && (string)ETO->query_diety() == "tyr") {
	 if(random(1000) > 998) 
	 {
		switch(random(10000)) 
		{
			case 0..6998:
				tell_object(ETO, "%^GREEN%^You feel the %^BOLD%^%^BLACK%^sp%^RESET%^i%^BOLD%^%^BLACK%^r%^RESET%^i%^BOLD%^%^BLACK%^t of F%^RESET%^e%^BOLD%^%^BLACK%^nr%^RESET%^i%^BOLD%^%^BLACK%^r %^RESET%^%^GREEN%^trying to take you over%^WHITE%^, %^YELLOW%^but you forces %^BLACK%^F%^WHITE%^e%^BLACK%^nr%^WHITE%^i%^BLACK%^r %^ORANGE%^into submission with your will%^RESET%^");
				tell_room(EETO,ETO->QCN+"'s eyes %^BOLD%^%^RED%^flares %^RESET%^with an %^BOLD%^%^BLACK%^ancient f%^RED%^e%^BLACK%^r%^RED%^a%^BLACK%^l r%^RED%^a%^BLACK%^g%^RED%^e%^RESET%^, until "+ETO->QS+" %^CYAN%^blinks, and it is gone%^WHITE%^", ({ETO}));
				break;
			case 6999..9999:
				tell_object(ETO, "%^CYAN%^From deep within you%^ORANGE%^, the power of %^BOLD%^%^BLACK%^F%^RED%^e%^BLACK%^nr%^RED%^i%^BLACK%^r %^RESET%^%^ORANGE%^wells up in you like a %^BOLD%^instinctual howl!%^RESET%^");
				tell_room(EETO, ETO->QCN+" %^CYAN%^seem concentrated for a moment, %^ORANGE%^but suddenly break out into an %^BOLD%^%^BLACK%^unearthly wolfs howl!%^RESET%^", ({ETO}));
				break;
			//case 9999:	
				
		}
	}
}
}


