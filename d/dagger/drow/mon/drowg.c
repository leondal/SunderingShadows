#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow");
   set_id(({"drow","guard","drow guard","drowmon"}));
   set_short("%^BOLD%^%^BLUE%^Drow guard%^RESET%^");
    set("long",
	"%^BOLD%^%^BLUE%^This is one of the standard male guard types "
	"of the Drow Elves of Underdark. Its blazing "
	"%^RED%^red%^BLUE%^ eyes are filled with hatred.  Its jet "
	"coal skin glistens sickly, but your attention is mostly "
   "drawn to the evil grin on its lips.  Under its garments you "
   "can make out the taut muscles of the creature and its stance "
	"shows that he is ready and more than willing to die in "
	"battle.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(17+random(3),3);   // adding 5, *Styx*  11/16/03
    set_size(2);
    set_overall_ac(3);
    set_max_hp(145);  // added 50 *Styx*  11/16/03
    set_hp(145);
    set_property("swarm",1);
//    set_wielding_limbs(({"right hand","left hand"}));  don't need this
    set_body_type("human");
    set_property("swarm",1);
    set_stats("strength",18);
    set_stats("dexterity",17);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_property ("magic resistance",9);
   set_exp(3500);
    set_max_level(25);  // added 5 *Styx*
    set_alignment(9);
    set_emotes(1,({
	"The drow guard looks nervous.",
	"The drow guard paces around the room.",
	"The drow guard ponders over why you are here.",
	"The drow guard examines his weapons.",
	"The drow guard looks you over.",
    }),0);
    new("/d/dagger/drow/obj/marmor.c")->move(TO);
    command("wear armor");
    new("/d/dagger/drow/obj/blsword.c")->move(this_object());
    command("wield sword");
    new("/d/dagger/drow/obj/bldagger.c")->move(this_object());
    command("wield dagger");
// adding chance of black robe (made it +2 now too), moving from drow hunters that were above ground *Styx* 11/16/03, last change 2/13/03
    if(!random(8))
	new("/d/dagger/drow/obj/blcloak.c")->move(TO);
    command("wear robe");
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
	force_me("yell Help! Scum has entered our vicinity!");
    }
}
