#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include "area_stuff.h"

#define ELARL "eldebaroarsheevarunelocation"
#define ELARR "eldebaroarsheevaruneroom"
#define ELARD "eldebaroarsheevarunedelay"
#define ELARSLOC "eldebaroarsheevalocation"
#define RUNE_DELAY 14400
#define ROB ELOB+"arsheeva_runestone"

string *RUNE_LOCS = ({"the western oasis", "southwest eldebaro", "southeast eldebaro", "northeast eldebaro", "northwest eldebaro", "central eldebaro", "NIL", "dead"});
void place_arsheeva();

void clear_arrays(string which)
{
    if(!stringp(which) || which == "all")
    {
        SAVE_D->remove_array(ELARL);
        SAVE_D->remove_array(ELARR);
        SAVE_D->remove_array(ELARD);
        SAVE_D->remove_array(ELARSLOC);
    }
    if(which == "room")
    {
        SAVE_D->remove_array(ELARR);
    }
    if(which == "delay")
    {
        SAVE_D->remove_array(ELARD);
    }
    if(which == "loc")
    {
        SAVE_D->remove_array(ELARL);
    }
    if(which == "arsheeva")
    {
        SAVE_D->remove_array(ELARSLOC);
    }
}

string return_current_room(string current_loc)
{
    string current_room;
    int room_num;
    if(!stringp(current_loc)) return "ERROR";
    switch(current_loc)
    {
        case "the western oasis":
            current_room = (ELROOMSW + (random(15)+1));
            break;
        case "southwest eldebaro":
            if(random(2)) room_num = 30 + random(5);
            else room_num = 45 + random(5);
            break;
        case "southeast eldebaro":
            if(random(2)) room_num = 55 + random(5);
            else room_num = 40 + random(5);
            break;
        case "northeast eldebaro": 
            if(random(2)) room_num = 159 + random(6);
            else room_num = 174 + random(6);
            break;
        case "northwest eldebaro":
            if(random(2)) room_num = 165 + random(9);
            else room_num = 150 + random(9);
            break;
        case "central eldebaro":
            if(random(2)) room_num = 120 + random(15);
            else room_num = 105 + random(15);
            break;            
    }
    if(stringp(current_room)) return current_room;
    else return (ELROOMSD + room_num);
}

string get_current_location()
{
    string *saved_arr, current_location;
    int rune_delay;
    if(!pointerp(saved_arr = SAVE_D->query_array(ELARL)) || !sizeof(saved_arr))
    {
        current_location = RUNE_LOCS[0];
        clear_arrays("all");
        SAVE_D->set_value(ELARL, current_location);
    }
    else
    {
        current_location = saved_arr[0];
        if(current_location == RUNE_LOCS[0]) return current_location;
        if(pointerp(saved_arr = SAVE_D->query_array(ELARD)) && sizeof(saved_arr))
        {
            rune_delay = to_int(saved_arr[0]);
            if(time() > rune_delay)
            {
                current_location = RUNE_LOCS[0];
                clear_arrays("all");
                SAVE_D->set_value(ELARL, current_location);
            }
        }
        else
        {
            current_location = RUNE_LOCS[0];
            clear_arrays("all");
            SAVE_D->set_value(ELARL, current_location);
        }
    }
    if(member_array(current_location, RUNE_LOCS) == -1) 
    {
        current_location = RUNE_LOCS[0];
        clear_arrays("all");
        SAVE_D->set_value(ELARL, current_location);
    }
    return current_location;
}

