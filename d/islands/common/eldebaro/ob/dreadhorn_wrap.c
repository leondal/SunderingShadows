#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

void create()
{
    ::create();
    set_name("piece of dingy cloth");
    set_id(({ "cloth", "dingy cloth", "piece of cloth",
    "piece of dingy cloth", "dreadhorn_xxx_wrap"}));
    
    set_short("%^RESET%^%^WHITE%^piece of dingy cloth%^RESET%^");    
    
    set_long("%^RESET%^%^WHITE%^This is a thick strip of dingy cloth. "+
    "You are unable to determine what type of fabric it is or even what "+
    "type of purpose it might serve. However, for a fleeting moment you "+
    "imagine that you could wrap it around something to create a sort of "+
    "makeshift grip.");
    
    set_weight(0);
    set_value(1);
}