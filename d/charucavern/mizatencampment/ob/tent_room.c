#include <std.h>
#include "../inherits/area_stuff.h"
inherit ROOM;

string MyDest, UNIQ_ID;
object destination, entry_tent;

nosave mixed cleaner;
nosave int tent_installed;

int filth;

void set_my_tent(string str) { UNIQ_ID = str; }
string query_my_tent() { return UNIQ_ID; }
int query_filth() { return filth; }
void set_filth(int x) { filth = x; }
int is_tent() { return 1; }

string longdesc()
{
    string ret;
    ret = "%^RESET%^%^GREEN%^The inside of this tent is quite roomy and comfortable. "+
    "It has been %^RESET%^%^WHITE%^sewn carefully%^RESET%^%^GREEN%^ from a very thick "+
    "and heavy fabric. The floor, walls, and ceiling of it have been coated with a "+
    "%^BOLD%^%^BLACK%^thick malleable substance%^RESET%^%^GREEN%^ in order to protect "+
    "it from the elements. There are, however, vents near the bottom of each "+
    "wall that allow air to circulate through the tent. A large %^BOLD%^%^WHITE%^opening"+
    "%^RESET%^%^GREEN%^ that hangs loosely and has been sewn from a lighter fabric "+
    "provides a means of escaping.";
    switch(filth)
    {
        case 0..400:
            ret += " It is currently fairly clean.%^RESET%^";
            break;
        case 401..550:
            ret += " It is currently quite dingy. You could %^BOLD%^%^WHITE%^clean"+
            "%^RESET%^%^GREEN%^ it if you wanted.%^RESET%^";
            break;
        case 551..700:
            ret += " It is currently quite dirty. You should probably %^BOLD%^%^WHITE%^"+
            " clean%^RESET%^%^GREEN%^ it unless you want to live in the filth.%^RESET%^";
            break;
        case 701..850:
            ret += " It is currently very dirty. You should %^BOLD%^%^WHITE%^clean"+
            "%^RESET%^%^GREEN%^ it, unless you wish to live in the filth.%^RESET%^";
            break;
        case 851..1000:
            ret += " It is filthy. You should immediately %^BOLD%^%^WHITE%^clean"+
            "%^RESET%^%^GREEN%^ it.%^RESET%^";
            break;
        case 1001..1250:
            ret += " It is very filthy. You should immediately %^BOLD%^%^WHITE%^clean"+
            "%^RESET%^%^GREEN%^ it.%^RESET%^";
            break;
        default:
            ret += " It is absolutely disgusting, as the filth has been allowed to "+
            "build up. You have a strong urge to %^BOLD%^%^WHITE%^clean%^RESET%^%^GREEN%^ "+
            "it.%^RESET%^";
            break;
    }
    return ret;
}

void create()
{
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(WOOD_BUILDING);
    set_travel(SLICK_FLOOR);
    set_name("Inside of a tent");
    set_short("The inside of a tent");

    set_property("no sticks",1);
    //make this dependent on area?
    //set_property("no teleport", 1);
    filth = 0;
    set_long((:TO, "longdesc":));

    //set_listen("default","The sound of rumbling echoes all around you.");
    //set_smell("default","\nThe smell of rot and decay invades your senses.");
    call_out("check_my_tent", 5);
}

int filter_tents(object ob, string MYID)
{
    if(!objectp(ob)) return 0;
    if(!ob->is_tent()) return 0;
    if((string)ob->query_my_tent() == MYID) return 1;
    return 0;
}


void check_tent()
{
    object where, *inv, tent_ob;
    int x;
    if(!objectp(TO)) return;
    if(!stringp(MyDest))
    {
        //tell_object("/std/user#1244235", "removing the tent because it couldn't find the string environment");
        TO->remove();
        return;
    }
    if(!objectp(destination))
    {
        if(!objectp(destination = find_object_or_load(MyDest)))
        {
            //tell_object("/std/user#1244235", "removing the tent because it couldn't find the environment");
            TO->remove();
            return;
        }
    }
    inv = filter_array(all_inventory(destination), "filter_tents", TO, UNIQ_ID);
    if(!sizeof(inv))
    {
        //tell_object("/std/user#1244235", "trying to create a new tent entry object.");
        tent_ob = new(MOB+"tent_object");
        tent_ob->register_tent_room(TO);
        tent_ob->set_my_tent(query_my_tent());
        tent_ob->move(destination);
        TO->set_had_players();
        tent_ob->set_had_players();
        entry_tent = tent_ob;
        TO->add_exit(MyDest, "opening");
        tent_installed = 1;
        return;
    }
    else
    {
        if((object)inv[0]->query_tent_room() != TO)
        {
            //tell_object("/std/user#1244235", "found a tent entry for this tent setting it up to work.");
            inv[0]->register_tent_room(TO);
            entry_tent = inv[0];
            TO->add_exit(MyDest, "opening");
            inv[0]->set_my_tent(query_my_tent());
            tent_installed = 1;
            inv -= ({inv[0]});
        }
        //more than one of them - remove it
        //if(sizeof(inv)) inv->remove();
    }
    return;
}

