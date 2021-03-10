
#include <std.h>


inherit OBJECT;

void create() {
  ::create();
  set_name("jack-o-lantern");
  set_id(({"jack-o-lantern","pumpkin","lantern","jack lantern"}));
  set_short("Jack-O'-Lantern");
    set_long("The frightful jack-o'-lantern is intended to scare away the \n"+
            "evil spirits that have beset the world.  The innards are \n"+
           "carved out and filled with candlelight.");
  set_weight(2);
  set_value(1);
  set_no_clean(1);
}
