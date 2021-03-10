/*==============================================================================================================================================
Saide, April 2017 - A daemon to created phased worlds. Potentially both simply to work with and complex.

Alternative World Daemon - designed to allow on the fly creation of 'alternative versions' of areas.

**Important Varibles**
All are set using set("variable name", mixed value)

"alt world borders" - this is an array of room file names
                      A player cannot move into these rooms.
                      Peering into these rooms will give players a random
                      message about the "world ending" in that direction.

"alternative world" - the name for the alternative world - should be a unique name
                      this will show up on the 'wp' command and will serve as the method
                      for which alternative versions are linked together -
                      IE an alternative version of tabor with the name "Goblin Invasion"
                      will only link up with other rooms with this same name.
                      An alternative version of tabor with the name "Kobold Invasion"
                      will only link up with other rooms with this same name, neither will
                      be connected and both can exist at the same time.
                      The daemon will handle the various variables and assigning them.

alt world monsters -  This should be a mapping in the form of (["key" : value]),
                      key should be the monster file name, value should be the number of monsters to
                      create, much like the way that croom/cvault works - with one notable exception
                      explained with alt world monster chance.

alt world monster chance - This is a number that determines the percentage chance of a
                      particular monster spawning. The code will roll 1d100 versus this chance,
                      if the roll is greater then the monster will not be spawned.
                      The difference between this daemon and croom/cvault is that this
                      chance is checked for EACH monster file - so it's possible for a room
                      to spawn 1 monster in the list, or skip one, spawn one, skip one, spawn one.
                      If this is not set it defaults to random(25).

alt allow normal monsters - this can be a 1 or a 0, by default it is a 0. If it is a zero
                     then any monster, other than a guard, will "morph" into a random
                     monster from the monster list set by the variable alt world monsters -
                     if there is a list, otherwise it will behave as if you set it to 1.
                     When set to 1 then normal monsters which spawn in the normal version
                     of the area will be allowed to exist.

alt world guards   - This defaults to 0 if not set. By default guards that exist in
                     the normal version of an area will simply disappear in the alternative
                     version of the world. If you set this to 1 then the guards will remain
                     and behave as if they were in the normal world. ** NOTE ** I am not
                     sure what would happen if someone was put in jail in the alternative world.

alt world ends at  - This is a time value that the alternative world will expire at.
                     This is **NOT REQUIRED** but if you set it, make sure to do time() + integer value.
                     If time() is greater, then the world will expire on init(). Players will be moved
                     to either the real version of the room they are in, or whereever they
                     entered the alternative world at.

alt world special rooms - This is a mapping in the form of (["key" : "value"])
                     Key should be the string file name of the room in the original world that will be
                     replaced by the file name "value". So when players peer or move into the
                     room file name "key" the room will be replaced by the file in "value".
                     The exits from the original room will be set up in the new room, so the
                     new room will effectively be in the same position as the old room.

alt world exit rooms - This is an array list of rooms that "exit" from the alternative world.
                     Entering into one of these rooms will remove players from the alternative world.
                     If the player has "entered alt world" set on them - a string file name explained below
                     then entering one of these rooms will move the player to that location, otherwise it will
                     move the player to the "real" version of the room.

entered alt world   - This should be set on players who enter alternative worlds. It is not
                    required, but if it is not set then any player who is exiting an alternative "world"
                    will be moved to the base name of the file that they are in when they exit the world.

****************************************************************************
Below is an example of an automatically created alternative version of tabor
when the gong in the goblin stronghold is struck.
****************************************************************************

Below is the code used in the goblin stronghold when the gong is struck.
It creates an automated alternative version of Tabor that has goblins
over-running it. There are a few different variable names passed
to the alt_world_perimeters() function that are not important above.
I will explain those below.

**EXPLAINATION**
************************************************************
Below code creates a new copy of the object that handles
automatically created an alternative world

ob1 = new("/d/common/obj/special/alt_world_creator.c");

END
************************************************************

ob1->alt_world_perimeters(
(["alt world borders" : ({"/d/darkwood/tabor/road/road4", "/d/shadow/virtual/river/tabor.dock", "/d/shadow/room/forest/road58", "/d/koenig/streams/path18"}),

"alt world monsters" : (["/d/shadow/room/goblin/mon/archer.c" : 1 + random(2),
"/d/shadow/room/goblin/mon/soldier.c" : 1 + random(2),
"/d/shadow/room/goblin/mon/raider.c" : 1 + random(2),
"/d/shadow/room/goblin/mon/footman.c" : 1 + random(2),]),

"alt world monster chance" : 20 + random(20),

"alt allow normal monsters" : 1,

"alt world ends at" : 3600,

***************************************************************************************
**EXPLAINATION**

"start room" - this is the first room that will be cloned and that players
will be moved into. A copy of it will be created, variables will be set up on
it and then players will be moved into this new version. Once this happens
the daemon will handle keeping track of all of the various variables

"start room" : "/d/darkwood/tabor/room/math1",

**END**
***************************************************************************************

***************************************************************************************
**EXPLAINATION**

"low level" is the level below which a player will not receive an
invitation to join in an automated alternative world,

"high level" is the level above which a player will not receive an
invitation to join in an automated alternative world,

In the below example any online players between levels 6 and 12 will receive
an invitation to join the alternative world 'tabor invasion'

"low level" : 6, "high level" : 12,

**END**
***************************************************************************************


*********************************************************************************************************************************************************
**EXPLAINATION**

"invite msg" - this is the message that will be sent to any players online who qualify to enter a automated random event.
This is fully customizable, with a couple of exceptions. First, there is approximately 4 minutes ONLY
for a player to either type "yes/y" or "no/n". Furthermore, this message should notify them
that they need to type either yes or no, otherwise they will not be aware of this.

"invite msg" : "%^BOLD%^%^WHITE%^You are invited to participate in a Phased event, "+
"'%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'. You will be in an alternative version of "+
"Tabor that is being over run by %^BOLD%^%^RED%^Goblins%^BOLD%^%^WHITE%^. Only other online users who are "+
"an appropriate level will be inside the world with you. There will be borders which you cannot move beyond. "+
"This particular event will last for approximately one real life hour. If you die within the event if "+
"there is no one inside who can ressurect you, then you will be out of it. Can you live to tell the tale?\n\n"+
"If you wish to participate then simply "+
"type '%^BOLD%^%^CYAN%^yes%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^y%^BOLD%^%^WHITE%^'. If you do not wish to participate "+
"you may type '%^BOLD%^%^CYAN%^no%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^'. You have approximately "+
"four minutes to accept this invitation. After all players have responded the event will start and you will be moved into the alternative "+
"version of Tabor.%^RESET%^",

**END**
**********************************************************************************************************************************************************

**********************************************************************************************************************
**EXPLAINATION**

"accept msg" - this is the message that a player who accepts by typing yes or y will see, if they are invited into an
alternative world automatically.

"accept msg" : "%^BOLD%^%^WHITE%^You have accepted the invitation for the phased event '%^BOLD%^%^BLACK%^"+
"Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'. The event will start momentarily.%^RESET%^",

**END**
**********************************************************************************************************************

****************************************************************************************************************************************
**EXPLAINATION**

"decline msg" - this is the message that a player who declines by typing no or n will see, if they were invited
into an automated alternative world.

"decline msg" : "%^BOLD%^%^WHITE%^"+
"You have declined the invitation for the phased event '%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'.%^RESET%^",

**END**
****************************************************************************************************************************************

***********************************************************************************************************************************
**EXPLAINATION**

"start msg" - this is the message that a player who has accept an invitation will see when an alternative world is actually
created and they are moved into it.

"start msg" : "%^BOLD%^%^CYAN%^The timed phased event '%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^CYAN%^' "+
"is now starting! You are now within a version of Tabor that is being over-run by goblins... do you have "+
"what it takes to survive? Or will you be slaughted and left to rot?%^RESET%^"]));

**END**
***********************************************************************************************************************************

*******************************************
**EXPLAINATION**
The below will set up the object to
have the correct "alternative world"
name to be used with this daemon.

ob1->alt_world("tabor invasion");

**END**
******************************************


**TO DO**

allow custom room descriptions to replace original descriptions.

**IMPORTANT NOTES**

The code is pretty customizable. I am going to set up the areas on dallyh to work
quite differently. I will post the code inside this daemon when I have it set up, but
by setting up "special rooms" with code inside those rooms to remove players from alternative
worlds or simply end the alternative world when something is done by some player, the
potential is pretty extreme.

Hopefully these explainations make the daemon easier to understand/work with. Ultimately
some of the decisions will need to be made by you, the creator. Feel free to send me
mails about any questions/suggestions.
===================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>

#define WORLD_SHIFT "%^BOLD%^%^BLACK%^The world around you fades away.... and you find yourself somewhere else!%^RESET%^"
#define MORPH_OB "/d/common/obj/special/alt_world_change"

/**
 * @file
 */

