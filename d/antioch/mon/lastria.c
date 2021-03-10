//  Created by Demonforce, for Shadowgate
//  Coded 25 June, 1995
// Personal pony/demon

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit MONSTER;

create() {
   ::create();
set_name("lastria");
  set_id( ({
"lastria, dark queen", "queen", "lastria"
  }) );
  set_race("elf");
     set_gender("female");
  set("short","Lastria, dark queen");
  set("long",
"She holds the element of lust, grasping it with two hands.\n"
     );
  set_body_type("human");
  set("aggressive", 18);
  set_alignment(9);
  set_size( 2 );
     set_stats("intelligence", 14);
     set_stats("wisdom", 20);
     set_stats("strength", 16);
set_stats("charisma", 21);
set_stats("dexterity", 18);
     set_stats("constitution", 22);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(10,3);
  set_hp(80);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_level(15);
  set_exp(1000);
     new("/d/antioch/obj/lust.c")->move(this_object());
}
