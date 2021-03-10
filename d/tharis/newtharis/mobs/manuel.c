//manuel.c - Vendor for the thief tailor in Tharis.  Circe 9/9/04
#include <std.h>
inherit VENDOR;

void create() {
   ::create();
   set_name("Manuel");
   set_id(({"Manuel","manuel","shop keeper","shopkeeper","tailor","vendor"}));
   set_short("Manuel, a massive dark-skinned human");
   set("aggressive", 0);
   set_level(19);
   set_long(
      "Manuel is an extremely large, well-built man with "+
      "mahogany skin.  He wears a sleeveless leather tunic "+
      "that reveals his massive biceps, the right one decorated "+
      "with a black, spiralling tattoo.  His muscular legs are "+
      "clad in tight, thin leather pants tucked into his "+
      "matching leather boots.  His head is covered with a "+
      "dusky gray cloth, and there is a long scar reaching from "+
      "the corner of his left eye all the way down to his chin.  "+
      "His ready smile takes on a somewhat menacing appearance "+
      "at times, making you sure he can handle anything in his shop.");
   set_gender("male");
   set_alignment(6);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_storage_room("/d/tharis/Tharis/storage/tailor_storage.c");
   set_items_allowed("clothing");
   set_items_allowed("misc");
   set_items_allowed("armor");
   set_exp(0);
   remove_std_db();
}

void init(){
    ::init();
    if((TP->is_class("thief") || TP->is_class("bard")) && !TP->query_invis()){
      tell_object(TP,"Manuel seems to take your measure as you enter, and he surreptitiously makes the thief sign to you.");
    }
}