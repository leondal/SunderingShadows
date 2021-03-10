/*==============================================================================================================================================
Random World/Area Events - bonus experience for certain time or when certain events occur

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#define WORLD_EVENT_SAVE "/daemon/save/world_events"
inherit DAEMON;

mapping WORLD_EVENTS;
nosave int MAX_WORLD_EVENTS = 5;
nosave int WORLD_EVENT_CHANCE = 100+random(11);
nosave int WEEK_DELAY = 604800;
nosave int WEEKLY_START_TIME = 1501261255; // Fri Jul 28 17:00:55 GMT 2017
nosave int WEEKLY_EVENT_LENGTH = 216000;
nosave int CHECKING = 0;
int NEXT_WEEKLY_EVENT, NEXT_WEEKLY_EVENT_END, WEEKLY_EVENT_ONGOING;

void world_events_save()
{
    seteuid(UID_ROOT);
    save_object(WORLD_EVENT_SAVE);
    seteuid(geteuid());
}

void create()
{
    if(!mapp(WORLD_EVENTS)) world_events_restore();
    if(!mapp(WORLD_EVENTS))
    {
        WORLD_EVENTS = ([]);
    }
    establish_weekend_events();
    set_heart_beat(30);
    return;
}

void world_events_restore()
{
    seteuid(UID_ROOT);
    restore_object(WORLD_EVENT_SAVE);
    seteuid(geteuid());
}

int check_events()
{
    string *events, thisEvent, eventName, msg, eventArea;
    int x, flag;
    if(base_name(TO) != WORLD_EVENTS_D)
    {
        /*if(objectp(find_player("saide")))
        {
            tell_object(find_player("saide"), "Removing "+identify(TO)+"!");
        }*/
        TO->remove();
        return 0;
    }
    if(!mapp(WORLD_EVENTS)) world_events_restore();
    if(!mapp(WORLD_EVENTS))
    {
        WORLD_EVENTS = ([]);
        return 0;
    }
    if(CHECKING)
    {
        /*if(objectp(find_player("saide")))
        {
            tell_object(find_player("saide"), "calling check_events() before the first call is completed?");
        }*/
        return 0;
    }
    CHECKING = 1;
    events = keys(WORLD_EVENTS);
    for(x = 0;x < sizeof(events);x++)
    {
        thisEvent = events[x];
        if(time() > WORLD_EVENTS[thisEvent]["end time"])
        {
            eventName = WORLD_EVENTS[thisEvent]["event name"];

            if(WORLD_EVENTS[thisEvent]["announce"])
            {
                if(WORLD_EVENTS[thisEvent]["announce to"] == "world")
                {
                    msg = WORLD_EVENTS[thisEvent]["announce end"];
                    foreach(object player in users())
                    {
                        if(!objectp(player)) continue;
                        //tell_object(find_player("saide"), "player now = "+identify(player) +" and TO = "+identify(TO));
                        message("tell", msg, player);
                        continue;
                    }
                    //message("tell", msg, users());*/
                }
                else if(stringp(eventArea = WORLD_EVENTS[thisEvent]["announce to"]) != "world")
                {
                    if(stringp(msg = WORLD_EVENTS[thisEvent]["announce end"]))
                    {
                        broadcast_area(eventArea, msg);
                    }
                }
            }
            if(WORLD_EVENTS[thisEvent]["increases delay"]) WORLD_EVENT_CHANCE -= additional_mod();
            if(WORLD_EVENTS[thisEvent]["weekly event"]) WEEKLY_EVENT_ONGOING = 0;
            map_delete(WORLD_EVENTS, thisEvent);
            flag = 1;
            continue;
        }
        continue;
    }
    if(flag) world_events_save();
    CHECKING = 0;
    return sizeof(keys(WORLD_EVENTS));
}

varargs int get_exp_modifier(object who)
{
    string *events, myEvent, eventLoc, whoLoc;
    int x, mod;
    if(!check_events()) return 0;
    mod = 0;
    events = keys(WORLD_EVENTS);
    for(x = 0;x < sizeof(events);x++)
    {
        myEvent = events[x];
        if(WORLD_EVENTS[myEvent]["type"] == "exp bonus")
        {
            if(WORLD_EVENTS[myEvent]["announce to"] == "world")
            {
                mod += WORLD_EVENTS[myEvent]["modifier"];
                continue;
            }
            if(!objectp(who)) continue;
            if(!stringp(eventLoc = WORLD_EVENTS[myEvent]["announce to"])) continue;
            if(!objectp(environment(who))) continue;
            if(!stringp(whoLoc = base_name(environment(who)))) continue;
            if(strsrch(whoLoc, eventLoc) == -1) continue;
            mod += WORLD_EVENTS[myEvent]["modifier"];
            continue;
        }
        continue;
    }
    return mod;
}

