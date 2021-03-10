#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("beggar");
  set_id(({ "dayperson", "dirty beggar","beggar" }));
  set_short(  "Dirty beggar"  );
  set_long(
  "  This pitiful soul sits here with a hand outstretched waiting for the mercy of others."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
  if(!random(2)){set_gender("male");} else { set_gender("female");}
set_body_type("human");
  set_hd(1,1);
  set_emotes(2,({
   "The beggar looks pathetic.",
   "Beggar smiles weakly as a passerby gives "+TO->query_objective()+" a few copper coins.",
  "Beggar coughs and holds "+TO->query_possessive()+" side.",
  }),0);
   set_max_hp(10);
set_hp(5);
set_overall_ac(10);
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_exp(15);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new(OBJ+"rags")->move(TO);
  command("wearall");
}
