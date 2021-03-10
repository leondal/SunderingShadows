#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("warrior");
    set_id(({"Altherian warrior","warrior","altherian warrior"}));
    set_short("Altherian Warrior");
    set_long("
    This is one of the few surviving warriors of the Altherian Elite Infantry that was all but destroyed by the Kinnesaruda in their rise to power.
    This warrior shows his age but is still quite potent and stands at ready for attack.
");
    set_race("human");
    set_gender("male");
    set_hd(30,6);
    set_size(2);
    set_overall_ac(-14);
    set_class("fighter");
    set_property("full attacks",1);
    set_guild_level("fighter",30);
    set_max_hp(500);
    set_hp(500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",22);
     set("aggressive", 0);
    set_mob_magic_resistance("average");
    set_alignment(1);
    set_exp(35000);
    new("/d/attaya/seneca/obj/bronzemesh.c")->move(TO);
    command("wear armour");
    new("/d/attaya/seneca/obj/claymore.c")->move(TO);
    command("wield sword in right hand and left hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
}
void die(object ob) {
    message("environment",
    "%^RED%^The Altherian warrior coughs up blood and drops to his knees."
    ,environment(TO));
    :: die(TO);
}
void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"impale")) {
	dam="hurts";
    } else {
	dam="impales";
    }
    tell_object(targ,
       "%^BOLD%^%^MAGENTA%^ The Altherian warrior charges towards you and "+dam+ " you with his claymore!"
    );
    tell_room(environment(targ),
        "%^MAGENTA%^The Altherian warrior charges with his claymore and "
	"impales "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    if(dam=="impales") {
	targ->do_damage("torso",roll_dice(6,6));
	tell_object(targ,
     "%^RED%^You feel intense pain and your abillity to fight has been comprimised!\n"
	);
    } else {
	targ->do_damage("torso",roll_dice(4,6));
    }
    return 1;
}
