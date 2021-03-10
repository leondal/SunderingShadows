#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;

int opened, lever1, lever2, lever3, lever4;

string ret, *levers;

void create() 
{
    ::create();   
    set_exits(([
       "southwest" : MROOMS"hidden3",
    ] ));    
    ret = (string)TO->query_long();
    set_long((:TO, "get_my_long":));   
    opened = 0;
    lever1 = 0;
    lever2 = 0;
    lever3 = 0;
    lever4 = 0;
    levers = ({});
    add_item(({"holes", "hole"}), (:TO, "hole_description":));
}

mixed hole_description()
{
    if(opened) return 0;
    if(lever1 && lever2 && lever3)
    {
        return "%^BOLD%^%^WHITE%^There is one hole here. It is to the right "+
        "of the strange mural and beneath a lever which has been pushed "+
        "against the wall. You realize that there is a %^RESET%^%^ORANGE%^"+
        "mechanical%^BOLD%^%^WHITE%^ attachment inside the hole. You "+
        "think that if you had a lever that would fit, you could "+
        "attach it.%^RESET%^";
    }
    if(lever1 && lever2)
    {
        return "%^BOLD%^%^WHITE%^There are two holes here. They are "+
        "both to the right of the strange mural. You realize that there is "+
        "mechanical%^BOLD%^%^WHITE%^ attachment inside both of them. You "+
        "think that if you had a lever that would fit either, you could "+
        "attach it.%^RESET%^";
    }
    if(lever1)
    {
        return "%^BOLD%^%^WHITE%^There are three holes here. Two of them "+
        "are to the right of the strange mural. The other one is to "+
        "the left of the strange mural and above a lever which has "+
        "been pressed against the wall. You realize that there is "+
        "mechanical%^BOLD%^%^WHITE%^ attachment inside all of them. You "+
        "think that if you had a lever that would fit any, you could "+
        "attach it.%^RESET%^";
    }
    return "%^BOLD%^%^WHITE%^There are four holes here. Two of them "+
    "are to the right of the strange mural. The other two are to "+
    "the left of the strange mural. You realize that there is "+
    "mechanical%^BOLD%^%^WHITE%^ attachment inside all of them. You "+
    "think that if you had a lever that would fit any, you could "+
    "attach it.%^RESET%^";
}

string lever_description()
{
    string str = "";
    if(lever1 && lever2 && lever3)
    {
        str += " There are two levers to the left of the mural that "+
        "are pressed against the wall. There is one lever to the right of "+
        "the mural that is pressed against the wall. Beneath the lever "+
        "to the right of the mural is a hole.";
    }
    else if(lever1 && lever2)
    {
        str += " There are two levers to the left of the mural that "+
        "are pressed against the wall. There are two holes to the "+
        "right of the mural.";
    }
    else if(lever1)
    {
        str += " There is one lever to the left of the mural that is "+
        "pressed against the wall. There is a hole above the lever to "+
        "the left of the mural. There are two holes to the right of the "+
        "mural.";
    }
    return str;    
}

string get_my_long()
{
    string str;
    str = ret;
    str += "%^BOLD%^%^BLACK%^ The tunnel continues southwest.";
    if(opened)
    {
        str += "%^BOLD%^%^BLACK%^ The outline of a strange "+
        "%^BOLD%^%^MAGENTA%^m%^RESET%^%^CYAN%^u%^BOLD%^%^MAGENTA%^"+
        "r%^RESET%^%^CYAN%^a%^BOLD%^%^MAGENTA%^l %^BOLD%^%^BLACK%^"+
        "is visible around an opening in the "+
        "north wall. There are two levers on either "+
        "side of it, all of them pushed against the wall.%^RESET%^";
    }
    else
    {
        str += "%^BOLD%^%^BLACK%^ A strange "+
        "%^BOLD%^%^MAGENTA%^m%^RESET%^%^CYAN%^u%^BOLD%^%^MAGENTA%^"+
        "r%^RESET%^%^CYAN%^a%^BOLD%^%^MAGENTA%^l %^BOLD%^%^BLACK%^"+
        "is visible on the north wall. It depicts an elaborate "+
        "door.";
    
        if(lever1 && lever2 && lever3)
        {
            str += " There are two levers to the left of the mural that "+
            "are pressed against the wall. There is one lever to the right of "+
            "the mural that is pressed against the wall. Beneath the lever "+
            "to the right of the mural is a hole.";
        }
        else if(lever1 && lever2)
        {
            str += " There are two levers to the left of the mural that "+
            "are pressed against the wall. There are two holes to the "+
            "right of the mural.";
        }
        else if(lever1)
        {
            str += " There is one lever to the left of the mural that is "+
            "pressed against the wall. There is a hole above the lever to "+
            "the left of the mural. There are two holes to the right of the "+
            "mural.";
        }
        else str += " There are two holes on the left and two holes on the "+
        "right side of the mural.%^RESET%^";
    }
    return str;    
}

void init()
{
    ::init();
    add_action("attach", "attach");
}

int attach(string str)
{
    object myLev;
    string levType;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(opened) return 0;
    if(!objectp(myLev = present(str, TP)))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You do not have a "+str+".");
        return 1;
    }
    if(!stringp(levType = myLev->query_lever_type()))
    {
        tell_object(TP, "%^BOLD%^%^GREEN%^That does not fit here.%^RESET%^");
        return 1;
    }
    if(member_array(levType, levers) != -1)
    {
        tell_object(TP, "%^BOLD%^%^RED%^That lever is already attached here.%^RESET%^");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^RED%^You quickly attach the "+myLev->query_short()+ 
    "%^BOLD%^%^RED%^ to one of the holes and it spins around quickly before pressing against the "+
    "wall!%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ quickly attaches the "+myLev->query_short()+
    "%^BOLD%^%^RED%^ to one of the holes and it spins around quickly before pressing against the "+
    "wall!%^RESET%^", TP);
    levers += ({levType});
    add_item(({"levers"}), (:TO, "lever_description":));
    if(sizeof(levers) == 4) { remove_item(({"holes", "hole"})); opened = 1; }
    if(!lever1) lever1 = 1;
    else if(!lever2) lever2 = 1;
    else if(!lever3) lever3 = 1;
    else if(!lever4) lever4 = 1;
    if(objectp(myLev)) myLev->remove();
    if(opened)
    {
        tell_room(TO, "%^BOLD%^%^MAGENTA%^The mural shimmers and the inside of it "+
        "fades away, revealing an opening on the north wall!%^RESET%^");
        add_exit(MROOMS"hidden5", "north");
    }
    return 1;
}