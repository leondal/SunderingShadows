//fixed the weapons and armor to come from /d/common and removed swarm
//so they don't jump into a fight against the orcs and ogres.  *Styx* 2/22/02

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create()
{
    ::create();
    set_name("voadkyn");
    set_id(({ "voadkyn", "voadkyn scout", "scout", "mnster" }));
    set_short("A voadkyn scout");
    set_long("Otherwise known as wood giants, voadkyns " +
             "are thin, light giants.  They have no hair on their " +
             "bodies, including their large heads.  His calves are " +
             "wrapped tight in dark green leather straps, with " +
             "his forearms wrapped in a similar fashion.  A short " +
             "leather kilt is the only other clothing the " +
             "giant is wearing.");
    set_race("voadkyn");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set("aggressive", 0);
    set_class("ranger");
    set_mlevel("ranger", 10);
    set_hd(10, 2);
    set_level(12);
//  set_property("swarm",1);
    set_exp(1800);
    set_overall_ac(3);
    set_alignment(7);
    set_stats("strength", 18);
    new("/d/common/obj/weapon/two_hand_sword")->move(TO);
    command("wield sword");
    new("/d/common/obj/weapon/two_hand_sword")->move(TO);
    command("wield sword");
    new(OBJ + "lstudded")->move(TO);
    command("wear armor");
    set_emotes(2, ({
        "The voadkyn says:  %^CYAN%^Beware traveling off the " +
        "path, there have been many orcs around lately.%^RESET%^",
        "The voadkyn asks:  %^CYAN%^Do you have any poison " +
        "antidote with you?  Those ettercaps have a nasty " +
        "bite...%^RESET%^",
        "The voadkyn says:  %^CYAN%^We spotted an ogre northwest " +
        "of where the path splits.  It would be best if you stay " +
        "clear of there.%^RESET%^"
    }), 0);
    add_money("gold", random(20));
}
