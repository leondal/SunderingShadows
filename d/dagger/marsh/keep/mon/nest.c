#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
	set_name("A hornet from the nest");
	set_id( ({"hornet","hornets","hornets nest","nest"}) );
set_short("A hornets nest");
	set_long(
	"You stand before a huge hornets nest.  The air is filled"+
	" with workers as they go about there way.  You can't help "+
	"wonder what could be inside.");
	set_emotes(5, ({"Buzzing sounds are all around."}),0);
    set_hd(8,10);
    set_level(25);
	set_race("hornet");
    set_gender("male");
    set_size(3);
    set_overall_ac(15);
    set_class("fighter");
    set_guild_level("fighter",25);
	set_max_hp(700);
	set_hp(700);
	add_money("silver",random(5));
	add_money("gold",random(20));
    set_wielding_limbs(({"right hand","left hand"}));
	add_limb("stinger", "stinger",96,1,4);
	add_limb("stinger", "stinger",96,1,4);
	add_limb("stinger", "stinger",96,1,4);
	add_limb("stinger", "stinger",96,1,4);
    set_attacks_num(6);
	set_attack_limbs(({"stinger","stinger","stinger","stinger","stinger","stinger","stinger","stinger"}));
   set_base_damage_type("blunt");
    set_damage(1,8);
    set_body_type("human");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(15000);
    set_alignment(9);
}