mixed check_exp_events(int exp, object who)
{
    int modifier, x;
    if(!intp(exp)) return exp;
    if(!check_events()) return exp;
    modifier = get_exp_modifier(who);
    if(!modifier) return exp;
    if(modifier > 0) exp += to_float((exp * modifier) / 100);
    if(modifier < 0) exp -= to_float((exp * modifier) / 100);
    return exp;
}

varargs int treasure_drop_rate_event(int chance, object who)
{
    int modifier;
    if(!intp(chance)) return chance;
    if(!check_events()) return chance;
    modifier = get_random_treasure_modifier(who);
    if(!modifier) return chance;
    return (chance + modifier);
}

int get_random_treasure_modifier(object who)
{
    string *events, myEvent, eventLoc, whoLoc;
    int x, mod;
    if(!check_events()) return 0;
    mod = 0;
    events = keys(WORLD_EVENTS);
    for(x = 0;x < sizeof(events);x++)
    {
        myEvent = events[x];
        if(WORLD_EVENTS[myEvent]["type"] != "treasure drop rate") continue;
        if(WORLD_EVENTS[myEvent]["announce to"] == "world")
        {
            mod += WORLD_EVENTS[myEvent]["modifier"];
            continue;
        }
        if(!objectp(who)) continue;
        if(!stringp(eventLoc = WORLD_EVENTS[myEvent]["announce to"])) continue;
        if(!stringp(whoLoc = base_name(environment(who)))) continue;
        if(strsrch(whoLoc, eventLoc) == -1) continue;
        mod += WORLD_EVENTS[myEvent]["modifier"];
        continue;
    }
    return mod;
}


//stacking item bonuses - Saide - August, 2017
varargs int stacking_bonus_active(object who, int neg)
{
    string *events, myEvent, eventLoc, whoLoc, checkbonus;
    int x, mod;
    if(!check_events()) return 0;
    mod = 0;
    events = keys(WORLD_EVENTS);
    if(neg == -1) checkbonus = "dead item bonuses";
    else checkbonus = "stacking item bonuses";
    for(x = 0;x < sizeof(events);x++)
    {
        myEvent = events[x];
        if(WORLD_EVENTS[myEvent]["type"] != checkbonus) continue;
        if(WORLD_EVENTS[myEvent]["announce to"] == "world")
        {
            mod += WORLD_EVENTS[myEvent]["modifier"];
            if(mod) return mod;
            continue;
        }
        if(!objectp(who)) continue;
        if(!stringp(eventLoc = WORLD_EVENTS[myEvent]["announce to"])) continue;
        if(!stringp(whoLoc = base_name(environment(who)))) continue;
        if(strsrch(whoLoc, eventLoc) == -1) continue;
        mod += WORLD_EVENTS[myEvent]["modifier"];
        if(mod) return mod;
        continue;
    }
    return mod;
}


//will add an elemental of randomness - simply because the additional increase
//may or may not be as high when it's added as when its removed - Saide
int additional_mod()
{
    return 10 + random(15);
}

void kill_event(string eventName)
{
    if(!stringp(eventName)) return;
    check_events();
    if(!WORLD_EVENTS[eventName]) return;
    WORLD_EVENTS[eventName]["end time"] = 0;
    check_events();
    return;
}

