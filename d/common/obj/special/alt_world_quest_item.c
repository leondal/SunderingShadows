#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "/d/common/obj/special/alt_world_quests.h"
inherit OBJECT;

string belongsTo, myAltWorld;
mapping perimeters;
int started, delay, remaining, lastsFor;
string rewardType, areaName;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("soulbound", 1);

    set_id(({"alt world quest item", "alt world exit item", "mysterious device", "device", "saidealtworldquestitem"}));
    set_name("mysterious device");
    set_short(CRAYON_D->color_string("Mysterious Device", "dark red"));

    set_long("%^BOLD%^%^BLACK%^This strange device is composed of a "+
    "faintly glowing substance. It is square, with edges which are sharp, almost sharp "+
    "enough to cut flesh if handled carelessly. There are runes covering most of the surface, "+
    "though they seem absent behind the glow. You quickly realize that there is writing covering "+
    "all of it, which seems to move about on its own accord, continually shifting places and the script "+
    "itself seems to change, ranging from elegant to sloppy. You think that you should "+
    "%^BOLD%^%^CYAN%^read%^BOLD%^%^BLACK%^ it.%^RESET%^");

    set_weight(0);

    set_read("%^BOLD%^%^WHITE%^You now possess a device that exists only because of powerful magic the likes of which must not be allowed to spread across the realm, less all that is known shall collapse. If you have no desire to stop it, then destroy this device, go on your way, and be as you may... that is your choice.\n\n%^BOLD%^%^WHITE%^However, if you are brave, then you may use this device to try to prevent the complete annihilation of our world. This will require a few things of you. First, you must find the location that this particular device is linked to. You must %^BOLD%^%^CYAN%^<gaze device>%^BOLD%^%^WHITE%^ in order to get an idea of where this particular device is linked.\n\n %^BOLD%^%^WHITE%^Once you have found the location that binds this device, then you may %^BOLD%^%^CYAN%^<power device>%^BOLD%^%^WHITE%^ to be transported to a world beyond this one, one that has been perverted by twisted magics. Once you do so, the magic that allows you to manipulate this device shall begin to wane.... It will not last forever and once gone, your chance to end the perversion that binds this device will be %^BOLD%^%^BLACK%^forfeit%^BOLD%^%^WHITE%^.\n\n%^BOLD%^%^WHITE%^ While the magic still exists and you walk within that world, you may %^BOLD%^%^CYAN%^<leave device> %^BOLD%^%^WHITE%^ at any time. However, while in that world you should seek out a %^BOLD%^%^RED%^ fragment of it%^BOLD%^%^WHITE%^... it may be laying in plain sight, or held by one of the creatures that exists there... whichever the case might be, once you, a being who dwells not of that world touches it, you will severe the link and put an end to the perversion. Shall you succeed in doing this you will be well rewarded...%^RESET%^");
    set_heart_beat(60);
    set_language("wizish");
    lastsFor = time() + 30000;
}

int set_reward_type(string str)
{
    rewardType = str;
    if(rewardType != "gold" && rewardType != "mats") rewardType = "gold";
    tell_object(TP,"%^BOLD%^%^WHITE%^Alt reality reward type is set to %^CYAN%^"+rewardType+"%^WHITE%^!%^RESET%^");
    return 1;
}

