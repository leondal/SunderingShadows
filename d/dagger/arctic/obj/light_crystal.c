#include <std.h>
#include "../arctic.h"
inherit OBJECT;

object who;
object obj;

void create() 
{
    ::create();
    set_id( ({ "crystal","small crystal","light crystal", "small yellow crystal"}) );
    set_name("Light Crystal");
    set_short("%^RESET%^%^BOLD%^a small g%^RESET%^%^YELLOW%^lo%^RESET%^%^BOLD%^wi%^RESET%^n%^BOLD%^g cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^");
   
    set_long("%^RESET%^%^BOLD%^This is a small "
        "cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^%^BOLD%^ "
        "not much larger than a gold piece.  It is naturally formed into "
        "an elongated octagonal shape which comes to a point at each end.  "
        "The %^RESET%^clear%^BOLD%^ crystal "
        "has a mysterious %^RESET%^%^YELLOW%^yellow "
        "%^RESET%^%^BOLD%^g%^RESET%^%^YELLOW%^lo%^RESET%^%^BOLD%^w coming from inside.%^RESET%^");

    set_weight(1);
    set("value", 500);

    set_heart_beat(1);
}

int move(mixed dest) 
{
    int x;

    if (objectp(ETO)) 
        ETO->set_property("light", -2);
        who = 0;
    
    x = ::move(dest);

    if (objectp(ETO))
        ETO->set_property("light", 2);
   
    return x;
}

remove() 
{
    if (objectp(ETO))
        ETO->set_property("light",-2);
        who = 0;
    return ::remove();
}

void heart_beat()
{

    if(!objectp(ETO)) return;
    if(!living(ETO)) return;

    if(living(ETO) && ETO != who)
    {
        who = ETO;
        
        tell_room(environment(who), "%^BOLD%^The warm g%^RESET%^%^YELLOW%^lo%^RESET%^%^BOLD%^w "
            "of the cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^"
            "%^BOLD%^ held by "+who->query_cap_name()+" brightens the room%^RESET%^",who);
        tell_object(who, "%^BOLD%^The warm g%^RESET%^%^YELLOW%^lo%^RESET%^%^BOLD%^w "
            "of the cr%^RESET%^%^YELLOW%^ys%^RESET%^%^BOLD%^ta%^BLUE%^l%^RESET%^"
            "%^BOLD%^ brightens the room%^RESET%^");
    }

    if(!random(1000))
    {
        tell_room(ETO, "The crystal grows dull and lifeless.");
        set_heart_beat(0);
        obj = new(OBJ"clear_crystal");
        obj->move(ETO);
        remove();
        return;        
    }

    return;
}