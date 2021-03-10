/*
  I've commented a few places here to explain what I was thinking and hopefully
  make it simple to understand the process of adding more messages.  I opted to 
  use switches after a discussion with Styx about them being more simple than
  mappings and easier to maintain.  The player_func will require an extra set 
  of arrays and messages.  They follow along the same lines though, so should
  be fairly easy to understand  -Ares 4/29/06

varargs string default_func(object player,string type,string search)
{
    string *searches,*rand;
    *** This array must be added to each time a new item is added to the switch
    *** It is used to pick the search at random between all of the different 
    *** searches in the terrain.
    searches = ({ "default" });  
    int pick;
    *** The first time the function is called, it will not have a search passed.
    *** It will pick one at random from the searches array, and return it to 
    *** the calling function, this way your search will stay on the same item.
    *** IE, if you start searching a pile of junk, your messages will pertain
    *** to the pile of junk, and not some completely different item
    if(!stringp(search)) { search = searches[random(sizeof(searches))]; }

    switch(search)
    {
    *** The cases of the first switch are the items that can be searched.
    *** This is choosen at random before the start message, but will 
    *** remain the same.
    case "default":
        switch(type)
        {
        *** This is the first message the player and the room will see when
        *** A person begins to search the object.
        case "start":
            tell_object(PL,"You start digging through a bunch of random junk.");
            tell_room(EPL,""+PL->QCN+" starts digging through a bunch of random "
                "junk,",PL);
            break;
        *** This is where the random message goes.   The first message is what the 
        *** player searching sees, and the second message is what the room sees and so
        *** forth.  Even indexes of the array will be seen by the player unless there
        *** is also a target.  Then index 0 and every 3 thereafter.
        case "random":
        *** WITHOUT TARGET ***
            rand   = ({ "You dig around through stuff",
                        "PL->QCN digs around through stuff.",
                        "You dig around through more stuff.",
                        "PL->QCN digs around through more stuff.",
                        "More stuff, more digging around.",
                        "PL->QCN is digging more, more stuff.",
                        "Digging, digging, digging...",
                        "PL->QCN is digging, digging diggin."});
        *** WITH TARGET ***
            rand   = ({ "You dig through "+TA->QCN+"'s clothes.",
                        ""+PL->QCN+" digs through "+TA->QCN+"'s clothes.",
                        ""+PL->QCN+" digs through your clothes!",
                        "You empty out "+TA->QCN+"'s pockets.",
                        ""+PL->QCN+" empties out "+TA->QCN+"'s pockets.",
                        ""+PL->QCN+" empties out your pockets.",
                        "You shake "+TA->QCN+" to see what falls out.",
                        ""+PL->QCN+" shakes "+TA->QCN+" to see what falls out.",
                        ""+PL->QCN+" shakes you hard, trying to find something.",
                        "You really get your hand in there, and you didn't even have to buy dinner!",
                        "WOW, did "+PL->QCN+" really search "+TA->QCN+" there?!",
                        "WOAH, "+PL->QCN+" really gets "+PL->QP+" hand in there, damn, and "+PL->QO+" didn't even buy you dinner!",});
        *** This function actually displays the random message to the target
            send_random_messages(rand,player,targ);
            break;
        *** This is the message sent when the player actually finds something
        case "success":
            tell_object(PL,"You find something in the pile of junk!");
            tell_room(EPL,""+PL->QCN+" finds something in the pile of junk.",PL);
            break;
        *** This message is sent when nothing is found
        case "failure":
            tell_object(PL,"You find nothing but useless... junk.");
            tell_room(EPL,""+PL->QCN+" finds nothing but useless... junk.");
            break;
        *** This message is sent if something broke somewhere.
        default:
            tell_object(PL,"default terrain search messages broken, tell a wiz.");
            break;
        }
    }
    *** This returns the search variable to the calling function.
    *** This is important to keep track of what item is getting searched.
    *** IE, if you start searching a coil of rope, it wouldn't make sense
    *** to be crawling around in the bilge with the next message a player
    *** is shown.
    return search;
}*/

