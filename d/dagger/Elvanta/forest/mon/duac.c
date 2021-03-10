//  Created by Demonforce, for Shadowgate
//  Coded 25 June, 1995
// Personal pony/demon

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
   ::create();
set_name("duac");
  set_id( ({
"duac", "statue"
  }) );
set("race", "statue");
set_gender("male");
  set("short",
"A statue of Duac"
     );
  set("long",
"%^BOLD%^WHITE%^Another of Anuin's victims is Duac.  He is cast in marble the colour of snow on a dark winters evening.  He lays upon the ground at Anuin's feet, with one arm raised in supplication.  Although, he was a victim, he also would fight to the death for her and because of her.%^RESET%^");
set_level(20);
  set_body_type("human");
  set("aggressive", 18);
  set_alignment( 50 );
  set_size( 2 );
     set_stats("intelligence", 14);
     set_stats("wisdom", 20);
     set_stats("strength", 16);
set_stats("charisma", 21);
set_stats("dexterity", 18);
     set_stats("constitution", 22);
set_hp(150);
add_money("gold", 150);
set_exp(900);
   set_max_mp(0);
   set_mp(query_max_mp());
set_hd(25,1);
  set_max_hp(query_hd());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
     set_wielding_limbs( ({ "left fog arm" }) );
     new("/d/antioch/obj/lust.c")->move(this_object());
}
