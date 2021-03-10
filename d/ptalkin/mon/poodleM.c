// A fieldmouse that lives in the meadow
// Pator@ShadowGate
// Mar 8 1996

inherit "/std/monster";

create() {
    ::create();
   set_name("poodle");
   set_author("pator");
   set_id( ({ "poodle","dog" }) );
   set_short("A little poodle");
   set_level(4);
   set("long", "A little poodle. It looks not that old.\n");
   set_gender("male");
   set_class("mamal");
   set("race", "dog");
   set_body_type("quadruped");
   set_alignment(2);
   set_hd(2,0);
   set("aggressive",0);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",7);
   set_stats("strength",12);
   set_stats("charisma",4);
   set_stats("dexterity",11);
   set_stats("constitution",10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_mp(0);
   set_mp(query_max_mp());
   add_money("copper",random(5));

}

