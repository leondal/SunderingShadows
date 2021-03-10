#include <std.h>
#include "../defs.h"
inherit "/std/comp_vend";

void create(){
   ::create();
   set_name("uugaruf");
   set_short("Uugaruf, duergar merchant");
   set_id(({"uugaruf","Uugaruf","merchant","duergar merchant"}));
   set_long("This creature is perhaps a dwarf, though there are enough differences to make you look twice to "
"check.  Lean and tough where normally a dwarf would be massive, he has grayed skin and hair that mirror the "
"color of stone.  The hair does not cover his bald head, but frames his chin in a moustache and beard.  Dull "
"black eyes survey his small niche with a cheerless expression, in a face that never hints at any emotion "
"other than bitterness.  Judging by the myriad of crystals around him, though, you imagine he may sell you "
"some.");
   set_race("duergar");
   set_body_type("human");
   set_gender("male");
   set_class("psion");
   set_hd(25,1);
   set_max_hp(500);
   set_hp(500);
   set_spells(({"mind thrust","mind thrust","mind thrust","energy bolt","energy bolt"}));
   set_spell_chance(70);
   set_alignment(3);
   remove_std_db();
    set_shop_type("psion");
    set_components(100);
   set_spoken("undercommon");
}
