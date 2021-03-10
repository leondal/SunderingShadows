#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

void create() 
{
    ::create();   
    set_exits(([
       "northwest" : MROOMS"hidden17",       
       //"south" : MROOMS"hidden10",
    ] ));        
    set_crack_destination("tomb4_7");
    set_cracked_wall("east");
    set_long((string)TO->query_long()+"%^BOLD%^%^BLACK%^ A large %^BOLD%^%^WHITE%^"+
    "crack%^BOLD%^%^BLACK%^ extends almost the entire length of the "+TO->query_cracked_wall()+
    "ern wall. The tunnel continues toward the northwest.%^RESET%^");
    add_item(({"crack", "cracks"}), (:TO, "crack_description":));
}
