#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;

mapping MyRooms;

void create()
{
    ::create();
    MyRooms = ([]);
    set_name("smooth hollow orb");
    set_id(({ "orb", "hollow orb", "orb of magical disruption",
    "smooth orb"}));

    set_short("%^BOLD%^%^CYAN%^O%^BOLD%^%^WHITE%^rb of "+
    "m%^BOLD%^%^CYAN%^a%^WHITE%^g%^CYAN%^i%^WHITE%^c%^CYAN%^"+
    "a%^WHITE%^l d%^CYAN%^i%^WHITE%^sr%^CYAN%^u%^WHITE%^pt"+
    "%^CYAN%^io%^WHITE%^n%^RESET%^");
    set_obvious_short("smooth hollow orb");

    set_long("%^BOLD%^%^WHITE%^This tiny orb is completely smooth. It appears "+
    "hollow as there is a %^BOLD%^%^CYAN%^hazy%^BOLD%^%^WHITE%^ looking "+
    "substance inside of it. You are unable to feel the substance moving around, however, "+
    "and believe it to be a gas or a fog, instead of liquid. Just holding the orb "+
    "you get an uneasy feeling, though you are not sure why. You "+
    "do not believe that it is fragile by any means, but strange "+
    "fl%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^sh%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^s "+
    "of light periodically emanate outward from the inside of it. Something "+
    "makes you think that you could use the orb to %^BOLD%^%^BLACK%^disrupt"+
    "%^BOLD%^%^WHITE%^ something, but you are not sure what that might mean.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^This object is known as an orb of "+
    "magical disruption. It was believed to be a thing of legend, a horror "+
    "story told to those who play with the arcane, or the divine, or even those "+
    "who are gifted with psionics.\n\nThis object allows whoever posseses it "+
    "to potentially %^BOLD%^%^BLACK%^disrupt%^BOLD%^%^WHITE%^ all magic cast in the area, "+
    "for a time. It is said that only time will reverse this affect or if the "+
    "orb is somehow destroyed. A powerful fog inside the orb is rumored to grant it "+
    "this power. The origins of the fog are entirely unknown as is how much might "+
    "remain inside such an object.%^RESET%^");

    set_property("lore difficulty", 35);

    set_weight(1);
    set_value(1000);
}

void init()
{
    ::init();
    add_action("disrupt", "disrupt");
}

int remove()
{
    mixed *Rooms;
    int x;
    Rooms = keys(MyRooms);
    for(x = 0;x < sizeof(Rooms);x++)
    {
        if(!objectp(Rooms[x])) continue;
        tell_room(Rooms[x], "%^BOLD%^%^CYAN%^An invisible force suddenly leaves the area!%^RESET%^");
        Rooms[x]->remove_property("wild magic");
        Rooms[x]->remove_property("wild magic affect");
        continue;
    }
    MyRooms = ([]);
    return ::remove();
}

void check_orb_rooms()
{
    mixed *Rooms;
    int x;
    Rooms = keys(MyRooms);
    if(!sizeof(Rooms)) return;
    for(x = 0;x < sizeof(Rooms);x++)
    {
        if(!objectp(Rooms[x]))
        {
            map_delete(MyRooms, Rooms[x]);
            continue;
        }
        if(time() > MyRooms[Rooms[x]]["ends at"])
        {
            tell_room(Rooms[x], "%^BOLD%^%^CYAN%^An invisible force suddenly leaves the area!%^RESET%^");
            Rooms[x]->remove_property("wild magic");
            Rooms[x]->remove_property("wild magic affect");
            map_delete(MyRooms, Rooms[x]);
            continue;
        }
    }
    if(sizeof(keys(MyRooms))) call_out("check_orb_rooms", 30);
    return;
}

int disrupt(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!EETO->is_room()) return 0;
    tell_object(ETO, "%^BOLD%^%^BLACK%^You carefully focus on the orb.....%^RESET%^");
    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ seems to be carefully focusing on a smooth hollow orb.%^RESET%^", ETO);
    if(EETO->query_property("wild magic"))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^Despite your efforts it appears that nothing happens...%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ stops focusing on the smooth hollow orb.", ETO);
        return 1;
    }
    //random complete failure...
    if(!random(50))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The orb suddenly shatters!%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s smooth hollow orb suddenly shatters!%^RESET%^", ETO);
        TO->remove();
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel an aura of power suddenly wash over the area around you "+
    "as something totally unseen settles here!%^RESET%^");
    tell_room(EETO, "%^BOLD%^%^CYAN%^Suddenly you feel an aura of power wash over the area.... and "+
    "you realize that something totally unseen settles here as "+ETOQCN+"%^BOLD%^%^CYAN%^ stops "+
    "focusing on the smooth hollow orb.%^RESET%^", ETO);
    EETO->set_property("wild magic", ((int)ETO->query_base_character_level()));
    EETO->set_property("wild magic affect", ({"random", "random level", 0}));
    MyRooms += ([EETO : (["ends at" : time() + 300 + random(300) + random(300)]),]);
   // MyRooms += ([EETO : (["ends at" : 1,]),]);
    call_out("check_orb_rooms", 30);
    return 1;
}

int isMagic() { return 5;}
