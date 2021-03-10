#include <std.h>
inherit ARMOUR;

#define BREATH "/d/magic/obj/breathob.c"

int good,x;
int melted = 0;
string *cold,where;
object breath_obj;

void desc();
void is_good();

void create()
{
    ::create();
    is_good();
    set_id(({"ring","icy ring","coral ring","ring of water breathing"}));
    set_name("ring of water breathing");
    set_short("Ring of Water Breathing");
    desc();    
    set_type("ring");
    set_weight(1);
    set_value(2500);
    set_limbs(({"right hand"}));
    set_remove( (: TO,"rem_ring" :) );
    set_wear( (: TO,"wear_ring" :) );
    set_heart_beat(1);
}


void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(melted == 1)
    {
        set_heart_beat(0); 
        return;
    }

    where = EETO->query_name();

    cold = ({"The Bottom of the Lake",
             "Inside a shark's stomach",
             "Under the Lake"});

    x = member_array(where,cold);

    if(good == 0 && x == -1)
    {
        tell_object(ETO, "%^CYAN%^The ring melts away as "
            "you climb out of the icy waters of the lake.%^CYAN%^");
        tell_room(EETO, "%^CYAN%^The ice melts off of the ring held "
            "by "+ETO->QCN+".%^RESET%^",ETO);
        set_heart_beat(0);
        TO->remove();
        return;
    }

    if(x == -1)
    {
        tell_object(ETO, "%^CYAN%^The ice slowly melts off of the "
            "ring as you climb out of the icy waters of the "
            "lake.  The coral band begins to glow a bright "
            "light and the ring reshapes itself!%^RESET%^");
        tell_room(EETO, "%^CYAN%^The ice melts off of the ring held "
            "by "+ETO->QCN+" and it begings to glow!%^RESET%^",ETO);
        melted = 1;
        desc();
        set_heart_beat(0);
        return;
    }
    
}

void is_good() { if(!random(10)) good = 1; else good = 0; return; }

void desc()
{
    if(melted == 0)
    {
        set_long("%^CYAN%^This ring shaped circle of ice appears "
            "to be surrounding some type of white stone.  The "
            "ring looks naturally formed rather than the design of some "
            "craftsman.  The ice is not smooth, but lumpy and "
            "irregular, and the stone inside is not a perfect circle "
            "but rather oblong and rough.%^RESET%^");
        set_obvious_short("an icy ring");
        return;
    }

    set_long("%^BOLD%^The white coral of this ring has been bleeched "
        "to a pristine white color.  The ring is perfectly smooth "
        "and has no markings of any kind.  It looks like nothing "
        "more than a simple white band.%^RESET%^");
    set_obvious_short("a band of pure white");

}
   
int wear_ring()
{   
    ETO->set_property("water breather", 1);
    return 1;
}

int rem_ring()
{  
    ETO->set_property("water breather", -1);
    return 1;
}