varargs void inject_event(mapping eventMap, int flag)
{
    string eventName, *events, eventType, announceTo, start_msg, end_msg, notification;
    int x, len, announce, eChance;
    mixed mod;
    //old function - or enable to launch random functions - Saide, Feb 18, 2017
    //return;
    if(!mapp(eventMap)) return;
    check_events();
    if(!sizeof(events = keys(eventMap))) return;
    eChance = 2;
    eChance += sizeof(keys(WORLD_EVENTS));
    if(roll_dice(eChance, 20) > roll_dice(1,100) && !flag) return;
    for(x = 0;x < sizeof(events);x++)
    {
        eventName = events[x];
        //event with the same name is already active
        if(WORLD_EVENTS[eventName]) continue;
        if(!stringp(start_msg = eventMap[eventName]["start message"])) continue;
        if(!intp(len = eventMap[eventName]["length"])) len = 25 + random(31) + random(31);
        if(!stringp(eventType = eventMap[eventName]["event type"])) eventType = "exp bonus";
        if(!intp(announce = eventMap[eventName]["announce"])) announce = 1;
        if(!stringp(announceTo = eventMap[eventName]["announce to"])) announceTo = "world";
        if(!stringp(end_msg = eventMap[eventName]["end message"]))
        {
            end_msg = "%^BOLD%^%^RED%^The event "+eventName+" has ended!%^RESET%^";
        }
        if(undefinedp(announce)) announce = 1;
        if(undefinedp(len)) len = 25 + random(31) + random(31);
        if(eventType == "monster modifications")
        {
            if(!mapp(mod = eventMap[eventName]["modifier"])) continue;
        }
        else
        {
            if(!intp(mod = eventMap[eventName]["modifier"])) mod = 25 + random(10) + random(10) + random(10);
        }
        if(undefinedp(mod)) mod = 25 + random(10) + random(10) + random(10);
        if(!stringp(notification = eventMap[eventName]["notification"]))
        {
            notification = mod+"% " + eventType;
        }
        WORLD_EVENTS += ([eventName : (["type" : eventType, "end time": (time() + (len*60)),
        "event name" : eventName, "modifier" : mod, "announce" : announce, "announce to" : announceTo,
        "announce start" : start_msg, "announce end" : end_msg, "notification" : notification, "announced" : 0]),]);
        world_events_save();
        continue;
    }

    announce_events();
    return;
}

int monster_modification_event(int to_mod, string myMod, object who)
{
    int x, mod, y;
    string eventLoc, whoLoc, *events, thisEvent, *mods, thisMod;
    object myMaster;
    mapping modMap;

    if(!intp(to_mod)) return to_mod;
    if(!objectp(who)) return to_mod;
    if(!stringp(myMod)) return to_mod;
    if(!stringp(whoLoc = base_name(environment(who)))) return to_mod;
    if(userp(who)) return to_mod;
    if(who->query_level() < 5) return to_mod;
    if(objectp(myMaster = who->query_property("minion")))
    {
        if(userp(myMaster)) return to_mod;
    }
    if(!check_events()) return to_mod;
    if(!sizeof(events = keys(WORLD_EVENTS))) return to_mod;
    mod = 0;
    for(x = 0;x < sizeof(events);x++)
    {
        thisEvent = events[x];
        if(WORLD_EVENTS[thisEvent]["type"] != "monster modifications") continue;
        if(!stringp(eventLoc = WORLD_EVENTS[thisEvent]["announce to"])) continue;
        if(eventLoc == "world") modMap = WORLD_EVENTS[thisEvent]["modifier"];
        else if(strsrch(whoLoc, eventLoc) != -1) modMap = WORLD_EVENTS[thisEvent]["modifier"];
        if(!mapp(modMap)) continue;
        if(!sizeof(mods = keys(modMap))) continue;
        for(y = 0;y < sizeof(mods);y++)
        {
            thisMod = mods[y];
            if(thisMod != myMod) continue;
            mod += modMap[thisMod];
            continue;
        }
        modMap = ([]);
        continue;
    }
    return (mod + to_mod);
}

void establish_random_events()
{
    string *events, eventName;
    int length, mod, flag, chance;
    if(!mapp(WORLD_EVENTS)) return;
    check_events();
    events = keys(WORLD_EVENTS);
    if(sizeof(events) > MAX_WORLD_EVENTS) return;
    if(random(WORLD_EVENT_CHANCE)) return;
    switch(random(10))
    {
        case 0..4:
            if(WORLD_EVENTS["WorldWide Bonus Experience"]) return;
            length = 25 + random(31) + random(31);
            mod = 25 + random(10) + random(10) + random(10);
            eventName = "WorldWide Bonus Experience";
            WORLD_EVENTS += ([eventName : (["type" : "exp bonus", "end time" : (time() + (length*60)),
            "event name" : eventName, "modifier" : mod, "announce" : 1, "announce to" : "world",
            "announce start" : "%^BOLD%^%^WHITE%^The %^BOLD%^%^CYAN%^"+eventName+"%^BOLD%^%^WHITE%^ event "+
            "has launched and will be active for the next "+length+" minutes. Any experience awarded during "+
            "this time will award an additional %^BOLD%^%^CYAN%^("+mod+"%)%^BOLD%^%^WHITE%^!%^RESET%^",
            "announce end": "%^BOLD%^%^RED%^The event "+eventName + " event has ended!%^RESET%^", "announced" : 0,
            "notification" : mod+"% Bonus Exp", "increases delay" : 1]), ]);
            world_events_save();
            flag = 1;
            break;
        case 5..9:
            if(WORLD_EVENTS["WorldWide Treasure"]) return;
            length = 15 + random(25) + random(25);
            mod = 3 + random(3) + random(5);
            eventName = "WorldWide Treasure";
            WORLD_EVENTS += ([eventName : (["type" : "treasure drop rate", "end time" : (time() + (length * 60)),
            "event name" : eventName, "modifier" : mod, "announce" : 1, "announce to" : "world",
            "announce start" : "%^BOLD%^%^WHITE%^The %^BOLD%^%^CYAN%^"+eventName+"%^BOLD%^%^WHITE%^ event "+
            "has launched and will be active for the next "+length+" minutes. Monsters world wide will "+
            "have a %^BOLD%^%^CYAN%^("+mod+"%)%^BOLD%^%^WHITE%^ increased chance to drop random treasure!%^RESET%^",
            "announce end" : "%^BOLD%^%^RED%^The event "+eventName+" has ended!%^RESET%^", "announced" : 0,
            "notification" : mod+"% higher random treasure drop rate.", "increases delay" : 1]),]);
            world_events_save();
            flag = 1;
            break;
    }
    if(flag)
    {
        announce_events();
        WORLD_EVENT_CHANCE += additional_mod();
    }
    return;
}

