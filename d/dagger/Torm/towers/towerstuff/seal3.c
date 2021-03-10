#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
void create(){
  ::create();
  set_name("Varri's Seal");
  set_id(({"seal","varri's seal","varris seal"}));
  set_short("Varri's Seal");
  set_long(
  "  This is a simple seal bearing the emblem of the lord it belonged to."
  "  Carved into its silver face is a lightning bold over a gear."
  );
  set_weight(1);
 set_value(25);
}
