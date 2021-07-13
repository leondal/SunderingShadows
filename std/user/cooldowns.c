/**
 * @file
 * @brief This inheritable handles cooldowns on pretty much  anything.
 *
 */

mapping cooldowns = ([  ]);

/**
 * Tells the player when the cooldown is complete
 */
int notify_available(string str)
{
    tell_object(this_object(), "[%^CYAN%^COOLDOWN%^RESET%^] -- %^YELLOW%^" + capitalize(str) + "%^CYAN%^ is now available.%^RESET%^\n");
    return 1;
}

/**
 * Checks the time left on the cooldown
 */
int cooldown(string str)
{
    if(!mapp(cooldowns))
        cooldowns = ([  ]);
    
    if (member_array(str, keys(cooldowns)) >= 0) {
        return cooldowns[str];
    }

    return 0;
}

/**
 * Adds a cooldown (could really be anything)
 */
int add_cooldown(string str, int delay)
{
    if(!mapp(cooldowns))
        cooldowns = ([  ]);
    
    if (member_array(str, keys(cooldowns)) >= 0) {
        return 0;
    }

    (mapping)cooldowns += ([ str:(time() + delay), ]);
    return 1;
}

/**
 * Allows premature removal of cooldown
 */
int remove_cooldown(string str)
{
    if(!mapp(cooldowns))
        cooldowns = ([  ]);
    
    if (member_array(str, keys(cooldowns)) < 0) {
        return 0;
    }

    map_delete(cooldowns, str);
    notify_available(str);
    return 1;
}

/**
 * Checks cooldowns to see if they're expired
 */
void process_cooldowns(string key, int delay)
{
    if (delay <= time()) {
        remove_cooldown(key);
    }
}

/**
 * Returns the entire list of cooldowns
 */
mapping query_cooldowns()
{
    return cooldowns;
}

/**
 * Checks cooldown every heart beat
 */
 
 /*
void heart_beat()
{
    if (sizeof(cooldowns)) {
        foreach(string key in(keys(cooldowns)))
        {
            tell_object(find_player("tlaloc"), "Attempting to process " + key);
            process_cooldowns(key, cooldowns[key]);
        }    
    }
    else {
        cooldowns = ([]);
    }
}
*/
