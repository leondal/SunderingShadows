//weaponsmith.c - by ~Circe~ for new Seneca 1/22/08
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create(){
   ::create();
   set_name("rarkud");
   set_id(({"rarkud","Rarkud","rarkud slatehelm","Rarkud Slatehelm","weaponsmith","shopkeeper"}));
   set_short("Rarkud Slatehelm, Seneca Weaponsmith");
   set_long("Nearly as wide as he is tall, this dwarf is heavily "+
      "muscled and definitely knows his way around the forge.  "+
      "His thick %^RED%^red hair %^CYAN%^is tied back with a "+
      "%^ORANGE%^leather thong %^CYAN%^at the base of his neck, "+
      "with several slender braids feeding into it.  Echoing "+
      "this, his full %^RED%^beard%^CYAN%^ is gathered into a "+
      "single wrist-thick braid bound in %^RESET%^silver %^CYAN%^"+
      "that ends just at his belt buckle.  His expansive chest is "+
      "barely contained by a %^ORANGE%^leather jerkin %^CYAN%^"+
      "that creaks lightly as he moves, and supple %^BOLD%^"+
      "%^BLACK%^leather pants %^RESET%^%^CYAN%^are tucked into "+
      "matching %^BOLD%^%^BLACK%^boots%^RESET%^%^CYAN%^.  His "+
      "crowning feature are the twin %^RESET%^bracers %^CYAN%^"+
      "worn around his wrist, each of which is engraved with the "+
      "likeness of %^BOLD%^Moradin%^RESET%^%^CYAN%^.%^RESET%^");
   set_gender("male");
   set_alignment(2);
   set_race("dwarf");
   add_money("gold", random(500));
   set_property("no attack",1);
   set("aggressive", 0);
   set_level(59);
   set_hd(59,3);
   set_max_hp(query_hp());
   set_storage_room(STORAGE"weapon_storage.c");
   set_items_allowed("weapon");
   set_nwp("weaponsmithing",20);
}