string ar_desc()
{
    string current_location;
    int cur_place;
    current_location = get_current_location();
    if(current_location == "NIL" || current_location == "dead") return "";
    cur_place = member_array(current_location, RUNE_LOCS);
    if(!intp(cur_place) || cur_place == -1) return "";
    switch(cur_place)
    {
        case 0:            
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^In%^BOLD%^%^WHITE%^vu%^BOLD%^%^BLACK%^ln%^BOLD%^%^CYAN%^er%^BOLD%^%^RED%^ab%^BOLD%^%^YELLOW%^le%^BOLD%^%^WHITE%^)";
            break;
        case 1:
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^Invu%^BOLD%^%^BLACK%^ln%^BOLD%^%^CYAN%^er%^BOLD%^%^RED%^ab%^BOLD%^%^YELLOW%^le%^BOLD%^%^WHITE%^)";
            break;
        case 2:
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^Invuln%^BOLD%^%^CYAN%^er%^BOLD%^%^RED%^ab%^BOLD%^%^YELLOW%^le%^BOLD%^%^WHITE%^)";
            break;
        case 3:
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^Invulner%^BOLD%^%^RED%^ab%^BOLD%^%^YELLOW%^le%^BOLD%^%^WHITE%^)";
            break;
        case 4:
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^Invulnerab%^BOLD%^%^YELLOW%^le%^BOLD%^%^WHITE%^)";
            break;
        case 5:
            return "%^BOLD%^%^WHITE%^ (%^BOLD%^%^MAGENTA%^Invulnerable%^BOLD%^%^WHITE%^)";
            break;
        default: 
            return "";
            break;
    }
    return "";    
}

void update_rune_location(object room)
{
    string current_location, current_room;
    int cur_place;
    current_location = get_current_location();
    cur_place = member_array(current_location, RUNE_LOCS);
    if(current_location == "dead") return;
    cur_place++;
    current_location = RUNE_LOCS[cur_place];
    clear_arrays("all");
    SAVE_D->set_value(ELARL, current_location);
    SAVE_D->set_value(ELARD, time() + RUNE_DELAY);
    if(current_location != "NIL")
    {
        current_room = return_current_room(current_location);
        SAVE_D->set_value(ELARR, current_room);
    }
    if(current_location == "dead")
    {
        SAVE_D->set_value(ELARD, time() + RUNE_DELAY);
        return;
    }
    if(objectp(room))
    {
        if(current_location == "NIL")
        {
            tell_room(room, "%^BOLD%^%^WHITE%^The runes protecting Arsheeva Wyndar have faltered.... for a time. He is vulnerable now!!!%^RESET%^");
        }
        else
        {
            tell_room(room, "%^BOLD%^%^YELLOW%^Several bolts of lighting zap toward "+current_location+"!! You get a sense that the "+
            "next rune protecting Arsheeva Wyndar can be found there!%^RESET%^");
        }
    }
    call_out("check_rune", 4);
    return;    
}

void place_rune(object room)
{
    string current_location, current_room, *saved_arr;
    int rune_delay, room_num;
    current_location = get_current_location();
    place_arsheeva();
    //if it's NIL (all runes have been destroyed and there is still a delay) do nothing here
    if(current_location == "NIL" || current_location == "dead") return;
    if(pointerp(saved_arr = SAVE_D->query_array(ELARR)) && sizeof(saved_arr))
    {
        current_room = saved_arr[0];        
    }
    else
    {
        current_room = return_current_room(current_location);
        clear_arrays("room");
        SAVE_D->set_value(ELARR, current_room);
    }
    if(!stringp(current_room) || current_room == "ERROR") return;
    else
    {
        if(!objectp(room)) return;
        if(base_name(room) == current_room) 
        {
            if(!present("arsheeva rune", room)) find_object_or_load(ROB)->move(room);
            return;
        }
    }
    return;
}

void place_arsheeva()
{
    object ARV, where;
    string current_loc, *saved_arr, current_location;
    current_location = get_current_location();
    //he's dead, don't place him
    if(current_location == "dead") return;
    ARV = find_object_or_load(ELMON+"arsheeva_wyndar");
    if(objectp(ARV))
    {
        if(environment(ARV)) return;
    }
    if(!pointerp(saved_arr = SAVE_D->query_array(ELARSLOC)) || !sizeof(saved_arr))
    {
        current_loc = (ELROOMSD +(60 + random(120)));
        SAVE_D->remove_array(ELARSLOC);
        SAVE_D->set_value(ELARSLOC, current_loc);
    }
    else current_loc = saved_arr[0];
    where = find_object_or_load(current_loc);
    if(!objectp(where)) return;
    if(objectp(ARV)) ARV->move(where);
    return;    
}

void check_rune()
{
    string current_location, current_room, *saved_arr;
    current_location = get_current_location();
    if(pointerp(saved_arr = SAVE_D->query_array(ELARR)) && sizeof(saved_arr))
    {
        current_room = saved_arr[0];        
    }
    else
    {
        current_room = return_current_room(current_location);
    }
    place_rune(find_object_or_load(current_room));
    return;
}