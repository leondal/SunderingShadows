#include <std.h>
#include "../defs.h"
inherit NPC;

void create() {
   ::create();
   set_name("ilivaere");
   set_id(({"ilivaere","priestess","mystery","deep mystery","mystery of bane","deep mystery of bane"}));
   set_short("%^RESET%^%^MAGENTA%^Ilivaere, Deep Mystery of Bane%^RESET%^");
   set_long("%^MAGENTA%^This drow priestess is clad as if she were about to go into battle. %^BOLD%^%^BLACK%^ "
"Jet-black chain armor%^RESET%^%^MAGENTA%^ encases her figure, and %^BLACK%^%^BOLD%^darkened gauntlets "
"%^RESET%^%^MAGENTA%^with sharpened fingertips cover each of her hands.  Her %^WHITE%^dull white hair "
"%^MAGENTA%^has been tied into numerous braids that fall about her face, framing angular drow features and her "
"%^RED%^blood-red eyes%^MAGENTA%^.  Of a perfectly identical hue is the cloak that covers her shoulders and "
"flows in rippling waves down her back.  She carries herself with a proud, regal bearing as befits her station "
"within the shrine of her god.%^RESET%^");
   set_alignment(3);
   set_race("drow");
   set_class("cleric");
   set_class("fighter");
   set_body_type("human");
   set_hd(25,1);
   set_max_hp(800);
   set_hp(800);
   set_gender("female");
   set_property("no bow",1);
}
