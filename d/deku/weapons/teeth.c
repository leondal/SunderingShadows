inherit "/std/weapon";

create() {
  ::create();
  set_name("teeth");
  set("id", ({"teeth"}) );
  set_short("Annis teeth");
  set("long", "These are the ugly green teeth of a Annis.\n");
  set_type("bludgeoning");
set_property("monsterweapon",1);
  set_weight(1);
  set_size(1);
  set_value(100);
  set_wc(1,4);
  set_large_wc(1,3);
}
