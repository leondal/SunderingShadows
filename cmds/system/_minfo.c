/** -*-C++-*- **
 * _minfo.c  -- simple command to display memory statistics
 *
 * craz@shadowgate -- 9609 -- creation
*Styx* increased list loose to show 50 from 20, removed double spacing, and added help 11/02
 *****/
#include <std.h>
#include <daemons.h>

inherit DAEMON;

/* define some constants */
#define MEM_THRESH    33000
#define LIL_THRESH    5000
#define INSTANCE_COUNT 50

/* define some data members */
nosave string msg;

/*****
 * void parseArgs( string str )
 *  -- parses the command line arguments and then calls the proper
 *     functions
 *****/
void parseArgs( string str ) {
    string *args;

    /* in no argument was specified, then do the default */
    if ( !str || str == "" ) {
        TO->junk(0);
        return ;
    }

    /* explode the arguments into an array */
    args = explode( str, " " );

    switch ( args[0] ) {
    case "-u" :
        listUser( args[1] );
        break;
    case "-l":
        listLoose();
        break;
    case "-p":
        junk(1, find_player(args[1]));
        break;

    default :
        write( "Unknown argument %^CYAN%^" + args[0] + "%^RESET%^\n" );
    }
}

// increasing max size of list of loose objects to 50 from 20 - *Styx* 11/3/02
void listLoose() {
    object *objs;
    int i,j, stop, mem;
    string msg;
    msg = "";

    objs = objects();
    j=sizeof(objs);
    for (i=0;i<j && stop < 50;i++) {
        if (clonep(objs[i]) && !objectp(environment(objs[i])) && !objs[i]->is_room()) {
            //if(!stringp(objs[i]->query_creator())) objs[i]->remove();
            stop++;
            write(" Object "+base_name(objs[i]) +" created by "+objs[i]->query_creator());
        }
    }
    return 1;
}

/*****
 * void listUser( string user );
 *  -- lists the memory usage by a specific user.  this will simply list
 *     all the objects that have been loaded in the user's home
 *     directory and below.
 *****/
void listUser( string user ) {
    object *o = objects();
    object u;
    string path;
//    string path = sprintf( "/realms/%s/", user );
    int c;
// adding a check for string since it bombs without one *Styx* 3/15/05
    if(!user) {
	write("Please also specify the user (wiz) name you wish to see the objects for.");
	return;
    }
    path = sprintf( "/realms/%s/", user );

    /* find the user */
    if ( stat( path ) == 0 ) {
        write( "The user %^CYAN%^" + capitalize( user ) +
               "%^RESET%^ does not exist." );
        return ;
    }

    /* banner */
    msg += "    %^CYAN%^-=-=-=-=-=-=-=- %^BOLD%^GREEN%^ " +
           capitalize( user ) + "'s Loaded "
           "Objects%^RESET%^CYAN%^ -=-=-=-=-=-=-=- %^RESET%^\n";

    /* loop throught the loaded objects looking for the user's objects */
    for ( c = 0; c < sizeof( o ); ++c ) {
        if ( strsrch( file_name( o[c] ), path ) == 0 ) {
            /* found an object... put the text into 'msg' */
            msg += sprintf( "      %-40s%s %d%s\n", identify( o[c] ),
                            " %^BOLD%^CYAN%^", memory_info( o[c] ), "%^RESET%^" );
        }
    }
}


