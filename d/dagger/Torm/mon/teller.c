#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/std/monster";
create(){
::create();
  set_name("bank teller");
  set_id(({
  "teller","bank teller",
  }));
  set_short(
  "Bank teller"
  );
  set_long(
  "  This weasely looking little man sits behind a steel cage servicing the people who wish to have their money protected here."
   "  He appears rather bored and often gets fed up with slow customers who can't make up their mind fast enough for his liking.  He seems to be getting away with his impolite attitude, however, for Torm is a large trade port on the Dagger Sea and those wishing to purchase things need to have coin to do so, and it's often best stored in an account instead of kept upon yourself with all the pirates and thieves lurking about."
  );
  set_race("human");
  set_gender("male");
set_body_type("human");
  set_hd(1,1);
set_max_hp(5);
set_hp(5);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
set_exp(15);
set_wielding_limbs( ({"left hand", "right hand"}) );
}