void create_random_alt_world_monsters(object area);
void update_alt_world(string awname, object questOb, int monstercount, object my);

int room_check(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->is_room()) return 1;
    return 0;
}

int alt_room_check(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->is_room() && ob->query("alternative world")) return 1;
    return 0;
}

int living_valid_environment(object ob)
{
    if(!objectp(ob)) return 0;
    if(!objectp(environment(ob))) return 0;
    return 1;
}

int user_check(object ob)
{
    if(!objectp(ob)) return 0;
    if(userp(ob)) return 1;
    return 0;
}

int alt_world_border(object loc, string awname)
{
    string *aborders;
    if(!objectp(loc)) return 0;
    if(!stringp(awname)) return 0;
    if(loc->query("alternative world") == awname)
    {
        if(!pointerp(aborders = loc->query("alt world borders"))) return 0;
        if(member_array(base_name(loc), aborders) != -1) return 1;
    }
    return 0;
}

void alt_world_border_messages(object who, object dest)
{
    string peer_message;
    if(!objectp(who)) return;
    if(!objectp(dest) || !stringp(peer_message = dest->query("alt world border message")))
    {
        switch(random(10))
        {
            case 0..1:
                tell_object(who, "%^BOLD%^%^GREEN%^The world seems to simply fade away in that direction....%^RESET%^");
                break;
            case 2..4:
                tell_object(who, "%^BOLD%^%^RED%^A nightmarish world exists in that direction.... one which breaks apart as "+
                "you gaze upon it!%^RESET%^");
                break;
            case 5..6:
                tell_object(who, "%^BOLD%^%^WHITE%^You see flashes of your own life... briefly before a nothingness consumes your vision.%^RESET%^");
                break;
            case 7..8:
                tell_object(who, "%^BOLD%^%^CYAN%^A vast void stretches as far as the eyes can see.....%^RESET%^");
                break;
            case 9:
                tell_object(who, "%^BOLD%^%^BLACK%^A darkness seeps out of the land in that direction before quickly overtaking it!%^RESET%^");
                break;
        }
    }
    else if(stringp(peer_message)) tell_object(who, peer_message);
    return;
}

