#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "south" : MROOMS"hidden20",       
       //"south" : MROOMS"hidden10",
    ] ));        
    set_crack_destination("tomb2_9");
    set_cracked_wall("north");
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ A large %^BOLD%^%^WHITE%^"+
    "crack%^BOLD%^%^BLACK%^ extends almost the entire length of the "+TO->query_cracked_wall()+
    "ern wall. The tunnel continues toward the south.%^RESET%^");
    add_item(({"crack", "cracks"}), (:TO, "crack_description":));
}
