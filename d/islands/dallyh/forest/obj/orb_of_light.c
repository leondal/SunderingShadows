#include <std.h>
#include <daemons.h>
#include "../../fways.h"
inherit OBJECT;

void create() 
{
    ::create();
    set_name("a brilliant orb of light");
    set_value(0);
    set_weight(10000);
    
    set_id(({"light", "orb of light", "brilliant orb of light", "dallyhorboflightsaide", "orb"}));
    set_property("no animate", 1);

    set_short("%^BOLD%^%^WHITE%^A br%^BOLD%^%^YELLOW%^i%^BOLD%^%^MAGENTA%^ll%^BOLD%^%^YELLOW%^"+
    "ia%^BOLD%^%^WHITE%^nt %^BOLD%^%^YELLOW%^o%^BOLD%^%^WHITE%^rb %^BOLD%^%^YELLOW%^o"+
    "%^BOLD%^%^WHITE%^f l%^BOLD%^%^YELLOW%^i%^BOLD%^%^MAGENTA%^gh%^BOLD%^%^WHITE%^t%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^You gaze upon this brilliant orb of light and are unable "+
    "to discern any real form. It just explodes outward continually from a point of origin that seems "+
    "to constantly shift and move about chaotically. A feeling of peace almost overwhelms you. "+
    "You are suddenly relaxed and all of the worries that you carry with you seem to fade away. "+
    "Something seems off though, as if what you are looking at is not contained within the orb but is "+
    "somehow all around you in this forest. For a very brief moment you think that you are looking at the "+
    "very soul of the forest, but you are not sure if this is just your mind playing tricks on you or "+
    "something else entirely.%^RESET%^");

    call_out("check_room", 12);    
}

void check_room()
{
    object *vics, ob;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = all_living(ETO);
    if(!sizeof(vics)) 
    {
        call_out("check_room", 12);
        return;
    }
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(vics[x]->query_true_invis()) continue;
        if(vics[x]->query_property("dallyh_informed")) continue;
        if(present("dallyhinfoobj", vics[x])) continue;
        tell_object(vics[x], "%^BOLD%^%^WHITE%^A power washes over you, threatening "+
        "to consume your very essence.... your mind goes %^BOLD%^%^RED%^BLANK%^BOLD%^%^WHITE%^"+
        " for a moment..... before you feel a peaceful presence enter it!");
        ob = new(FOPATH"dallyhinfoobj");
        ob->move(vics[x]);
        ob->inform_me(vics[x]);
        vics[x]->set_property("dallyh_informed", 1);
        continue;
    }
    call_out("check_room", 12);
    return;
}

int get() { return 0; }

void init()
{
    ::init();
    return check_room();
}

