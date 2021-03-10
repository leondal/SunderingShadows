
#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

create() {
    ::create();
   set_id(({ "sword", "longsword", "long sword", "long" }));
   set_name("longsword");
   set_short("A long sword");
   set_long(
@AZHA
  This is an old, nicked-up, but serviceable long sword.  Its 
craftsmanship is unlike that of the northern realms, but also
unlike the scimitars and katanas commonly in use in the south.
Most likely a frontier hybrid of some form.
AZHA
   );
}
