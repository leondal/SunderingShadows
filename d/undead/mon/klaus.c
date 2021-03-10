#include <std.h>
#include "../undead.h"
inherit NPC;

void create(){
   ::create();
   set_nwp("riding",10);
   set_name("klaus");
   set_id(({"klaus","shop keeper","shopkeeper","genasi"}) );
   set_short("Klaus, a rangy half-elf man");
   set_long("%^RESET%^%^CYAN%^Klaus is rangy and rugged-looking, with a "
"mess of %^YELLOW%^straw-colored hair %^RESET%^%^CYAN%^covering half of his "
"face.  He seems a little %^ORANGE%^awkward %^CYAN%^and out-of-place in "
"town here, as if there is somewhere he would rather be.  But when it comes "
"to his horses he seems right at home, talking to them as if he would a "
"real person.%^RESET%^");
   set_gender("male");
   set_alignment(7);
   set_race("half-elf");
   set_body_type("human");
   set_class("ranger");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
}
