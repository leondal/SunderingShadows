#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_nwp("healing",8);
   set_name("taalaar");
   set_id(({"taalaar","healer"}));
   set_short("Taalaar, goblin herbalist");
   set_long("This little creature is every bit as grimy as the rest in the cavern, despite his rumoured "
"knowledge of herbalism.  His black hair is thin and slick, and he has nimble fingers and little dirty "
"fangs.  He has an intelligent, but rather greedy shine to his eye, obviously more interested in the coins "
"his customers bring than their ailments.  But apparently he's the best they have in this place, if you're "
"daring enough to buy his wares.");
   set_alignment(9);
   set_race("goblin");
   set_class("thief");
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_gender("male");
   set_spoken("undercommon");
}
