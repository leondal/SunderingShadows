#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

void create()
{
    ::create();
    set_name("strange emerald stone");
    set_id(({ "stone", "emerald stone", "strange stone",
    "strange emerald stone", "emerald", "dreadhorn_xxx_guard"}));
    
    set_short("%^BOLD%^%^GREEN%^strange emerald stone%^RESET%^");    
    
    set_long("%^BOLD%^%^GREEN%^This strange emerald stone is almost "+
    "perfectly flat and only an inch or so thick. It seems hollow "+
    "on the inside. However, you can hear a liquid sloshing around inside "+
    "of it at even the slightest movement. You are not sure of the purpose "+
    "of the stone, but for a fleeting moment you realize that it could "+
    "function as a makeshift guard for a weapon, if one were desperate and "+
    "attempting to assemble one.%^RESET%^");
    
    set_lore("%^BOLD%^%^GREEN%^The original purpose of this stone has been "+
    "lost. Some legends suggest that it once served as means of protecting "+
    "priests of Lysara. Supposedly they were able to store a fraction of their "+
    "souls in the stone so that should they perish, the stone could be used "+
    "to bring them back to life. Now, however, it seems to contain a strange and "+
    "foul liquid, that is recognizable as deathblade poison. Someone has obviously "+
    "corrupted the original purpose of this, at least if the legends about its original "+
    "intentions are to be believed.%^RESET%^");
    
    set_property("lore difficulty", 20);
    
    set_weight(0);
    set_value(1);
}