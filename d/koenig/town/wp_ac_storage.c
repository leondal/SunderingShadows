#include <std.h>
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
  set_properties( (["light":1, "indoors":1]) );
  set_short("A storage room for the weapons and armour shop.");
  set_long("Supplies are stored here for the shop.");
  set_exits( (["east" : "/d/koenig/town/store2.c"]) );
}
void reset() {
  ::reset();
if (!present("bastard",this_object())) {
  new("/d/common/obj/weapon/bastard.c")->move(this_object());
  new("/d/common/obj/weapon/bastard.c")->move(this_object());
}

if (!present("broad",this_object())) {
  new("/d/common/obj/weapon/broad.c")->move(this_object());
  new("/d/common/obj/weapon/broad.c")->move(this_object());
}

if (!present("dagger",this_object())) {
  new("/d/common/obj/weapon/dagger.c")->move(this_object());
  new("/d/common/obj/weapon/dagger.c")->move(this_object());
}
if (!present("axe",this_object()))
  new("/d/common/obj/weapon/battle_axe.c")->move(this_object());

if (!present("mace",this_object()))
  new("/d/common/obj/weapon/mace.c")->move(this_object());

if (!present("staff",this_object()))
  new("/d/common/obj/weapon/quarter_staff.c")->move(this_object());

if (!present("banded",this_object()))
  new("/d/common/obj/armour/banded.c")->move(this_object());

if (!present("chain",this_object())) {
  new("/d/common/obj/armour/chain.c")->move(this_object());
  new("/d/common/obj/armour/chain.c")->move(this_object());
}

if (!present("field",this_object())) {
  new("/d/common/obj/armour/field.c")->move(this_object());
  new("/d/common/obj/armour/field.c")->move(this_object());
}

if (!present("robe",this_object())) {
  new("/d/common/obj/armour/robe.c")->move(this_object());
  new("/d/common/obj/armour/robe.c")->move(this_object());
}

if (!present("shield",this_object())) {
  new("/d/common/obj/armour/mshield.c")->move(this_object());
  new("/d/common/obj/armour/mshield.c")->move(this_object());
}

if (!present("buckler",this_object())) 
  new("/d/common/obj/armour/buckler.c")->move(this_object());

if (!present("helm",this_object())) {
  new("/d/common/obj/armour/helm.c")->move(this_object());
  new("/d/common/obj/armour/helm.c")->move(this_object());
}

}