#include <std.h>

// A few defines because I'm lazy and don't like to type a lot
#define PL  player
#define EPL environment(player)
#define TA  targ

varargs string heavy_forest_func(object player,string type,string search);
varargs string light_forest_func(object player,string type,string search);
varargs string jungle_func(object player,string type,string search);
varargs string dense_jungle_func(object player,string type,string search);
varargs string scrub_lands_func(object player,string type,string search);
varargs string grasslands_func(object player,string type,string search);
varargs string savannah_func(object player,string type,string search);
varargs string desert_func(object player,string type,string search);
varargs string desert_dunes_func(object player,string type,string search);
varargs string desert_rocks_func(object player,string type,string search);
varargs string rocky_func(object player,string type,string search);
varargs string hills_func(object player,string type,string search);
varargs string branches_func(object player,string type,string search);
varargs string old_mounts_func(object player,string type,string search);
varargs string new_mounts_func(object player,string type,string search);
varargs string swamp_func(object player,string type,string search);
varargs string marsh_func(object player,string type,string search);
varargs string snow_func(object player,string type,string search);
varargs string ice_func(object player,string type,string search);
varargs string shallow_water_func(object player,string type,string search);
varargs string deep_water_func(object player,string type,string search);
varargs string meadows_func(object player,string type,string search);
varargs string beach_func(object player,string type,string search);
varargs string shore_func(object player,string type,string search);
varargs string barren_func(object player,string type,string search);
varargs string glacier_func(object player,string type,string search);
varargs string ruins_func(object player,string type,string search);
varargs string boats_func(object player,string type,string search);
varargs string city_func(object player,string type,string search);
varargs string village_func(object player,string type,string search);
varargs string cemetery_func(object player,string type,string search);
varargs string garden_func(object player,string type,string search);
varargs string stone_building_func(object player,string type,string search);
varargs string wood_building_func(object player,string type,string search);
varargs string hut_func(object player,string type,string search);
varargs string nat_cave_func(object player,string type,string search);
varargs string built_cave_func(object player,string type,string search);
varargs string built_tunnel_func(object player,string type,string search);
varargs string nat_tunnel_func(object player,string type,string search);
varargs string player_func(object player,string type,object targ,string search);
varargs string default_func(object player,string type,string search);
varargs string display_terrain_search_messages(object player,string type,string terrain,string search,object targ);
varargs void send_random_messages(string *messages,object player,object targ);

void create() {}


varargs string heavy_forest_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string light_forest_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string jungle_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string dense_jungle_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string scrub_lands_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string grasslands_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string savannah_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string desert_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string desert_dunes_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string desert_rocks_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string rocky_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string hills_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string branches_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string old_mounts_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string new_mounts_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string swamp_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string marsh_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string snow_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string ice_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string shallow_water_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string deep_water_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string meadows_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string beach_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string shore_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string barren_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string glacier_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string ruins_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string boats_func(object player,string type,string search)
{
    return default_func(player,type,search);
}


varargs string city_func(object player,string type,string search)
{
    string *searches,*rand;
    searches = ({ "garbage" });
    if(!stringp(search)) { search = searches[random(sizeof(searches))]; }

    switch(search)
    {
    case "garbage":
        switch(type)
        {
        case "start":
            tell_object(PL,"Ignoring the stench, you begin to poke around in a "
                "pile of garbage.");
            tell_room(EPL,""+PL->QCN+" starts poking through "
                "a pile of garbage.",PL);
            break;
        case "random":
            rand =   ({ "You don't even want to know what that was!",
                        ""+PL->QCN+" shudders as "+PL->QS+" pulls "+PL->QP+" hand back.",
                        "Flies flitter annoyingly around your head.",
                        ""+PL->QCN+" swats at some flies around "+PL->QP+" head.",
                        "You stop to shake a few ants from your fingers.",
                        ""+PL->QCN+" shakes some ants from "+PL->QP+" fingers."});
            send_random_messages(rand,player);
            break;
        case "success":
            tell_object(PL,"You find something in the pile of garbage!");
            tell_room(EPL,""+PL->QCN+" finds something in the pile of garbage.",PL);
            break;
        case "failure":
            tell_object(PL,"You find nothing but filthy garbage.");
            tell_room(EPL,""+PL->QCN+" stops searching the garbage and comes up "
                "empty handed...  mostly.",PL);
            break;
        default:
            tell_object(PL,"city terrain search messages broken, tell a wiz.");
            break;
        }
    }
    return search;
}


