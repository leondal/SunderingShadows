// Chernobog (12/3/20)
// Alternate thief tools

#include <std.h>
inherit OBJECT;

void create(){
    ::create();
    set_name("locksmith tools");
    set_id(({"tools","thief toolx","thief tools","lock picks","locksmith tools","picks"}));
    set_short("%^RESET%^%^MAGENTA%^A small %^BOLD%^%^BLACK%^leatherbound %^RESET%^"+
        "%^MAGENTA%^set of %^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^o%^RESET%^l%^BOLD%^"+
        "%^BLACK%^s%^RESET%^");
    set_long("%^RESET%^%^MAGENTA%^This is a small, soft leather case that can be rolled "+
        "and tied closed with leather thongs. The case, when fully opened, reveals rows "+
        "of pouches and slots filled with various skeleton keys, long metal picks and "+
        "pries, and it even has a small hammer with a metal wedge. These tools would aid "+
        "any locksmith. The leather case has been dyed a mottled black, and the tools "+
        "themselves have been crafted to be dark and matte, all the better to hide in "+
        "the shadows.\n\n%^RESET%^%^ORANGE%^The image of a lonely mountain partially "+
        "obscuring a full moon has been embossed on the front of the leather case."+
        "%^RESET%^");
    set_value(30);
    set_weight(1);
}

void break_picks(){
    TO->set_id(({"tools","broken tool","lock picks","picks"}));
    TO->set_short("A leather case of broken tools");
    TO->set_long("This soft leather case has many pouches that were once filled with "+
        "tools. Now, however, many of the tools are missing or broken, making this set "+
        "completely worthless for opening a stubborn lock.");
    TO->set_value(0);
    TO->set_property("broken",1);
}

