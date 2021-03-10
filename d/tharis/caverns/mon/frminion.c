#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"fire minion","minion"}));
    set_name("Fire Minion");
    set_short("A Fire Minion");
    set_long(
	"This creatures body is made up of pure living fire. Its body flickers and swirls constantly. It appears as a humanoid shape."
    );
    set_body_type("human");
    set_race("fire minion");
    set_gender("male");
    set_size(2);
    set_hd(8,1);
    set_hp(70);
    set_overall_ac(3);
    set_stats("strength",19);
    set_stats("constitution",18);
    set_property("strength","fire");
    set("aggressive",18);
    set_exp(1100);
    add_money("gold",random(100)+250);
    add_money("copper",random(100)+50);
    set_class("mage");
    set_guild_level("mage",10);
    set_spells(({
	"fireball",
	"burning hands",
	"scorcher",
	"flaming sphere"
    }));
    set_spell_chance(45);
    set_funcs(({"inferno"}));
    set_func_chance(45);
}
void inferno(object targ){
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	dam="burns";
	} else {
	dam="incinerates";
    }
    tell_object(targ,"%^BOLD%^RED%^The Fire Minion extends its aura of flame and it "+dam+" you!");
    tell_room(environment(targ),"%^BOLD%^RED%^The Fire Minion extends its aura of flame and "+dam+" "+targ->query_cap_name()+"!",targ);
    if(dam =="incinerates"){
	targ->do_damage("torso",roll_dice(2,10));
	} else {
	targ->do_damage("torso",((roll_dice(2,10))/2));
    }
    return 1;
}
