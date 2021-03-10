//Coded by Bane//
// guild stuff commented out by Styx 8/2002 & (hopefully) bugs fixed
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"guardian","tera-sin"}));
    set_name("Tera-Sin");
    set_short("Tera-Sin, Guardian of Angels");
    set_long(
	"A man of solid mass and muscle stands before you.  Clad in an "+
	"ancient armor this warrior of exceptional skill stands guard "+
	"over this stronghold of Ghosts.  Behind his towering helm is "+
	"the face of DEATH INCARNATE!"
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(80,300);
    set_hp(940);
    set_exp(10000);   //lowered from 50k per T to leave in game but lower exp
    set_overall_ac(0);
    set_damage_bonus(10);
    set_stats("strength",24);
    set_stats("dexterity",19);
    set_stats("constitution",22);
//    set("aggressive","member");
    set("aggressive", 21);
    set_mob_magic_resistance("average");
    set_property("strength","paralyzed");
    set_property("no bump",1);
    set_class("fighter");
    set_guild_level("fighter",40);
    set_property("swarm", 1);        
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/common/obj/weapon/two_hand_sword")->move(this_object());
    command("wield sword in right hand and left hand");
    new("/d/common/obj/armour/fullplate")->move(this_object());
    command("wear armor");
    set_funcs(({"charge"}));
    set_func_chance(40);  //increased from 25 because full attacks was too much
}
void charge(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon",-4)){
	tell_object(targ,"%^BOLD%^RED%^Tera-Sin charges at you driving his sword into your body!");
	tell_room(ETO,"%^BOLD%^RED%^Tera-Sin charges at "+targ->query_cap_name()+" driving his sword into "+targ->query_objective()+"!",targ);
	targ->do_damage("torso",roll_dice(10,10));
	return;
    }
    tell_object(targ,"%^BOLD%^RED%^Tera-Sin charges right past you driving his sword into the wall!");
    tell_room(ETO,"%^BOLD%^RED%^Tera-Sin charges right past "+targ->query_cap_name()+" driving his sword into the wall!",targ);
    return;
}
/*
void member(){
    if((string)TP->query_guild() != "Fallen Angel"){
	tell_object(TP,"%^BOLD%^RED%^Tera-Sin screams at you and attacks!");
   	tell_room(ETO,"%^BOLD%^RED%^Tera-Sin screams at "+TP->query_cap_name()+" and attacks "+TP->query_objective()+"!",TP);
	force_me("kill "+TPQCN);
  	return 1;
    }
    write("%^MAGENTA%^Tera-Sin says%^RESET%^: Welcome home Angel.");
    return 1;
}

void init(){
    int i, j;
    object *user;
    ::init();
// no idea why this is cast as int not string & T didn't either.    
    if((int)TP->query_name() != "Josul" && (int)TP->query_name() != "Tera-Sin"){
    if((int)TP->query_guild() != "Fallen Angel"){
	force_me("kill "+TPQCN);
	user = users();
	i = sizeof(user);
            for(j = 0;j < i;j++) {
		if((string)user[j]->query_guild() == "Fallen Angel"){
		    tell_object(user[j],"Tera-Sin %^MAGENTA%^<angels> %^RESET%^"
		    "Angels we are under seige!"
		    );
                }
	}
	return 1;
    }
    }
}
*/
void heart_beat(){
    ::heart_beat();
// changed TP to TO & check for objectp(TO) added    
    if(!objectp(TO))   return;
    if(TO->query_hp() < 938){
	TO->add_hp(3);
        return 1;
    }
}
