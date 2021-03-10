inherit DAEMON;

/**
 * @file
 * @brief Levelcheck related functions
 */

/**
 * This function returns colored version of levelcheck between players
 *
 * @param first First player
 * @param second Second player
 * @return empty string on error, green K if PK is allowed, yellow A if adventuring only is allowed
 *
 */
public string levelcheck_string(object first, object second)
{
    switch (levelcheck(first, second)) {
    case 0: return " %^RESET%^%^BOLD%^%^RED%^F%^RESET%^";
    case 1: return " %^RESET%^%^BOLD%^%^YELLOW%^A%^RESET%^";
    case 2: return " %^RESET%^%^BOLD%^%^BLUE%^P%^RESET%^";
    case 3: return " %^RESET%^%^BOLD%^%^GREEN%^K%^RESET%^";
    default: return " %^RESET%^%^BOLD%^%^RED%^F%^RESET%^";
    }
}

/**
 * This function determines whether players are within levelcheck
 *
 * @param first First player
 * @param second Second player
 *
 * @return 0 -- nothing is allowed
 *         1 -- adventuring is allowed
 *         2 -- pk is allowed
 *         3 -- pk and adventuring are allowed
 *
 */
public int levelcheck(object first, object second)
{
    int lvl, lvl2;
    int diff;
    int range;
    int low;
    int result = 0;

    if (!objectp(first)) {
        return 0;
    }
    if (!objectp(second)) {
        return 0;
    }

    if (first == second) {
        return 3;
    }

    lvl = (int)first->query_base_character_level();
    lvl2 = (int)second->query_base_character_level();

    if (lvl2 > lvl) {
        low = lvl;
    }else {
        low = lvl2;
    }

    diff = lvl - lvl2;
    diff = absolute_value(diff);

    switch (low) {
    case 1..50: range = 11; break;
    default: range = 6;
    }

    //First bit -- kill, second -- adventure
    if (diff < range) {
        result = result | 3;
    }

    if (lvl < lvl2) {
        result = result | 2;
    }

    if (second->query("no_levelcheck")) {
        result = result | 2;
    }

    if (first->query_death_flag()) {
        result = result & 1;
    }
    if (second->query_death_flag()) {
        result = result & 1;
    }

    if (first->get_pk_death_flag()) {
        result = result & 1;
    }
    if (second->get_pk_death_flag()) {
        result = result & 1;
    }

    if (first->query("no pk")) {
        result = result & 1;
    }
    if (second->query("no pk")) {
        result = result & 1;
    }

    return result;
}
