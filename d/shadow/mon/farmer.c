inherit "/std/monster";
void create() {
::create();
set_name("farmer");
set_id( ({"farmer", "the farmer", "a farmer"}) );
set("short", "a Farmer");
set("long", "This man has toiled many an acre of land.");
set("race", "human");
set_gender("male");
set_body_type("human");
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
set_max_sp(10);
set_sp(8);
set_exp(15);
set("aggressive",5);
set_property("rake",1);
set_wielding_limbs( ({"left hand", "right hand"}) );
if(random(2)){
new("/d/shadow/obj/weapon/rake.c")->move(this_object());
command("wield rake in right hand");
} else {
new("/d/shadow/obj/weapon/scythe.c")->move(this_object());
command("wield scythe in right hand");
}
}
