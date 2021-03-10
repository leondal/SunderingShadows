#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_name("girdle");
    set_id(({"girdle","Lace girdle","lace girdle"}));
    set_short("Lace girdle");
    set_long("This girdle is to be worn to make one's form more "+
       "pleasing.  It is made of the finest red lace, crafted by "+
       "the weavers of Seneca.  The stitching is reinforced for "+
       "strength and durability.  When wearing this girdle, the "+
       "wearer feels very comfortable yet protected to a great extent.");
    set_type("clothing");
    set_limbs(({"torso"}));
    set_weight(1);
    set_value(3);
}
