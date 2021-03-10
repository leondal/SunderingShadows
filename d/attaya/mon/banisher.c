#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("banisher");
    set_id(({"banisher","knight","undead"}));
    set_short("Banisher");
    set_long(
      "The Banisher is a tough warrior with potent abillities.  It has limited magical abilities and well honed combat skills.The actual warrior hides beneath a complete body armor."
    );
    set_race("undead");
    set_gender("male");
    set_hd(30,6);
    set_size(2);
    set_overall_ac(-15);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_max_hp(query_hp());
    set_hp(600+random(130));
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",22);
    set_stats("dexterity",22);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(30000);
    set_emotes(5,({
	"The Banisher paces from one side of the hallway to the other.",
	"The Banisher sharpens his falchion against the wall.\n %^YELLOW%^Sparks fly everywhere!",
      }),0);
    new("/d/attaya/obj/uarmor.c")->move(TO);
    command("wear armour");
    new("/d/attaya/obj/boots.c")->move(TO);
    command("wear boots");
    new("/d/attaya/obj/shelm.c")->move(TO);
    command("wear helmet");
    new("/d/attaya/obj/gauntlets.c")->move(TO);
    command("wear gauntlets");
    new("/d/attaya/obj/falchion.c")->move(this_object());
    command("wield sword in right hand");
    new("/d/attaya/obj/falchion.c")->move(this_object());
    command("wield sword in left hand");
    set_funcs(({"fire"}));
    set_func_chance(20);
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^MAGENTA%^The Banisher shrieks horribly and grasps at your eyes before falling to his knees and finally flat on his stomach!"
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
	force_me("cackle");
	force_me("say %^BOLD%^%^RED%^I shall tear you apart!");
    }
}
void fire(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"petrification_polymorph")) {
	dam="hurts";
    } else {
	dam="blasts";
    }
    tell_object(targ,
      "%^BOLD%^%^BLUE%^ A sphere of blue flame appears around Banisher for a moment before he gathers the energies into his hands and "+dam+ " you!"
    );
    tell_room(environment(targ),
      "%^BOLD%^%^BLUE%^A sphere of blue flame appears around Banisher for a moment before he gathers the energies into his hands and "
      "blasts them at "+targ->query_cap_name()+"!%^RESET%^"
      ,targ);
    set_property("magic",1);
    if(dam=="blasts") {
	targ->do_damage("torso",roll_dice(4,20));
	remove_property("magic");
	tell_object(targ,
	  "%^RED%^A bone-shattering wave of energy tears through you!\n"
	);
    } else {
	targ->do_damage("torso",roll_dice(4,16));
    }
    return 1;
}
