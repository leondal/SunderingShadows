#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";

create(){
  ::create();
  set_name("pirate");
  set_id(({ "pirate","drunken pirate", "drunk" }));
  set_short( "Drunken pirate" );
  set_long(
  "  This pirate has a few to many ales under his belt and swaggers about self importantly."
  "  His hand keeps going to the hilt of his scimitar and he looks about with a drunken leer."
   "  His fine silk shirt now has a bit of wine spilled on it but he doesn't seem to notice or care."
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
  set_exp(query_hp()*10);
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
