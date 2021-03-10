inherit "std/monster";

create() {
    ::create();
	set_name("rat");
	set_id( ({ "rat" }) );
	set("race", "rat");
	set_gender("male");
	set("short", "Giant Rat");
   set("long","Giant rats are 3 feet long and have gray fur.  This monster\n"+
                "is very nasty and stinky, it may even carry a disease.");
	set_level(1);
	set_body_type("quadruped");
  	set("aggressive",20);
        set_hd(2,1);
  	set_alignment(5);
  	set_size(1);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
           set_hp(20);
        set_exp(10);
}
