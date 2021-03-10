#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";

create(){
  ::create();
  set_name("Torm citizen");
  set_id(({ "citizen","Torm citizen","pickpocket" }));
  set_short("Torm citizen");
   if(!random(2)){set_gender("male");} else { set_gender("female");}
  set_long(
   "This simple townsperson continues about with "+TO->query_possessive()+" regular life. "+capitalize(TO->query_subjective())+" seems rather busy, but interested in mundane things instead of a life of adventure."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
set_body_type("human");
  set_hd(random(10)+5);
  set_wimpy(50);
  set_max_hp(query_level()*5);
  add_search_path("/cmds/thief");
set_hp(query_max_hp());
set_overall_ac(10);
  set_thief_skill("detect noise",95);
  set_thief_skill("hide in shadows",80);
  set_thief_skill("move silently",90);
  set_thief_skill("pick pockets",80);
 set_class("thief");
  set_mlevel("thief",query_hd());
set_size(2);
set_stats("strength",12);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(query_hp()*10);
set_wielding_limbs( ({"left hand", "right hand"}) );
 toggle_steal();
}
