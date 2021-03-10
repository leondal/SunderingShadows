#include <std.h>

inherit "/std/monster.c";

void create() 
{
    ::create();
    set_name("Test Dummy");
    set_id(({"dummy", "test dummy", "testdummy", "practice dummy"}));
    set_race("test dummy");
    set_skill("perception",10000);
    set_body_type("human");
    set_short("practice dummy");
    set_long("This is a rugged practice dummy shaped "
        "in the rough dimensions of a man and covered "
        "with an old red shirt and black pants.  It seems to "
        "be stuffed with leather and looks to have seen "
        "a great deal of use.");
    set_hd(1,1);
    set_level(1);
    set_class("fighter");
    set_mlevel("fighter", 1);
    set_hp(10000000);
    set_exp(1);
    set_overall_ac(9);
}