int init_tent(object tentbag, object where)
{
    object tent_ob;
    if(!objectp(tentbag)) return 0;
    if(!objectp(where)) return 0;
    set_my_tent((string)tentbag->query_my_tent());
    set_filth((int)tentbag->query_filth());
    MyDest = base_name(where);
    destination = where;
    tent_ob = new(MOB+"tent_object");
    tent_ob->register_tent_room(TO);
    tent_ob->set_my_tent((string)tentbag->query_my_tent());
    tent_ob->move(destination);
    entry_tent = tent_ob;
    set_had_players();
    tent_ob->set_had_players();
    tent_installed = 1;
    TO->add_exit(MyDest, "opening");
    TO->set_property("no teleport", (int)destination->query_property("no teleport"));
    TO->set_property("teleport proof", (int)destination->query_property("teleport proof"));
    if(stringp(destination->query_smell("default"))) TO->set_smell("default", "\nWafting in from outside: "+(string)destination->query_smell("default"));
    if(stringp(destination->query_listen("default"))) TO->set_listen("default", "Filtering in from outside: "+(string)destination->query_listen("default"));
    return 1;
}

void check_my_tent()
{
    int inv;
    object lice;
    if(!objectp(TO)) return;
    call_out("check_my_tent", 5);
    if(!objectp(destination) || !tent_installed || !objectp(entry_tent)) check_tent();
    //if(!objectp(environment(entry_tent))) check_tent();
    //if(base_name(environment(entry_tent)) != MyDest) check_tent();
    if(objectp(entry_tent))
    {
        if(!objectp(environment(entry_tent)))
        {
            check_tent();
            return;
        }
        if(objectp(environment(entry_tent)))
        {
            if(base_name(environment(entry_tent)) != MyDest) check_tent();
        }
    }
    if(!objectp(TO)) return;
    if(random(250)) return;

    inv = sizeof(all_inventory(TO));
    if(!inv) inv = random(30);
    else inv *= (1+random(10)+random(10));
    filth += inv;
    return;
}

void init()
{
    ::init();
    add_action("clean_func", "clean");
}

void continue_cleaning()
{
    if(!objectp(TO)) return;
    if(!objectp(cleaner)) return;
    if(!environment(cleaner))
    {
        cleaner = 0;
        return;
    }
    if(environment(cleaner) != TO)
    {
        tell_object(cleaner, "%^BOLD%^%^WHITE%^You stop cleaning the tent to do something else.");
        cleaner = 0;
        return;
    }
    filth -= 10 * (1 + random(4));
    if(filth < 0) filth = 0;
    switch(random(3))
    {
        case 0:
            tell_object(cleaner, "%^BOLD%^%^RED%^You scrub and scrub, carefully scrubbing away the filth in the tent.%^RESET%^");
            tell_room(TO, cleaner->QCN+"%^BOLD%^%^RED%^ scrubs and scrubs, carefully scrubbing away the filth in the tent.%^RESET%^", cleaner);
            break;
        case 1:
            tell_object(cleaner, "%^BOLD%^%^BLUE%^You carefully continue cleaning the tent, be gentle with the thick fabric, but "+
            "focus intently on making it clean again.%^RESET%^");
            tell_room(TO, cleaner->QCN+"%^BOLD%^%^WHITE%^ carefully continues cleaning the tent, being gentle with the thick fabric, "+
            "but focusing intently on making it clean again.%^RESET%^", cleaner);
            break;
        case 2:
            tell_object(cleaner, "%^BOLD%^%^GREEN%^You quickly and carefully work at cleaning away the filth in the tent.%^RESET%^");
            tell_room(TO, cleaner->QCN+"%^BOLD%^%^GREEN%^ quickly and carefully works at cleaning away the filth in the tent.%^RESET%^", cleaner);
            break;
    }
    if(!filth)
    {
        tell_object(cleaner, "%^BOLD%^%^WHITE%^Finally! The tent looks new again, your cleaning has paid off!%^RESET%^");
        tell_room(TO, cleaner->QCN+"%^BOLD%^%^WHITE%^ has finally managed to clean the tent enough that it looks new again!%^RESET%^", cleaner);
    }
    else
    {
        call_out("continue_cleaning", 4);
    }
    return;
}

void check_cleaning(string str)
{
    if(objectp(cleaner))
    {
        tell_object(cleaner, "%^BOLD%^%^WHITE%^You stop cleaning the tent to do something else.");
        tell_room(TO, cleaner->QCN +"%^BOLD%^%^WHITE%^ stops cleaning the tent to do something else.");
        cleaner = 0;
        return;
    }
    return;
}

int clean_func(string str)
{
    int how_clean;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(str != "tent" && str != "my tent" && str != "inside of tent" && str != "inside of my tent") return 0;
    if(objectp(cleaner))
    {
        if(cleaner == TP)
        {
            tell_object(TP, "%^BOLD%^%^RED%^You are already cleaning the tent!%^RESET%^");
            return 1;
        }
        else
        {
            tell_object(TP, "%^BOLD%^%^RED%^Someone else is already cleaning the tent!%^RESET%^");
            return 1;
        }
    }
    if(!filth)
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^This tent is not dirty, you see no reason to clean it!%^RESET%^");
        return 1;
    }
    tell_object(TP, "%^BOLD%^%^BLACK%^You start carefully cleaning the tent, trying to avoid tearing it!%^RESET%^");
    tell_room(TO, TPQCN+"%^BOLD%^%^BLACK%^ starts carefully cleaning the tent, trying to avoid tearing it!%^RESET%^");
    cleaner = TP;
    call_out("continue_cleaning", 4);
    input_to("check_cleaning", 1);
    return 1;
}
