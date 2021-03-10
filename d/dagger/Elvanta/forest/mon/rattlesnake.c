inherit "/std/monster";

create() {
  object fangs;
    ::create();
   set_name("snake");
   set_id( ({ "rattlesnake","rattler","snake" }) );
   set_short("A big rattlesnake");
   set_level(3);
   set("long", "A big rattlesnake. It is hissing and it's rattles are shaking violently. It looks very upset, and dangerous.\n");
   set("race", "snake");
   set_gender("male");
   set_body_type("snake");
   set_wielding_limbs(({"mouth"}));
   set_alignment(2);
   set("aggressive",20);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",5);
   set_stats("charisma",3);
   set_stats("dexterity",18);
   set_stats("constitution",14);
   set_max_mp(0);
   set_hd(3,1);
set_max_hp(query_hp());
set_max_sp(query_hp());
set_sp(query_max_sp());
   set_max_hp(query_hp());
   set_mp(query_max_mp());
   new("/d/shadow/mon/obj/fangs")->move(this_object());
   this_object()->force_me("wield fangs in mouth"); 
}

