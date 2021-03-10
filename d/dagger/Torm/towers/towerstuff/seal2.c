#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
void create(){
  ::create();
  set_id(({"seal","enegu's seal","enegus seal"}));
  set_name("Enegu's Seal");
  set_short("Enegu's Seal");
  set_long(
  "  This is a simple seal bearing the emblem of the lord it belonged to."
  "  Carved into its silver face is a dagger stuck through a pigs head."
  );
  set_weight(1);
 set_value(25);
}
