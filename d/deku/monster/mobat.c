inherit "/std/monster";

void create() {
  ::create();
  set_name("mobat");
  set_id(( { "mobat", "bat"} ));
  set("race", "bat");
  set_gender("neuter");
  set("short", "Mobat");
  set("long", "This creature in some ways looks like a normal bat.");

  set_level(3);
  set_alignment(-20);
  set_body_type("fowl");
  set("aggressive", 15);
  set_size(1);
  set_hd(3,1);
  set_alignment(6);
  add_money("copper",random(30));
}
