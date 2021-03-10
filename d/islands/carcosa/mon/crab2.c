inherit "/std/monster.c";

void create() {
  :: create();  
   set_name("Crab");
   set_id( ({ "crab" }) );
  set_short("A mean looking crab");
   set_level(2);
   set("long", "The crab snaps his claws at you.\n");
   set_gender("male");
   set("race", "arachnid");
   set_body_type("arachnid");
   set_alignment(0);
   set_size(1);
   set_stats("intelligence",1);
   set_stats("wisdom",1);
   set_stats("strength",2);
   set_stats("charisma",1);
   set_stats("dexterity",2);
   set_stats("constitution",2);
   set_max_mp(3);
   set_hp(5);
    set_max_hp(7);
    set_max_sp(6);
    set_sp(5);
    set_exp(10);
    set_overall_ac(9);
    set_emotes(8,(
		   {
		     "The crab snaps at your feet.","The crab tears at your clothes."
}
),0);

}