void clear_alt_vars(object who)
{
    if (!objectp(who))
        return;
    who->delete("entered alt world");
    who->delete("leaving alt world");
    who->delete("alt world borders");
    who->delete("alt world monsters");
    who->delete("alt world monster chance");
    who->delete("alt allow normal monsters");
    who->delete("alternative world guards");
    who->delete("leaving alt world");
    who->delete("alternative world");
    who->delete("created for");
    who->delete("created for player");
    who->delete("alt world quest");
    who->delete("reward type");
    who->delete("party area");
    return 1;
}

varargs mixed remove_from_alt_world(object who)
{
    string entrypoint;
    if(!objectp(who)) return; //uh-oh something went wrong

    if(stringp(entrypoint = who->query("entered alt world")))
    {
        if(file_exists(entrypoint) || file_exists(entrypoint +".c"))
        {
            tell_object(who, WORLD_SHIFT);
            who->set("leaving alt world", 1);
            who->move(entrypoint);
            if(!who->query_invis())
            {
                tell_room(environment(who), who->QCN+"%^BOLD%^%^BLACK%^ suddenly appears!!%^RESET%^", who);
            }
            clear_alt_vars(who);
            return entrypoint;
        }
        else entrypoint = 0;
    }
    if(!stringp(entrypoint) || entrypoint == 0)
    {
        entrypoint = base_name(environment(who));
        who->set("leaving alt world", 1);
        tell_object(who, WORLD_SHIFT);
        who->move(entrypoint);
        if(!who->query_invis())
        {
            tell_room(environment(who), who->QCN+"%^BOLD%^%^BLACK%^ suddenly appears!!%^RESET%^", who);
        }
        clear_alt_vars(who);
        return entrypoint;
    }
    return;
}