void setup_perimeters()
{
    mapping mymon, myquests, qchoices;
    string *mlist, *monster_list = ({}), *myBorders = ({}), *qcs;
    int mlev, choices = 0, chsize, mchance;
    if(!stringp(belongsTo) || ETO->query_true_name() != belongsTo)
    {
        TO->remove();
        return;
    }
    mlev = ETO->query_base_character_level();

    mchance = mlev + random(mlev) + random(mlev);

    if(mchance > 85) mchance = 85;
    if(mchance < 15) mchance = 15;
    mlev = CHAMPION_D->fix_level(mlev);
    if(mlev < 5) mlev = 5;
    if(mlev > 105) mlev = 105;
    mlist = CHAMPION_D->retrieve_monster_list(mlev);

    qchoices = LEVEL_AREAS[mlev][random(sizeof(LEVEL_AREAS[mlev]))];
    qcs = keys(qchoices);
    areaName = qcs[random(sizeof(qcs))];
    myquests = qchoices[areaName];

    if(!pointerp(mlist) || !sizeof(mlist))
    {
        tell_object(ETO, "ERROR generating list of random monsters.");
        TO->remove();
        return;
    }

    //build a list of monsters to be in this area.

    chsize = roll_dice(1, 3) + roll_dice(1, 3);
    choices = 0;
    foreach(string mfile in mlist)
    {
        if(!stringp(mfile)) continue;
        if(random(5)) continue;
        if(choices >= chsize) break;
        choices++;
        monster_list += ({mfile});
        continue;
    }

    if(choices < chsize)
    {
        if(sizeof(monster_list) < (chsize/2))
        {
            while(choices <= chsize)
            {
                monster_list += ({mlist[random(sizeof(mlist))]});
                choices ++;
                continue;
            }
        }
    }
    monster_list = distinct_array(monster_list);
    mymon = ([]);
    foreach(string mfile in monster_list)
    {
        if(!stringp(mfile)) continue;
        mymon += ([mfile : roll_dice(1,3)]);
        continue;
    }

    //end of monster list building
    //mymon should be a mapping with a file name of a monster, and a number - roll_dice(1, 3) that can spawn


    perimeters = (["alt world borders" : myquests["boundaries"],
    "alt world monsters" : mymon,
    "alt world monster chance" : mchance,
    "alt allow normal monsters" : 0,
    "alt world ends at" : 14400,
    "start room" : myquests["entry point"],

    "party area" : 1,
    "alt world quest" : 1,

    "invite msg" : "%^BOLD%^%^WHITE%^You are invited to participate in a Phased event. "+
    "You will be in an alternative version of "+
    "an area that exists because of a perverse and powerful magic, unlike anything seen before. Only users in your party who are "+
    "of appropriate level will be inside this area with you. There will be borders which you cannot move beyond. "+
    "This particular event will last for approximately four hours of real life time, or until a %^BOLD%^%^RED%^"+
    "fragment of the reality%^BOLD%^%^WHITE%^ is discovered and touched by one of you. If you die within the event if "+
    "there is no one inside who can ressurect you, then you will be out of it, unless you are the one who is it "+
    "set up for - in which you may re-enter the event. You are free to exit the event at anytime you are not in combat, simply by typing %^BOLD%^%^CYAN%^leave event%^BOLD%^%^WHITE%^ "+
    "because of a powerful tether (in your inventory) between you and the primordial plane of existence. Can you live to tell the tale?\n\n"+
    "If you wish to participate then simply "+
    "type '%^BOLD%^%^CYAN%^yes%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^y%^BOLD%^%^WHITE%^'. If you do not wish to participate "+
    "you may type '%^BOLD%^%^CYAN%^no%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^'. You have approximately "+
    "four minutes to accept this invitation. After all players have responded the event will start and you will be moved into the alternative "+
    "world.%^RESET%^",

    "reward type" : rewardType,

    "accept msg" : "%^BOLD%^%^WHITE%^You have accepted the invitation for the phased event, it will start momentarily.%^RESET%^",

    "decline msg" : "%^BOLD%^%^WHITE%^"+
    "You have declined the invitation for the phased event.%^RESET%^",

    "start msg" : "%^BOLD%^%^CYAN%^The phased event is now starting! ... do you have "+
    "what it takes to survive? Or will you be slaughted and left to rot? Remember, your objective here is to find a "+
    "%^BOLD%^%^RED%^fragment of reality%^BOLD%^%^CYAN%^ in an attempt to stop the spread of the powerful and "+
    "perverse magic.%^RESET%^"]);

    myAltWorld = belongsTo + " alt quest";
    //tell_object(find_player("saide"), "perimeters = "+identify(perimeters));
    return;
}

