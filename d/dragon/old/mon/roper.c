#include <std.h>

inherit "/std/monster";

void create() {
  ::create();
  set_name("roper");
  set_id(({"roper","Roper"}));
  set_short("Roper");
  set_long("This yellowish gray monster appears to be a mass of foul, \n"+
           "festering corruption.  It is cigar-shaped, about 9' long, \n"+
           "with a diameter of some 3'.  The roper has six strands of\n"+
           "strong, sticky rope-like excretions.\n");
  set_property("weekness","fire");
  set_property("strength","cold");
  set_property("strength","lightning");
  set_level(8);
  set_hd(14);
  set_overall_ac(0);
  set_size(3);
  set_stats("strength",19);
  set_stats("intelligence",19);
  set_stats("wisdom", 8);
  set_stats("dexerity", 10);
  set_stats("constitution", 24);
