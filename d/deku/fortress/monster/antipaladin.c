//Coded by Bane//
//Okay, I'm gonna start trying to document changes - I removed the set_hd() and set the stats
//that weren't already set.  set_mlevel() so it's actually an 14th level paladin, got rid 
//of the body_type and wielding limbs, added slightly more hps and changed the way the exp 
//it gives works - should give around 1800-2100 now, before it was simply 1700 - Saide
#include <std.h>
inherit MONSTER;
object ob;
void create(){
    ::create();
    set_id(({"antipaladin","human","anti"}));
    set_name("antipaladin");
    set_short("A tall human decked with black plate");
    set_long("%^RESET%^This man is tall and his body is completely "+
    "decked with a suit of darkened fullplate armor.  His eyes, "+
    "visible only because the visor of the helm is raised, are a "+
    "dark and very cold blue.  The visible parts of his flesh "+
    "are a slightly tanned brown, suggesting that he has saw at "+
    "least some sunlight recently.  He carries a massive two "+
    "handed sword, that is always kept clean, at his side.%^RESET%^");
    set_race("human");
    set_gender("male");
    set_alignment(3);
    set_stats("strength",18);
    set_stats("dexterity",17);
    set_stats("constitution",15);
    set_stats("charisma",17);
    set_stats("wisdom",16);
    set_stats("intelligence",15);
    set("aggressive",1);
    set_class("antipaladin");
    set_guild_level("antipaladin",14 + random(5));
    set_mlevel("antipaladin",14 + random(5));
    set_hp(150 + random(51));
    set_exp(query_max_hp() * 150);
    set_property("swarm",1);
    add_search_path("/cmds/antipaladin");
    add_money("gold",random(200)+250);
    new("/d/common/obj/weapon/two_hand_sword")->move(TO);
    command("wield sword");
    ob = new("/d/shadow/room/city/cguild/antipaladin/antiplate");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    command("wear plate");
    set_property("full attacks",1);
}
