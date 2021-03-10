//Coded by Bane//
// guild stuff commented out by Styx 8/2002 & (hopefully) bugs fixed

#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"guardian","josul","Josul"}));
    set_name("Josul");
    set_short("Josul, Dark Angel");
    set_long(
	"This man stands before you tall and rigid, a fearsome glare "+
	"in his eyes.  Equipped in fine armor and wielding terrible "+
	"swords this warrior looks quite strong.  He stands his guard "+
	"in this castle, never tiring."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(75,300);
    set_hp(890);
    set_exp(10000);	//lowered from 50k per T to leave in game but lower exp
    set_overall_ac(0);
    set_damage_bonus(10);
    set_stats("strength",25);
    set_stats("dexterity",19);
    set_stats("constitution",22);
//    set("aggressive","member");
    set("aggressive", 21);
    set_mob_magic_resistance("average");
    set_property("strength","paralyzed");
    set_property("no bump",1);
    set_class("ranger");
    set_guild_level("ranger",50);
    set_mlevel("ranger", 50);         // he was ranger 0, added to fix that
//  set_property("full attacks", 1);  // not sure whether to add this or not
    set_property("swarm", 1);         // added by Styx
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/common/obj/weapon/longsword")->move(this_object());
    command("wield sword");
    new("/d/common/obj/weapon/longsword")->move(this_object());
    command("wield sword");
    new("/d/common/obj/armour/chain")->move(this_object());
    command("wear armor");
    new("/d/common/obj/armour/helm")->move(this_object());
    command("wear helm");
    set_funcs(({"slice"}));
    set_func_chance(45);   //increased from 25 rather than give full attacks
}
void slice(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon",-4)){
 	tell_object(targ,"%^BOLD%^GREEN%^Josul swings his sword in an arc slicing you across the chest!");
 	tell_room(ETO,"%^BOLD%^GREEN%^Josul swings his sword in an arc slicing "+targ->query_cap_name()+" across the chest!",targ);
	targ->do_damage("torso",roll_dice(10,10));
	return;
    }
    tell_object(targ,"%^BOLD%^GREEN%^Josul swings his sword in an arc barely missing your neck!");
    tell_room(ETO,"%^BOLD%^GREEN%^Josul swings his sword in an arc barely missing "+targ->query_cap_name()+"'s neck!",targ);
    return;
}
/*
void member(){
    if((string)TP->query_guild() != "Fallen Angel"){
	tell_object(TP,"%^BOLD%^GREEN%^Josul snarls at you and attacks!");
	tell_room(ETO,"%^BOLD%^GREEN%^Josul snarls at "+TP->query_cap_name()+" and attacks "+TP->query_objective()+"!",TP);
	force_me("kill "+TPQCN);
  	return;
    }
    write("%^MAGENTA%^Josul says%^RESET%^: Hello brethen.");
    return;
}

void init(){
    ::init();
// no idea why this is cast as int not string & T didn't either.    
    if((int)TP->query_name() != "Tera-Sin" && (int)TP->query_name() != "Josul"){
    if((int)TP->query_guild() != "Fallen Angel"){
	force_me("kill "+TPQCN);
	return 1;
    }
    }
}
*/
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO))  return;
    if(TO->query_hp() < 888){
	TO->add_hp(3);
	return;
    }
}
