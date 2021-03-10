#include <std.h>
#include "../arctic.h"
#include "../cracks.h"

inherit CROOM;

void check_ice();
void thin_ice();
int fall_through();
void freeze();

string *str,*item,dir,verb,where,hold,tmp;
int cracked;

void create()
{

    ::create();
    set_name("Frozen Lake");
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
    set_property("light",3);
    set_climate("arctic");

    set_short("%^BOLD%^A fr%^RESET%^o%^CYAN%^ze%^RESET%^%^BOLD%^n lake%^RESET%^");
    
    set_long("%^CYAN%^Soaring rock walls surround this small "
             "lake on all sides.  The path to the nortwest, "
             "and another, larger opening farther to the south "
             "seem to be the only breaks in the sheer "
             "%^RESET%^%^BOLD%^granite%^RESET%^%^CYAN%^ "
             "around you.  The smooth "
             "%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^e%^RESET%^%^CYAN%^ "
             "of the lake surface is covered with a thin layer "
             "of %^RESET%^snow%^CYAN%^, the calm wind not "
             "having enough strength here to clear it away.");

    
    set_items(([ 
                ({"walls","wall","granite"}) : "%^BOLD%^The towering "
                "i%^CYAN%^%^RESET%^c%^BOLD%^ic%^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^e "
                "covered walls stretch far above.%^RESET%^",
                ({"icicle","icicles"}) : "%^CYAN%^The %^RESET%^%^BOLD%^"
                "i%^CYAN%^%^RESET%^c%^BOLD%^ic%^RESET%^%^CYAN%^l%^RESET%^%^BOLD%^es "
                "%^CYAN%^range in size from no bigger than a finger, to hundreds of "
                "feet in length.",
                "path" : "%^BOLD%^The path in the northwest disappears "
                "behind a spire of rock on its way back towards the drow "
                "cave roads.%^RESET%^",
                "opening" : "%^BOLD%^A wide break in the rock walls to "
                "the south allows the %^RESET%^fr%^CYAN%^o%^RESET%^zen%^BOLD%^ "
                "river to flow away down the mountain ",
                "snow" : "White powdery snow covers the ice of the lake, "
                "cushioning your footfalls.",
                "ice" : "%^CYAN%^The smooth "
                "%^RESET%^%^BOLD%^i%^CYAN%^c%^RESET%^%^BOLD%^e%^RESET%^%^CYAN%^ "
                "is of the lake looks safe to walk on."
             ]));

    //this exit prevents bad index error from thin_ice()
    set_exits(([
        "out"   : LAKE"road1",
             ]));

    set_smell("default", "The cold air smells crisp and very clean.");
    set_listen("default", "Occasional groans and pops can be heard "
                          "from the ice.");

}


void check_ice()
{
    if(!random(5))
    {
        thin_ice();
        cracked = 1;
        return;
    }
    return;
}

void thin_ice()
{
    if(cracked == 1) return;

    str = (string *)TO->query_exits();  
    dir = str[random(sizeof(str))];
    hold = TO->query_long();
    tmp = hold;
    set_pre_exit_functions(({dir}),({"fall_through"}));
    hold += "\nThere are cracks in the ice to the "+dir+".";
    add_item("cracks" , "The cracks in the ice make it look "
        "very unstable.  Walking over them will probably "
        "break the ice");
    TO->set_long(hold);
    return;
}

int fall_through()
{
    verb = query_verb();
    where = CRACKS[base_name(TO)];
    
    if(TP->id("arcticmon"))
    {
        tell_room(TO,"%^BOLD%^%^GREEN%^The arctic creature skillfully "
            "navigates the dangerous ice to the "+verb+".%^RESET%^",TP);
        return 1;
    }

    tell_object(TP,"%^BOLD%^%^GREEN%^The ice breaks as you walk "+verb+" and "
        "you plunge down into the frigid water!%^RESET%^");
    tell_room(TO,"%^BOLD%^%^GREEN%^As "+TPQCN+" walks "+verb+" the ice breaks "
        "open underneath "+TP->QP+" and "+TP->QS+" plunges "
        "into the frigid water!%^RESET%^",TP);
    TP->move_player(where);
    return 0;

}

void freeze()
{
    if(query_pre_exit_function(dir))
    {
        remove_pre_exit_function(dir);
        set_long(tmp);
        cracked = 0;
    }
//    item = keys(query_items());
//    if(member_array("cracks", item)) remove_item("cracks");
//    item = keys(query_items());
    remove_item("cracks");
    return;
}

void reset()
{
    ::reset();
    if(!random(3) && cracked == 1) freeze();
    return;
}



