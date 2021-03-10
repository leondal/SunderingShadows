#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("fisherman");
  set_id(({ "dayperson","fisherman","man","fisher" }));
  set_emotes(2,({
  "Fisherman complains about the weather.",
  "Fisherman complains about the heat.",
  "Fisherman complains about his bad catch of fish.",
  "Fisherman complains about the nightlife.",
  }));
  set_short(
  "Fisherman"
  );
  set_long(
  "  This simple man looks out to the sea to check for the weather once in awhile."
  "  He smells of salt and fish which is really overpowering this close to him."
   "  His skin is darkly tanned, almost to the point where it is beginning to appear like leather.  He is dressed in simple and slighly ragged clothing and is definitely on the skinny side."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
  set_gender("male");
set_body_type("human");
  set_hd(5,1);
  set_max_hp(30);
set_hp(query_max_hp());
  set_overall_ac(3);
  set_property("full attacks",1);
set_size(2);
  set_stats("strength",17);
set_stats("intelligence",7);
set_stats("dexterity",9);
set_stats("charisma",7);
set_stats("constitution",11);
set_stats("wisdom",8);
set_money("silver",random(100));
  set_exp(query_hp()*10);
set_wielding_limbs( ({"left hand", "right hand"}) );
  new(OBJ+"pantsc.c")->move(TO);
  command("wearall");
}
