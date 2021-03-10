#include <std.h>

inherit ARMOUR;

#define COLORS ({"%^BOLD%^%^BLACK%^inky black",\
"%^RESET%^d%^BOLD%^%^BLACK%^u%^RESET%^s%^BOLD%^%^BLACK%^k%^RESET%^y %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^a%^RESET%^y%^BOLD%^%^BLACK%^",\
"%^RESET%^%^ORANGE%^natural tan",\
"%^BOLD%^%^WHITE%^brilliant white",\
"%^RESET%^%^GREEN%^forest green",\
"%^RESET%^%^ORANGE%^deep brown"})

void create(){
    string COLOR;
    ::create();
    COLOR = COLORS[random(sizeof(COLORS))];
    set_name("gloves");
    set_id(({"gloves","gauntlets","glove","gauntlet","leather gloves",""+COLOR+" leather gloves%^RESET%^"}));
    set_short(""+COLOR+" leather gloves%^RESET%^");
    set_long("These gloves are made from heavy leather dyed "+COLOR+" "+
       "%^RESET%^and are designed to protect your hands.  Wonderfully, "+
       "they also have a %^ORANGE%^fur lining%^RESET%^ and actually "+
       "keep your hands very warm.");
    set_type("clothing");
    set_limbs(({"right hand","left hand"}));
    set_weight(1);
    set_value(20+random(11));
}
