#include <std.h>
inherit "/std/monster";

create() {
    ::create();
	set_name("orc");
	set_id( ({ "orc","large orc", "orc guard", "orcguard" }) );
	set_race("orc");
	set_gender("male");
   set("short", "Large orc");
   set("long","This is a typical barbaric-looking, pig-nosed orc.");
	set_body_type("human");
  	set("aggressive",10);
  	set_alignment(3);
  	set_size(2);
   set_hd(8,2);
   set_stats("wisdom",4);
   set_stats("strength",16);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_hp(random(10)+50);
   set_exp(150);
   set_stats("constitution",7);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
   "/d/common/daemon/randgear_d.c"->arm_me(TO,"edgedm",0,0);
   if(!random(3)) "/d/common/daemon/randgear_d.c"->arm_me(TO,"edgeds",0,0);
	add_money("silver",random(10)+100);
	add_money("gold",random(20)+50);
}
