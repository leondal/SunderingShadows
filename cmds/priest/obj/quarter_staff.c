#include <std.h>

inherit "/std/weapon";
object old;
object owner;
int duration;

create() {
    ::create();
   set_id(({ "staff", "quarter", "quarter staff", "shillelagh" }));
   set_name("shillelagh");
    set_short("A fine wooden staff");
   set_long(
	"This is a fine looking quarter staff. \n"
   );
   set_weight(4);
   set_size(1);
   set("value", 0);
   set_type("magebludgeon");
}

