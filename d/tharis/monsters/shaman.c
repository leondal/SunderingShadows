//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"tlincalli","shaman","Shaman Tlincalli"}));
    set_name("Shaman Tlincalli");
    set_short("A Shaman Tlincalli");
    set_long(
	"This horror appears to be part human and part scorpion. It has a "+
	"dark skinned human torso. Bony plates cover its chest and stomach. "+
	"The torso is supported by a bony-plated insectoid body. This four "+
	"foot long body is supported by six legs. Bony plates completely "+
	"cover the legs making them appear skeletal. The protruding spine "+
	"continues along the abdomen and extends behind it to form a tail "+
	"ten feet long tipped in a nasty stinger."
    );
    set_body_type("human");
    set_race("tlincalli");
    set_gender("male");
    set_alignment(3);
    set_size(2);
    set_hd(36,33);
    set_hp(805);
    set_exp(7000);
    set_overall_ac(0);
    set("aggressive",21);
    set_property("swarm",1);
    set_mob_magic_resistance("average");
    set_class("cleric");
    set_guild_level("cleric",36);
    set_spells(({
	"cause critical wounds",
	"call lightning",
	"flame strike",
	"limb attack",
    }));
    set_spell_chance(80);
    remove_limb("right leg");
    remove_limb("left leg");
    remove_limb("right foot");
    remove_limb("left foot");
    add_limb("abdomen","torso", 0, 0, 0);
    add_limb("right foreleg","abdomen", 0, 0, 0);
    add_limb("left foreleg","abdomen", 0, 0, 0);
    add_limb("right middle leg","abdomen", 0, 0, 0);
    add_limb("left middle leg","abdomen", 0, 0, 0);
    add_limb("right rear leg","abdomen", 0, 0, 0);
    add_limb("left rear leg","abdomen", 0, 0, 0);
    add_limb("tail","abdomen", 0, 0, 0);
    add_limb("stinger","tail", 0, 0, 0);
    set_attack_limbs(({"right hand","left hand","stinger"}));
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_damage(2,4);
    set_attack_bonus(5);
    set_hit_funcs( (["stinger":(:TO,"poison":)]) );
}
void poison(object targ){
    if(!"/daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^RED%^The Tlincalli's poison burns in your veins like fire!");
	tell_room(ETO,"%^BOLD%^RED%^The Tlincalli's sting causes "+targ->query_cap_name()+" to scream out in pain!",targ);
	targ->do_damage("torso",roll_dice(10,5));
	return 1;
    }
    return 1;
}
void set_paralyzed(int time,string message){return 1;}
void init(){
	::init();
     new("/cmds/spells/a/_animate_object")->use_spell(TO,TP->query_name(),36,100,"cleric");
	if(wizardp(TP)) return;
	}
