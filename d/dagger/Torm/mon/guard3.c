#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>

inherit "/d/dagger/Torm/mon/dayperson.c";
create (){
  object ob;
  ::create ();
  set_name("Torm wall guard");
  set_property("swarm",1);
  set_id(({
  "dayperson","guard","torm wall guard","archer",
  "torm city guard","torm guardsman"}));
  set_short("Torm wall guard");
  set_long(
  "  This crossbow man watches the ground outside of Torm carefully."
   "  His mithril armor and weapons shine brightly though and he looks proficient in his duties."
  );
set_property("swarm",1);
set_gender("male");
  if(!random(2)){
  set_race("human");
  } else {
  set_race("half-elf");
  }
set_body_type("human");
set_hd(18,1);
set_size(2);
  set_class("fighter");
  set_mlevel("fighter",18);
  set_property("full attacks",1);
  set_stats("strength",17);
set_stats("intelligence", 13);
set_stats("dexterity", 17);
set_stats("charisma", 16);
set_stats("wisdom", 10);
set_stats("constitution", 14);
set_alignment(1);
  set_max_hp(random(100)+200);
  set_hp(query_max_hp());
  set_exp(1000);
set("aggressive", 0);
set_emotes(1, ({"%^BOLD%^You shall never defeat the Forces of Good!!"}), 1);
set_overall_ac(8);
add_money("gold", 50 + random(100));

  new(OBJ"torm_leather.c")->move(TO);
  new(OBJ"torm_bracers.c")->move(TO);
   new("/d/common/obj/lrweapon/hcrossbow.c")->move(TO);
  command("wield crossbow");
  ob=new(OBJ+"bolts");
  if(random(10))   ob->set_property("monsterweapon",1);
  ob->move(TO);
  command("wearall");
  present("leather",TO)->set_property("monsterweapon",1);
  set_moving(0);
  set_speed(0);
}
