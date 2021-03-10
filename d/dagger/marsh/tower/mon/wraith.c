//General difficulty increase Octothorpe 5/25/09
#include <std.h>
inherit WEAPONLESS;

void create() {
    :: create();
    set_name("wraith");
    set_id(({
        "shadow wraith","wraith"
    }));
    set_short("%^RESET%^%^BLUE%^Shadow wraith%^RESET%^");
    set_long(
        "A shadowy humanoid shape which floats above the floor. It's cold "
	"blue eyes gaze deep into your soul, as if searching for your inner "
	"being."
    );
    set_gender("male");
    set_level(27);
    set_hd(27,9);
    set_size(2);
    set_weight(50);
set_property("no bows",1);
    set("aggressive",50);
set_property("magic",1);
    set_attacks_num(2);
    set_damage(4,6);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"}));
    set_overall_ac(-10);
    set_body_type("humanoid");
    set_race("undead");
    set_property("undead",1);
    set_class("fighter");
    set_guild_level("fighter",27);
    set_stats("strength",25);
    set_stats("constitution",25);
    set_stats("dexterity",25);
    set_stats("wisdom",25);
    set_stats("intelligence",25);
    set_stats("charisma",15);
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_exp(30000);
    set_max_level(36);
    set_max_hp(330);
    set_hp(330);
    add_money("gold",random(5000));
    set_emotes(1,({
        "%^BLUE%^The wraith reaches out towards you.%^RESET%^",
	"%^RED%^The shadow wraith gazes deep into your soul.",
	"The shadow wraith floats towards you.",
        "%^MAGENTA%^Shadow Wraith says: %^RESET%^It is futile. He will imprison you as he did me.",
    }),0);
    set_funcs(({"absorb"}));
    set_func_chance(50);
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10);
}
void absorb(object targ){
    int dam;
    if(!targ) return;
    tell_room(ETO,
	"%^BOLD%^%^GREEN%^"
	"The shadow wraith's eyes blaze with a bright %^BLUE%^blue light%^GREEN%^ "
	"as he strikes "
	+targ->query_cap_name()+
	"!%^RESET%^"
    ,targ);
    tell_object(targ,
	"%^BOLD%^%^GREEN%^"
	"The shadow wraith's eyes blaze with a bright %^BLUE%^blue light%^GREEN%^ "
	"as he strikes you!\n%^RED%^An intense chill fills your soul as a portion "
	"of your life is drained away!%^RESET%^"
    );
    dam = (int)targ->query_hp()/2;
    targ->do_damage("torso",dam);
    TO->add_hp(dam/2);
}
void set_paralyzed(int time,string message){return 1;}
/*
void die(object ob) {
    message("environment",
	"%^BOLD%^%^BLUE%^The shadow wraith's form drifts away leaving the former trapped soul's "
	"body laying in final resting before you.%^RESET%^"
    ,environment(TO));
    :: die(ob);
}
*/
