#include <std.h>

inherit "/d/common/obj/jewelry/ring";

void create()
{
    ::create();
    set_name("ring");
    set_id(({"ring","ring of blackness", "dark ring", "thin ring"}));
    set_obvious_short("thin metal band");
    set_short("%^BOLD%^%^BLACK%^R%^WHITE%^i%^BLACK%^"+
    "ng of Bl%^WHITE%^a%^BLACK%^ckn%^WHITE%^e%^BLACK%^ss%^RESET%^");
    
    set_long("%^BOLD%^%^BLACK%^This ring is nothing more than a tiny "+
    "thin loop of dull, dark metal. Upon closer inspection you realize that "+
    "the metal is actually strands of w%^WHITE%^i%^BLACK%^re that have been "+
    "twisted together. Some process has been used to ensure that the strands of "+
    "wire remain together and you believe that something has been done to them "+
    "to make them sturdier than what they should be. There are no markings, symbols, "+
    "runes, or words on the ring that you can determine. It seems quite mundane.%^RESET%^");
    
    set_property("lore difficulty", 15);
    set_lore("%^BOLD%^%^BLACK%^These rings are simply known as rings of blackness. "+
    "The original purpose of them has been lost with the passage of time, but there is "+
    "something ominous about their history. Some rumors suggest that these trinkets were "+
    "given to some of those closest to Aorus Devar in order to seduce them with "+
    "potential power, so that they might betray him. It is said that a few of his "+
    "closest allies grew mad with the potential for power that the rings conveyed. "+
    "Some say that the rings served as a key to allow those who would strike against "+
    "Aorus Devar passage to Deku after he warded the Island. It is not known how much "+
    "truth there is to any of these rumors.%^RESET%^");
    
    set_value(500);    
    set_wear("You feel an almost intoxicating power wash over you.\n");
    set_remove("You feel almost empty as you remove the ring.\n");
}
