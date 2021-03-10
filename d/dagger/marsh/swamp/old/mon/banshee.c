#include <std.h>
inherit WEAPONLESS; 
#define SHDIR "/d/dagger/marsh/swamp/rooms/"+
int wander;
void create() {
    :: create();
    set_name("banshee");
    set_id(({
        "banshee","wailing banshee"
    }));
    set_short("%^RESET%^%^BLUE%^Wailing banshee%^RESET%^");
    set_long(
        "A shadowy ghost-like shape which floats above the marsh. It's hollow "
	"black eyes gaze upon you as it's mouth is open letting forth an eerie wail. "
	"It's arms and legs are adorned with chains which clank and sway with it's "
	"every move."
    );
    set_gender("male");
    set_level(26);
set_property("magic",1);
    set_hd(26,1);
    set_size(2);
   set_max_level(33);
    set_weight(50);
    set_attacks_num(4); 
    set_damage(1,8);
    set_base_damage_type("bludgeoning");
    add_limb("right chain","torso",0,0,0);
    add_limb("left chain","torso",0,0,0);
    set_attack_limbs(({"right hand","left hand","right chain","left chain"})); 
    set_overall_ac(-4);
    set_body_type("humanoid");
    set_race("undead");
    set_class("fighter");
    set_guild_level("fighter",15);
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",18);
    set_stats("wisdom",20);
    set_stats("intelligence",20);
    set_stats("charisma",15);
    set_alignment(6);
    set("aggressive",random(8)+7);
    set_mob_magic_resistance("average");
    set_exp(12500);
    set_max_hp(220);
    set_hp(220);
    add_money("gold",random(500)+200);
    set_emotes(1,({
        "%^BLUE%^The banshee wails in despair!%^RESET%^",
	"%^GREEN%^The banshee sings a song of darkness!",
	"The banshee screams out!",
        "%^MAGENTA%^Wailing banshee wails: %^RESET%^It lives not but lives! Demongate tower is our shroud of doom!",
    }),1);	
    set_funcs(({"absorb"}));
    set_func_chance(30);
    set_property("no death", 1);
}
void absorb(object targ){
    int dam;
    if(!targ) return;
    tell_room(ETO,
	"%^BOLD%^%^BLUE%^"
	"The banshee wails in an eerie tone towards "
	+targ->query_cap_name()+
	"!%^RESET%^"
    ,targ);
    tell_object(targ,
	"%^BOLD%^%^BLUE%^"
	"Your arms feel like lead and your legs like jelly as the banshee looks "
	"at you and wails in despair!%^RESET%^"
    );
    dam = (int)targ->query_level();
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death", -4))
      dam = dam/2;
    targ->set_paralyzed(dam,"You cannot move! The despair in you is too great!");
    TO->add_hp(dam);
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat() {
    string *exits;
    string exitn;	
    int i,j;
    ::heart_beat();
// Thanks to Tristan for example for this.
    if(wander > 20 && query_attackers() == ({})){
        if (!objectp(environment(TO))) return;
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
