//cleaned up a few typos and lowered chance of spammy emotes - Styx 12/22/01
   //set_exp(2000);

#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow warrior");
   set_id(({"drow","warrior","drow warrior","drowmon"}));
   set_short("%^BOLD%^%^BLUE%^Drow warrior%^RESET%^");
    set_long(
	"%^BOLD%^%^BLUE%^The Drow warrior stands before you glaring "
	"menacingly. The Drow warriors are generally of a tougher "
	"breed than the average Drow fighter and are therefore put "
	"in positions of leadership over small groups of fighters "
   "and guards. It is absolutely fearless in its stance.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(12+random(3),4);
    set_size(2);
    set_overall_ac(2);
   set_max_hp(350);
   set_hp(350);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",19);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
   set_exp(5500);
    set_max_level(20);
    set_alignment(9);
    set_emotes(2,({
	"The drow warrior says: Be on your guard!",
	"The drow warrior says: Do not concern yourself about our guest.",
	"The drow warrior chuckles politely.",
	"The drow fighter glances east and shudders.",
	"The drow warrior looks you over.",
	"The drow warrior says: Do not speak of the sun!",
    }),0);
    new("/d/dagger/drow/obj/marmor.c")->move(TO);
    command("wear armor");
    new("/d/dagger/drow/obj/blsword.c")->move(TO);
    command("wield sword");
    new("/d/dagger/drow/obj/blsword.c")->move(TO);
    command("wield sword");
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
