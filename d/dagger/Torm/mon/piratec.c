#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("Freebooter");
  set_id(({ "pirate","freebooter","dayperson" }));
  set_short( "Torm freebooter" );
  set_long(
  "  This pirate walks casually around with little thought for the few guards he might pass."
  "  He's not breaking any laws here and the seas are wide open for the goods his captain could sell back here to the merchants."
   "  The fine silk shirt and the glint of gold about him make it obvious that he earns a decent living at what he does."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
  set_gender("male");
set_body_type("human");
  set_hd(random(10)+12);
  set_max_hp(query_level()*10);
set_hp(query_max_hp());
  set_overall_ac(3);
  set_thief_skill("detect noise",95);
  set_thief_skill("hide in shadows",95);
  set_thief_skill("move silently",95);
  set_thief_skill("pick pockets",95);
 set_class("thief");
  set_mlevel("thief",query_hd());
  set_property("full attacks",1);
  set_scrambling(1);
set_size(2);
  set_stats("strength",19);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(query_hp()*5);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new(OBJ+"scimitar.c")->move(TO);
  command("wield scimitar");
  if(!random(2)){new(OBJ+"pantsl.c")->move(TO);} else {new(OBJ+"pantsc.c")->move(TO);}
  switch(random(4)){
  case 0:
  new(OBJ+"silkshirtw.c")->move(TO);
  break;
  case 1:
  new(OBJ+"silkshirtb.c")->move(TO);
  break;
  case 2:
  new(OBJ+"silkshirtr.c")->move(TO);
  break;
  case 3:
  new(OBJ+"silkshirtg.c")->move(TO);
  break;
  }
  command("wearall");
}
