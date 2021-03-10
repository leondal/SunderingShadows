//Coded by Bane//
// guild stuff commented out by Styx 8/2002 & (hopefully) bugs fixed

#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"lord","Lord","nihilus","Nihilus","lord nihilus","Lord Nihilus"}));
    set_name("Lord Nihilus");
    set_short("Lord Nihilus, fallen warlord");
    set_long(
	"Lord Nihilus is a once great warlord.  Now he spends all of eternity "+
	"in this fortress protecting the treasures within its tremendous "+
	"walls.  As a warrior he fought countless battles, turning himself "+
	"into a machine of death and destruction.  The former champion is now "+
	"only a ghost of his past glories."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(100,400);
    set_hp(1200);
    set_exp(10000);     //lowered from 50k per T to leave in game but lower exp
    set_overall_ac(0);
    set_damage_bonus(15);
    set_stats("strength",24);
    set_stats("dexterity",19);
    set_stats("constitution",23);
//    set("aggressive","member");
    set("aggressive", 21);
    set_property("swarm", 1);        
    set_mob_magic_resistance("average");
    set_property("strength","paralyzed");
    set_property("no bump",1);
    set_class("fighter");
    set_guild_level("fighter",100);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/tharis/obj/psword")->move(this_object());
    command("wield sword");
    new("/d/tharis/obj/psword")->move(this_object());
    command("wield sword");
    new("/d/shadow/guilds/angels/tmp/mon/farmor")->move(this_object());
    command("wear armor");
    new("/d/common/obj/armour/helm")->move(this_object());
    command("wear helm");
    set_funcs(({"berserk","dash","psionic"}));
    set_func_chance(35);
}
void berserk(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon",-4)){
	tell_object(targ,"%^BOLD%^BLUE%^Lord Nihilus smashes into you!");
	tell_room(ETO,"%^BOLD%^BLUE%^Lord Nihilus smashes into "+targ->query_cap_name()+"!",targ);
	targ->do_damage("torso",roll_dice(10,10));
	return;
    }
    tell_object(targ,"%^BOLD%^BLUE%^Lord Nihilus whirls past you!");
    tell_room(ETO,"%^BOLD%^BLUE%^Lord Nihilus whirls past "+targ->query_cap_name()+"!",targ);
    return;
}
void dash(object targ){
    tell_object(targ,"Lord Nihilus dashes at you!");
    tell_room(ETO,"Lord Nihilus dashes at "+targ->query_cap_name()+"!",targ);
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand",-4)){
	tell_object(targ,"%^BOLD%^RED%^You are knocked from your feet!");
	tell_room(ETO,"%^BOLD%^RED%^"+targ->query_cap_name()+" is knocked from "+targ->query_possessive()+" feet!");
	targ->do_damage("torso",roll_dice(5,10));
	targ->set_paralyzed(40,"You are stunned from that last attack.");
	return;
    }
    tell_object(targ,"%^BOLD%^RED%^You manage to avoid the assault!");
    tell_room(ETO,"%^BOLD%^RED%^"+targ->query_cap_name()+" manages to avoid the assault!",targ);
    return;
}
void psionic(object targ){
    tell_object(targ,"Lord Nihilus concentrates on you.");
    tell_room(ETO,"Lord Nihilus concentrates on "+targ->query_cap_name()+".",targ);
    if(!"daemon/saving_d"->saving_throw(targ,"spells",-4)){
	tell_object(targ,"%^BOLD%^GREEN%^Your equipment falls to the ground.");
	tell_room(ETO,"%^BOLD%^GREEN%^"+targ->query_cap_name()+"'s equipment falls to the ground.",targ);
	targ->force_me("drop all");
	return;
    }
    tell_object(targ,"%^BOLD%^GREEN%^You feel light headed.");
    tell_room(ETO,"%^BOLD%^GREEN%^"+targ->query_cap_name()+" looks dazed.",targ);
    return;
}
/*
void member(){
    if((string)TP->query_guild() != "Fallen Angel"){
	tell_object(TP,"%^BOLD%^RED%^Lord Nihilus growls at you and attacks!");
	tell_room(ETO,"%^BOLD%^RED%^Lord Nihilus growls at "+TP->query_cap_name()+" and attacks "+TP->query_objective()+"!",TP);
	force_me("kill "+TPQCN);
  	return 1;
    }
    write("Lord Nihilus nods.");
    return 1;
}
void init(){
    ::init();
// no idea why this is cast as int not string & T didn't either.    
    if((int)TP->query_name() != "Josul" && (int)TP->query_name() != "Tera-Sin" && (int)TP->query_name() != "Lord Nihilus"){
    if((int)TP->query_guild() != "Fallen Angel"){
	force_me("kill "+TPQCN);
    }
    }
}
*/
void heart_beat(){
    ::heart_beat();
// changed TP to TO & check for objectp(TO) added    
    if(!objectp(TO))   return;
    if(TO->query_hp() < 1198){
	TO->add_hp(3);
    }
}
