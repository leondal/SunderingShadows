#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
::create();
  set_name("Dockworker");
  set_id(({
  "dayperson","dock worker",
  "dockworker","worker",
  }));
  set_short(
  "Dockworker"
  );
  set_long(
  "  This barrel chested man stands ready to make fast the lines of incoming ships and haul cargo to the warehouses where they belong, and help reload the ships."
  "  He's in excellent shape and a scimitar is ready at his side for those who would try to steal from the ships which are his responsibility."
  );
  if(!random(2)){set_race("human");} else { set_race("half-elf");}
  set_gender("male");
set_body_type("human");
  set_hd(random(10)+12);
  set_max_hp(query_level()*7);
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
  set_stats("strength",18);
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
  new(OBJ+"pantsc.c")->move(TO);
  command("wearall");
}