mixed find_alt_world(mixed targ)
{
    object *to_check, obj_check, createdFor, QuestObject;
    string awname, *aborders, *exitrooms, pname, reward;
    int x, tellflag, guards_ok, norm, spawn, end_time, count, questarea, party_area;
    mapping amonsters, specialrooms;
    to_check = previous_object(-1);
    to_check = filter_array(to_check, "room_check", TO);
    if(stringp(targ) && strsrch(targ, "/d/common/boards") != -1) return ([]);
    if(objectp(targ) && strsrch(base_name(targ), "/d/common/boards") != -1) return ([]);
    if(!sizeof(to_check))
    {
        to_check = previous_object(-1);
        foreach(object ob in to_check)
        {
            if(!objectp(ob)) continue;
            if(!environment(ob)) continue;
            if(userp(ob)) continue;
            if(objectp(environment(ob)) && userp(environment(ob)))
            {
                to_check += ({environment(ob)});
                continue;
            }
            if(objectp(environment(environment(ob))) && userp(environment(environment(ob))))
            {
                to_check += ({environment(environment(ob))});
                continue;
            }
            continue;
        }
        to_check = filter_array(to_check, "user_check", TO);
    }
    if(!sizeof(to_check)) return ([]);
    for(x = 0;x < sizeof(to_check);x++)
    {
        if(stringp(awname))
            continue;
        if(!to_check[x]->query("alternative world"))
            continue;
        if(userp(to_check[x]))
        {
            obj_check = environment(to_check[x]);
        }
        else { obj_check = to_check[x]; }
        if(objectp(obj_check))
        {
            awname = obj_check->query("alternative world");
            aborders = obj_check->query("alt world borders");
            amonsters = obj_check->query("alt world monsters");
            guards_ok = obj_check->query("alternative world guards");
            norm = obj_check->query("alt allow normal monsters");
            spawn = obj_check->query("alt world monster chance");
            end_time = obj_check->query("alt world ends at");
            specialrooms = obj_check->query("alt world special rooms");
            exitrooms = obj_check->query("alt world exit rooms");
            createdFor = obj_check->query("created for");
            pname = obj_check->query("created for player");
            reward = obj_check->query("reward type");
            if(!objectp(QuestObject)) QuestObject = obj_check->query("alt world quest item");
            count = obj_check->query("monster count");
            party_area = obj_check->query("party area");
            questarea = obj_check->query("party area");
            if(!spawn) spawn = 25;
        }
        if(!pointerp(aborders)) continue;
        if(member_array(base_name(targ), aborders) != -1 || (stringp(targ) && member_array(targ, aborders) != -1) &&
        member_array(to_object("/cmds/mortal/_peer"), previous_object(-1)) == -1)
        {
            if(userp(to_check[x])) targ = environment(to_check[x]);
            else targ = to_check[x];
        }
        continue;
    }
    if(!stringp(awname)) return ([]);
    to_check = filter_array(previous_object(-1), "user_check", TO);
    if(sizeof(to_check))
    {
        for(x = 0;x < sizeof(to_check);x++)
        {
            if(!objectp(to_check[x])) continue;
            if(to_check[x]->query("leaving alt world"))
            {
                return ([]);
            }
        }
        if(!sizeof(to_check)) return ([]);
    }
    return (["target" : targ, "awname" : awname, "awborders" : aborders, "amonsters" : amonsters, "guards_ok" : guards_ok, "norm" : norm,
    "spawn" : spawn, "end time" : end_time, "special rooms" : specialrooms, "exit rooms" : exitrooms, "created for" : createdFor, "reward type" : reward,
    "QuestObject" : QuestObject, "created for player" : pname, "monster count" : count, "party area" : party_area, "alt world quest" : questarea ]);
}

