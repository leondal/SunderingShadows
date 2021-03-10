#include <std.h>
#include "../piratedefs.h"
inherit VENDOR;

void create() {
   ::create();
   set_name("Krinten");
   set_id(({"krinten","shop keeper","Krinten","thief"}));
   set_short("Krinten, Master of the Thieves shop");
   set_long("It's hard to make out the features of this humanoid, beneath the dark hooded cloak he wears.  "
"He is about the height and build of a human, but with slanted eyes of dull green, that peer back at you "
"from across the counter.  He says very little, just observes everything and everyone that passes through "
"his little nook here.");
   set_gender("male");
   set_alignment(6);
   set_class("thief");
   set_mlevel("thief",15);
   set_race("half-elf");
   set_body_type("human");
   set_storage_room(STORAGE"thief");
   set_hd(15,1);
   set("aggressive",0);
}
