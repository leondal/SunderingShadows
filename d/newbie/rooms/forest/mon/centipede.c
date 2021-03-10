// newbie/mon/centipede.c - Centipede for newbie cave

#include <std.h>
inherit "/std/monster";

void create() {
  ::create();
  set_name("centipede");
  set_id(( { "centipede", "giant centipede" } ));
  set_race("arthropod");
  set_gender("male");
  set_short("Giant centipede");
  set_long(
@STYX
%^ORANGE%^Countless legs sweep along as these arthropods writhe out from under the debris.  The giant wormlike bodies are the size of a human arm, with a blackish-brown scale-like exterior that consists of many segments, each having a pair of legs.  Sturdy and sharp pincers protrude from the mouth and snap viciously.  They swarm around your feet and begin crawling up your legs. 
STYX
  );
  set_level(2);
  set_alignment(6);
  set_body_type("arachnid");
    /* I know they aren't arachnids but arachnids have more legs than insectoid and they do have pincers so it's the closest choice */
  set("aggressive", 10);
  set_size(1);
  set_hd(2,2);
  set_stats("dexterity",15);
  set_stats("strength",10);
  set_overall_ac(7);
  set_hp(random(5)+20);
  set_exp(80);
  set_wimpy(4);
  set_achats(3, ({ "%^ORANGE%^The centipede's legs sweep along as it tries to writhe away into a hole.%^RESET%^" }) );

/* Goblin gatekeepers were AC 5, level 2, 32 hp, 125 exp. */

   set_funcs(({"pinch"}));
   set_func_chance(10);
}

void pinch(object targ) {
    targ->do_damage("torso",random(8)+3);
    tell_object(targ, "%^RED%^The centipede crawls up your leg and gets hold of some bare skin with it's strong pincer, making a nasty gash.\n");
    tell_room(ETO, "%^RED%^The centipede crawls up "+targ->query_cap_name()+"'s leg and leaves a nasty gash as it grabs hold of bare skin with it's sharp pincer!!", targ);
}