void junk(int what, object player) {
    object *o;
    object *u = users();
    object *m = ({});
    object *t = ({});
    object *warning = ({});
    object *rm = ({});
    mapping count = ([]);
    string *bad = ({});
    int i, rooms = 0, rMem = 0, oMem = 0, uMem = 0, mMem = 0, c, loose;

    switch (what) {
    case 0:
        o = objects();
        break;
    case 1:
        o = deep_inventory(player);
        break;
    }
    /* get the total memory size, and watch for large objects */
    for ( c = 0; c < sizeof( o ); ++c ) {
        oMem += memory_info( o[c] );
        if(objectp(o[c]) && o[c]->query("true_quietness") && member_group(o[c]->query_true_name(), "law")) continue;
        /* check to see if the object's memory is over the threshold */
        if (what == 0 && memory_info( o[c] ) > MEM_THRESH || what == 1 && memory_info(o[c]) > LIL_THRESH)
            warning += ({ o[c]});

        /* see if it is a monster */
        t = inherit_list( o[c] );
        if ( sizeof( t ) > 0 )
            if ( member_array( "std/monster.c", t ) != -1 )
                m += ({ o[c]});
        if (clonep(o[c]) && !objectp(environment(o[c]))) loose++;
        if (clonep(o[c])) {
            count[base_name(o[c])]++;
        }
        if (o[c]->is_room()) {
            rooms++;
            rMem+= memory_info(o[c]);
        }
    }

    /* get the total memory for users */
    for ( c = 0; c < sizeof( u ); ++c )
    {
        if(objectp(u[c]) && u[c]->query("true_quietness") && member_group(u[c]->query_true_name(), "law"))
        {
            rm += ({u[c]});
            continue;
        }
        uMem += memory_info( u[c] );
        continue;
    }
    u -= rm;
    /* get the total memory for monsters */
    for ( c = 0; c < sizeof( m ); ++c )
        mMem += memory_info( m[c] );

    /* total object stats */
    msg += "    %^CYAN%^Total Objects:           %^BOLD%^" + sizeof( o ) +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Memory in Objects:       %^BOLD%^" + oMem +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Avg. Memory per Object:  %^BOLD%^" +
           oMem / sizeof( o ) + "%^RESET%^\n";
    msg += "     %^CYAN%^Total cloned objects without env is "+loose+"\n\n";

    if (what == 0) {
    /* user stats */
    msg += "    %^CYAN%^Total Users:             %^BOLD%^" + sizeof( u ) +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Memory in Users:         %^BOLD%^" + uMem +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Avg. Memory per Users:   %^BOLD%^" +
           uMem / sizeof( u ) + "%^RESET%^\n\n";

    msg += "    %^CYAN%^Total Rooms:             %^BOLD%^" + rooms +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Memory in Rooms:         %^BOLD%^" + rMem +
           "%^RESET%^\n";
    msg += "    %^CYAN%^Avg. Memory per Room:   %^BOLD%^" +
           rMem / rooms  + "%^RESET%^\n\n";

    }
    /* print monsters */
    if ( sizeof( m ) > 0 ) {
        msg += "    %^CYAN%^Total NPCs:              %^BOLD%^" + sizeof( m ) +
               "%^RESET%^\n";
        msg += "    %^CYAN%^Memory in NPCs:          %^BOLD%^" + mMem +
               "%^RESET%^\n";
        msg += "    %^CYAN%^Avg. Memory per NPCs:    %^BOLD%^" +
               mMem / sizeof( m ) + "%^RESET%^\n\n";
    }
// moving high instance counts above large objects since the large objects list is so long, per discussion with Grendel and Garrett  *Styx* 3/15/05
    msg += "    %^CYAN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=%^RESET%^\n";
    bad = keys(count);
    for (i=0;i<sizeof(bad);i++) {
        if (count[bad[i]] > INSTANCE_COUNT) {
            msg += "        "+bad[i]+" has instance count of "+count[bad[i]]+"\n";
        }
    }

    /* print the large objects */
    if ( sizeof( warning ) > 0 ) {
        msg += "    %^CYAN%^-=-=-=-=-=-=-=- %^BOLD%^RED%^ Warning Large "
               "Objects%^RESET%^CYAN%^ -=-=-=-=-=-=-=- %^RESET%^\n";
	msg += "    %^BOLD%^There are "+sizeof(warning)+" large objects over "+MEM_THRESH+" in size.%^RESET%^\n";

        for ( c = 0; c < sizeof( warning ); ++c ) {
            if ( warning[c] == 0 )
                continue;

            msg += sprintf( "      %-50s%s %d%s\n", identify( warning[c] ),
                            " %^BOLD%^CYAN%^", memory_info( warning[c] ), "%^RESET%^" );
        }
//        msg += "    %^CYAN%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=";
    }
/* moved above *Styx*
    bad = keys(count);
    for (i=0;i<sizeof(bad);i++) {
        if (count[bad[i]] > INSTANCE_COUNT) {
            msg += "        "+bad[i]+" has instance count of "+count[bad[i]]+"\n";
        }
    }
*/
}



/*****
 * int cmd_info( string str )
 *  -- main point of executions  'str' is what the player
 *     typed as arguments to the command
 *****/
int cmd_minfo( string str ) {
    /* banner */
    set_eval_limit(90000000);
    msg = "  %^BOLD%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=- %^YELLOW%^Memory "
          "Statistics %^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n\n";

    /* now, handle the arguments */
    parseArgs( str );

    /* footer */
    msg += "\n  %^BOLD%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-"
           "=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n";
    TP->more(explode(msg,"\n"));

    /* all done */
    return 1;
}


void help() {
// help added by Styx after trying to sort through the code to figure out the arguments.
// was write( "Coming to a help system near you...\n" );

    write(
@STYX
     syntax   minfo [ -u | -l | -p ]

     optional arguments
	 -u <wizname> 	   user = wizname, checks the /realms/user dir objects
	 -l 		   loose (cloned objects with no env., only lists the first 50)
	 -p <playername>   player, gives memory stats on player & objects in inventory
				over 5,000

With no arguments summarizes memory use by object types, lists large objects, and lists objects with more than 50 instances cloned.
STYX
    );
}