varargs string village_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string cemetery_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string garden_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string stone_building_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string wood_building_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string hut_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string nat_cave_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string built_cave_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string built_tunnel_func(object player,string type,string search)
{
    return default_func(player,type,search);
}
varargs string nat_tunnel_func(object player,string type,string search)
{
    return default_func(player,type,search);
}


varargs string player_func(object player,string type,object targ,string search)
{
    string *searches,*rand;
    int pick;
    searches = ({ "general" });
    if(!objectp(targ)) { return default_func(player,type,search); }
    if(!stringp(search)) { search = searches[random(sizeof(searches))]; }

    switch(search)
    {
    case "general":
        switch(type)
        {
        case "start":
            tell_object(PL,"You start digging through "+TA->QCN+"'s equipment.");
            tell_object(TA,""+PL->QCN+" starts digging through your equipment.");
            tell_room(EPL,""+PL->QCN+" starts digging through "+TA->QCN+"'s "
                "equipment.",({TA,PL}));
            break;
        case "random":
            rand   = ({ "You dig through "+TA->QCN+"'s clothes.",
                        ""+PL->QCN+" digs through "+TA->QCN+"'s clothes.",
                        ""+PL->QCN+" digs through your clothes!",
                        "You empty out "+TA->QCN+"'s pockets.",
                        ""+PL->QCN+" empties out "+TA->QCN+"'s pockets.",
                        ""+PL->QCN+" empties out your pockets.",
                        "You shake "+TA->QCN+" to see what falls out.",
                        ""+PL->QCN+" shakes "+TA->QCN+" to see what falls out.",
                        ""+PL->QCN+" shakes you hard, trying to find something.",
                        "You really get your hand in there, and you didn't even have to buy dinner!",
                        "WOW, did "+PL->QCN+" really search "+TA->QCN+" there?!",
                        "WOAH, "+PL->QCN+" really gets "+PL->QP+" hand in there, damn, and "+PL->QO+" didn't even buy you dinner!",});
            send_random_messages(rand,player,targ);
            break;
        case "success":
            tell_object(PL,"You find something hidden on "+TA->QCN+"");
            tell_object(TA,""+PL->QCN+" finds some of your hidden stuff.");
            tell_room(EPL,""+PL->QCN+" finds something hidden on "+TA->QCN+".",({TA,PL}));
            break;
        case "failure":
            tell_object(PL,"If "+TA->QCN+" doesn't seem to have anything hidden, "
                "or it's in a place even you wouldn't search.");
            tell_object(TA,""+PL->QCN+" seems to give up the search without "
                "finding anything.");
            tell_room(EPL,""+PL->QCN+" stops searching "+TA->QCN+" after getting "
                "nothing but a good feel.",({TA,PL}));
            break;
        default:
            tell_object(PL,"default terrain search messages broken, tell a wiz.");
            break;
        }
    }
    return search;
}


