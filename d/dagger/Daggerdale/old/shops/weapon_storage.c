#include <std.h>
inherit "/d/common/inherit/wpn_storage";

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":2, "indoors":1]));
    set("short", "Daggerdale Weapon Store Storage Room");
    set("long", "Only supplies and such here.\n");
    set_exits( (["up" : "/d/dagger/Daggerdale/shops/weaponshop"]) );
}

void reset() {
  ::reset();
   if(!present("double bladed sword"))
   new("/d/common/obj/weapon/double_bladed_sword")->move(TO);
}

