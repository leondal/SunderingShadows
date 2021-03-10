//  /bin/soul/atmos.c
//  from the Nightmare Mudlib
//  everyone's soul commands
//  created by Jubal@TMI 0.8 910120
//  changed by Obsidian@ShadowGate 990919

#include <databases.h>
#include <std.h>

mapping atmos;
int line;

void create() {
    seteuid(getuid());
    atmos = allocate_mapping(250);
    line = 1;
//    message("broadcast", "Atmos shouts: A new reality has begun!", users());
    set_heart_beat(1);
}


/**********************************************************************
    Define the flags we need for various types of cmds.
*/

/* the default adverb for the cmd is overridden by an environment variable */
#define ENVIRONMENT 0x0001

/* use the optional verb instead of the query_verb() one */
#define OVERB 0x0002

/* apostrophize the target's name */
#define APOSTROPHE 0x0004

/* always use the adverb */
#define FORCEADVERB 0x0008

/* definitions for non-standard formats */
#define FORMAT0 0x0100
#define FORMAT1 0x0200
#define FORMAT2 0x0400
#define FORMAT (FORMAT0|FORMAT1|FORMAT2)

/* special variables used by the messages */
#define OBJECTIVE 0x0010
#define POSSESSIVE 0x0020
#define SUBJECTIVE 0x0040
#define VARIABLE (OBJECTIVE|POSSESSIVE|SUBJECTIVE)


/**********************************************************************
    Some simple support functions to make things easier later.
    These are pretty much self documenting.
*/

private int ghost(){
    return (int) previous_object() -> query_ghost();
}

private string subjective(){
    return (string) previous_object() -> query_subjective();
}

private string objective(){
    return (string) previous_object() -> query_objective();
}

private string possessive(){
    return (string) previous_object() -> query_possessive();
}


/**********************************************************************
    expand_macro() expands the $ variables.
*/

private string expand_macro( string msg, int flags, int personal ){
    string s1, s2;

    if( flags & OBJECTIVE ) while( sscanf( msg, "%s$O%s", s1, s2 ) == 2 )
        msg = s1 + ( personal ? "your" : objective() ) + s2;
    if( flags & POSSESSIVE ) while( sscanf( msg, "%s$P%s", s1, s2 ) == 2 )
        msg = s1 + ( personal ? "your" : possessive() ) + s2;
    if( flags & SUBJECTIVE ) while( sscanf( msg, "%s$S%s", s1, s2 ) == 2 )
        msg = s1 + ( personal ? "you" : subjective() ) + s2;
    return msg;
}


/**********************************************************************
    describe_action() takes the pieces of cmd outputs and puts them
    together into messages, and displays them to the appropriate
    people.
*/

