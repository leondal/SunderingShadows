// from Shadow desert toned down, esp. exp. from 120

inherit "/std/monster";

create() {
   ::create();
   set_name("rattlesnake");
   set_id( ({ "snake"," snakerattler","snake", "rattlesnake"}) );
   set_short("A large snake");
   set_long("%^ORANGE%^A big timber rattlesnake. It blends into the forest floor well when it tries to hide but this one is hissing and its rattles are shaking violently. It looks very upset, and dangerous.\n");
   set_race("snake");
   set_gender("male");
   set_body_type("snake");
   set_alignment(2);
   set("aggressive",17);
   set_size(1);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",18);
   set_stats("constitution",14);
   set_hd(2,1);
   set_exp(40);
   set_max_level(8);
   set_max_hp(query_hp());
   set_ac(8);
   new("/d/shadow/mon/obj/fangs")->move(this_object());
     command("wield fangs"); 
}

