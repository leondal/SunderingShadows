#include <std.h>
#include "/d/common/common.h"
inherit "/d/common/inherit/gs_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set_short("A storage froom for the adventurer shop.");
    set_long("Supplies and such for the adventurer shop are stored here.\n");
    set_exits( (["east" : "/d/koenig/town/general1.c"]) );
}

void reset() {

::reset();
if(!present("backpack"))               new(CMISC"backpack")->move(TO);
if(!present("perfume"))                  new("/d/tharis/obj/perfume.c")->move(TO);
if(!present("thief tools"))           new("/d/common/obj/misc/thief_tools.c")->move(TO);
/* changed to use the general inherit that also then uses items from common
if (!present("chest",this_object()))
{
  new("/d/shadow/obj/misc/chest.c")->move(this_object());
  new("/d/shadow/obj/misc/chest.c")->move(this_object());
}
if (!present("backpack",this_object()))
{
  new("/d/shadow/obj/misc/backpack.c")->move(this_object());
  new("/d/shadow/obj/misc/backpack.c")->move(this_object());
}
if (!present("bag",this_object()))
{
  new("/d/shadow/obj/misc/bag.c")->move(this_object());
  new("/d/shadow/obj/misc/bag.c")->move(this_object());
}
if (!present("basket",this_object()))
{
  new("/d/shadow/obj/misc/basket.c")->move(this_object());
  new("/d/shadow/obj/misc/basket.c")->move(this_object());
}
if (!present("lantern",this_object()))
{
  new("/d/shadow/obj/misc/lantern.c")->move(this_object());
  new("/d/shadow/obj/misc/lantern.c")->move(this_object());
  new("/d/shadow/obj/misc/lantern.c")->move(this_object());
  new("/d/shadow/obj/misc/lantern.c")->move(this_object());
}
if (!present("torch",this_object()))
{
  new("/d/shadow/obj/misc/torch.c")->move(this_object());
  new("/d/shadow/obj/misc/torch.c")->move(this_object());
  new("/d/shadow/obj/misc/torch.c")->move(this_object());
  new("/d/shadow/obj/misc/torch.c")->move(this_object());
}
if (!present("oil",this_object()))
{
  new("/d/shadow/obj/misc/oil.c")->move(this_object());
  new("/d/shadow/obj/misc/oil.c")->move(this_object());
}
if (!present("flint",this_object()))
{
  new("/d/shadow/obj/misc/flint.c")->move(this_object());
  new("/d/shadow/obj/misc/flint.c")->move(this_object());
}
if (!present("pouch",this_object()))
{
  new("/d/shadow/obj/misc/pouch.c")->move(this_object());
  new("/d/shadow/obj/misc/pouch.c")->move(this_object());
}
if (!present("thief tools",this_object()))
{
  new("/d/tharis/obj/thief_tools.c")->move(this_object());
  new("/d/tharis/obj/thief_tools.c")->move(this_object());
}
if (!present("climbing tools",this_object()))
{
  new("/d/shadow/obj/misc/climb_tool.c")->move(this_object());
  new("/d/shadow/obj/misc/climb_tool.c")->move(this_object());
}
if (!present("rope",this_object()))
{
  new("/d/shadow/obj/misc/rope.c")->move(this_object());
  new("/d/shadow/obj/misc/rope.c")->move(this_object());
}
if (!present("perfume",this_object()))
{
  new("/d/tharis/obj/perfume.c")->move(this_object());
  new("/d/tharis/obj/perfume.c")->move(this_object());
}
*/
}
