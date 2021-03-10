//sayen.c - herb vendor by ~Circe~ for new Seneca 6/3/08
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("sayen");
   set_id(({"Sayen","sayen","herb vendor","shopkeeper","vendor","mother","mother sayen","Mother Sayen"}));
   set_short("Mother Sayen");
   set("aggressive", 0);
   set_long("%^CYAN%^Mother Sayen is an aging woman with dark %^ORANGE%^"+
      "chestnut skin %^CYAN%^stretched to the thinness of "+
      "parchment.  The crinkles around her soft %^ORANGE%^ha%^GREEN%^z"+
      "%^ORANGE%^el ey%^GREEN%^e%^ORANGE%^s%^CYAN%^ hint at her "+
      "advancing years, and matching laugh lines show that she "+
      "has spent much of her long life smiling.  She has a quiet, "+
      "gentle way about her that makes many people feel at ease.  "+
      "She dresses simply, wearing a long dress in muted %^GREEN%^"+
      "green %^CYAN%^belted at the waist with simple %^RESET%^cord"+
      "%^CYAN%^.  Dangling from her belt are several %^ORANGE%^"+
      "leather pouches %^CYAN%^that likely contain the %^GREEN%^"+
      "herbs %^CYAN%^she sells.\n%^RESET%^\n<help shop> will get "+
      "you a list of shop commands");
   set_gender("female");
   set_alignment(4);
   set_race("human");
   add_money("gold", random(500));
   set_property("no attack",1);
   set_level(39);
   set_hd(59,3);
   set_overall_ac(-12); 
   set_max_hp(query_hp());
   set_storage_room(STORAGE"herb_storage.c");
   set_items_allowed("misc");
}
