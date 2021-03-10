//Added feats - Octothorpe 6/22/10

#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
    object ob;
   ::create();
    set_name("knight of the order of ximes");
    set_id(({"knight","knight of the order"}));
    set_short("Knight of the Order of Ximes");
    set_long("This is a very old knight who looks as though he's seen many battles.  "
        "He wears the Seal of the Order of Ximes on his robes, but other then "
        "that he appears rather plain. In his right hand he carries a shield "
        "made of the finest crystal, and in his left hand he holds a magnificent "
        "broad sword.");
    set_race("human");
    set_gender("male");
    set_body_type("human");
    set_hd(20,5);
    set_overall_ac(-3);
    set_size(2);
    set_stats("strength",19);
    set_stats("intelligence",14);
    set_stats("dexterity",18);
    set_stats("charisma",10);
    set_stats("constitution",17);
    set_stats("wisdom",15);
    set_money("gold", 100 + random(100));
    set_class("fighter");
    set_class("thief");
    set_guild_level("fighter",20);
    set_guild_level("thief",17);
    set_mlevel("fighter",20);
    add_search_path("cmds/fighter");
    set_max_hp(500+random(40));
    set_hp(query_max_hp());
    set_exp(40000);
    set_new_exp(25,"boss");
    set_property("full attacks",1);
    set("aggressive",0);
    set_alignment(3);
    set_mob_magic_resistance("average");
    set_funcs( ({"attack"}) );
    set_func_chance(100);
	set_monster_feats(({
        "shieldbash",
		"shieldwall",
		"deflection",
		"counter",
		"reflection",
		"powerattack",
		"shatter",
		"sunder",
		"rush"
    }));
    new(OBJS+"crystal_shield.c")->move(TO);
    ob = new(CWEAP"bastard.c");
    ob->set_property("enchantment",roll_dice(1,4));
    ob->move(TO);
    ob=new(OBJS"death_plate.c");
    ob->move(TO);
    command("wear plate");
    command("wield sword");
    command("wear shield");
    add_money("gold",random(12000)+550);
    add_money("platinum",random(1100)+30);
}

void attack()
{

    object *live;
    object targ;
    int i;

    live = all_living(ETO);
    live = filter_array(live, "is_non_immortal", FILTERS_D);

    for(i=0;i<sizeof(live);i++)
    {
        targ = live[i];
        if(!objectp(targ)) continue;
   
        TO->force_me("rush "+targ->query_name());
    }
    TO->set_func_chance(0);
    TO->force_me("parry");
    return;
}
