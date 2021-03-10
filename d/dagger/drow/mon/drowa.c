#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow");
   set_id(({"drow","archer","drow archer","drowmon"}));
   set_short("%^BLUE%^Drow archer%^RESET%^");
    set_long(
        "%^BOLD%^%^BLUE%^The Drow archer is highly "
        "reputed in their skill in archery. Armed with the famous bows of "
	"the Drow Regime, they also are known to carry venomous "
	"hand-throwing darts with them.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(9+random(4),6);
    set_size(2);
    set_overall_ac(3);
    set_max_hp(105);
    set_hp(105);
    set_max_level(20);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no_bump",1);
    set_stats("strength",18);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_property ("magic resistance",9);
    set_alignment(9);
    set_property("swarm",1);
    set_exp(3000);
    set_emotes(3,({
	"The drow archer examines his bow string.",
	"The drow archer peers out the arrow slit.",
	"The drow archer examines an arrow and grins.",
	"The drow archer discovers a broken arrow among his good ones "
	"and discards it to the floor.",
	"The drow archer fumbles with something hidden in his pocket."
    }),0);
    new("/d/dagger/drow/obj/marmor.c")->move(TO);
    command("wear armor");
    new("/d/dagger/drow/obj/blbow.c")->move(TO);
    command("wield bow in right hand");
//bow takes two hands, so wasn't wielding the sword - Styx 12/22/01
//    new("/d/dagger/drow/obj/blsword.c")->move(TO);
//    command("wield sword in left hand");
    set_funcs(({"dart"}));
    set_func_chance(20);
}
void aggfunc() {
    object shape;
    string mrace=TP->query_race();
    if(objectp(shape = TP->query_property("shapeshifted"))) mrace = (string)shape->query_shape_race();
    if(TP->query_invis()) return 1;
    if (mrace == "drow") {
	force_me ("bow");
	return 1;
    } else {
	TP->kill_ob(TO,0);
	force_me("say Kill all intruders!");
    }
}
void dart(object targ) {
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"poison")) {
	dam="hurts";
    } else {
	dam="poisons";
    }
    tell_object(targ,
	"%^GREEN%^The drow archer reaches into his pocket and suddenly "
	"hurls a small dart at you! The dart strikes and "+dam+
	" you!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^GREEN%^The drow archer reaches into his pocket and suddenly "
	"hurls a small dart at "+targ->query_cap_name()+"!%^RESET%^"
    ,targ);
    if(dam=="poisons") {
	targ->do_damage("torso",roll_dice(2,6));
	tell_object(targ,
	    "%^GREEN%^You feel the darts venom cause your muscles to "
	    "stiffen as hard as stone!%^RESET%^"
	);
	targ->set_paralyzed(random(30)+10,
	    "%^GREEN%^The venom still siezes your muscles!%^RESET%^"
	);
    } else {
	targ->do_damage("torso",roll_dice(1,6));
    }
    return 1;
}
