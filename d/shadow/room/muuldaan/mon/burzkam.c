#include <std.h>
#include "../defs.h"
inherit "/std/vendor";

void create(){
   ::create();
   set_nwp("weaponsmithing",8);
   set_nwp("armorsmithing",8);
   set_name("burzkam");
   set_id(({"burzkam","shop keeper","orc smith","orcish smith","shopkeeper","smith"}) );
   set_short("Burzkam, orcish smith");
   set_long("Burzkam is rather short for an orc, with a stooped forehead and flat snout common of his race.  "
"Beady orange-crimson eyes peer forth from his face, and a pair of tusks that jut more prominently past the "
"rest of his fangs.  His dull green skin is covered in coarse black hair, coating a body that is sheer bulk "
"and muscle, probably from the work he does here on weaponry and rough armor.  What he does manage to smith "
"seems a little lacking in quality, but it's probably the best you're going to find around here.\nTo get a "
"list of shop commands, type%^YELLOW%^ help shop%^RESET%^.");
   set_gender("male");
   set_alignment(9);
   set_race("orc");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(500);
   set_hp(500);
   set_storage_room(INH"smith");
   set_spoken("undercommon");
}