void establish_weekend_events()
{
    string *events, eventName, eventMod, eventDesc, eventNotify, eventType, eventMod2;
    int length, mod, flag, chance;
    check_events();
    //tell_object(find_player("saide"), "world_events = "+identify(WORLD_EVENTS));
    if(!mapp(WORLD_EVENTS)) return;
    events = keys(WORLD_EVENTS);
    if(time() > NEXT_WEEKLY_EVENT && time() > NEXT_WEEKLY_EVENT_END)
    {
        NEXT_WEEKLY_EVENT = 0;
        NEXT_WEEKLY_EVENT_END = 0;
    }
    //tell_object(find_player("saide"), "events = "+identify(events));
    //tell_object(find_player("saide"), "Next Weekly Event = "+NEXT_WEEKLY_EVENT);
    // tell_object(find_player("saide"), "Next Weekly Event End = "+NEXT_WEEKLY_EVENT_END);
    if(!NEXT_WEEKLY_EVENT || !NEXT_WEEKLY_EVENT_END)
    {
        if(time() > WEEKLY_START_TIME + WEEKLY_EVENT_LENGTH)
        {
            mod = 1;
            while((time() - WEEK_DELAY*mod) > (WEEKLY_START_TIME + WEEKLY_EVENT_LENGTH))
            {
                mod += 1;
                continue;
            }
            NEXT_WEEKLY_EVENT = (WEEKLY_START_TIME + (WEEK_DELAY*mod));
            NEXT_WEEKLY_EVENT_END = NEXT_WEEKLY_EVENT + WEEKLY_EVENT_LENGTH;
        }
        else
        {
            NEXT_WEEKLY_EVENT = WEEKLY_START_TIME;
            NEXT_WEEKLY_EVENT_END = NEXT_WEEKLY_EVENT + WEEKLY_EVENT_LENGTH;
        }
    }
    if(WEEKLY_EVENT_ONGOING) return;
    if(NEXT_WEEKLY_EVENT > time()) return;
    if(WORLD_EVENTS["Fate's Conundrum!"]) return;

    length = (NEXT_WEEKLY_EVENT_END - time()) / (60 * 60);
    eventName = "Fate's Conundrum!";
    WEEKLY_EVENT_ONGOING = 1;
    flag = 1;
    eventDesc = "%^BOLD%^%^WHITE%^A %^BOLD%^%^GREEN%^ROAR%^BOLD%^%^WHITE%^ echoes across the world....\n\n"+
                "%^BOLD%^%^BLACK%^Suddenly a %^BOLD%^%^BLUE%^myst%^CYAN%^e%^BLUE%^r%^CYAN%^iou%^BOLD%^%^BLUE%^s %^BOLD%^%^WHITE%^being "+
                "%^BOLD%^%^BLACK%^is visible to you....\n\n"+
                "%^BOLD%^%^GREEN%^You watch in %^BOLD%^%^RED%^HORROR%^BOLD%^%^GREEN%^ as it tosses a %^BOLD%^%^CYAN%^large glowing "+
                "%^BOLD%^%^GREEN%^dice toward you!\n\n";

    mod = 15 + random(5);
    eventType = "exp bonus";
    eventNotify = mod+"% Bonus Exp!";
    eventMod = "%^BOLD%^%^WHITE%^The number %^CYAN%^1%^BOLD%^%^WHITE%^ lands facing up!!";

    eventDesc += eventMod +"\n\n";
    eventDesc += "%^BOLD%^%^BLACK%^The %^BOLD%^%^BLUE%^myst%^CYAN%^e%^BLUE%^r%^CYAN%^iou%^BOLD%^%^BLUE%^s %^BOLD%^%^WHITE%^being "+
                 "%^BOLD%^%^GREEN%^CACKLES%^BOLD%^%^BLACK%^ insanely for a brief moment before vanishing as suddenly as it appeared!%^RESET%^\n\n";
    eventDesc += "\n\n%^BOLD%^%^WHITE%^"+eventName+"%^BOLD%^%^WHITE%^ has been triggered!%^RESET%^";

    WORLD_EVENTS += ([eventName : (["type" : eventType, "end time" : NEXT_WEEKLY_EVENT_END,
    "event name" : eventName, "modifier" : mod, "announce" : 1, "announce to" : "world",
    "announce start" : eventDesc, "announce end" : "%^BOLD%^%^RED%^The event "+eventName+" has ended!%^RESET%^", "announced" : 0,
    "notification" : eventNotify, "increases delay" : 0, "weekly event" : 1]),]);

    if(flag)
    {
        world_events_save();
        announce_events();
    }
    return;
}


