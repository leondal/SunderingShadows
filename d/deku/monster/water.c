inherit "/std/monster";

create() {
  ::create();
  set_name("elemental");
  set_id(({"water","elemental"}));
  set_gender("neuter");
  set_race("elemental");
  set("short","Water elemental");
    set("long","There is nothing to this monster, it is just water!");
  set_level(10);
  set_class("fighter");
  set("aggressive",16);
  set_size(3);
  set_hd(10,3);
  set_hp(80);
  set_alignment(5);
  set_body_type("elemental");

  set_exp(600);

  set_overall_ac(2);
     set_property("magic",1);
   set_property("water breather",1);
}
