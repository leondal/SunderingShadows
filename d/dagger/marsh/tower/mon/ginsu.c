#include <std.h>
inherit WEAPONLESS; 
int FLAG;
object vic;
void create() {
    :: create();
    set_name("ginsu");
    set_id(({
        "ginsu","ginsu_beast","beast","ginsu beast"
    }));
    set_short("%^RESET%^%^RED%^Ginsu beast%^RESET%^");
    set_long(
        "This mammal like creature is nothing more than a numerous amount of blades, knives, sharp "
	"pointy objects, broken glass and other metal instruments all protruding, whirling, writhing, "
	"slicing, dicing, cutting, shreding and pureeing everything in it's path!"
    );
    set_level(11);
    set_hd(11,1);
    set_weight(100);
    set_attacks_num(4); 
    set_damage(1,6);
    set_base_damage_type("slashing");
    set_attack_limbs(({"blades","knives","dicers","slicers"})); 
    set_overall_ac(4);
    set_body_type("mammal");
    set_race("beast");
    add_limb("blades","head",0,0,0);
    add_limb("knives","head",0,0,0);
    add_limb("dicers","head",0,0,0);
    add_limb("slicers","head",0,0,0);
    set_class("fighter");
    set_guild_level("fighter",11);
    set_stats("strength",16);
    set_stats("constitution",10);
    set_stats("dexterity",10);
    set_stats("wisdom",1);
    set_stats("intelligence",1);
    set_stats("charisma",1);
    set_exp(0);
    set_max_hp(50);
    set_hp(50);
    set_emotes(15,({
        "The Ginsu beast slices!",
	"The Ginsu Beast dices!",
	"The Ginsu Beast chops!",
        "The Ginsu beast tenderizes!",
	"The Ginsu Beast grinds!",
	"The Ginsu Beast whirls!",
	"The Ginsu Beast twirls!",
        "The Ginsu beast slices!",
	"The Ginsu Beast dices!",
	"The Ginsu Beast chops!",
        "The Ginsu beast tenderizes!",
	"The Ginsu Beast grinds!",
	"The Ginsu Beast can be yours for only five gold!",
    }),1);	
}
void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(FLAG == 0 && TO->query_current_attacker()) {
	FLAG = 1;
	return;
    }
    if(FLAG == 1 && !(TO->query_current_attacker())) {
	tell_room(ETO,
	    "%^ORANGE%^The %^BLUE%^Ginsu Beast%^ORANGE%^ whirls around, "
	    "grinds to a halt and vanishes!%^RESET%^"
	);
        TO->remove();
        return;
    } else {
	return;
    }
}
