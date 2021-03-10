#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void create() 
{
    ::create();
    set_name("Frost Giant Scout");
    set_id(({"giant","frost giant","scout","arcticmon"}));
    set_race("frost giant");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set_short("A frost giant");
    set_long("%^RESET%^%^BOLD%^This massive frost giant stands over "
        "twenty feet tall.  He has the pale blue skin and light blue "
        "eyes that are common to those of his race.  His body is "
        "muscular and proportioned much as a giant human.  The long "
        "white hair on his head flows down his back.  He holds a "
        "large sword in his hand and is wearing a suit of chain "
        "padded with furs.%^RESET%^");
    set_hd(28,1);
    set_level(28);
    set_class("fighter");
    set_mlevel("fighter", 28);
    add_search_path("/cmds/fighter");
    set_hp(500);
    set_exp(15000);
    set_property("swarm", 1);
    set_overall_ac(-6);
    set_stats("strength",19);
    set_stats("dexterity",15);
    set_stats("intelligence",13);
    set_stats("wisdom",14);
    set_stats("constitution",20);
    set_stats("charisma",11);
    set_property("full attacks", 1);
    set("aggressive", 20);
    new(CWEAP"two_hand_sword.c")->move(TO);
    force_me("wield sword");
    new(CARMOR"chain.c")->move(TO);
    force_me("wear chain");
    set_parrying(1);
    add_money("electrum",random(1000)+500);

}
