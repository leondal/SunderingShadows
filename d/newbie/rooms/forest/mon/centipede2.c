// newbie/mon/centipede2.c - Old (larger) centipede for newbie cave

#include <std.h>
#include "../../../newbie.h"
#include "../forest.h"

inherit "/std/monster";

void create() {
  ::create();
  set_name("centipede");
  set_id(( { "centipede", "old centipede" } ));
  set_race("arthropod");
  set_gender("male");
  set_short("Old centipede");
  set_long(
@STYX
%^ORANGE%^This is obviously a VERY old giant centipede.  Countless legs sweep along as it writhes out from under the debris and raises up menacingly.  It is a much larger version of the others with pincers alone around six inches long.
STYX
  );
  set_level(3);
  set_alignment(6);
  set_body_type("arachnid");
  set("aggressive", 8);
  set_size(1);
  set_hd(3,2);
  set_stats("dexterity",15);
  set_stats("strength",16);
  set_overall_ac(6);
  set_hp(30);
  set_exp(250);
  set_achats(6, ({ "%^ORANGE%^The old centipede rises up menacingly, snapping its pincers at you.%^RESET%^" }) );
   set_funcs(({"pinch"}));
   set_func_chance(20);
   new(STUFF"centdagger.c")->move(TO);
     command("wield pincer");
}

void pinch(object targ) {
    targ->do_damage("torso",random(10)+4);
    tell_object(targ, "%^RED%^The old centipede snaps at you and makes a nasty gash with its strong pincer.\n");
    tell_room(ETO, "%^RED%^The old centipede snaps at "+targ->query_cap_name()+"'s leg and leaves a nasty gash as it grabs hold of bare skin with its sharp pincer!!", targ);
}

