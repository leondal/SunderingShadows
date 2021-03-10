#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
void create(){
  ::create();
  set_name("Savan's Seal");
  set_short("Savan's Seal");
  set_id(({"seal","savan's seal","savans seal"}));
  set_long(
  "  This is a simple seal bearing the emblem of the lord it belonged to."
  "  Carved into its silver face is a hawk over a sword."
  );
  set_weight(1);
 set_value(25);
}
