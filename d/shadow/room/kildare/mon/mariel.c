#include <std.h>
#include "../kildare.h"
inherit "/std/vendor";

create() {
   ::create();
  set_name("mariel");
  set_id(({"clothier","mariel","tailor"}));
  set_short("Mariel, a young tailor");
   set("aggressive", 0);
   set_level(15);
  set_long(
    "Mariel is a tall, lithe young woman with long, auburn hair "+
    "that flows in waves past her slender waist.  She wears a "+
    "tea length deep green wool skirt with light green ivy vines "+
    "embroidered along the hem underneath a fuzzy white woolen "+
    "sweater that looks quite soft to the touch.  She has delicate "+
    "features and moves nimbly around the shop with a red pin cushion "+
    "wrapped around her wrist and a small belt at her side holding "+
    "various implements of the tailoring trade."
  );
   set_gender("female");
   set_alignment(4);
   set_race("human");
   set_body_type("human");
   set_storage_room(STOR"tailor");
   set_property("no attack", 1);
   set_hd(15,3);
   set_exp(10);
   set_items_allowed("clothing");
   set_max_hp(query_hp());
}
