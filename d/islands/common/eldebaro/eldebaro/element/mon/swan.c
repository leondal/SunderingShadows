#include <std.h>

inherit "/std/monster.c";


create() {
    ::create();
    set_name("swan");
    set_id( ({ "guard", "swan", "human" }) );
    set_race("human");
    set_gender("male");
    set("short", "A swan samurai");
   set("long", "An elite warrior assigned to protect "+
   "the construction crew of this place.  He is dressed in "+
   "light armor and wields a wicked looking katana.\n");
    set_level(14);
    set_hd(14,0);
    set_body_type("human");
    set_class("fighter");
    set("aggressive", 0);
    set_alignment(7);
    set_size(2);
    set_stats("intelligence",12);
-   set_stats("wisdom",12);
    set_stats("strength",18);
    set_stats("charisma",10);
    set_stats("dexterity",14);
    set_stats("constitution",16);
    set_hp(108);
    set_max_hp(query_hp());
    set_exp(1000);
    set_overall_ac(3);
    set_wielding_limbs( ({ "right hand", "left hand" }) );
    new("/d/avatars/myrkul/katana")->move(this_object());
    command("wield katana");
    add_money("electrum",random(10));
    add_money("silver",random(10));
    add_money("gold",random(5));
    add_money("copper",random(20));
}
