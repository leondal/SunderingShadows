#include <std.h>
#include <magic.h>
#include <rooms.h>
#include "../inherits/area_stuff.h"

#define ALPHA ({"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t",\
                "u", "v", "w", "x", "y", "z"})

#define NUMA ({1, 2, 3, 4, 5, 6, 7, 8, 9, 0})

inherit OBJECT;

int has_tent, filth;
string UNIQ_ID;

void set_my_tent(string str) { UNIQ_ID = str; }
string query_my_tent() { return UNIQ_ID; }

void set_filth(int x) { filth = x; }
int query_filth() { return filth; }

int filter_tents(object ob, string MYID)
{
    if(!objectp(ob)) return 0;
    if(!ob->is_tent()) return 0;
    if((string)ob->query_my_tent() == MYID) return 1;
    return 0;
}

void generate_unique_tent()
{
    int let, num, amt, tlet;
    string temp = "";
    let = 10 + random(11);
    num = 10 + random(11);
    amt = let+num;
    while(amt--)
    {
        if(random(2))
        {
            if(num)
            {
                temp += NUMA[random(sizeof(NUMA))];
                num--;
                continue;
            }
            else
            {
                tlet = ALPHA[random(sizeof(ALPHA))];
                if(random(2)) tlet = capitalize(tlet);
                temp += tlet;
                let--;
                continue;
            }
        }
        else
        {
            if(let)
            {
                tlet = ALPHA[random(sizeof(ALPHA))];
                if(random(2)) tlet = capitalize(tlet);
                temp += tlet;
                let--;
                continue;
            }
            else
            {
                temp += NUMA[random(sizeof(NUMA))];
                num--;
                continue;
            }
        }
    }
    set_my_tent(temp);
    return;
}

string longdesc()
{
    string ret;
    ret = "%^RESET%^%^GREEN%^This large bag is made from a very "+
    "%^BOLD%^thick fabric%^RESET%^%^GREEN%^. It is approximately three "+
    "feet long, two feet wide, and covered with a %^BOLD%^%^BLACK%^"+
    "thick malleable substance%^RESET%^%^GREEN%^ in order to make it "+
    "more resistant to the elements.";

    if(has_tent)
    {
        ret += " It currently has a tent within it that you can "+
        "%^BOLD%^%^WHITE%^pitch%^RESET%^%^GREEN%^ somewhere, should "+
        "you decide that you need a shelter.%^RESET%^";
    }
    else
    {
        ret += " It currently has no tent within it. If you can "+
        "remember where you left your tent you could easily %^BOLD%^%^WHITE%^"+
        "bag%^RESET%^%^GREEN%^ it back up to use somewhere else.%^RESET%^";
    }
    return ret;
}

void create()
{
    ::create();
    generate_unique_tent();
    set_name("a tent bag");
    set_id( ({ "tent", "tent bag", "bag containing tent", "bag" }) );
    set_short("%^RESET%^%^GREEN%^A tent bag%^RESET%^");
    has_tent = 1;
    set_long((:TO, "longdesc":));
    set_value(5000);
    set_weight(10);
    set_lore("%^RESET%^%^GREEN%^These bags and the tents that they contain "+
    "were created by one of the wizards at "+
    "the Mizat Encampment, in order to provide a quick and easy means for shelter "+
    "as the encampment expanded. Recognizing that eventually the "+
    "group would move on he coated them with a thick malleable substance that "+
    "would allow for them to withstand almost any environment.%^RESET%^");
    set_property("lore difficulty", 12);
}

void init()
{
    ::init();
    add_action("pitch_func", "pitch");
    add_action("bag_func", "bag");
}

int bag_func(string str)
{
    object *inv;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!stringp(str)) return 0;
    if(str != "tent" && str != "my tent") return 0;
    if(has_tent)
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^The tent bag already contains a tent.%^RESET%^");
        return 1;
    }
    inv = filter_array(all_inventory(EETO), "filter_tents", TO, UNIQ_ID);
    if(!sizeof(inv))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^Your tent isn't here.%^RESET%^");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You are too busy to have time to bag the tent right now!%^RESET%^");
        return 1;
    }

    tell_room(EETO, ETOQCN+"%^RESET%^%^GREEN%^ starts bagging up the tent here.%^RESET%^", ETO);
    tell_object(ETO, "%^RESET%^%^GREEN%^You begin to bag the tent!%^RESET%^");
    ETO->set_paralyzed(24, "%^RESET%^%^GREEN%^You are busy bagging the tent!%^RESET%^");
	call_out("bag_started", 12);
    return 1;
}

int bag_started() {
    object *inv;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(has_tent)
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^The tent bag already contains a tent.%^RESET%^");
        return 1;
    }
    inv = filter_array(all_inventory(EETO), "filter_tents", TO, UNIQ_ID);
    if(!sizeof(inv))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^Your tent isn't here.%^RESET%^");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You are too busy to have time to bag the tent right now!%^RESET%^");
        return 1;
    }

    if(inv[0]->take_down_tent(ETO, TO))
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^You finish bagging up your tent!%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^ finishes bagging up "+ETO->QP+" tent!%^RESET%^", ETO);
        has_tent = 1;
        inv[0]->remove();
        return 1;
    }
    return 1;
}

int pitch_func(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!stringp(str)) return 0;
    if(str != "tent" && str != "my tent") return 0;
    if(!has_tent)
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^The tent bag is currently empty.%^RESET%^");
        return 1;
    }
    if(EETO->query_property("no pocket space") || clonep(EETO) || !EETO->is_room() || EETO->is_tent())
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You can't seem to figure out how to set the "+
        "tent up here.");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You are too busy to have time to pitch the tent right now!%^RESET%^");
        return 1;
    }

    tell_object(ETO, "%^RESET%^%^GREEN%^You begin to pitch the tent.%^RESET%^");
    tell_room(EETO, ETOQCN+"%^RESET%^%^GREEN%^ begins pitching a tent here.%^RESET%^", ETO);
    ETO->set_paralyzed(24, "%^RESET%^%^GREEN%^You are busy pitching the tent!%^RESET%^");
	call_out("pitch_started", 12);
    return 1;
}

int pitch_started() {
    object myRoom;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!has_tent)
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^The tent bag is currently empty.%^RESET%^");
        return 1;
    }
    if(EETO->query_property("no pocket space") || clonep(EETO) || !EETO->is_room() || EETO->is_tent())
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You can't seem to figure out how to set the "+
        "tent up here.");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "%^RESET%^%^GREEN%^You are too busy to have time to pitch the tent right now!%^RESET%^");
        return 1;
    }

    myRoom = new(MOB+"tent_room");
    if(myRoom->init_tent(TO, EETO))
    {
        tell_object(ETO, "%^BOLD%^%^MAGENTA%^You finish pitching the tent here!%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^MAGENTA%^ finishes pitching "+ETO->QP+" tent here!%^RESET%^", ETO);
        has_tent = 0;
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^BLACK%^You can't seem to figure out how to set the tent up here!%^RESET%^");
    myRoom->remove();
    return 1;
}
