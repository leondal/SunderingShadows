#include <std.h>
inherit MONSTER;
create() {
        ::create();
        set_name("haw");
        set_id( ({ "haw" }) );
        set("race", "haw");
        set_gender("male");
        set("short", "A huge Haw");
        set("long","This Haw looks like he is having a bad day.  He looks very mean.");
        set_level(7);
set_body_type("human");
        set("aggressive",5);
        set_size(2);
        set_hd(4,1);
        set_stats("intelligence",12);
        set_stats("wisdom",8);
        set_stats("strength",20);
        set_stats("charisma",8);
        set_stats("dexterity",12);
        set_stats("constitution",13);
        set_max_mp(0);
        set_mp(query_max_mp());
        set_max_hp(query_hp());
        set_max_sp(query_hp());
        set_sp(query_max_sp());
new("/d/shadow/room/maze/weapon/icepick.c")->move(this_object());
         command("wield pick in right hand");
         add_money("gold",random(200));
        set_money("silver",random(100));
new("/d/shadow/room/maze/weapon/axe.c")->move(this_object());
command("wield axe");
}
