inherit "/std/monster";

void create() {
  ::create();
  set_name("bee");
  set_id(( { "bee", "killer bee"} ));
  set("race", "bee");
  set_gender("neuter");
  set("short", "Killer bee");
  set("long","Killer bees are 1' long giant bees with a very vicious temper.\n"+
             "Killer bees attack on sight, especially anyone within 30' of\n"+
             "their hive.");

set_level(10);
  set_alignment(6);
set_body_type("insectoid_winged");
  set("aggressive", 15);
  set_size(1);
set_hd(10,1);
set_wielding_limbs(({"torso"}));
new("/d/dagger/Elvanta/forest/items/wpns/stinger")->move(this_object());
command("wield stinger in torso");
this_player()->add_poisoning(10);
set_exp(50);
add_money("gold", 5);
}
