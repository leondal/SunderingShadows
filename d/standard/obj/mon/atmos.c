inherit "/std/monster";

void create() {
    ::create();
   set_name("atmos");
   set_id( ({ "atmos" }) );
    set_short("High mortal Atmos, Lord of Praxis");
   set("aggressive", 0);
  set_level(26);
    set_long("Atmos is the lord of Praxis and all high mortals.\n");
   set_alignment(1000);
   set("race", "human");
   set_max_hp(400000);
   set_hp(400000);
  set_body_type("human");
}
