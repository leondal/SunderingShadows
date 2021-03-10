//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"runner","elf","dune runner","elven dune runner"}));
    set_name("elven dune runner");
    set_short("An Elven Dune Runner");
    set_long(
	"Before you stands a young elf. He is wearing a lightweight "+
	"armor that doesnt hinder running. This elf is one of many "+
	"runners that are sent across the desert with messages for "+
	"cities. He is quick and agile and looks like a tough opponent."
    );
    set_body_type("human");
    set_race("elf");
    set_gender("male");
    set_size(2);
    set_hd(10,5);
    set_max_level(18);
    set_hp(85);
    set_alignment(7);
    set_exp(1700);
    set_overall_ac(4);
    set_stats("strength",19);
    set_stats("dexterity",19);
    set("aggressive",1);
    set_class("ranger");
    set_guild_level("ranger",11);
    add_money("gold",random(200)+250);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield sword in right hand");
    new("/d/common/obj/weapon/longsword")->move(TO);
    command("wield sword in left hand");
    new("/d/common/obj/armour/chain")->move(TO);
    command("wear chain mail");
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
