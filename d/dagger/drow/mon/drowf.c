// fixed various typos - Styx 7/16/01, lowered emote frequency - Styx 12/22/01

#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("drow");
   set_id(({"drow","fighter","drow fighter","drowmon"}));
   set_short("%^BOLD%^%^BLUE%^Drow fighter%^RESET%^");
    set("long",
	"%^BOLD%^%^BLUE%^This is one of the standard male fighter "
	"types of the Drow Elves of Underdark.  Its blazing "
	"%^RED%^red%^BLUE%^ eyes are filled with hatred.  Its jet "
	"coal skin glistens sickly, but your attention is mostly "
	"drawn to the evil grin on its lips.  Under its garments "
	"you can make out the taut muscles of the creature and its "
	"stance shows that he is ready and more than willing to die in "
	"battle.%^RESET%^"
    );
    set_race("drow");
    set_gender("male");
    set_hd(9+random(4),3);
    set_size(2);
    set_overall_ac(6);
    set_max_hp(70);
    set_hp(70);
   set_exp(2000);
    set_max_level(20);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_property("magic resistance",7);
    set_alignment(9);
    set_emotes(3,({
	"The drow fighter says: I do not trust this foul creature.",
	"The drow fighter says: He can mold our minds...it will be good to "
	"be rid of him.",
	"The drow fighter peers east.",
	"The drow fighter glances east and shudders.",
    }),0);
    new("/d/dagger/drow/obj/marmor.c")->move(TO);
    command("wear armor");
    new("/d/dagger/drow/obj/blsword.c")->move(this_object());
    command("wield sword in right hand");
    new("/d/dagger/drow/obj/bldagger.c")->move(this_object());
    command("wield dagger in left hand");
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
	force_me("say You shall die quickly scum!");
    }
}
