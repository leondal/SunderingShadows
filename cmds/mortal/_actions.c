#include <std.h>

inherit DAEMON;

#define WEATHER ({ "moon", "sun", "sky", "sera", "tyrannos", "moons", "stars" })

int cmd_actions()
{
    string msg, * items, * searches, * actions;
    mapping* itemmap, * searchmap;
    int i, num, found = 0;

// This section reports out the items you can look at in a room.

    itemmap = ETP->query_items();
    num = sizeof(itemmap);
    if (num > 0) {
        items = keys(itemmap);
        items -= WEATHER;
        num = sizeof(items);
        if (num > 0) {
            found = 1;
            msg = "You can <look> at the following items in this room: \n";
            // this if statement parses the array into a list separated by
            // commas and ending with a period.
            tell_object(TP, msg + implode(items, ", ") + "\n");
        }
    }
// This section reports out the searches you can find in a room.

    searchmap = ETP->query_searches();
    num = sizeof(searchmap);
    if (num > 0) {
        found = 1;
        searches = keys(searchmap);
        msg = "You can <search> the following items in this room: \n";
        // this if statement parses the array into a list separated by
        // commas and ending with a period.
        tell_object(TP, msg + implode(searches, ", ") + "\n");
    }

// This section reports out the actions you can take in a room.

    actions = ETP->query_actions();
    num = sizeof(actions);
    if (num > 0) {
        found = 1;
        msg = "You feel that you can take the following actions in this room: \n";
        // this if statement parses the array into a list separated by
        // commas and ending with a period.
        tell_object(TP, msg + implode(actions, ", ") + "\n");
    }
    if (!found) {
        write("There are no features to observe.");
    }

    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

actions - display possible actions

%^CYAN%^DESCRIPTION%^RESET%^

This command tells players about items that can be looked at %^ORANGE%^<look item>%^RESET%^, items that can be searched %^ORANGE%^<search item>%^RESET%^, and actions that can be taken in this room.

Note this will not tell you the object of a command. For example: for %^ORANGE%^<pull lever>%^RESET%^ this command will only show %^ORANGE%^<pull>%^RESET%^ and not %^ORANGE%^<lever>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

look, search
");
}