mixed find_alt(mixed targ)
{
    string child_file, awname, *aborders, altdesc, *sprooms, *exitrooms;
    object *chilrens, altworld, bb, *to_check;
    mapping mymap, amonsters, specialrooms;
    mixed otarg;
    int x, guards_ok = 0, norm = 0, spawn = 25, end_time, is_spec = 0;
    otarg = targ;
    mymap = find_alt_world(targ);
    awname = mymap["awname"];
    if(!stringp(awname)) return targ;
    aborders = mymap["awborders"];
    amonsters = mymap["amonsters"];
    guards_ok = mymap["guards_ok"];
    targ = mymap["target"];
    norm = mymap["norm"];
    spawn = mymap["spawn"];
    end_time = mymap["end time"];
    specialrooms = mymap["special rooms"];
    exitrooms = mymap["exit rooms"];
    if(!spawn) spawn = 25;
    //else return targ;
    if(objectp(targ)) child_file = base_name(targ);
    else if(stringp(targ)) child_file = targ;
    else
    {
        return targ;
    }
    if(mapp(specialrooms) && sizeof(sprooms = keys(specialrooms)))
    {
        if(member_array(child_file, sprooms) != -1)
        {
            child_file = specialrooms[child_file];
            is_spec = 1;
        }
    }
    chilrens = children(child_file);
    for(x = 0;x < sizeof(chilrens);x++)
    {
        if(!objectp(chilrens[x])) continue;
        if(chilrens[x]->query("alternative world") != awname) continue;
        else
        {
            altworld = chilrens[x];
            break;
        }
        continue;
    }
    if(!objectp(altworld))
    {
        if(file_exists(child_file) || file_exists(child_file + ".c"))
        {
            altworld = new(child_file);
            altworld->set("alternative world", awname);
            altworld->set("alt world borders", aborders);
            altworld->set("alt world monsters", amonsters);
            altworld->set("alt world guards", guards_ok);
            altworld->set("alt allow normal monsters", norm);
            altworld->set("alt world monster chance", spawn);
            altworld->set("alt world ends at", end_time);
            altworld->set("alt world special rooms", specialrooms);
            altworld->set("alt world exit rooms", exitrooms);
            altworld->set("created for", mymap["created for"]);
            altworld->set("reward type", mymap["reward type"]);
            altworld->set("alt world quest item", mymap["QuestObject"]);
            altworld->set("monster count", mymap["monster count"]);
            altworld->set("party area", mymap["party area"]);
            altworld->set("created for player", mymap["created for player"]);
            altworld->set("alt world quest", mymap["alt world quest"]);
            if(is_spec)
            {
                sprooms = otarg->query_exits();
                specialrooms = ([]);
                for(x = 0;x < sizeof(sprooms);x++)
                {
                    specialrooms += ([sprooms[x] : otarg->query_exit(sprooms[x])]);
                    continue;
                }
                altworld->set_exits(specialrooms);
            }
            if(objectp(bb = present("board", altworld))) bb->remove();
            if(objectp(altworld) && !altworld->query_property("no teleport")) altworld->set_property("no teleport", 1);
            if(objectp(altworld) && !altworld->query_property("no scry")) altworld->set_property("no scry", 1);
            if(objectp(altworld) && !altworld->query_property("no pocket space")) altworld->set_property("no pocket space", 1);
            create_random_alt_world_monsters(altworld);
            return altworld;
        }
        else return targ;
    }
    if(objectp(altworld) && !altworld->query_property("no teleport")) altworld->set_property("no teleport", 1);
    create_random_alt_world_monsters(altworld);
    return altworld;
}

