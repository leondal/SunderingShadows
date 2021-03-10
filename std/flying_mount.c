// /std/flying_mount.c
// Inherit for animals that can fly from place to place similar to teleport
// Created on 08/02/09 by Ares

#include <std.h>
#include <daemons.h>

inherit "/std/riding_animal.c";

string FLYING_ROOM = "/std/flying_room";

#include <common_destinations.h>

nosave string FLIGHT;    // string to keep track of what "stage" of flight its in, default is landed
string too_soon;  // The message the mount gives if they try to fly it too often
int flying_prof;  // different from riding prof, so it can be harder/easier to fly than to ride
int flight_delay; // can fly TWICE in this time period, so once there and once back
int flights;      // to track number of flights its made, this will clear after the time limit passes
int initial_time; // first time the mount flew
int rested_time;  // time it will be when it's no longer "tired"
int ward_pass;    // strength to bypass teleport wards, for rooms that use "teleport proof", rather than "no teleport"
int FLY_DEAD;     // on the off chance somebody decides to kill their mount it flight, we want it to temporarily wait to die so it doesn't bug

void create()
{
    ::create();
    FLIGHT = "landed";
    set_id(({"steed","mount"}));
    set_name("a winged steed");
    set_short("A winged steed");
    set_long("This is a noble winged steed, you should never see "
        "this description.");
}

// needs to be set in number of seconds between round trips (can fly twice in this time span)
void set_flight_delay(int num) { flight_delay = num; }

// returns the delay in SECONDS per round trip.. meaning fly to somewhere and back
int query_flight_delay()
{
    if (!flight_delay) {
        return 1800;
    }
    return flight_delay;
}

// sets the athletics skill you need to fly this mount
void set_flying_prof(int num) { flying_prof = num; }

// returns the prof to fly the mount, it's different than just riding, but defaults to normal riding if you don't set it
int query_flying_prof()
{
    if(flying_prof) { return flying_prof; }
    return query_riding_level();
}

// returns whatever the current stage is, if it's not in the air, it returns "landed"
string query_fight_stage() { return FLIGHT; }

// sets the stage of flight the mount is in, for the purpose of pretty messages
void set_flight_stage(string str) { FLIGHT = str; }

// used to set the message for flying too often/too tired
void set_too_soon_message(string str) { too_soon = str; }

// message for the mount being too tired, it has a default if it's not set
string query_too_soon_message()
{
    if(stringp(too_soon) && too_soon != "") { return too_soon; }
    return "Your mount is too tired to fly again right now.";
}

// sets how strong of a no-tp ward that they can pass
void set_ward_pass(int num) { ward_pass = num; }

// returns the strength for the purpose of bypassing tp wards
int query_ward_pass()
{
    if(ward_pass) { return ward_pass; }
    return (int)TO->query_level();
}


