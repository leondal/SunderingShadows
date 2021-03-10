//fixed various typos-Styx 7/16/01  lowered chance of spammy emotes-Styx 12/22
// Increasing exp Dinji 8-26-07

#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow soldier");
   set_id(({"drow","soldier","drow soldier","drowmon"}));
   set_short("%^BOLD%^%^BLUE%^Drow soldier%^RESET%^");
    set_long(
	"%^BOLD%^%^BLUE%^The Drow soldier is a menacing sight "
	"indeed. These highly trained soldiers are used by the Drow "
	"regime for war purposes and are known to be ruthless in "
	"combat. They follow their orders ruthlessly and to the death "
	"with no questions asked.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(10+random(4),6);
    set_size(2);
    set_overall_ac(2);
   set_max_hp(350);
   set_hp(350);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_alignment(9);
    set_mob_magic_resistance("average");
   //set_exp(2000);
   set_exp(5500);
    set_max_level(20);
    set_emotes(2,({
	"The drow soldier polishes his sword.",
	"The drow soldier examines you carefully.",
	"%^MAGENTA%^The drow soldier says: %^RESET%^Enter a battle to win or enter a "
	"battle to die, either way brings just rewards.",
	"The drow soldier looks at you in disgust."
    }),0);
    new("/d/dagger/drow/obj/marmor.c")->move(TO);
    command("wear armor");
    new("/d/dagger/drow/obj/blsword.c")->move(TO);
    command("wield sword in right hand");
    new("/d/dagger/drow/obj/blsword.c")->move(TO);
    command("wield sword in left hand");
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
