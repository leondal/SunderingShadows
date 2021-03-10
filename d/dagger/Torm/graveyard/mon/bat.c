inherit "/std/monster";

void create() {
  ::create();
  set_name("bat");
  set_id(( { "Bat", "bat"} ));
  set("race", "bat");
  set_gender("neuter");
set("short","Vampire Bat");
set("long","This creature of the night seems harmless, but that glint in it's eye indicates it's thirst for blood...your blood to be exact!!");

set_level(15);
  set_alignment(6);
  set_body_type("fowl");
  set("aggressive", 15);
new("/d/dagger/Torm/graveyard/weapon/vfangs")->move(this_object());
add_limb("mouth","mouth",75,1,5);
set_wielding_limbs(({
"mouth"}));
  command("wield fangs in mouth");
  set_size(1);
  set_ac(3);
set_hd(10,20);
set_hp(100);
}
