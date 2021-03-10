#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("human");
  set_id(({"human","Human","human_follower"}));
  set_race("human");
  set_gender("male");
  set_short("A dirty male human with greasy hair");
  set_long("This man is of a slightly above average height, a little "+
  "under six feet tall and has a slack build.  His body is dirty, "+
  "unwashed, and partly hidden beneath a suit of chain mail.  A "+
  "strong body odor eminates from him and you wish that something "+
  "stronger was covering him.  His black hair, in perfect compliment "+
  "with his body, is greasy and thick with filth.  His eyes are a "+
  "unassuming brown and reflect a mixture of boredom and slight "+
  "curiosity.");
  set("aggressive",10);
  set_alignment(8);
  set_hd(10 + random(4),2);
  set_stats("strength",14 + random(3));
  set_stats("dexterity",12);
  set_stats("constitution",11);
  set_stats("wisdom",10);
  set_stats("intelligence",10);
  set_stats("charisma",9);
  new("/d/common/obj/misc/pouch")->move(TO);
  command("wear pouch");
  add_money("silver",random(300));
  set_hp(query_hd() * 8);
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  new("/d/common/obj/weapon/shortsword")->move(TO);
  command("wield sword");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear chain");
  set_exp(query_max_hp() * 10);
}
