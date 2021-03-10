//  Created by Demonforce, for shadowGate
//  Coded 20 November, 1995
//  Nymph for Village Random Encounters

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
   ::create();
set_name("nymph");
  set_id( ({
"wolf", "a wolf"
  }) );
set("race", "tree");
set_gender("female");
  set("short",
"A nymph"
     );
  set("long",
"This nymph is mostly a tree yet has soft skin like a human.\n"
     );
set_level( 14 );
  set_body_type("human");
  set("aggressive", 6);
  set_alignment(6);
  set_size( 2 );
set_stats("intelligence", 14);
set_stats("wisdom", 17);
set_stats("strength", 15);
set_stats("charisma", 10);
set_stats("dexterity", 17);
   set_stats("constitution", 6);
   set_max_mp(0);
   set_mp(query_max_mp());
set_hd(12,0);
set_exp(1500);
set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  set_hp(query_max_hp());
  set_wielding_limbs( ({ "right hand", "left hand" }) );
new(ARM+ "barkback")->move(this_player());
    command("wear armor");
add_money("silver",random(40));
add_money("copper",random(50));
  set_emotes(10, ({
"The nymph forms into a tree",
}), 1);
}