string random_spawn_message(object mymob)
{
    if(!objectp(mymob))
    {
        return "An error monster falls out of the sky!!";
    }
    return mymob->QCN+"%^BOLD%^%^WHITE%^ materializes in front of you!%^RESET%^";
}

void spawn_quest_item(object area)
{
    object QuestOb;
    if(!objectp(area)) return;
    if(roll_dice(3, 10) < roll_dice(1, 100) || objectp(QuestOb = area->query("alt world quest item"))) return;
    QuestOb = new("/d/common/obj/special/alt_world_fragment");
    QuestOb->set_reward_type(area->query("reward type"));
    update_alt_world(area->query("alternative world"), QuestOb, (int)area->query("monster count"), area);
    return;
}

void setup_alt_monster(object mob, object player)
{
    int newlev, x, mod;
    string *mclasses;
    if(!objectp(mob)) return;
    if(!objectp(player))
    {
        if(!objectp(player = find_player(environment(mob)->query("created for player")))) return;
    }
    newlev = player->query_base_character_level();
    if(mob->query_level() < newlev)
    {
        for(x = 0;x < sizeof(mclasses = mob->query_classes());x++)
        {
            mob->set_guild_level(mclasses[x], newlev);
            mob->set_mlevel(mclasses[x], newlev);
            continue;
        }
    }
    switch(newlev)
    {
        case 0..10:
            mod = newlev*7;
            break;
        case 11..20:
            mod = newlev*8;
            break;
        case 21..25:
            mod = newlev*12;
            break;
        case 26..30:
            mod = newlev * 14;
            break;
        case 31..35:
            mod = newlev * 16;
            break;
        case 36..40:
            mod = newlev * 20;
            break;
        case 41..45:
            mod = newlev * 25;
            break;
        case 46..50:
            mod = newlev * 35;
            break;
    }
    if(mob->query_max_hp() < mod)
    {
        mob->set_max_hp((mod + random(mod)));
        mob->set_hp((int)mob->query_max_hp());
    }
    mob->set_max_level(newlev+5);
    mob->set_new_exp(newlev, "normal");
    return;
}

