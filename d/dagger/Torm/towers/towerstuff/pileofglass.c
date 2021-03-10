#include <std.h>
#include "/d/dagger/Torm/tormdefs.h";
inherit OBJECT;
  void create(){
  ::create();
  set_name("glass");
  set_id(({"pile of glass","glass","pile",
  }));
  set_short("pile of glass");
  set_long(
  "  This is a pile of brightly colored glass that appears to have once been a stained glass window that's been smashed beyond all recognition of what its image once was."
  );
  set_weight(100);
  set_value(1);
  set_property("no animate",1);
}
