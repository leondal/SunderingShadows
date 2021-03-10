#include <std.h>
#include "../../defs.h"
inherit WEAPONLESS;

void create() {
    object ob;
    ::create();
    set_id(({"grell","philosopher grell","grell philosopher"}));
    set_name("grell");
    set_short("%^RESET%^%^ORANGE%^A large, %^RED%^dark-skinned %^ORANGE%^grell%^RESET%^");
    set_long("%^RESET%^The creature before you looks remarkably like a giant floating brain. A solid crest of "
"several %^RED%^dark bony protrusions %^RESET%^marks a line down the centre of its head. It has a %^YELLOW%^"
"vicious beak %^RESET%^protruding from one end, presumably the front, though there seem to be no eyes or "
"sensory organs, leaving you wonder how it manages to direct itself. It seems to have no problems with this "
"though, floating about in the air by some form of levitation, with about %^ORANGE%^ten tentacles %^RESET%^"
"curling and writhing along beneath it. This one seems much larger, and %^RED%^darker %^RESET%^of color, than "
"its companions, and wears a glowing ring on one long tentacle.");
    set_race("grell");
    set_race("human");
    set_gender("male");
    set_alignment(6);
    remove_limb("neck");
    remove_limb("right foot");
    remove_limb("left foot");
    remove_limb("right hand");
    remove_limb("left hand");
    remove_limb("left leg");
    remove_limb("right leg");
    remove_limb("left arm");
    remove_limb("right arm");
    remove_limb("waist");
    remove_limb("head");
    add_limb("first tentacle","torso", 0, 0, 0);
    add_limb("second tentacle","torso", 0, 0, 0);
    add_limb("third tentacle","torso", 0, 0, 0);
    add_limb("fourth tentacle","torso", 0, 0, 0);
    add_limb("fifth tentacle","torso", 0, 0, 0);
    add_limb("sixth tentacle","torso", 0, 0, 0);
    add_limb("seventh tentacle","torso", 0, 0, 0);
    add_limb("eighth tentacle","torso", 0, 0, 0);
    add_limb("ninth tentacle","torso", 0, 0, 0);
    add_limb("tenth tentacle","torso", 0, 0, 0);
    set_class("fighter");
    set_hd(28,12);
    set_guild_level("fighter",28);
    set_mlevel("fighter",28);
    set_nogo(({MID+"tunnel09","/d/dagger/kinaro/mines/lower2q"}));
    set_speed(70);
    set_moving(1);
    set_max_hp(300);
    set_hp(300);
    set_property("swarm",1);
    set_stats("strength",17);
    set_exp(3000);
    set_overall_ac(-16);
    set("aggressive",25);
    set_attack_limbs(({"first tentacle","second tentacle","third tentacle","fourth tentacle","fifth tentacle","sixth tentacle","seventh tentacle","eighth tentacle","ninth tentacle","tenth tentacle"}));
    ob = new("/d/deku/armours/ring_p.c");
    if(ob->query_property("enchantment")) ob->remove_property("enchantment");
    if(random(4)) ob->set_property("enchantment",3);
    else ob->set_property("enchantment",4);
    ob->move(TO);
    set_attacks_num(4);
    set_base_damage_type("bludgeoning");
    set_damage(2,4);
    set_property("no steal",1);
    set_property("strength","electrcity");
}