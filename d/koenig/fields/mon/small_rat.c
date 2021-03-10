inherit "/std/monster";

create() {
  	::create();
  	set_name("rat");
  	set_id( ({ "rat", "monster", "vermin", "mouse" }) );
  	set_short("A tiny rat");
  	set("aggressive", 0);
  	set_level(1);
  	set_hd(1,1);
  	set_long("This is a tiny rat, scurrying around eating corn.\n");
  	set_body_type("quadruped");
  	set_alignment(5);
  	set_race("rat");
  	set_exp(50);
}
