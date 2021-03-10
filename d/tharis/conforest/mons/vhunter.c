//fixed the weapons and armor to come from /d/common and removed swarm
//so they don't jump into a fight against the orcs and ogres.  *Styx* 2/22/02

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("voadkyn");
    set_id(({ "voadkyn", "voadkyn hunter", "hunter", "monster" }));
    set_short("A voadkyn hunter");
    set_long("Otherwise known as wood giants, voadkyns " +
             "are thin, light giants.  They have no hair on their " +
             "bodies, including their large heads.  His calves are " +
             "wrapped tight in dark green leather straps, with " +
             "his forearms wrapped in a similar fashion.  He wears " +
             "a dark green tunic and baggy brown trousers.  A " +
             "large longbow is strapped over his shoulder, and two " +
             "huge swords dangle from his waist.");
    set_race("voadkyn");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set("aggressive", 0);
    set_class("ranger");
    set_mlevel("ranger", 10);
    set_hd(10, 2);
    set_level(12);
    set_property("full attacks", 1);
    set_exp(1500);
    set_overall_ac(3);
    set_alignment(7);
    set_stats("strength", 18);
    new(OBJ + "two_battle_axe")->move(TO);
    command("wield axe");
    new(OBJ + "lleather")->move(TO);
    command("wear armor");
    new("/d/common/obj/lrweapon/longbow")->move(TO);
    set_emotes(2, ({
        "The voadkyn says:  %^CYAN%^For some reason, the wildlife " +
        "in this forest is quite aggressive.%^RESET%^",
        "The voadkyn asks:  %^CYAN%^Do you have any poison " +
        "antidote with you?  Those ettercaps have a nasty " +
        "bite...%^RESET%^",
        "The voadkyn says:  %^CYAN%^Our scouts have been fighting " +
        "a large number of orcs lately in the forest, but the " +
        "paths seem to be a bit safer.%^RESET%^"
    }), 0);
    add_money("gold", random(20));
}