void init()
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO) || !userp(ETO))
    {
        TO->remove();
        return;
    }
    if(ETO->query_true_name() != belongsTo)
    {
        if(!stringp(belongsTo))
        {
            belongsTo = ETO->query_true_name();
            setup_perimeters();
        }
        else TO->remove();
    }
    add_action("gaze_func", "gaze");
    add_action("power_func", "power");
    add_action("leave_func", "leave");
    add_action("set_reward_type", "reward");
}

int leave_func(string str)
{
    if(!objectp(TO) || !objectp(ETO) || !objectp(EETO)) return 0;
    if(!stringp(str) || (str != "device" && str != "event")) return 0;
    if(ETO->query("alternative world") != EETO->query("alternative world") || !ETO->query("alternative world"))
    {
        tell_object(ETO, "You are not within an alternative world, or are within one for which this device is not linked. "+
        "If you think this an error please contact an immortal for assistance.");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "You are not able to do that during combat!");
        return 1;
    }
    ALT_WORLD_D->remove_from_alt_world(ETO);
    return 1;
}

int gaze_func(string str)
{
    string entryfile;
    object mytarg;
    if(!objectp(TO) || !objectp(ETO) || !objectp(EETO)) return 0;
    if(!stringp(str) || str != "device") return 0;
    if(ETO->query("alternative world") || EETO->query("alternative world"))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You gaze deeply into the strange device.... but nothing seems to happen.%^RESET%^");
        return 1;
    }
    if(!stringp(entryfile = perimeters["start room"]))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^There is something wrong with your device, please notify an immortal.%^RESET%^");
        return 1;
    }
    mytarg = find_object_or_load(entryfile);
    if(!objectp(mytarg))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^There is something wrong with your device, please notify an immortal.%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You gaze deeply into the strange device.... and visions dance within your mind urging you to find "+
    "a place that looks like : \n\n"+mytarg->query_short()+"\n"+mytarg->query_long()+"%^BOLD%^%^WHITE%^\n\nThis is located "+
    "near the "+areaName+".%^RESET%^");
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ gazes deeply into a strange device.... seemingly transfixed by "+
        "it for a brief moment!", ETO);
    }
    return 1;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!stringp(myAltWorld)) return;
    if(time() > remaining && remaining > 0 || time() > lastsFor)
    {
        ALT_WORLD_D->clear_alt_world(myAltWorld);
        TO->remove();
        return;
    }
}

int power_func(string str)
{
    object aworld;
    string myEnv, entryfile;
    if(!objectp(TO) || !objectp(ETO) || !objectp(EETO)) return 0;
    if(!stringp(str) || str != "device") return 0;
    if(ETO->query("alternative world") || EETO->query("alternative world"))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The device doesn't respond at all.....%^RESET%^");
        return 1;
    }
    if(!stringp(entryfile = perimeters["start room"]))
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^There is something wrong with your device, please notify an immortal.%^RESET%^");
        return 1;
    }
    myEnv = base_name(EETO);
    if(myEnv != entryfile)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You realize that the device is not linked to this area and has no power here.%^RESET%^");
        return 1;
    }
    if(sizeof(ETO->query_attackers()))
    {
        tell_object(ETO, "You are not able to do that during combat!");
        return 1;
    }
    //if it's not started - IE used once - clear any potential conflicting areas
    if(!started)
    {
        started = 1;
        remaining = 14800 + time();
        ALT_WORLD_D->clear_alt_world(myAltWorld);
    }
    if(started && delay > time())
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The device doesn't respond at all.....%^RESET%^");
        return 1;
    }
    delay = time() + 400;
    aworld = new("/d/common/obj/special/alt_world_creator.c");
    if(!perimeters["created for"]) perimeters += (["created for" : ETO]);
    else perimeters["created for"] = ETO;
    aworld->alt_world_perimeters(perimeters);
    aworld->alt_world(myAltWorld);
    return 1;
}

string query_perimeters() { return identify(perimeters); }
