#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("butterfly");
  set_id(({
  "butterfly","fly","butter fly","insect",
  }));
  set_short(
   "%^YELLOW%^A colorful butterfly%^RED%^"
  );
  set_long(
   "This small butterfly has brightly colored wings that are quite beautiful.  It flits about the flowers and shrubs, never staying in one place for too long."
   );
  set_race("insect");
  set_gender("neuter");
  set_hd(1,1);
  set_body_type("insectoid");
  set_emotes(10,({
  "The butterfly flits about your head.",
  "The butterfly settles on the edge of a flower and then lifts into the air again.",
  }),0);
set_max_hp(5);
set_hp(5);
set_overall_ac(10);
set_size(1);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
set("aggressive",5);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(query_night()){
  tell_room(ETO,"%^MAGENTA%^The butterfly settles on a bush and disapears from sight.");
  TO->move("/d/shadowgate/void.c");
  TO->remove();
  }
}
