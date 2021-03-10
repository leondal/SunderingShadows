#include <std.h>
inherit WEAPONLESS; 
#define SHDIR "/d/dagger/marsh/swamp/rooms/"+
int wander;
void create() {
    :: create();
    set_name("wraith");
    set_id(({ "bog wraith","wraith"  }));
    set_short("%^RESET%^%^GREEN%^Bog wraith%^RESET%^");
    set_long(
        "A shadowy humanoid shape which floats above the marsh. Its cold "
	"green eyes gaze deep into your soul, as if searching for your inner "
	"being."
    );
    set_gender("male");
    set_property("magic",1);
    set_level(24);
    set_hd(24,3);
    set_size(2);
    set_weight(50);
    set_attacks_num(2); 
    set_damage(2,6);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"})); 
    set_overall_ac(-5);
    set_body_type("humanoid");
    set_race("undead");
    set_class("fighter");
    set_guild_level("fighter",17);
    set_stats("strength",20);
    set_stats("constitution",20);
    set_stats("dexterity",20);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",15);
    set_alignment(6);
    set("aggressive",random(10)+7);
    set_mob_magic_resistance("average");
    set_exp(13000);
    set_max_hp(250);
    set_hp(250);
    add_money("gold",random(1000));
    set_emotes(1,({
        "%^BLUE%^The wraith reaches out towards you.%^RESET%^",
	"%^GREEN%^The bog wraith gazes deep into your soul.",
	"The bog wraith floats towards you.",
        "%^MAGENTA%^Bog Wraith says: %^RESET%^Search not for Demongate Tower, lest you wish to join me in my eternal plight!",
    }),0);	
    set_funcs(({"absorb"}));
    set_func_chance(40);
}
void absorb(object targ){
    int dam;
    if(!targ) return;
    tell_room(ETO,	"%^BOLD%^%^GREEN%^"
	"The bog wraith's eyes blaze with a bright %^RED%^red light%^GREEN%^ "
	"as he strikes "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    tell_object(targ,	"%^BOLD%^%^GREEN%^"
	"The shadow wraith's eyes blaze with a bright %^RED%^red light%^GREEN%^ "
	"as he strikes you!\n%^RED%^An intense chill fills your soul as a portion "
	"of your life is drained away!%^RESET%^"
    );
    dam = (int)targ->query_hp()/3;
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death", -4))
      dam = dam/2;
    targ->do_damage("torso",dam);
    TO->add_hp(dam/3);
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
