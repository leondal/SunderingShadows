#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";

create(){
  ::create();
  set_name("old king");
  set_id(({ "old king","man","senile king", "king","old man" }));
  set_short( "Old king" );
  set_long(
  "  This old man putters about in the park tending to the flowers."
  "  He'd almost be mistaken for a gardener, but his clothes show very fine quality through the dirt on them."
  "  The old king smiles at anyone who passes and turns back to his work."
   "  Muttering and fussing with a flower's stem you realize his mind is not all there anymore."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
  set_hd(20,1);
  set_max_hp(300);
  set_hp(300);
  set_overall_ac(0);
set_size(2);
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
  if(ETO->query_property("indoors")) return 1;
  tell_room(ETO,"%^GREEN%^Old king sighs and heads up the stairs in the back of the mansion to a balcony on the second story.");
  TO->move("/d/shadow/void.c");
  TO->remove();
  }
}