protected int describe_action( string verb, object victim, string pre, string post, int flags ){
    object pob, *all, *pick;
    string src_name, src_name_x, victim_name, victim_name_x, v_ext, msg;
    int i;

    if( ! verb || ghost() || ( i = strlen( verb ) ) < 2 ) return 0;
    if( verb[i-1] == 's' || verb[i-1] == 'x' || verb[i-1] == 'z' ||
        verb[i-1] == 'o' || verb[i-1] == 'h' &&
        ( verb[i-2] == 't' || verb[i-2] == 'c' || verb[i-2] == 's' ) )
        v_ext = "es";
    else v_ext = "s";
    verb = " " + verb;
    post = ( post ? " " + post + "." : "." );

    pob = previous_object();
    src_name = (string) pob -> query_cap_name();
    src_name_x = (string) pob -> query_cap_name();
    if( ! src_name )
        src_name = (string) pob -> query_short();
    if( pob->query_invis() )
        src_name_x = "("+pob->getParsableName() +")";
    if( ! src_name_x )
        src_name_x = (string) pob -> query_short();

    if( victim ){
        pre = ( pre ? " " + pre + " " : " " );
        victim_name = (string) victim -> query_cap_name();
        victim_name_x = (string) victim -> query_cap_name();
        if( ! victim_name )
            victim_name = (string) victim -> query_short();
        if( ! victim_name )
            victim_name = "Someone";

        if(victim->query_invis())
           victim_name_x = "("+victim->getParsableName()+")";
        if( ! victim_name_x )
            victim_name_x = (string) victim -> query_short();
        if( ! victim_name_x )
            victim_name_x = "Someone";

        if( flags & APOSTROPHE ){
            victim_name += "'" +
            ( victim_name[ strlen( victim_name ) - 1 ] != 's' ? "s" : "" );
            victim_name_x += "'" +
            ( victim_name_x[ strlen( victim_name_x ) - 1 ] != 's' ? "s" : "" );
        }
    }
    else{
        victim_name = "";
        victim_name_x = "";
        pre = ( pre ? " " + pre : "" );
    }

    all = ({});
    pick = ({});
    if(objectp(ETP)) all = all_inventory(ETP);
    else all = ({});
    all -= ({ TP });
    if( victim ) all -= ({ victim });
    for( i = 0; i < sizeof( all ); i++ ){
      if(avatarp(all[i]) || all[i]->detecting_invis() ) pick += ({ all[i]});
    }
    if( pointerp( pick ) ) all -= pick;

    /* check if soul command is allowed */
    if(TP->query("emote loss")) return 0;

    /* tell the commander */
    if( victim && victim -> query_invis() && wizardp( TP ) )
        msg = sprintf("You%s%s%s%s", verb, pre, victim_name_x, post);
    else msg = sprintf("You%s%s%s%s", verb, pre, victim_name, post);
    if( flags & VARIABLE ) msg = expand_macro( msg, flags, 1 );
    message("emote", msg, this_player());

    /* souls logging here */
    if(!random(5) && interactive(TP)){
        if(file_size("/log/emotes/souls.log") > 150000){
            cp("/log/emotes/souls.log","/log/emotes/souls.old");
            rm("/log/emotes/souls.log");
        }
        write_file("/log/emotes/souls.log",TPQN+" : "+msg+"\n");
    }

    /* tell the commandee */
    if( victim ){
        if( wizardp( victim ) )
            msg = sprintf("%s%s%s%syou%s%s", src_name_x, verb, v_ext, pre,
                (flags & APOSTROPHE ? "r" : ""), post);
        else msg = sprintf("%s%s%s%syou%s%s", src_name, verb, v_ext, pre,
            (flags & APOSTROPHE ? "r" : ""), post);
        if( flags & VARIABLE ) msg = expand_macro( msg, flags, 0 );
        message("emote", msg, victim);
    }
    else
        victim = this_object();

    /* tell the innocent bystanders */
    msg = sprintf("%s%s%s%s%s%s", src_name, verb, v_ext, pre,
        victim_name, post);
    if( flags & VARIABLE ) msg = expand_macro( msg, flags, 0 );
    message("emote", msg, all);

    /* tell the innocent bystanding wizards */
    msg = sprintf("%s%s%s%s%s%s", src_name_x, verb, v_ext, pre,
        victim_name_x, post);
    if( flags & VARIABLE ) msg = expand_macro( msg, flags, 0 );
    message("emote", msg, pick);

    return 1;
}


/**********************************************************************
    extract_args() splits a string into a name and adjective.  If
    there is an object around the player which responds to the
    first word of the string, and is living (and is not the player
    herself), then the first element in the return array will be
    the living object.  The second argument will either be the rest
    of the argument string, or the entire string if no match is
    found.  If the found object is not living, or is the player
    herself, then extract_args() returns 0.
*/

protected mixed *extract_args( string arg ){
    string name, adj;
    object victim;

    if( ! arg || arg == "" ) return ({ 0, 0 });
    if( sscanf( arg, "%s %s", name, adj ) < 2 ){
        name = arg;
    }
   name = lower_case(name);
    victim = present( name, environment( previous_object() ) );
    if( ! victim )
        adj = arg;
    else if( ! living( victim ) ||
        victim == previous_object() ) return 0;
    return ({ victim, adj });
}


/**********************************************************************
    do_soul() is the command hook which receives control from the
    player object to determine if a soul command has been called,
    and take appropriate action if this is the case.
*/

