#include "/d/shadow/mon/melnmarn.h"
#include <std.h>
inherit MONSTER;

create() {
    ::create();
    set_name("archer");
    set_id( ({ "an archer", "archer" }) );
set("race", "elf");
    set_gender("male");
    set("short", "An archer");
set("long", "This is an elven archer assigned to guard Elvanta");
set_level(25);
set_hd(25,0);
set_hp(100);
    set_body_type("human");
    set_class("fighter");
    set("aggressive", 0);
    set_alignment(7);
    set_size(2);
set_stats("intelligence", 18);
set_stats("wisdom", 16);
set_stats("strength", 18);
set_stats("charisma", 16);
set_stats("dexterity", 20);
set_stats("constitution", 20);
set_property("swarm", 1);
    set_max_mp(0);
    set_mp(query_max_mp());
set_hp(130);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());	
set_exp(1500);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
new(WEAPONDIR+"two_hand_sword")->move(this_object());
    command("wield sword in right hand and left hand");
new("/d/dagger/Elvanta/forest/items/armor/mithril")->move(this_object());
    command("wear armor");
    add_money("electrum",random(10));
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));


}
