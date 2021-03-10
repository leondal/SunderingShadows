#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();
   
    set_exits(([
       "northeast" : MROOMS"hidden2",       
    ] ));    
    set_crack_destination("tomb1_3");
    set_cracked_wall("west");
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ A large %^BOLD%^%^WHITE%^"+
    "crack%^BOLD%^%^BLACK%^ extends almost the entire length of the "+TO->query_cracked_wall()+
    "ern wall. The tunnel continues toward the northeast.%^RESET%^");
    add_item(({"crack", "cracks"}), (:TO, "crack_description":));
}
