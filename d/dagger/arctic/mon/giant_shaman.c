#include <std.h>
#include "../arctic.h"
inherit CREATURE;

void create() 
{
    object obj,obj1;
    
    ::create();
    set_name("Frost Giant Shaman");
    set_id(({"giant", "frost giant", "old giant", "old frost giant", "shaman","giant shaman","arcticmon"}));
    set_race("frost giant");
    set_body_type("human");
    set_gender("female");
    set_size(3);
    set_short("An old frost giant");
    set_long("%^RESET%^%^BOLD%^This hunched frost giant appears ancient.  "
        "Her pale skin is no longer blue, but a creamy white color.  Both "
        "of her eyes are completely white, but she surveys her surroundings "
        "with keen awareness.  The thin, brittle white hair that runs down her "
        "back looks as ancient as her wrinkled face.  She is wearing a mantle "
        "made from the hide of a beautiful winter wolf.%^RESET%^");
    set_hd(35,1);
    set_class("mage");
    set_mlevel("mage", 35);
    set_guild_level("mage", 35);
    add_search_path("/cmds/wizard");
    set_hp(500);
    set_exp(30000);
    set_property("swarm", 1);
    set_overall_ac(-5);
    set_stats("strength",15);
    set_stats("dexterity",16);
    set_stats("intelligence",19);
    set_stats("wisdom",17);
    set_stats("constitution",16);
    set_stats("charisma",9);
    set("aggressive", 20);
    new(OBJ"wolf_mantle")->move(TO);
    obj = new(OBJ"scroll_case");
    if(!random(2))
    {
        obj1 = new("/d/magic/scroll");
        obj1->set_spell(random(6)+3);
        obj1->move(obj);
    }    
    obj->move(TO);
    force_me("wear mantle");
    add_money("gold",random(1000));
    add_money("silver",random(5000));
    add_money("electrum",random(500));
    add_money("platinum",random(100));
    set_spells(({"chill touch",
                 "cone of cold", 
                 "lightning bolt",
                 "powerword stun"}));
    set_spell_chance(100);

}
