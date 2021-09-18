#include <std.h>
#include "token_hunt.h"

inherit OBJECT;

void create()
{
    ::create();
    set_id(({"wagon",}));

    set_name("wagon");

    set_short("%^MAGENTA%^A small wagon, rounded with goods");

    set_long("%^BOLD%^%^WHITE%^This small wagon comes complete with four thick walls to keep all the supplies it is hauling safe and secure. Four large wheels provide a sturdy means of transport and you notice that a fifth wheel is strapped under the belly to provide for a quick repair should one of the first four break. At the front a wide, flat seat provides a spot for the driver to sit and guide the large, lumbering %^YELLOW%^triceratops %^WHITE%^that pulls the wagon. Beside the driver's seat is a secure looking %^BLUE%^iron chest %^WHITE%^with several %^MAGENTA%^magical runes %^WHITE%^decorating it. More of these enchanted chests are located in the back of the wagon and every one of them appears to be very well maintained. Draped over the sides of the wagon are a number of %^MAGENTA%^%^BOLD%^b%^BLUE%^r%^MAGENTA%^igh%^BLUE%^t%^MAGENTA%^ly%^WHITE%^ colored banners, each proclaiming that this is the fabled %^YELLOW%^Emporium of Exotic Wares%^WHITE%^: A traveling warehouse of rare, fabulous things that have been brought back from all over the realm and sold to the small gnome that tends the traveling shop.

You can see a list posted on the side of the wagon, maybe you can <read list>.
There's also a slot near the wagon wheel with a box protruding from it. You could probably <retrieve box>.");
    // There's also a second slot for mysterous devices. You could probably <retrieve device [with gold|mats]>.
    set_weight(100000000);
}

int read_list(string str)
{
    object ob,token_ob;
    int i;

    string *shorts=({}),*locations=({}),type;


    if(!stringp(str) || str != "list") { return 0; }
    if(!objectp(TP)) { return 0; }

    if(!objectp(ob=present("shopkeeper",ETO)))
    {
        tell_object(TP,"This list is covered with blood!");
        return 1;
    }
    type = ob->query_store_type();

    token_ob = find_object_or_load(TOKEN_D);

    token_ob->check_population();

    shorts      = token_ob->monster_locations(type);
    locations   = token_ob->true_locations(type);

    tell_object(TP,"%^RESET%^%^BOLD%^Last known locations.%^RESET%^");
    tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    for(i=0;i<sizeof(shorts);i++)
    {
        tell_object(TP,"    "+shorts[i]+"");
    }
    tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");

    if(avatarp(TP))
    {
        tell_object(TP,"%^RESET%^%^BOLD%^True locations for all.%^RESET%^");
        tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
        for(i=0;i<sizeof(locations);i++)
        {
            tell_object(TP,"    "+locations[i]+"");
        }
        tell_object(TP,"%^MAGENTA%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^");
    }
    if(objectp(ob=present("shopkeeper",ETO)))
    {
        if(!avatarp(TP))
        {
            ob->force_me("say If you're thinking about going after one of those "
                "shapechangers for the tokens, then be careful.  They are some "
                "of the strongest creatures you'll ever face.");
        }
    }
    return 1;
}

int retrieve_stuff(string str)
{
    if (!stringp(str)) {
        return 0;
    }
    if (str == "box" || str == "Box") {
        tell_object(TP, "You pull a box from the dispenser and it falls onto the ground.");
        new(FILE_PATH "tokens")->move(ETO);
        return 1;
    }
    
    //return 0;
    
    if(regexp(str,"device"))
    {
        object ob;
        string rewardType;
        if(sscanf(str,"device with %s",rewardType)!=1)
            rewardType = "gold";
        tell_object(TP,"You pull a mysterious device from the dispenser and it falls into your hands.");
        if(TP->query("last alt quest") > time())
        {
            tell_object(TP, "%^BOLD%^%^WHITE%^In order to prevent your being from "+
            "faltering you must wait awhile longer before you request another "+
            "device that will allow you to venture into the alternative worlds!%^RESET%^");
            return 1;
        }
        if(objectp(present("saidealtworldquestitem", TP)))
        {
            tell_object(TP, "%^BOLD%^%^WHITE%^In order to prevent your being from shattering "+
            "into fragments... you must be rid of the current device that you have, before you are "+
            "able to request another.%^RESET%^");
            return 1;
        }
        if(TP->query("alternative world") || ETP->query("alternative world"))
        {
            tell_object(TP, "%^BOLD%^%^WHITE%^In order to prevent your being from shattering "+
            "into fragments... you are unable to request another device while within an "+
            "alternative world!%^RESET%^");
            return 1;
        }
        ob = new("/d/common/obj/special/alt_world_quest_item.c");
        ob->set_reward_type(rewardType);
        ob->move(TP);
        tell_object(TP, "%^BOLD%^%^WHITE%^What sounds like a thousand voices echo deep within your mind and seem to "+
        "reverberate through your entire body.... \n\n"+
        "Careful what you request tiny mortal, for a magic spreads across this realm, the likes of which has "+
        "never before been. It is much bigger than you could ever possibly know....\n\n"+
        "You now hold a device which presents a link to a world, much like your own, but twisted and different....\n\n"+
        "Created by a God older than any worshipped by you mortals, this device will allow you entry into an area of "+
        "this world. If you are brave enough then find a fragment of it, touch it, and you will, at least for a time, "+
        "help to stem the flow.\n\n"+
        "If you are succesful you shall be rewarded.");
        TP->delete("last alt quest");
        TP->set("last alt quest", time() + 7000);
        return 1;
    }
    return 0;
}

int request_marker(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!avatarp(TP)) { return 0; }
    if(!stringp(str)) { return 0; }
    if(str != "marker" && str != "Marker") { return 0; }
    tell_object(TP,"You retrieve a marker.");
    new(FILE_PATH"token_marker")->move(TP);
    return 1;
}

void init()
{
    ::init();
    add_action("read_list","read");
    add_action("retrieve_stuff","retrieve");
    add_action("request_marker","request");
    if(!objectp(TP)) { return; }
    if(avatarp(TP))
    {
        tell_object(TP,"%^GREEN%^Type <request marker> to get a marker that will let "
            "you add additional directories to the places where mobs are allowed to "
            "spawn");
    }
}
