#include <std.h>
inherit "/std/monster";

create()
{
    ::create();
    set_name("dwarf");
    set_id(({ "dwarf", "worker", "dwarven miner" }));
    set_race("dwarf");
    set_gender("male");
    set_short("Dwarven worker");
    set_long("This dwarven miner wears simple leather pants and a " +
             "cotton tunic over his black leather boots.  His brown hair is " +
             "worn in a thick braid that falls well past his shoulders, and " +
             "his long beard is brushed and tucked into his belt.  His green " +
             "eyes are sharp from many years spent examining gems in the mines, " +
             "and he seems quite adept at using the pick in his hands.");
    set_level(6);
    set_body_type("human");
    remove_property("swarm");
    set_alignment(1);
    set_size(1);
    set_hd(6, 1);
    set_stats("intelligence", 6);
    set_stats("wisdom", 4);
    set_stats("strength", 17);
    set_stats("charisma", 3);
    set_stats("dexterity", 15);
    //set_exp(150);
    set_exp(700);
    set_hp(60);
    set_stats("constitution", 17);
    set_max_mp(0);
    set_mp(query_max_mp());
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_wielding_limbs(({ "right hand", "left hand" }));
    new("/d/shadow/room/mountain/obj/mining_pick")->move(TO);
    command("wield pick");
    add_money("silver", random(10));
    add_money("gold", random(20));
    set_moving(1);
    set_speed(120);
    set_nogo(({ "/d/shadow/room/mountain/road6" }));
    command("speak wizish");
    if (!random(3)) { //these guys are too easy a target for vampdrain and have started taking countermeasures - Odin 6/19/2020
        set_property("garlic_scent", 1);
    }
}
void init()
{
    ::init();
    if (TP->query_property("is_mining")) {
        force_me("say Sneakin' around mining our gems, are ye?");
    }
    ::init();
}
