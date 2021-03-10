inherit "std/npc";

void create()   {
  ::create();
  set_name("bob");
  set_short("Bob");
  set_id(({"bob","Bob"}));
  set_long("This is bob");
  set_level(10);
  set("race","human");
  set_gender("male");
  set_body_type("dragon");
  set_base_topic("nothin");
}
