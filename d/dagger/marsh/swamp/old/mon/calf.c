#include <std.h>
inherit WEAPONLESS; 
#define SHDIR "/d/dagger/marsh/swamp/rooms/"+
int wander;
void create() {
    :: create();
    set_name("calf");
    set_id(({
        "calf","headless calf","cow"
    }));
    set_short("%^RESET%^%^RED%^Headless calf%^RESET%^");
    set_long(
	"The abomination before you is a sick sight! A small undead calf that was obviously "
        "beheaded in some gruesome freak manner. A viscous substance still leaks out of its "
        "severed neck and it's sickly skin is covered in matted dried blood and hair."
    );
    set_gender("male");
    set_level(15);
    set_hd(15,3);
    set_size(2);
    set_weight(70);
    set_attacks_num(3); 
    set_damage(1,6);
    set_base_damage_type("bludgeoning");
    add_limb("severed neck","torso",0,0,0);
    add_limb("right hoof","right foreleg",0,0,0);
    add_limb("left hoof","lef foreleg",0,0,0);
    set_attack_limbs(({"right hoof","left hoof","severed neck"})); 
    set_overall_ac(-4);
    set_body_type("mammal");
    set_race("undead");
    set_class("fighter");
    set_guild_level("fighter",13);
    set_stats("strength",18);
    set_stats("constitution",17);
    set_stats("dexterity",17);
    set_stats("wisdom",16);
    set_stats("intelligence",15);
    set_stats("charisma",-15);
    set_alignment(6);
    set("aggressive",random(6)+7);
    set_mob_magic_resistance("average");
    set_exp(7000);
    set_max_hp(200);
   set_max_level(33);
    set_hp(200);
    set_funcs(({"moo"}));
    set_func_chance(30);
    set_property("no death", 1);
}
void moo(object targ){
    int dam;
    if(!targ) return;
    tell_room(ETO,
	"%^BOLD%^%^CYAN%^"
	"The headless calf goes:%^RESET%^ MOO!!!\n%^RED%^"
	+targ->query_cap_name()+
	" screams in disgust and internal pain!%^RESET%^"
    ,targ);
    tell_object(targ,
	"%^BOLD%^%^CYAN%^"
	"The headless calf goes:%^RESET%^ MOO!!!\n%^RED%^Your internal organs feel "
	"as though they just exploded!%^RESET%^"
    );
    dam = (int)targ->query_level();
    dam = dam + random(dam) + random(20);
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death", -4))
      dam = dam/2;
    targ->do_damage(targ->return_target_limb(),dam);
    TO->add_hp(dam/2);
    return 1;
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat() {
    string *exits;
    string exitn;	
    int i,j;
    ::heart_beat();
// Thanks to Tristan for example for this.
    if(wander > 20 && query_attackers() == ({})){
        exits = environment(TO)->query_exits();
        i = sizeof(exits);
        j = random(i);
        exitn = (string)environment(TO)->query_exit(exits[j]);
        if(exitn != SHDIR "m44") {
            TO->force_me(exits[j]);
	    wander = 0;
	    return;
	} else {
	    return;
	}
    } else {
        wander = wander + 1;
	return;
    }
}
