#include "std.h";
inherit OBJECT;

object spell;

create(){
    ::create();
    set_name("mass of web");
    set_id( ({ "mass", "web", "mass of web", "web mass",
        "webmass"}) );
    set_short("A mass of web");
    set("long", "This is a huge mass of web.  It seems that far "+
        "within it, you can hear something trying to get out.  You "+
        "can <break web> to help whatever is inside.\n");
    set_weight(450);
}

init()
{
    ::init();
    add_action("breaking","break");
}

void set_spell(object ob)
{
    spell=ob;
    return 1;
}

void breaking(string str)
{
    if(str != "web")
    {
        notify_fail("What?\n");
        return 0;
    }
    tell_object(TP,"You claw at the surface of the web mass.");
    tell_room(environment(TP),TPQCN+" claws at the surface of "+
        "the web mass.", TP);
    TP->set_paralyzed(7,"You are busy ripping through the web "+
        "mass!");
    call_out("webbreak", 7, TP);
    return 1;
}

void webbreak(object clawer)
{
    if(!clawer)
        return 1;
    clawer->set_paralyzed(0,"You are clearing away the torn web!");
    if(!present(clawer, environment(TO)))
        return 1;
    if(spell)
        spell->helped();
    return 1;
}
