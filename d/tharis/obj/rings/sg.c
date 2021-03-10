//updated by Circe 9/18/04
inherit "/std/armour";

void create() {
  ::create();
  set_name("ring");
  set_id(({"ring","gold band","slight gold band","thin band","slight band"}));
  set_short("%^YELLOW%^slight gold band%^RESET%^");
//  set("long", "This is a small gold band.\n");
  set_long("%^YELLOW%^This slender ring is quite delicate and formed "+
     "of soft gold that can bend and scratch if care is not taken.  "+
     "There are no marks of embellishment on the ring's surface, "+
     "though one skilled in engraving could probably add an "+
     "inscription inside.%^RESET%^");
  set_type("ring");
  set_limbs(({"left hand"}));
  set_weight(1);
  set_value(10);
}
