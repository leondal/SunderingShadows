#include <std.h>
#include "/d/common/common.h"
#include "../../elfisland1.h"

inherit "/d/common/inherit/gs_storage";
object ob;

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Village General Storage");
   set_long("This is the supply room for the elf village market.");
   set_exits( (["up" : TOWN+"market"]) );
}
