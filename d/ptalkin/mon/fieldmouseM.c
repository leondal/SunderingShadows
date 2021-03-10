// A fieldmouse that lives in the meadow
// Pator@ShadowGate
// Mar 8 1996

inherit "/std/monster";

create() {
    ::create();
   set_name("mouse");
   set_author("pator");
   set_id( ({ "mouse","field mouse","fieldmouse" }) );
   set_short("A fieldmouse");
   set_level(2);
   set("long", "A field mouse.\n");
   set_gender("male");
   set_class("mamal");
   set("race", "mouse");
   set_body_type("quadruped");
   set_alignment(2);
   set_hd(2,0);
   set("aggressive",0);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",9);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_max_mp(0);
   set_mp(query_max_mp());
   add_money("copper",random(5));

}

