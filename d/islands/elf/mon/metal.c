#include <std.h>;

inherit VENDOR;

void create() {
 ::create();
  set_gender("male");
  set_short("Illy, metal vendor");
  set_name("Illy");
  set_id(({"illy","metal","vendor","metal vendor"}));
  set_long("Illy is a typical moon elf.  She has"+
  " a black pony tail and green eyes.   She wears"+
  " a wool cloak and leather cloathing.   Thick "+
  "leather gloves cover her hands as she provides"+
  " metal for those wishing to use the skyforge.");
  set_alignment(2);
  set_race("elf");
  set_storage_room("/d/islands/elf/storage/metal");
  set_hd(14 + random(6),3);
  set_hp(query_hd() * 12 + random(21));
  set_exp(query_max_hp() * 5);
  set_stats("strength",17);
  set_stats("dexterity",14);
  set_stats("constitution",12);
  set_stats("wisdom",16);
  set_stats("intelligence",12);
  set_stats("charisma",14);
  set_items_allowed("material");
  new("/std/obj/metal")->move(TO);
}
