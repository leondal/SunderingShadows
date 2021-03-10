#include <std.h>

inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^BLACK%^inky black",\
"%^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^s%^BOLD%^%^BLACK%^k%^RESET%^y %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^",\
"%^RESET%^%^ORANGE%^natural tan",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^RESET%^%^GREEN%^forest green",\
"%^RESET%^%^ORANGE%^deep brown"})

string COLOR;

void create(){
    ::create();
    COLOR = COLORS[random(sizeof(COLORS))];
    set_name("riding boots");
    set_id(({"riding boots","boots","leather riding boots",""+COLOR+" riding boots%^RESET%^"}));
    set_short(""+COLOR+" riding boots%^RESET%^");
    set_long("These tall riding boots are made of thick leather dyed "+
       ""+COLOR+"%^RESET%^.  They are meant to allow the wearer more comfort "+
       "and control when riding a mount.  Each boot is fitted with a "+
       "thick, well-made sole and heel and equipped with a mithril "+
       "spur that seems always to remain untarnished.");
    set_type("clothing");
    set_limbs(({"right foot","left foot"}));
    set_weight(1);
    set_value(25+random(11));
}