int do_cmd( string verb, string args ){
    mixed *dat, *argv;
    string adverb;

    /* check if the command exists */
#ifdef MUDOS
    if( ! ( dat = atmos[ verb ] ) ) return 0;
#else
    if( ! ( dat = assoc( verb, atmos ) ) ) return 0;
#endif

    /* parse the argument string */
    if( ! ( argv = extract_args( args ) ) ) return 0;

    /* check if we need an environment override */
    if( argv[1] ) adverb = argv[1];
    if( ! adverb && ( dat[0] & ENVIRONMENT ) )
        adverb = (string) previous_object() -> getenv( verb );
    if( adverb && ( dat[0] & FORCEADVERB ) && dat[2] )
        adverb = dat[2] + " " + adverb;
    else if( ! adverb ) adverb = dat[2];
    if( adverb && ! strlen( adverb ) ) adverb = 0;

    if( ! ( dat[0] & FORMAT ) )
        describe_action( dat[0] & OVERB ? dat[4] : verb, argv[0],
            argv[0] ? dat[1] : 0, adverb ? adverb : 0, dat[0] );
    else if( dat[0] & FORMAT0 )
        describe_action( dat[0] & OVERB ? dat[4] : verb, 0,
            adverb ? adverb : 0, 0, dat[0] );
    else if( dat[0] & FORMAT1 )
        describe_action( dat[0] & OVERB ? dat[4] : verb, argv[0],
            ( dat[3] ? dat[3] : "" ) +
            ( dat[3] && argv[0] ? " " : "" ) +
            ( argv[0] ? dat[1] : "" ),
            adverb ? adverb : 0, dat[0] );
    else if( dat[0] & FORMAT2 )
        describe_action( dat[0] & OVERB ? dat[4] : verb, argv[0],
            argv[0] ? dat[1] : dat[3],
            adverb ? adverb : 0, dat[0] );
    return 1;
}


/**********************************************************************
    The heart_beat() is used when the object is first loaded to
    read in the command data file 10 lines at a time so that a
    heavy initial load is not placed on the system to set up soul
    commands.
*/

heart_beat(){
    string *dat;
    int i;

    dat = read_file(SOUL_DB, line, 10);
    if( dat ) dat = explode( dat, "\n" );
    if( dat ) for( i=0 ; i<sizeof(dat) ; i++, line++ ){
        string *expl;
        int j, flags;

        if(!dat[i] || dat[i] == "") continue;
        if(dat[i][0] == '#') continue;
        expl = explode( dat[i] + ":", ":" );
        if( ! expl || sizeof( expl ) < 6 ) continue;
        if( strlen( expl[0] ) == 0 ) continue;

        /* clean up the data */
        if( ! strlen( expl[2] ) ) expl[2] = 0;
        if( ! strlen( expl[3] ) ) expl[3] = 0;
        if( ! strlen( expl[4] ) ) expl[4] = 0;
        if( ! strlen( expl[5] ) ) expl[5] = 0;

        /* parse flags */
        flags = 0;
        for( j=0 ; j<strlen( expl[1] ) ; j++ ) switch( expl[1][j] ){
            case 'E': flags |= ENVIRONMENT; break;
            case 'V': if( expl[5] ) flags |= OVERB; break;
            case 'A': flags |= APOSTROPHE; break;
            case 'F': flags |= FORCEADVERB; break;
            case '0': flags |= FORMAT0; break;
            case '1': flags |= FORMAT1; break;
            case '2': flags |= FORMAT2; break;
            case 'O': flags |= OBJECTIVE; break;
            case 'P': flags |= POSSESSIVE; break;
            case 'S': flags |= SUBJECTIVE; break;
        }

        /* insert the command into the atmos alist */
#ifdef MUDOS
        atmos[expl[0]] = ({ flags, expl[2], expl[3], expl[4], expl[5] });
#else
        atmos = insert_alist( expl[0],
            ({ flags, expl[2], expl[3], expl[4], expl[5] }), atmos );
#endif
    }
    if( i < 10 ){
        set_heart_beat( 0 );
        message("broadcast", "Atmos shouts: Our souls are "
        "now complete.", users());
//        "now complete.", users());
        line = -1;
    }
}

mixed *query_atmos( string verb ){
    return atmos[ verb ];
}

string *query_feelings() { return keys(atmos); }