void create_random_alt_world_monsters(object area)
{
    string *mychoices, my_choice;
    int chance = 0, x, i, flag, mcount = 0;
    mapping mymonsters;
    object mymob, *mymobs, QuestOb;
    if(!objectp(area) || !area->query("alternative world"))
    {
        return;
    }
    if(area->query("no alt monsters") && !area->query("alt world quest"))
    {
        return;
    }
    if(area->query("alt world monsters placed") || area->query("no alt monsters"))
    {
        if(area->query("alt world monsters placed") > time())
        {
            return;
        }
        spawn_quest_item(area);
    }
     if(pointerp(mymobs = area->query("spawned alt world monsters")))
    {
        mymobs = filter_array(mymobs, "living_valid_environment", TO);
        if(sizeof(mymobs)) return;
    }
    if(!mapp(mymonsters = area->query("alt world monsters")) || !sizeof(mychoices = keys(mymonsters)))
    {
        area->set("no alt monsters", 1);
        return;
    }
    chance = area->query("alt world monster chance");
    if(!chance) chance = random(25);
    mymobs = ({});
    for(x = 0;x < sizeof(mychoices);x++)
    {
        if(roll_dice(1, 100) > chance) continue;
        my_choice = mychoices[random(sizeof(mychoices))];
        if(!i = mymonsters[my_choice]) i = 1;
        while(i--)
        {
            if(catch(mymob = new(my_choice)))
            {
                log_file("alternative_world_fails", "Failed to create new monster "+my_choice+
                " at "+base_name(area)+" in alternative world "+area->query("alternative world")+"\n");
                continue;
            }
            if(objectp(mymob))
            {
                mymob->set("alternative world okay", 1);
                if(area->query("alt world quest") && !objectp(area->query("alt world quest item")))
                {
                    if(area->query("monster count") > roll_dice(1, 45))
                    {
                        if(!random(2))
                        {
                            QuestOb = new("/d/common/obj/special/alt_world_fragment");
                            QuestOb->set_reward_type(area->query("reward type"));
                            if(roll_dice(1,20) > 10) QuestOb->move(mymob);
                            else QuestOb->move(area);
                            area->set("alt world quest item", QuestOb);
                        }
                    }
                }
                mcount++;
                area->set("monster count", ((int)area->query("monster count") + 1));
                mymob->move(area);
                mymob->setup_alt_monster(mymob, area->query("created for"));
                mymob->set_property("swarm", 1);
                mymob->set_property("full attacks", 1);
                foreach(object mobitem in all_inventory(mymob))
                {
                    if(!objectp(mobitem)) continue;
                    if(mobitem == QuestOb || mobitem->id("alt world quest item")) continue;
                    mobitem->set_property("monsterweapon", 1);
                    mobitem->set_property("monster weapon", 1);
                    continue;
                }
                mymobs += ({mymob});
                tell_room(area, random_spawn_message(mymob));
                continue;
            }
        }
        mychoices -= ({my_choice});
        continue;
    }
    if(sizeof(mymobs)) area->set("spawned alt world monsters", mymobs);
    area->set("alt world monsters placed", (time() + 1200 + random(601)));
    update_alt_world(area->query("alternative world"), QuestOb, (int)area->query("monster count"), area);
    return;
}

//should they be in this world? if not move them to the "real world"
//or move them to the point where they entered the alternative world
//if it's a monster - should it be in the alternative world or should it
//be morphed to something else? if so, to what?
void in_alt_world(object who, object area)
{
    int norm, end_time, flag = 0;
    object morph_obj;
    string *exit_rooms;
    if(!objectp(area) || !objectp(who)) return;
    if(!area->query("alternative world")) return;
    if(who->query("leaving alt world")) return;
    if(who->query("alternative world okay")) return;
    if(userp(who))
    {
        if(intp(end_time = area->query("alt world ends at")))
        {
            if(end_time > 0 && time() > end_time) flag = 2;
        }
        if(!flag && pointerp(exit_rooms = area->query("alt world exit rooms")))
        {
            if(member_array(base_name(area), exit_rooms) != -1) flag = 1;
        }
        if(!flag && who->query("alternative world check") > time()) return;
        if(!stringp(who->query("alternative world")) ||
        ((string)who->query("alternative world") != (string)area->query("alternative world")) || flag == 1 || flag == 2)
        {
            if(flag == 2) { clear_alt_world(area->query("alternative world")); }
            else remove_from_alt_world(who);
            return;
        }
        if(area->query("alt world quest") == 1 && !objectp(area->query("created for")))
        {
            if(!objectp(find_player(area->query("created for player"))))
            {
                remove_from_alt_world(who);
                return;
            }
            else
            {
                area->delete("created for");
                area->set("created for", find_player(area->query("created for player")));
            }
        }
        who->set("alternative world check", (time() + 600));
        return;
    }
    //if it's a guard and guards aren't set up to be allowed - remove it.
    if(who->is_guardsman())
    {
        if(area->query("alt world guards"))
        {
            who->set("alternative world okay", 1);
            return;
        }
        tell_room(area, who->QCN+"%^BOLD%^%^CYAN%^ simply fades away!%^RESET%^");
        who->move("/d/shadowgate/void");
        if(objectp(who)) who->remove();
        return;
    }
    //it's a minion or a merc - do nothing/if normal monsters are allowed - do nothing.
    norm = area->query("alt allow normal monsters");
    if(who->is_merc() || who->query_property("minion") || who->query_property("spell_creature") || norm > 0) return;
    if(who->query_property("alt_world_morphing") || who->query("alternative world okay")) return;
    else
    {
        morph_obj = new(MORPH_OB);
        morph_obj->move(who);
        if(objectp(who)) who->set_property("alt_world_morphing", 1);
        return;
    }
    return;
}

