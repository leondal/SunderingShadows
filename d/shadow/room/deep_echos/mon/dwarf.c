// slave dwarves captures to send to drow
#include <std.h>
inherit "/std/monster";

create() {
  ::create();
  set_name("slavedwarf");
  set_id(({"dwarf","slave","dwarf slave","slave dwarf"}));
  set_gender("male");
  set_race("dwarf");
  set_short("chained stocky dwarf");
  set_long("This short muscular dwarf looks terrible. "+
   " He has been abused, and his spirit looks"+
   " broken.  His beard is cut and his head shaved."+
   "  He must have been through something awful."+
   "  His body looks broken.  He is covered with "+
   "many lashes and has open wounds all over his body. "+
   " He wears a simple loincloth.");
  set_body_type("human");
  set_alignment(1);
  set_hd(6,2);
  set_stats("strength",16);
  set("aggressive",0);
  set_stats("intelligence", 6);
  set_stats("wisdom", 10);
  set_stats("charisma",10);
  set_stats("dexterity",10);
  set_size(2);
  set_property("swarm",0);
  set_wielding_limbs(({"right hand","left hand"}));
  set_overall_ac(12);
  set_hp(random(50));
  set_max_level(1);
  set_emotes(2,({
   "Dwarf looks pitiful.",
   "Dwarf shamefully strokes where his beard should be.",
   "Dwarf tries not to cry.",
   "%^MAGENTA%^Dwarf says:%^RESET%^ Damn ogres.",
   "%^MAGENTA%^Dwarf says:%^RESET%^ I guess this is the end.",
   "Dwarf tries to break his chains.",
   }),0);
}
