//  Created by Demonforce, for ShadowGate
//  Coded on 27 Dec, 1995
//  Poet for Antioch Castle

#include <std.h>
#include </d/antioch/areadefs.h>
inherit MONSTER;

create() {
   ::create();
     set_name("poet");
set_id( ({"poet", "a poet", "the poet"}) );
  set("race", "human");
     set_gender("female");
     set_short("A lovely poet");
set("long", "She sits here enchanting those who pass her by.\n");
  set_level(6);
  set_body_type("human");
set("aggressive", 1);
set_alignment(1);
  set_size(2);
   set_stats("intelligence", 6);
   set_stats("wisdom", 7);
   set_stats("strength", 13);
   set_stats("charisma", 5);
   set_stats("dexterity", 9);
   set_stats("constitution", 7);
   set_max_mp(0);
   set_mp(query_max_mp());
  set_hd(6, 3);
  set_max_hp(query_hp());
  set_max_sp(query_hp());
  set_sp(query_max_sp());
  add_money("silver",random(10));
  add_money("copper",random(20));
  set_emotes(10, ({
"%^MAGENTA%^The poet says%^RESET%^: Do you like singing, or poems?"
    }), 0);
}
void init() {
     ::init();
add_action("yes", "yes");
add_action("no", "no");
}
     int yes(string str) {
     write("Good, i'll sing you something.\n");
     write("It's called the golden bird.\n");
write("%^MAGENTA%^The poet sings%^RESET%^<%^RED%^come%^RESET%^> come little bird.  Don't be wounded don't be hurt.\n");
     write("I like that song.\n");
return 1;
}
     int no(string str) {
     write("%^MAGENTA%^The poet shouts%^RESET%^: It's you that is missing out, not me!\n");
return 1;
}
