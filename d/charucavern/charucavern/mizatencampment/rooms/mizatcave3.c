#include <std.h>
#include "../inherits/area_stuff.h"
inherit MIZCAVE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^Directly to the east the cavern opens up into "+
    "what you belief to be an encampment. A %^BOLD%^%^RED%^metal sign%^BOLD%^%^WHITE%^ has been "+
    "attached to the wall as it opens up.%^RESET%^");
    
    set_exits((["east" : MROOMS +"mizat_encamp1", "west" : MROOMS +"mizatcave2" ]));	
    
    add_item(({"sign", "metal sign"}), ({"%^BOLD%^%^RED%^A message has been scrawled "+
    "into the center of the sign in a very elaborate writing style. Perhaps you should read "+
    "it.%^RESET%^", "%^BOLD%^%^WHITE%^Hello to all! If you have found your way this far down "+
    "then we welcome you to the Mizat Encampment! All are welcome here and there is no thought given "+
    "to drawn weapons. However, should you choose to use a weapon on any who call this place home, "+
    "our response will be swift. Be tolerant within our home and you are welcome but be otherwise and "+
    "turn back now.%^RESET%^", "wizish"}));
    
}