// checks if the mount is too tired to fly again and keeps track of when they'll be rested
int flight_check()
{
    switch(flights)
    {
    case 0:
        initial_time = time();
        rested_time = initial_time + query_flight_delay();
        flights = 1;
        return 1;
    case 1:
        if(time() > rested_time)
        {
            initial_time = time();
            rested_time = initial_time + query_flight_delay();
            flights = 1;
            return 1;
        }
        else
        {
            flights = 2;
            return 1;
        }
    default:
        if(time() > rested_time)
        {
            initial_time = time();
            rested_time = initial_time + query_flight_delay();
            flights = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

// handles the skill check to ride the mount
int ride_check(object obj)
{
    int skill,check,result;

    if(!objectp(obj)) { return 0; }

    skill = (int)obj->query_skill("athletics");
    check = query_flying_prof();

    skill = roll_dice(4,6) + skill;
    if(obj->query_blind()) { skill = skill - 5; } // penalty if they can't see
    result = skill - check;

    if(result > 0) { return 1; }                    //  1 passed
    if(result <= 0 && result >= -4) { return 0; }   //  0 bad location
    if(result < -4) { return -1; }                  // -1 fall
}

// returns 0 if they don't remember the location
int location_check(object obj,string location)
{
    string *remembered=({});
    if(!objectp(obj)) { return 0; }
    if(!stringp(location) || location == "" || location == " ") { return 0; }

    remembered = (string *)obj->query_rem_rooms_sort();

    if(member_array(location,remembered) == -1) { return 0; }
    return 1;
}

// checks to make sure the rooms aren't bugged and/or teleport proof and they're both outdoors
string room_check(object obj,string location)
{
    object start,end;
    string room;
    mapping temp;
    int start_proof,end_proof,power;

    if(!objectp(obj)) { return ""; }
    if(!stringp(location) || location == "" || location == " ") { return ""; }

    temp = obj->query_rem_rooms();

    room = temp[location];

    if (!temp[location]) {
        room = preset_destinations[location];
    }

    if(!stringp(room) || room == "" || room == " ")
    {
        tell_object(obj,"You don't know a place called "+location+" to fly to.");
        return "";
    }
    if(!objectp(find_object_or_load(room)))
    {
        tell_object(obj,"Something is wrong with the location "+location+", you can't fly there.");
        return "";
    }

    end   = find_object_or_load(room);
    start = environment(obj);

    if(start == end)
    {
        tell_object(obj,"You are already there, no reason to fly!");
        return "";
    }

    start_proof = (int)start->query_property("teleport proof");
    end_proof   = (int)end->query_property("teleport proof");
    power       = query_ward_pass();

    if(power < start_proof || power < end_proof)
    {
        tell_object(obj,"Just as you begin to take off, the hairs on the back of "
            "your neck stand on end.  You get the overwhelming feeling that flying "
            "would be a bad idea right now.");
        return "";
    }

    if(start->query_property("indoors"))
    {
        tell_object(obj,"You can't take off from inside here!");
        return "";
    }
    if(end->query_property("indoors"))
    {
        tell_object(obj,"Your destination must be outdoors.");
        return "";
    }

    if(start->query_property("no teleport") || end->query_property("no teleport"))
    {
        tell_object(obj,"Just as you begin to take off, the hairs on the back of "
            "your neck stand on end.  You get the overwhelming feeling that flying "
            "would be a bad idea right now.");
        return "";
    }

    return base_name(end);
}

// checks various status effects, including if they're mounted and they own the mount
int status_check(object obj)
{
    if(!objectp(obj)) { return 0; }

    if((object)obj->query_in_vehicle() != TO)
    {
        tell_object(obj,"You must be mounting the "+TO->query_short()+" in order to fly it.");
        return 0;
    }
    if(!TO->query_owner() || (object)TO->query_owner() != obj)
    {
        tell_object(obj,"You can only fly your own mount!");
        return 0;
    }

    if(obj->query_bound() || obj->query_tripped() || obj->query_paralyzed())
    {
        obj->send_paralyzed_message("info",obj);
        return 0;
    }

    return 1;
}

// this is to filter out rooms they should be miss-teleport(flying) into
int valid_room_filter(string room)
{
    int length;
    string test;
    object obj;

    if(!stringp(room)) { return 0; }
    length = strlen(room);
    test = room[length-2..length];
    if(test != ".c") { return 0; }
    if(!objectp(obj = find_object_or_load(room))) { return 0; }
    if(obj->query_property("no teleport")) { return 0; }
    if(obj->query_property("teleport proof")) { return 0; }
    if(obj->query_property("indoors")) { return 0; }
    if(!obj->is_room()) { return 0; }
    return 1;
}

// to get the room they'll land in if they fail a riding check
string get_bad_room(string begin,string finish,int which)
{
    object start,end,final=0;
    string path,bad,*rooms=({}),*tmp=({});
    int i,num;

    if(!stringp(begin))  { return ""; }
    if(!stringp(finish)) { return ""; }
    if(!intp(which))     { return ""; }

    if(!objectp(start = find_object_or_load(begin))) { return ""; }
    if(!objectp(end = find_object_or_load(finish))) { return ""; }

    if(which < 2)  { path = begin; }
    else           { path = finish; }

    num = strsrch(path,"/",-1) + 1;
    path = arrange_string(path,num);

    rooms = get_dir(path);
    if(!sizeof(rooms)) { return begin; }
    for(i=0;i<sizeof(rooms);i++)
    {
        tmp += ({ ""+path+""+rooms[i]+"" });
    }
    rooms = tmp;

    rooms = filter_array(rooms,"valid_room_filter",TO);
    rooms -= ({ path +""+begin+".c" });
    rooms -= ({ path +""+finish+".c" });

    if(!sizeof(rooms)) { return begin; }

    bad = rooms[random(sizeof(rooms))];
    return bad;
}

// gets the mount independant messages to play during flight
// can override this function to make messages of your own
string flight_messages(string stage)
{
    string *choices,sh;

    sh = orig_short;

    switch(stage)
    {
    case "begin":
    case "initial climb":

        choices = ({ "%^CYAN%^You feel your stomach fall as "+sh+" %^RESET%^%^CYAN%^rapidly climbs into the air!%^RESET%^",
            "%^BOLD%^%^GREEN%^Your breath catches as "+sh+" %^RESET%^%^BOLD%^%^GREEN%^quickly climbs straight up!%^RESET%^",
            "%^BLUE%^A cold wind chills you as the rapid climb rushes through a pocket of frigid air!%^RESET%^",
            "%^GREEN%^You can see the tops of trees growing smaller underneath you!%^RESET%^",
            "%^BOLD%^You can see what looks like people watching you from a building in the distance.%^RESET%^"});
        break;

    case "climbing":

        choices = ({ "%^GREEN%^The trees grow smaller as your "+sh+" %^RESET%^%^GREEN%^quickly climbs into the sky!%^RESET%^",
            "%^BOLD%^The shapes of buildings get more difficult to distinguish as the ground gets further beneath you!.%^RESET%^",
            "%^WHITE%^Your "+sh+" dips in a sudden current of air and you feel weightless for a moment!%^RESET%^",
            "%^BLUE%^An icy wind blows hard against your skin, causing your teeth to chatter!%^RESET%^",
            "%^YELLOW%^The sky above looks incredibly vivid as you get closer to the heavens themselves!%^RESET%^",});
        break;

    case "soaring":

        choices = ({ "%^BOLD%^Distant mountain peaks form a jagged line on the horizon as you glide weightlessly through the air on your "+sh+".%^RESET%^",
            "%^GREEN%^You can see dense evergreens packed into tight blotches on the ground far, far below!%^RESET%^",
            "%^RED%^It is hard to breathe this high in the sky and the air is bitterly %^CYAN%^cold!%^RESET%^",
            "%^BLUE%^You can see the ocean on the horizon, stretching as far as the eye can see.  Little glimmers of %^RESET%^%^BOLD%^silver%^RESET%^%^BLUE%^ light reflect from the surface of the water!%^RESET%^",
            "%^MAGENTA%^Tiny specks pepper the ground, some of them clustered together.  It looks like they are buildings!%^RESET%^" });
        break;

    case "falling":

        choices = ({ "%^MAGENTA%^OH NO!  You are spiraling down towards the unyielding ground below!  You've fallen off of the "+sh+"!%^RESET%^",
            "%^RED%^You have to do something, you might die if you hit the ground from this height!%^RESET%^",
            "%^YELLOW%^For an instant you panic!  Your hands claw at the air and you open your mouth to scream but all you can hear is the deafening road of air rushing by your ears!%^RESET%^",
            "%^RED%^Do something!  Do something!  Do something!  You are going to die!!!%^RED%^",});
        break;

    case "final falling":

        choices = ({ "%^RED%^This is the end!  You know you won't survive this!%^RESET%^" });
        break;

    case "landing":

        choices = ({ "%^YELLOW%^You feel suddenly warmer as your "+sh+" %^RESET%^%^YELLOW%^descends back towards the ground, the cold air at the high altitudes gradually being left behind!%^RESET%^",
            "%^GREEN%^The trees get bigger as you slowly approach the ground for a landing!%^RESET%^",
            "%^BOLD%^You can see a building in the distance with what looks like people outside.  Are they all pointing at you?%^RESET%^",
            "%^MAGENTA%^Your stomach lurches up into your throat as a sudden updraft sends your mount into an unexpected climb!%^RESET%^",
            "%^BOLD%^%^GREEN%^You feel almost weightless, as if you're sliding off the back of your "+sh+" %^RESET%^%^BOLD%^%^GREEN%^as you descend towards the ground!%^RESET%^" });
        break;

    case "final landing":

        choices = ({ "%^YELLOW%^Your breath catches as the ground rushes upwards quickly, your "+sh+" %^RESET%^%^YELLOW%^gliding in carefully towards landing!%^RESET%^",
            "%^BOLD%^You can see several buildings in the distance just before dipping below a ridge in the earth!%^RESET%^",
            "%^GREEN%^You careen through the air, almost clipping the tops of trees as you approach your destination!%^RESET%^",
            "%^RED%^Your "+sh+" %^RESET%^%^RED%^suddenly swerves to avoid a large bird, nearly knocking you off of its back!%^RESET%^",
            "%^BOLD%^%^GREEN%^You feel queezy as you look down at the ground rushing by at a blinding pace!%^RESET%^" });
        break;

    default: return "Error, please contact a wiz.";
    }

    return choices[random(sizeof(choices))];
}

// gives the next stage to progress the flight messages
string advance_stage(string stage)
{
    switch(stage)
    {
    case "begin":           return "initial climb";
    case "initial climb":   return "climbing";
    case "climbing":        return "soaring";
    case "soaring":         return "landing";
    case "landing":         return "final landing";
    case "falling":         return "final falling";
    default:                return "landed";
    }
    return "landed";
}

// so the mount can land after the player falls and smacks the ground
void land_mount_without_rider(object room)
{
    if(FLY_DEAD)
    {
        tell_room(room,"%^MAGENTA"+TO->query_short()+" flutters to the "
            "ground and hits with a hard thud, crying out a last primal "
            "scream before "+TO->QP+" body shudders and the life fades "
            "from "+TO->QO+"!");
        TO->move(room);
        ::die(TO);
        return;
    }
    tell_room(room,"%^GREEN%^"+TO->query_short()+" glides in for a "
        "perfect landing.");
    TO->move(room);
    return;
}

// handles all the riding checks and messages while in the air
void do_flight(mapping info)
{
    int steps,mid_way,check,altitude,num=0;
    string stage;
    object landing_room,start_room,rider,flying_room;

    stage = info["stage"];
    steps = info["steps"];

    // to check falling damage
    altitude = info["altitude"];
    switch(stage)
    {
    case "begin":           altitude = roll_dice(1,10) * 10; break;
    case "initial climb":   altitude = roll_dice(1,10) * 10; break;
    case "climbing":        altitude = roll_dice(3,10) * 15; break;
    case "soaring":         altitude = roll_dice(4,10) * 20; break;
    case "landing":         altitude = roll_dice(3,10) * 15; break;
    case "final landing":   altitude = roll_dice(1,10) * 10; break;
    default: break;
    }

    info["altitude"] = altitude;

    flying_room = info["room"];

    flying_room->set_altitude(altitude);

    rider = info["rider"];
    check = ride_check(rider);

    // aborts if they are not in the flying room anymore, in case of teleportation, etc
    if(!environment(rider)->is_flight_room())
    {
        FLIGHT = "landed";
        return;
    }

    // if they're more than half way there, they get a wrong room in the end
    // directory, else it's in the beginning directory
    if((check == 0 || check == -1) && !info["bad room"])
    {
        if(info["passed midpoint"]) { num = 2; }
        else { num = 1; }
        info["bad room"] = get_bad_room(info["start room"],info["end room"],num);
    }

    if(!info["falling"])
    {
        if((object)rider->query_in_vehicle() != TO) { check = -1; }

        if(check == -1 && stage != "landed")
        {
            info["bad room"] = get_bad_room(info["start room"],info["end room"],num);
            info["falling"] = 1;
            if(altitude) { steps = altitude / 10; }
            else { steps = roll_dice(1,4) + 4; }
            info["steps"] = steps;
            stage = "falling";
            info["stage"] = stage;
            ETO->change_stage(stage);
            exit(orig_short);
        }
    }

    if(info["bad room"]) { landing_room = find_object_or_load(info["bad room"]); }
    else { landing_room = find_object_or_load(info["end room"]); }

    start_room = find_object_or_load(info["start room"]);

    if(!steps)
    {
        stage = advance_stage(stage);
        info["stage"] = stage;
        FLIGHT = stage;
        environment(rider)->change_stage(stage);
    }

    switch(stage)
    {
    case "landed":

        rider->move(landing_room);
        TO->move(landing_room);
        rider->force_me("look");

        tell_object(rider,"%^BOLD%^%^GREEN%^You pull back on the reins as your "
            "mount hits the ground, landing at your destination.");
        tell_room(environment(rider),"%^BOLD%^%^GREEN%^"+rider->QCN+" pulls back "
            "on the reins of "+rider->QP+" mount as "+TO->QS+" comes in for "
            "a smooth landing.",rider);
        return;

    case "initial climb":

        tell_room(start_room,"%^BOLD%^You can see a mount and rider climbing "
            "quickly into the air, getting smaller and smaller the further "
            "away they move.",rider);
        break;

    case "climbing":

        if(random(2))
        {
            tell_room(start_room,"%^BOLD%^Far in the sky, a spot grows smaller and "
                "smaller as it climbs ever higher.",rider);
        }
        break;

    case "landing":

        if(random(2))
        {
            tell_room(landing_room,"%^BOLD%^%^BLACK%^You can barely make out something "
                "flying far above you in the air.  It seems to be getting closer.",rider);
        }
        break;

    case "final landing":

        tell_room(landing_room,"%^BOLD%^%^CYAN%^You can see something flying closer "
            "as if it's about to land right here!",rider);
        break;

    case "falling":

        if(random(2))
        {
            tell_room(landing_room,"%^BOLD%^%^RED%^You can see a tiny speck high up in the "
                "air, it's falling rapidly straight towards you!",rider);
        }
        break;

    case "final falling":

        if(!steps)
        {
            rider->move(landing_room);
            if(!rider->query_property("flying"))
            {
                tell_object(rider,"%^RED%^You plummet rapidly towards the ground and "
                    "%^YELLOW%^S%^RED%^L%^YELLOW%^A%^RED%^M into it with bone shattering "
                    "force!");
                tell_room(environment(rider),"%^RED%^"+rider->QCN+" plummets rapidly towards "
                    "the ground and %^YELLOW%^S%^RED%^L%^YELLOW%^A%^RED%^M%^YELLOW%^S%^RED%^ slams "
                    "into it with bone shattering force!",rider);
            }
            else
            {
                tell_object(rider,"%^CYAN%^The power of the flight spell slows your descent "
                    "and at the last minute you land hard on your feet!");
                tell_room(environment(rider),"%^BLUE%^"+rider->QCN+" slows as "+rider->QS+" falls "
                    "towards the ground, landing hard on "+rider->QP+" feet!",rider);
                altitude = altitude / 50;
            }
            rider->remove_property("flying rider");
            rider->force_me("look");
            TO->set_property("magic",1);
            rider->add_attacker(TO);
            rider->cause_typed_damage(rider, "torso", altitude, "bludgeoning");
            rider->continue_attack();
            rider->remove_attacker(TO);
            FLIGHT = "landed";
            if(!rider->query_property("flying"))
            {
                rider->set_paralyzed(roll_dice(8,6),"%^RED%^Oh GOD!  Everything HURTS!  You can't even move!");
            }
            call_out("land_mount_without_rider",roll_dice(10,8),landing_room);
            return;
        }

        tell_room(landing_room,"%^BOLD%^%^MAGENTA%^You can see "+rider->QCN+" screaming as "
            ""+rider->QP+" plummets towards the ground!",rider);
        break;

    }

    if(!steps || steps == 0)
    {
        switch(stage)
        {
        case "initial climb":   steps = roll_dice(1,3) + 1;  break;
        case "climbing":        steps = roll_dice(1,3) + 2;  break;
        case "soaring":         steps = roll_dice(2,6) + 4; break;
        case "landing":         steps = roll_dice(1,3) + 2;  break;
        case "final landing":   steps = roll_dice(1,3) + 1;  break;
        default:                steps = 1; break;
        }
    }

    if(!mid_way && stage == "soaring") { mid_way = steps / 2; }
    if(mid_way)
    {
        if(stage == "soaring" && steps < mid_way) { info["passed midpoint"] = 1; }
        else { info["passed midpoint"] = 2; }
    }

    tell_room(environment(rider),flight_messages(stage));
    steps --;
    info["steps"] = steps;
    check_flying(info);
}

// responsible for calling the echoes for flight messages
void check_flying(mapping info)
{
    switch(info["stage"])
    {
    case "begin":           info["timer"] = 0; info["stage"] = "begin";          break;
    case "initial climb":   info["timer"] = 1; info["stage"] = "initial climb";  break;
    case "climbing":        info["timer"] = 3; info["stage"] = "climbing";       break;
    case "soaring":         info["timer"] = 4; info["stage"] = "soaring";        break;
    case "falling":         info["timer"] = 1; info["stage"] = "falling";        break;
    case "final falling":   info["timer"] = 1; info["stage"] = "final falling";  break;
    case "landing":         info["timer"] = 3; info["stage"] = "landing";        break;
    case "final landing":   info["timer"] = 1; info["stage"] = "final landing";  break;
    case "landed":  // intentionally falls through
        if(objectp(info["rider"]))
        {
            info["rider"]->remove_property("flying rider");
        }
    default: return;
    }
    call_out("do_flight",info["timer"],info);
}

void setup_flying_room(object room,string falling_room)
{
    room->set_falling_room(room);
}


// command to take off, handles all the status checks and valid rooms and etc
int take_off(string str)
{
    mapping info;
    object room;
    string *tmp,start,dest,bad,end;
    int check;

    if(!objectp(TP)) { return 1; }

    if(!flight_check())
    {
        tell_object(TP,"Your mount is too tired to fly again right now.");
        return 1;
    }

    if(FLIGHT != "landed")
    {
        tell_object(TP,"You are already in flight!");
        return 1;
    }

    if(!stringp(str) || str == "" || str == " ")
    {
        tell_object(TP,"fly to where?");
        return 1;
    }
    tmp = explode(str," ");
    if(!sizeof(tmp))
    {
        tell_object(TP,"fly to where?");
        return 1;
    }

    if(tmp[0] == "to")
    {
        dest = replace_string(implode(tmp," "),"to ","",1);
    }
    else
    {
        dest = implode(tmp," ");
    }

    end   = room_check(TP,dest);
    if(end == "" || end == " " || !objectp(find_object_or_load(end))) { return 1; }
    start = base_name(ETO);

    if(!status_check(TP))        { return 1; }
    if(!location_check(TP,dest)) { return 1; }
    if(end == "")                { return 1; }

    check = ride_check(TP);
    room = new(FLYING_ROOM);

    info = ([]);

    TP->set_property("flying rider",1);

    // they failed badly enough to fall off the mount
    if(check == -1)
    {
        tell_object(TP,"%^RESET%^%^BOLD%^Your "+TO->query_short()+" pitches upwards and you "
            "fall off backwards with a hard thud!");
        tell_room(ETP,"%^RESET%^%^BOLD%^"+TP->QCN+"'s "+TO->query_short()+" pitches "
            "upwards and "+TP->QCN+" falls off backwards with a thud!",TP);
        exit(orig_short);
        TP->set_paralyzed(roll_dice(3,6),"%^BOLD%^You are catching your breath!%^RESET%^");
        TP->remove_property("flying rider");
        return 1;
    }
    // they already failed their riding check at this point so they're going to the wrong room
    else if(check == 0)
    {
        tell_object(TP,"%^GREEN%^You grip the reins tightly and your mount "
            "surges off the ground and into the air!");
        tell_room(ETP,"%^GREEN%^"+TP->QCN+" grips the reins of "+TP->QP+" mount "
            "and it surges off the ground and into the air!",TP);

        bad = get_bad_room(start,end,1);
        info = (["rider":TP,"bad room" : bad,"start room" : start,"end room" : end, "stage" : "begin", "room" : room ]);
        check_flying(info);

        setup_flying_room(room,bad);

        TP->move(room);
        TO->move(room);
        TP->force_me("look");
        return 1;
    }

    // passed their riding check and are taking off normally
    else if(check == 1)
    {
        tell_object(TP,"%^GREEN%^You grip the reins tightly and your mount "
            "surges off the ground and into the air!");
        tell_room(ETP,"%^GREEN%^"+TP->QCN+" grips the reins of "+TP->QP+" mount "
            "and it surges off the ground and into the air!",TP);
        info = (["rider":TP,"start room" : start, "end room" : end, "stage" : "begin", "room" : room ]);
        check_flying(info);

        bad = get_bad_room(start,end,1);
        setup_flying_room(room,bad);

        TP->move(room);
        TO->move(room);
        TP->force_me("look");
        return 1;
    }

    tell_object(TP,"Something is wrong, contact a wiz.");
    return 1;
}

void init()
{
    ::init();
    add_action("take_off","fly");
}

// override to enter, so people can't mount if it's in mid flight
int enter(string str)
{
    if(!objectp(TP)) { return 0; }
    if(!objectp(TO)) { return 0; }

    if((object)TP->query_in_vehicle() == TO)
    {
        tell_object(TP,"You are already mounted");
        return 1;
    }

    if(FLIGHT != "landed")
    {
        tell_object(TP,"%^CYAN%^You are falling out of the sky, you can't "
            "get back on your mount!%^RESET%^");
        return 1;
    }
    ::enter(str);
    return 0;
}

// override so they will fall if they get out while in the air
int exit(string str)
{
    if(!objectp(TP)) { return 1; }
    if(!objectp(TO)) { return 1; }

    if(FLIGHT != "landed")
    {
        tell_object(TP,"%^RED%^With a sudden wrong shift you find yourself "
            "off of your mount and falling through the open air!");
    }
    ::exit(str);
    return 1;
}

// we want to override die, in case somebody gets the bright idea to kill their mount in flight
void die(mixed ob)
{
    object room;
    if(FLIGHT == "landed")
    {
        ::die(ob);
        return;
    }
    FLY_DEAD = 1;
    tell_room(environment(TO),"%^RED%^The "+TO->query_short()+" shrieks and falls away, dropping "
        "down to spiral slowly towards the earth!");
    room = new(FLYING_ROOM);
    TO->move(room);
    return;
}

int is_flying_mount() { return 1; }
