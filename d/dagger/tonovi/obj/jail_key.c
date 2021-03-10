//  Jail Key-Opens Doors

inherit  "/std/armour";
void create() {
  ::create();
  set_name("Tonovi jail key");
  set_id(({"key", "skeleton key", "Tonovi jail key"}));
  set_short("a skeleton key");
  set_long("This skeleton key seems to be made of mithril.  "+
     "It is long and ends with the crest of Tonovi, through "+
     "which a leather thong has been run so the key may be "+
     "worn to prevent thievery.");
  set_property("no animate", 1);
  set_weight(20);
  set("value", 10);
  set_type("clothing");
  set_limbs( ({"waist"}) );
}
