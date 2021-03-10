inherit "/std/monster";

create() {
    ::create();
   set_name("giantrat");
   set_id( ({ "giantrat","giant","rat","giant rat" }) );
   set_short("A giant rat");
   set_level(2);
   set("long", "A giant rat.\n");
   set_gender("male");
    set("race", "rat");
   set_body_type("quadruped");
   set_alignment(2);
   set_hd(2,0);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",1);
   set_stats("wisdom",4);
   set_stats("strength",12);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",17);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_mp(0);
   set_mp(query_max_mp());
   add_money("copper",random(5));

}

