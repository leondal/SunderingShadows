#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("Torm citizen");
  set_property("swarm",1);
  set_id(({ "dayperson", "citizen","Torm citizen","torm citizen" }));
  set_short( "Torm citizen"  );
  if(!random(2)){set_gender("male");} else { set_gender("female");}
  set_long(
   "This simple townsperson continues about with "+TO->query_possessive()+" regular life. "+capitalize(TO->query_subjective())+" seems rather busy, but interested in mundane things instead of a life of adventure."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
set_body_type("human");
  set_emotes(1,({
  "Torm citizen smiles at you and continues about "+TO->query_possessive()+" day.",
    "%^MAGENTA%^Torm citizen says: %^RESET%^Fine day isn't it?",
  }),0);
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
