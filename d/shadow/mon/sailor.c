inherit "/std/monster";


create()
{
  ::create();

  set_name("sailor");
set("id", ({"sailor", "a sailor", "the sailor"}) );
  set_short("a Sailor");
  set_long("This burly man is on shore leave and apparently looking for some good, hard fun.");
  set_race("human");
  set_gender("male");
  set_body_type("human");
  set_hd(5);
  set_ac(8);
  set_size(2);
  set_max_hp(10);
  set_hp(10);
  set_max_sp(9);
  set_sp(9);
  set_stats("strength", 15);
  set_stats("intelligence", 6);
  set_stats("dexterity", 6);
  set_stats("charisma", 4);
  set_stats("constitution", 11);
  set_stats("wisdom", 5);
  set_money("gold", random(100));
  set_exp(15);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set("aggressive", 8);
  set_emotes(5, ({"%^MAGENTA%^Bubba says: %^RESET%^Come here baby and lets have some real fun!\n",
"The sailor pushes you around tryin to pick a fight.\n"}) );

}
