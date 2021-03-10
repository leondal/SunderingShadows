#include <std.h>
inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("knight");
    set_id(({"undead knight","knight","skeletal knight"}));
    set_short("%^RESET%^%^BLUE%^Skeletal Knight of the Kinnesaruda");
    set_long("Among the proudest of the undead legions are those branded knights by Intruder.  The knights have been granted the powers that they possess through the execution of others."
    );
    set_race("undead");
    set_gender("male");
    set_hd(21,6);
    set_size(2);
    set_overall_ac(-14);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_max_hp(500);
    set_hp(500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("human");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
    set_property ("full attacks",1);
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(24000);
    set_emotes(3,({
	"The knight paces from one side of the hallway to the other.",
	"The knight taps his mace against the wall.\n %^YELLOW%^Sparks fly everywhere!",
      }),0);
    new("/d/attaya/obj/uarmor.c")->move(TO);
    command("wear armour");
    new("/d/attaya/obj/dmace.c")->move(this_object());
    command("wield mace in right hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
    if(!random(20)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void die(object ob) {
    message("environment",
      "%^BOLD%^%^MAGENTA%^The brave soul of the knight vanishes into the orifice!"
      ,environment(TO));
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("say Greetings, kindred.");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("emote 's eyes glow with an unholy energy.");
    }
}
void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="smashes";
    } else {
	dam="destroys";
    }
    tell_object(targ, "%^BOLD%^%^MAGENTA%^ The ancient knight charges towards you and "+dam+ " you with his mace!" );
    tell_room(environment(targ),"%^MAGENTA%^The ancient knight charges with his mace and "
      "destroys "+targ->query_cap_name()+"!%^RESET%^",targ);
    if(dam=="destroys") {
	targ->do_damage("torso",roll_dice(8,6));
	tell_object(targ,
	  "%^RED%^You feel intense pain and your abillity to fight has been comprimised!\n"
	);
    } else {
	targ->do_damage("torso",roll_dice(4,6));
    }
    return 1;
}
