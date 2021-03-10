// fixed various typos - Styx 7/16/01, lowered emote frequency - Styx 12/22/01

#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow captain");
   set_id(({"drow","captain","drow captain","drowmon"}));
   set_short("%^BOLD%^%^BLUE%^Drow captain%^RESET%^");
    set_long(
	"%^BOLD%^%^BLUE%^The Drow captain is a soldier who has "
	"proven to also be competent in battle as well as have "
	"leadership qualities.  The Drow captains are usually given a "
 	"small number of troops to be under their command and take "
	"orders only from the Elite Drow forces.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(12+random(5),6);
    set_size(2);
    set_overall_ac(3);
    set_max_hp(110);
    set_hp(110);
    set_max_level(20);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",18);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_property("swarm",1);
   set_exp(4500);
    set_alignment(9);
    set_emotes(1,({
	"The drow captain inspects his soldiers.",
	"The drow captain frowns in intense concentration.",
	"The drow captain barks some orders."
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
