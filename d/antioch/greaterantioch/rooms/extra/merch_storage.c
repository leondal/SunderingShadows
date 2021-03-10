#include <std.h>
#include "/d/common/common.h"
#include "../../gantioch.h"

inherit "/d/common/inherit/gs_storage";
object ob;

void create() {
   ::create();
   set_property("no teleport",1);
   set_short("Merchant's Storage Cellar");
   set_long("This is the supply room for the roadside merchant.");
   set_exits( (["up" : HAMLET+"merchanthouse1"]) );
}
