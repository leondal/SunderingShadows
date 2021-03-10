#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_nwp("healing mount",10);
   set_name("xyros");
   set_id(({"xyros","drow","stablemaster"}));
   set_short("%^RESET%^%^BLUE%^Xyros Archuul, stablemaster%^RESET%^");
   set_long("%^BLUE%^This rather short drow is clad only in %^ORANGE%^simple clothes%^BLUE%^, and from the "
"look of him is certainly not of an upper-class family.  Despite this, and his job of tending to the beasts "
"here, he still carries himself with the pride and arrogance of any other drow in the city.  His %^WHITE%^long "
"white hair%^BLUE%^ is bound back from his face with a simple leather tie, and his%^RED%^ crimson eyes%^BLUE%^ "
"glitter as he shouts commands to the slaves tending the beasts here.%^RESET%^");
   set_alignment(9);
   set_race("drow");
   set_class("fighter");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("male");
   set_property("no bow",1);
}
