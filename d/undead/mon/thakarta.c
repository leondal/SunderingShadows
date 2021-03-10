#include <std.h>
#include "../undead.h"
inherit VENDOR;

void create(){
   ::create();
   set_nwp("armorsmithing",12);
   set_name("thakarta");
   set_id(({"thakarta","shop keeper","shopkeeper","smith"}) );
   set_short("Thakarta, half-ogrish smith");
   set_long("%^RESET%^%^CYAN%^Thakarta could be mistaken for a massive human "
"from behind, but from the front his mixed heritage is obvious.  Easily more "
"than seven feet tall, he towers above the customers that occasionally come "
"past, though he pays them no heed unless spoken to.  He has features that are "
"%^BLUE%^brutish %^CYAN%^and %^RED%^rough%^CYAN%^, though discernably human, "
"and his skin has a slight dull shade of %^ORANGE%^brown %^CYAN%^to it.  He is "
"constantly at work except when interrupted, constructing or repairing various "
"pieces of armor.%^RESET%^\nTo get a list of shop commands, type help shop.");
   set_gender("male");
   set_alignment(6);
   set_race("half-ogre");
   set_body_type("human");
   set_class("fighter");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set_storage_room(INH"smith_storage");
   set_items_allowed("armor");
   set_mymaxvalue(16);
}
