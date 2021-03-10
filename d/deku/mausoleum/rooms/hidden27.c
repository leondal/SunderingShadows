#include <std.h>
#include "../inherits/area_stuff.h"
inherit HID;
string ret;
int opened;
void create() 
{
    ::create();   
    set_exits(([
       "south" : MROOMS"hidden26",       
    ] ));    
    set_long((:TO, "get_my_long":));   
    add_items(({"indentation", "circular indentation"}), "%^RESET%^%^ORANGE%^"+
    "This small indentation catches your eye. It is directly in the center "+
    "of the northern wall. It is completely smooth and not all that deep but "+
    "it radiates with a faint magic. "+
    "You realize that if you had an object that would fit you could likely "+
    "insert it into the indentation.%^RESET%^");
    opened = 0;
}

string get_my_long()
{
    if(opened){
        return("%^BOLD%^%^BLACK%^You are within what you recognize instantly as "
           "an unfinished section of the '%^BOLD%^%^RED%^mausoleum of the damned"
           "%^BOLD%^%^BLACK%^'. There are portions of %^BOLD%^%^WHITE%^white stone"
           "%^BOLD%^%^BLACK%^ which attaches roughly with a much older %^RESET%^"
           "%^RED%^red stone%^BOLD%^%^BLACK%^. It appears that someone or "
           "something had started replacing the old stone at some distance point "
           "in the past before abruptly stopping. A %^RESET%^%^CYAN%^faint magic"
           "%^BOLD%^%^BLACK%^ radiates outward from the %^RESET%^%^RED%^red stone"
           "%^BOLD%^%^BLACK%^ providing a slightly disconcerting warmth. You are "
           "not sure what this place used to be, but there is an almost overwhelming "
           "sense of dr%^RESET%^%^RED%^ea%^BOLD%^%^BLACK%^d here. The walls are "
           "very close together and the floor is rough. Surprising though this portion of "
           "the mausoleum is withstanding the continous onslaught from the "
           "dirt above remarkably well. The tunnel continues to the north and south.%^RESET%^");
    }else{
        return("%^BOLD%^%^BLACK%^You are within what you recognize instantly as "
           "an unfinished section of the '%^BOLD%^%^RED%^mausoleum of the damned"
           "%^BOLD%^%^BLACK%^'. There are portions of %^BOLD%^%^WHITE%^white stone"
           "%^BOLD%^%^BLACK%^ which attaches roughly with a much older %^RESET%^"
           "%^RED%^red stone%^BOLD%^%^BLACK%^. It appears that someone or "
           "something had started replacing the old stone at some distance point "
           "in the past before abruptly stopping. A %^RESET%^%^CYAN%^faint magic"
           "%^BOLD%^%^BLACK%^ radiates outward from the %^RESET%^%^RED%^red stone"
           "%^BOLD%^%^BLACK%^ providing a slightly disconcerting warmth. You are "
           "not sure what this place used to be, but there is an almost overwhelming "
           "sense of dr%^RESET%^%^RED%^ea%^BOLD%^%^BLACK%^d here. The walls are "
           "very close together and the floor is rough. Surprising though this portion of "
           "the mausoleum is withstanding the continous onslaught from the "
           "dirt above remarkably well. The tunnel continues to the south. "
           "There is a %^RESET%^%^CYAN%^circular indentation%^BOLD%^%^BLACK%^ "
           "in the dead center of the northern wall.%^RESET%^");
   }
}

void init()
{
    ::init();
    add_action("insert_act", "insert");
}

void do_opening()
{
    if(!opened) return;
    tell_room(TO, "%^BOLD%^%^BLACK%^A section of the northern wall "+
    "shimmers and disappears!%^RESET%^");
    TO->set_long((:TO, "get_my_long":));
    add_exit(MROOMS"hidden28", "north");
    return;
}

int insert_act(string str)
{
    object Ob;
    string what;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(opened) return 0;
    if(!stringp(str))
    {
        tell_object(TP, "Try <insert ob into indentation>.");
        return 1;
    }
    if(sscanf(str, "%s into indentation", what) != 1)
    {
        tell_object(TP, "Try <insert ob into indentation>.");
        return 1;
    }
    if(!objectp(Ob = present(what, TP)))
    {
        tell_object(TP, "You have no "+what+"!");
        return 1;        
    }
    if(!Ob->id("mausoleum_of_the_damned_sphere_keyxxx71"))
    {
        tell_object(TP, "No matter how hard you try you "+
        "cannot get the "+what+" to fit into the indentation.");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^WHITE%^You insert the "+what+" into "+
    "the indentation... ");
    tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ inserts "+what+
    " into the indentation!", TP);
    Ob->remove();
    opened = 1;
    call_out("do_opening", 10);
    add_items(({"indentation", "circular indentation"}), "%^RESET%^%^ORANGE%^"+
    "This small indentation catches your eye. It is directly in the center "+
    "of the northern wall. It radiates with a faint magic. "+
    "There is a small hollow sphere inset into it.%^RESET%^");
    return 1;
}