int base_filename_check(object ob, string file)
{
    if(!objectp(ob)) return 0;
    if(base_name(ob) == file) return 1;
    return 0;
}

mixed check_objects(string file)
{
    object *obs, tar;
    int x;
    string msg = "";
    if(!stringp(file)) return;
    obs = filter_array(objects(), "base_filename_check", TO, file);
    if(!sizeof(obs))
        return;
    for(x = 0;x < sizeof(obs);x++)
    {
        if(file == "/std/bboard" && (!objectp(environment(obs[x])) || clonep(environment(obs[x]))))
        {
            obs[x]->remove();
            continue;
        }
        if(!objectp(obs[x]))
        {
            msg += "One invalid object with base name "+file+".\n\n";
        }
        else
        {
            msg += "Environment of "+identify(obs[x])+" = "+identify(environment(obs[x]))+".\n";
            msg += "Creator of "+identify(obs[x]) + " = "+obs[x]->query_creator()+".\n";
        }
        if(objectp(tar)) tell_object(tar, msg);
        msg = "";
        continue;
    }
    return;
}

void update_alt_world(string awname, object questOb, int monstercount, object my)
{
    object *obs;
    int x;
    obs = filter_array(objects(), "alt_room_check", TO);
    obs -= ({my});
    if(!objectp(questOb)) return;
    if(!sizeof(obs)) return;
    for(x = 0;x < sizeof(obs);x++)
    {
        if(!objectp(obs[x])) continue;
        if(obs[x] == my) continue;
        if((stringp(awname) && awname == obs[x]->query("alternative world")))
        {
            obs[x]->delete("monster count");
            obs[x]->delete("alt world quest item");
            obs[x]->set("monster count", monstercount);
            obs[x]->set("alt world quest item", questOb);
            continue;
        }
        continue;
    }
    return;
}

varargs void clear_alt_world(string awname, int flag)
{
    object *obs, *myinventory, targroom, *move_to;
    int x, count = 0, y;
    obs = filter_array(objects(), "alt_room_check", TO);
    if(!sizeof(obs))
        return;
    if(flag && !stringp(awname)) return;
    for(x = 0;x < sizeof(obs);x++)
    {
        if(!objectp(obs[x])) continue;
        if(!stringp(awname) || (stringp(awname) && awname == obs[x]->query("alternative world")))
        {
            //filter through list of objects in rooms - move players to where they entered
            //or the base name of the alternative world
            myinventory = ({});
            if(sizeof(myinventory = all_inventory(obs[x])))
            {
                move_to = ({});
                for(y = 0;y < sizeof(myinventory);y++)
                {
                    if(!objectp(myinventory[y])) continue;
                    if(userp(myinventory[y]))
                    {
                        remove_from_alt_world(myinventory[y]);
                        if(objectp(myinventory[y])) targroom = environment(myinventory[y]);
                        continue;
                    }
                    if(myinventory[y]->is_merc() || myinventory[y]->query_property("minion") || myinventory[y]->query_property("spell_creature"))
                    {
                        move_to += ({myinventory[y]});
                        continue;
                    }
                    if(myinventory[y]->is_monster())
                    {
                        myinventory[y]->move("/d/shadowgate/void");
                        if(objectp(myinventory[y])) myinventory[y]->remove();
                        continue;
                    }
                    move_to += ({myinventory[y]});
                    continue;
                }
                foreach(object targob in move_to)
                {
                    if(!objectp(targob)) continue;
                    if(objectp(targroom) && base_name(targob) != "/d/shadow/obj/special/signpost")
                    {
                        targob->move(targroom);
                        continue;
                    }
                    targob->move("/d/shadowgate/void");
                    if(objectp(targob)) targob->remove();
                    continue;
                }
            }
            obs[x]->remove();
            count++;
            continue;
        }
    }
    return;
}
