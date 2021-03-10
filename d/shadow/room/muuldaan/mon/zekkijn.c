#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

void create(){
   ::create();
   set_name("zekkijn");
   set_id(({"zekkijn","shop keeper","collector","bugbear collector","shopkeeper"}) );
   set_short("Zekkijn, bugbear collector");
   set_long("Zekkijn looks like an extremely large, seven-foot-tall version of a goblin, with the same "
"yellow-brown skin and sharp fangs.  His hair is a shade of dirty brown, and watery greenish-white eyes, "
"much as most other bugbears.  He has triangular, highset ears and a sturdy frame.  He keeps a constant "
"vigilant watch on the piles of trash around him, guarding them jealously from the creatures scurrying "
"past.\nTo get a list of shop commands, type%^YELLOW%^ help shop%^RESET%^.");
   set_gender("male");
   set_alignment(9);
   set_race("bugbear");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(500);
   set_hp(500);
   set_storage_room(INH"general");
   set_items_allowed("misc");
   set_spoken("undercommon");
}