varargs string default_func(object player,string type,string search)
{
    string *searches,*rand;
    int pick;
    searches = ({ "default" });
    if(!stringp(search)) { search = searches[random(sizeof(searches))]; }

    switch(search)
    {
    case "default":
        switch(type)
        {
        case "start":
            tell_object(PL,"You start digging through a bunch of random junk.");
            tell_room(EPL,""+PL->QCN+" starts digging through a bunch of random "
                "junk,",PL);
            break;
        case "random":
            rand   = ({ "You dig around through stuff",
                        ""+PL->QCN+" digs around through stuff.",
                        "You dig around through more stuff.",
                        ""+PL->QCN+" digs around through more stuff.",
                        "More stuff, more digging around.",
                        ""+PL->QCN+" is digging more, more stuff.",
                        "Digging, digging, digging...",
                        ""+PL->QCN+" is digging, digging diggin."});
            send_random_messages(rand,player);
            break;
        case "success":
            tell_object(PL,"You find something in the pile of junk!");
            tell_room(EPL,""+PL->QCN+" finds something in the pile of junk.",PL);
            break;
        case "failure":
            tell_object(PL,"You find nothing but useless... junk.");
            tell_room(EPL,""+PL->QCN+" finds nothing but useless... junk.",PL);
            break;
        default:
            tell_object(PL,"default terrain search messages broken, tell a wiz.");
            break;
        }
    }
    return search;
}



varargs string display_terrain_search_messages(object player,string type,string terrain,string search,object targ)
{
    if(!objectp(player))  { return 0; }
    if(!stringp(type))    { return 0; }
    if(!stringp(terrain)) { terrain = "default"; }


    switch(terrain)
    {
    case "heavy forest":    return heavy_forest_func(player,type,search);
    case "light forest":    return light_forest_func(player,type,search);
    case "jungle":          return jungle_func(player,type,search);
    case "dense jungle":    return dense_jungle_func(player,type,search);
    case "scrub lands":     return scrub_lands_func(player,type,search);
    case "grasslands":      return grasslands_func(player,type,search);
    case "savannah":        return savannah_func(player,type,search);
    case "desert":          return desert_func(player,type,search);
    case "desert dunes":    return desert_dunes_func(player,type,search);
    case "desert rocks":    return desert_rocks_func(player,type,search);
    case "rocky":           return rocky_func(player,type,search);
    case "hills":           return hills_func(player,type,search);
    case "branches":        return branches_func(player,type,search);
    case "old mounts":      return old_mounts_func(player,type,search);
    case "new mounts":      return new_mounts_func(player,type,search);
    case "swamp":           return swamp_func(player,type,search);
    case "marsh":           return marsh_func(player,type,search);
    case "snow":            return snow_func(player,type,search);
    case "ice":             return ice_func(player,type,search);
    case "shallow water":   return shallow_water_func(player,type,search);
    case "deep water":      return deep_water_func(player,type,search);
    case "meadows":         return meadows_func(player,type,search);
    case "beach":           return beach_func(player,type,search);
    case "shore":           return shore_func(player,type,search);
    case "barren":          return barren_func(player,type,search);
    case "glacier":         return glacier_func(player,type,search);
    case "ruins":           return ruins_func(player,type,search);
    case "boats":           return boats_func(player,type,search);
    case "city":            return city_func(player,type,search);
    case "village":         return village_func(player,type,search);
    case "cemetery":        return cemetery_func(player,type,search);
    case "garden":          return garden_func(player,type,search);
    case "stone building":  return stone_building_func(player,type,search);
    case "wood building":   return wood_building_func(player,type,search);
    case "hut":             return hut_func(player,type,search);
    case "nat cave":        return nat_cave_func(player,type,search);
    case "built cave":      return built_cave_func(player,type,search);
    case "built tunnel":    return built_tunnel_func(player,type,search);
    case "nat tunnel":      return nat_tunnel_func(player,type,search);
    case "player":          return player_func(player,type,targ,search);
    case "default":
    default :               return default_func(player,type,search);
    }
    return 0;
}

void send_random_messages(string *messages,object player,object targ)
{
    int pick,extra;
    pick = random(sizeof(messages));
    if(objectp(targ)) { extra = pick%3; }
    else { extra = pick%2; }
    if(extra) { pick -= extra; }
    tell_object(PL,messages[pick]);
    if(objectp(targ)) { tell_object(TA,messages[pick+2]); }
    if(objectp(targ)) { tell_room(EPL,messages[pick+1],({PL,TA})); }
    else { tell_room(EPL,messages[pick+1],PL); }
    return;
}