mixed query_event_notification(string eventName)
{
    string notification;
    if(!stringp(eventName)) return 0;
    if(!check_events()) return 0;
    if(!WORLD_EVENTS[eventName]) return 0;
    if(!stringp(notification = WORLD_EVENTS[eventName]["notification"])) return 0;
    return notification;
}

int event_time_remaining(string eventName)
{
    int remaining;
    if(!stringp(eventName)) return 0;
    if(!check_events()) return 0;
    if(!WORLD_EVENTS[eventName]) return 0;
    if(!intp(remaining = WORLD_EVENTS[eventName]["end time"])) return 0;
    remaining -= time();
    //remaining /= 60;
    return remaining;
}

void announce_events()
{
    string *events, thisEvent, msg, eventArea;
    int x;
    //if(!check_events()) return;
    if(!sizeof(events = keys(WORLD_EVENTS))) return;
    for(x = 0;x < sizeof(events);x++)
    {
        thisEvent = events[x];
        if(WORLD_EVENTS[thisEvent]["announced"] || !WORLD_EVENTS[thisEvent]["announce"]) continue;
        else
        {
            WORLD_EVENTS[thisEvent]["announced"] = 1;
            world_events_save();
            if(WORLD_EVENTS[thisEvent]["announce to"] == "world")
            {
                if(!stringp(msg = WORLD_EVENTS[thisEvent]["announce start"])) continue;
                message("tell", msg, users());
                continue;
            }
            else if(stringp(eventArea = WORLD_EVENTS[thisEvent]["announce to"]))
            {
                if(!stringp(msg = WORLD_EVENTS[thisEvent]["announce start"])) continue;
                broadcast_area(eventArea, msg);
                continue;
            }
        }
        continue;
    }
    return;
}

varargs mixed parsable_world_events(object who)
{
    string *events, *myEvents, myEvent, eventArea, myArea;
    int x;
    if(!check_events()) return 0;
    events = keys(WORLD_EVENTS);
    myEvents = ({});
    for(x = 0;x < sizeof(events);x++)
    {
        myEvent = events[x];
        if(WORLD_EVENTS[myEvent]["announce to"] == "world")
        {
            myEvents += ({WORLD_EVENTS[myEvent]["event name"]});
            continue;
        }
        if(!objectp(who)) continue;
        if(!objectp(environment(who))) continue;
        if(!stringp(myArea = base_name(environment(who)))) continue;
        if(!stringp(eventArea = WORLD_EVENTS[myEvent]["announce to"])) continue;
        if(strsrch(myArea, eventArea) == -1) continue;
        myEvents += ({WORLD_EVENTS[myEvent]["event name"]});
        continue;
    }
    if(!sizeof(myEvents)) return 0;
    return myEvents;
}

mixed identify_world_events() { return identify(WORLD_EVENTS); }

void heart_beat()
{
    if(!objectp(TO)) return;
    if(base_name(TO) != WORLD_EVENTS_D)
    {
        /*if(objectp(find_player("saide")))
        {
            tell_object(find_player("saide"), "Removing "+identify(TO)+"!");
        }*/
        TO->remove();
        return;
    }
    //check_events();
    establish_weekend_events();
    return;
}
