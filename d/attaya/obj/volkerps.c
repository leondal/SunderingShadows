#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("volkerps");
    set_property("no bows",1);
    set_id(({"volkerps","warrior","skeleton"}));
    set_short("Volkerps the Destroyer");
    set_long(
      "Volkerps is a warrior of the Tyva Vvox clan.\n He casts a very ominous shadow over you.  His silvery eyes peer down upon you and you wish only to hide forever from their gaze."
    );
    set_gender("male");
    set_hd(35,6);
    set_size(2);
   set_overall_ac(-18);
    set_class("fighter");
    set_guild_level("fighter",30);
   set_max_hp(1550);
   set_hp(1550);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_race("undead");
    set_property("swarm",1);
   set_property("full attacks",1);
   set_property("no death",1);
   set_property("magic",1);
    set("aggressive", 23);
    set_property("no_bump",1);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set_stats("strength",22);
    set_mob_magic_resistance("average");
    set_alignment(2);
    set_exp(35000);
    set_emotes(5,({
	"%^BOLD%^%^CYAN%^Volkerps pierces your soul with that horrible stare!",
	"The wind around you seems to pick up!",
	"The ground beneath you begins to feel uneasy.",
	"A shiver runs the length of your spine"
      }),0);
    set_funcs(({"desoul", "axis", "allies"}));
    set_func_chance(40);
    new("/d/attaya/obj/azure.c")->move(TO);
    command("wear armor");
    new("/d/attaya/obj/dmace.c")->move(TO);
    command("wield mace in right hand");
    new("/d/attaya/obj/lgauntlets.c")->move(TO);
    new("/d/attaya/obj/kilt.c")->move(TO);
    command("wearall");
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^CYAN%^Volkerps whispers to you: %^RESET%^I am not amused."
      ,environment(TO));
    force_me("shout %^BOLD%^%^RED%^ARRRRRRRRGH!  ");
    :: die(ob);
}
void desoul(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
	dam="hurts";
    } else {
	dam="poisons";
    }
    tell_room(environment(targ),
      "%^MAGENTA%^Volkerps raises his hands to the sky and a vortex of light forms above "+targ->query_cap_name()+"."
      ,targ);
    tell_object(targ,
      "%^BOLD%^%^MAGENTA%^Suddenly, several phantasmic daggers drop from the vortex.  The mass of shadows congeals again inside your flesh and "+dam+
      " you!%^RESET%^"
    );
    tell_room(environment(targ),
      "%^MAGENTA%^several phantasmic daggers drop from the vortex and pierce "+targ->query_cap_name()+"!"
      ,targ);
    if(dam=="poisons") {
	targ->do_damage("torso",roll_dice(4,10));
	targ->add_poisoning(30);
	tell_object(targ,
	  "%^BOLD%^%^BLACK%^The living shadows wrap wround your internal organs and try to squeeze the life from them."
	);
	targ->set_paralyzed(random(30)+10,
	  "%^BOLD%^%^RED%^Your very spirit wages a battle inside your body!"
	);
    } else {
	targ->do_damage("torso",roll_dice(6,10));
    }
    return 1;
}
void axis(){
    force_me ("axis");
}
void allies(){
    force_me ("allies");
}
