//     /cmds/mortal/_remember.c
//     Allows a player to "remember" places and objects.
//     Written by Vashkar@ShadowGate


#include <std.h>
#include <daemons.h>

inherit DAEMON;

string name, obname, a, b, *sortrem;
mapping remembered;

void shorten( int newsize );
void help();

int cmd_remember(string str) {
    object ob;
    int i;
    string filename;
    if (!str) {
        write("Remember what as what?");
        return 1;
    }
    if (sscanf(str,"here as %s",name)) {

        // Remembering a room.
        if ( !str )
            return notify_fail("Remember this room as what?\n");
        ob = environment(TP);
        filename=file_name(ob);
        if (!remembered = TP->query_rem_rooms() ) // mapping ([name:place])
            remembered = ([ ]);
        if (!sortrem = TP->query_rem_rooms_sort() ) //names
            sortrem = ({});
/*
        if(member_array(name,sortrem) > -1)
            return notify_fail("You already remembered a place as "+
                "that!\n");
        if(i = member_array(filename,values(remembered)) > -1)
            return notify_fail("You already remembered this place as "+
                sortrem[i]+"!\n");
  */
        remembered[name] = filename;
        sortrem = distinct_array(({ name}) + sortrem);
        if ( sizeof(sortrem) > (int)TP->query_base_stats("intelligence") && !avatarp(TP) )
            shorten( (int)TP->query_base_stats("intelligence") + (FEATS_D->usable_feat(TP, "worldly traveler") * 5) );
        TP->set_rem_rooms(remembered, sortrem);
        tell_object(TP, "You study the location, retaining its features firmly in your mind.");
    } else {
        // Remembering an object.
        sscanf(str,"%s as %s",obname,name);
        // Fix for no remembered object string...
        // Why do we still have this...?
        // -g 12/10/2002?
        if (!stringp(obname)) return notify_fail("Remember what as that?\n");
        // Change by Grazzt 8/22/98
        if ( !ob = present(obname,TP) )
            if ( !ob = present(obname,environment(TP)) )
                return notify_fail("You don't see that object "+
                                   "anywhere!\n");
        if (ob->query_invis()) return notify_fail("You don't see that object anywhere!\n");
        filename=file_name(ob);
        if (!remembered = TP->query_rem_obs() )
            remembered = ([ ]);
        if (!sortrem = TP->query_rem_obs_sort() )
            sortrem = ({});
/*
        if(member_array(name,sortrem) > -1)
            return notify_fail("You already remembered something as "+
                "that!\n");
*/
        if (i = member_array(filename,values(remembered)) > -1)
            return notify_fail("You already remembered that as "+
                               sortrem[i]+"!\n");
        sscanf(filename,"%s#%s",a,b);
        remembered[name]=a;
        sortrem = distinct_array(({ name}) + sortrem);
        if ( sizeof(sortrem) > (int)TP->query_base_stats("intelligence") )
            shorten( (int)TP->query_base_stats("intelligence") );
        TP->set_rem_obs(remembered, sortrem);
        write("You study "+ob->query_cap_name()+", retaining its "+
              "features firmly in your mind.");
    }
    return 1;
}

void shorten( int newsize ) {
    while (sizeof(sortrem) > newsize) {
        map_delete( remembered, sortrem[sizeof(sortrem) - 1] );
        sortrem -= ({ sortrem[sizeof(sortrem) - 1]});
    }
    return;
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

remember - memorize things

%^CYAN%^SYNOPSIS%^RESET%^

remember here as %^ORANGE%^%^ULINE%^NAME%^RESET%^
remember %^ORANGE%^%^ULINE%^OBJECT%^RESET%^ as %^ORANGE%^%^ULINE%^NAME%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command allows you to remember locations and objects.

You can remember only location you are currently in, with word 'here' used as a keyword.

To list currently remembered locations use %^ORANGE%^<recall>%^RESET%^.

%^CYAN%^SEE ALSO%^RESET%^

recall, unremember, nickname, forget
"
        );
}
