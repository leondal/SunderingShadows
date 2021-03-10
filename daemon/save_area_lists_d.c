// criminals_d.c
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
/// Created by Ares 8/24/05 based loosely off of the old guard_d.c /// 
/// for the shadow guards. The daemon will save wanted lists, and  ///
/// lists of prisoners for different areas.  It stores the areas   ///
/// inside of a mapping, and the list of names inside another      ///
/// mapping.  There is an array for each name, with the adjective, ///
/// followed by an alias(s).                                       ///
//////////////////////////////////////////////////////////////////////    
//////////////////////////////////////////////////////////////////////

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

#define SAVE_FILE "/daemon/save/arealists"
#define ERROR_LOG "Misc_Errors"
#define SUCC_LOG "criminal_log"

mapping __WantedLists;
mapping __PrisonerLists;
mapping __JailersLists;
mapping __BountyLists;
mapping __FineLists;
mapping __BannedLists;
private string *__ValidLocations;

string get_real_name(mixed live, object ob);// internal function
string get_desc(mixed live,object ob); // internal function

int send_error(mixed ob,mixed error); // internal function, writes errors to a log
int send_success(mixed ob,mixed error); // sends sucess messages back to user

// used to set an array of valid locations to prevent typos fubar'ing the mapping
int add_valid_location(string location);
// used to remove a location, useful for typos, or if an area no longer exists
int remove_valid_location(string location);
// returns 1 if the location is valid
int is_valid_location(string location);
// returns an array of all valid locations
string *query_valid_locations();

// Based on a suggestion, and some help from Garrett, added
// the ability to recognize criminals from the list.
void recognize_criminal(object me,string where,string name,string alias);

/**** Wanted list functions
* add_wanted adds a name to the list, added_by is needed for use with 
* realName in the case of players adding people to the lists by their alias
****/
int add_wanted(mixed live,string where,object added_by);
// see above, removed by needed to track real names vs recognized
int remove_wanted(mixed live,string where,object removed_by);
// returns a mapping of raw data of all the areas criminals
mapping query_wanted_list(string where);
// returns an array of all the wanted names for the specified area
string *query_wanted_names(string where);
// returns an array of all the wanted aliases for the name give in the area
// more than one alias could be possible with this, though only one will
// be set at the time they are first put on the list.  Note: it is possible
// and even likely that a player won't have an alias at first, until a PC
// or imm jailer assigns one. (becase of realName issues)
string *query_wanted_aliases(string live,string where,object ob);
// returns the adjective of the wanted person in the area specified
// with /NO/ name on the front.
string query_wanted_adjective(string live,string where,object ob);
// adds new aliases to the person who is wanted.  works with recognized name
// as well as real name.  ob needed again, for realName
int add_wanted_alias(string live,string alias,string where,object ob);
// returns 1 if they are wanted in the town, 0 if they are not wanted, also 
// needs ob for realName
int is_wanted(mixed live,string where,object ob);

/**** Banned lists by *Styx* 10/9/05 ******
* same functions as wanted, needed for separate lists
******/
int add_banned(mixed live,string where,object added_by);
int remove_banned(mixed live,string where,object removed_by);
mapping query_banned_list(string where);
string *query_banned_names(string where);
string *query_banned_aliases(string live,string where,object ob);
string query_banned_adjective(string live,string where,object ob);
int add_banned_alias(string live,string alias,string where,object ob);
int is_banned(mixed live,string where,object ob);

/**** Prisoner functions, below, identical in purpose to the wanted 
*  functions above, but save to a different mapping, as the two need to
*  be kept seperate  
****/
int add_prisoner(mixed live,string where,object added_by);
int remove_prisoner(mixed live,string where,object removed_by);
mapping query_prisoner_list(string where);
string *query_prisoner_names(string where);
string *query_prisoner_aliases(string live,string where,object ob);
string query_prisoner_adjective(string live,string where,object ob);
int add_prisoner_alias(string live,string alias,string where,object ob);
int is_prisoner(mixed live,string where,object ob);

/**** Jailer functions ****/
int add_jailer(mixed live,string where,object added_by);
int remove_jailer(mixed live,string where,object removed_by);
mapping query_jailer_list(string where);
string *query_jailer_names(string where);
string *query_jailer_aliases(string live,string where,object ob);
string query_jailer_adjective(string live,string where,object ob);
int add_jailer_alias(string live,string alias,string where,object ob);
int is_jailer(mixed live,string where,object ob);

/**** Bounty functions
* used to add a bounty to player, if they are not wanted in the place
* where the bounty is issued, it will automatically add them to the
* wanted list.
****/
void add_bounty(mixed live,string where,int amount,object ob);
// removes the bounty, but doesn't remove from the wanted list
void remove_bounty(mixed live,string where,object ob);
// returns a mapping with all the bounties for said area
mapping query_bounties(string where);
// returns the amount of the bounty on the player in the area
int query_bounty_amount(mixed live,string where,object ob);
// return 1 if they have a bounty in where, 0 if not
int has_fine(mixed live,string where,object ob);

/**** Fine functions
* added for use with interactive fines.  We can do a lot of
* things with this, everything from having guards check if
* a player has their weapons wielded, to a thief being caught
* stealing.
****/
void add_fine(mixed live,string where,int amount,object ob);
// used to remove the fine
void remove_fine(mixed live,string where,object ob);
// returns a mapping of people with fines in where, and their amount
mapping query_fines(string where);
// returns specific amount for the player in question
int query_fine_amount(mixed live,string where,object ob);
// returns an array of the names of all people who have fines in where
string *query_fine_names(string where);
// returns all the aliases of live, that has a fine in where
string *query_fine_aliases(string live,string where,object ob);
// returns the adjective of live if they have a fine in where
string query_fine_adjective(string live,string where,object ob);
// adds an additional alias to live
int add_fine_alias(string live,string alias,string where,object ob);
// returns 1 if they have a fine in where, 0 if not
int has_fine(mixed live,string where,object ob);

/**** clean_criminals() will filter through the mappings used by
* criminals_d and remove any invalid players, such as ones
* who have been rid or time rid
* all these can be called from the jail too
****/
void clean_criminals(); // Process hungry function, might cause some lag
void clean_wanted(); 
void clean_jailers(); 
void clean_prisoners(); 
void clean_bounties(); 
void clean_fines(); 
void clean_banned(); 

void SAVE(); // internal function


void create()
{
	::create();
    __WantedLists = ([]);
    __PrisonerLists = ([]);
    __JailersLists = ([]);
    __BountyLists = ([]);
    __FineLists = ([]);
    __BannedLists = ([]);
    __ValidLocations = ({});
//    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
//    seteuid(getuid());
	
}

string get_real_name(mixed live, object ob)
{
    string real_name;
    if(!objectp(ob)) return send_error(ob,"get_real_name() Invalid Object.");
    if(!objectp(live) && !stringp(live)) { return send_error(ob,"get_real_name() Invalid name passed."); }

    if(objectp(live) && live->is_player())
    {
        if(!live->is_player()) { return send_error(ob,"get_real_name() Not a User"); }
        return live->query_name();
    }
    
    if(!ob->is_player()) { return live; }
    if(avatarp(ob))
    {
        if(user_exists(live)) return live;
    }
    if(user_exists(real_name=ob->realName(live))) { return real_name; } 
    if(user_exists(live)) { return live; }
    return send_error(ob,"You don't have that player recognized.");
}

string get_desc(mixed live,object ob)
{
    string name;
    object player;

    name = get_real_name(live,ob);
    
    if(player=find_player(name))
    {
        return (string)player->getWholeDescriptivePhrase();
    }
    
    return "/adm/daemon/user_call"->user_call(name,"getWholeDescriptivePhrase");
}

int send_error(mixed ob,mixed error)
{
    if(objectp(ob)) 
    { 
       // if(!avatarp(ob)) { tell_object(ob,"Error: Please contact a wiz."); }
      /*  if(avatarp(ob))  {*/ 
     tell_object(ob,error);
     // }
     //   if(avatarp(ob))  { tell_object(ob,"\nError in AREALISTS_D"); }
    }
    log_file(ERROR_LOG,"AREALISTS_D "+error+" "+ctime(time())+"\n");
    return 0;
}

int send_success(mixed ob,mixed mess)
{
    if(objectp(ob)) 
    { 
       // if(!avatarp(ob)) { tell_object(ob,"Error: Please contact a wiz."); }
      /*  if(avatarp(ob))  {*/ tell_object(ob,mess);// }
     //   if(avatarp(ob))  { tell_object(ob,"\nError in AREALISTS_D"); }
    }
  //  log_file(SUCC_LOG,"AREALISTS_D "+mess+" "+ctime(time())+"\n");
    return 1;
}

int add_valid_location(string location)
{
    if(member_array(location,__ValidLocations) == -1)
    {
        __ValidLocations            += ({ location });
        __WantedLists[location]     = ([]);
        __PrisonerLists[location]   = ([]);
        __JailersLists[location]    = ([]);
        __BountyLists[location]     = ([]);
        __FineLists[location]       = ([]);
        SAVE();
        return 1;
    }
    return 0;
}

int remove_valid_location(string location)
{
    if(!is_valid_location(location)) { return 0; }
    __ValidLocations -= ({ location });
    map_delete(__WantedLists,location);
    map_delete(__PrisonerLists,location);
    map_delete(__JailersLists,location);
    map_delete(__BountyLists,location);
    map_delete(__FineLists,location);
    SAVE();
    return 1;
}

int is_valid_location(string location)
{
    if(member_array(location,__ValidLocations) != -1) { return 1; }
    return 0;
}

string *query_valid_locations()
{
    if(sizeof(__ValidLocations))
    {
        return __ValidLocations;
    }
    return send_error(0,"No valid locations set yet.");
}

void recognize_criminal(object me,string where,string name,string alias)
{
    string real_name;
    mapping wanted,prisoners;
    object user;
    real_name=get_real_name(name,me);

    if(!wanted = __WantedLists[where] && !prisoners = __PrisonerLists[where]) { return; }
    if(!wanted[name] && !prisoners[name]) { return; }

    "/adm/daemon/user_call"->user_call(real_name,"getRelationships");
    user = "/adm/daemon/user_call";

    me->addRelationship(user, alias);
    return;
}

int add_wanted(mixed live,string where,object added_by)
{   
    mapping criminal=([]);
    string real_name,alias,adj;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(added_by)) { return 0; }
    if(!is_valid_location(where)) { return send_error(added_by,"add_wanted() "+where +" is not a valid location"); }

    real_name = get_real_name(live,added_by);
    adj = get_desc(live,added_by);

    if(stringp(live)) { alias = live; }
    if(objectp(live)) { alias = live->query_name(); }
    if(!added_by->is_player() || avatarp(added_by)) { alias = "unknown"; }

    if(!__WantedLists[where]) { __WantedLists[where] = ([]); }

    criminal[real_name] = ({ adj , alias });
    __WantedLists[where] += criminal;

    if(stringp(live)) { send_success(added_by,capitalize(live)+" added to wanted list for "+where+".\n"); }
    if(objectp(live)) { send_success(added_by,capitalize(live->query_name())+" added to wanted list for "+where+".\n"); }

    SAVE();

    return 1;                                        

}

int remove_wanted(mixed live,string where,object removed_by)
{   
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(removed_by)) { return 0; }

    real_name = get_real_name(live,removed_by);

    if(!__WantedLists[where])   { return send_error(removed_by,"remove_wanted() No wanted list for "+where); }

    remove_bounty(live,where,removed_by);
    map_delete(__WantedLists[where],real_name);
    if(query_bounty_amount(live,where,removed_by))
    {
        remove_bounty(live,where,removed_by);
    }

    if(stringp(live)) { send_success(removed_by,capitalize(live)+" removed from wanted list at "+where+".\n"); }
    if(objectp(live)) { send_success(removed_by,capitalize(live->query_name())+" removed from wanted list at "+where+".\n"); }

    SAVE();

    return 1;
}

mapping query_wanted_list(string where)
{
    if(!__WantedLists[where]) { return send_error(0,"query_wanted() No wanted list for that location"); }
    return __WantedLists[where];
}

string *query_wanted_names(string where)
{
    if(!__WantedLists[where]) { return send_error(0,"query_wanted_names() No wanted list for that location."); }
    return keys(__WantedLists[where]);
}

string *query_wanted_aliases(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases=({}),real_name;
    int i;

    real_name = get_real_name(live,ob);

    if(!__WantedLists[where]) { return send_error(ob,"query_wanted_aliases() No wanted list for that location."); }
    criminals = __WantedLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_wanted_aliases() No wanted person by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_wanted_aliases() No aliases listed for that person. Tell a wiz."); }
    for(i=1;i<sizeof(tmp);i++)// yes i=1 intentionally
    {
        aliases += ({ tmp[i] });
    }
    return aliases;
}

string query_wanted_adjective(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__WantedLists[where]) { return send_error(ob,"query_wanted_adjective() No wanted list for that location."); }
    criminals = __WantedLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_wanted_adjective() No wanted person by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_wanted_adjective() No adjective listed for that person. Tell a wiz."); }
    return tmp[0];
}

int add_wanted_alias(string live,string alias,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__WantedLists[where]) { return send_error(ob,"add_wanted_alias() No wanted list for that location."); }
    criminals = __WantedLists[where];
    if(!sizeof(keys(criminals))) { return send_error(ob,"add_wanted_alias() No criminals in that location"); }
    if(!criminals[real_name]) { return send_error(ob,"add_wanted_alias() That person is not wanted."); }

    criminals[real_name] += ({ alias });
// added by *Styx* to get rid of the "Unknown" once an alias is added 9/20/05
    if(member_array("unknown", criminals[real_name]) != -1)
        criminals[real_name] -= ({ "unknown" });

    send_success(ob,capitalize(alias)+" added.\n");

    SAVE();

    return 1;
}

int is_wanted(mixed live,string where,object ob)
{
    string real_name,*criminals;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__WantedLists[where]) { return 0; }
    criminals = keys(__WantedLists[where]);
    if(member_array(real_name,criminals) != -1) { return 1; }
    return 0;
}

int add_prisoner(mixed live,string where,object added_by)
{   
    mapping criminal=([]);
    string real_name,alias,adj;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(added_by)) { return 0; }
    if(!is_valid_location(where)) { return send_error(added_by,"add_prisoner() "+where +" is not a valid location"); }

    real_name = get_real_name(live,added_by);
    adj = get_desc(live,added_by);

    if(stringp(live)) { alias = live; }
    if(objectp(live)) { alias = live->query_name(); }
    if(!added_by->is_player() || avatarp(added_by)) { alias = "unknown"; }

    if(!__PrisonerLists[where]) { __PrisonerLists[where] = ([]); }

    criminal[real_name] = ({ adj , alias });
    __PrisonerLists[where] += criminal;

    if(stringp(live)) { send_success(added_by,capitalize(live)+" added to prisoner list for "+where+".\n"); }
    if(objectp(live)) { send_success(added_by,capitalize(live->query_name())+" added to prisoner list for "+where+".\n"); }

    SAVE();

    return 1;                                        

}

int remove_prisoner(mixed live,string where,object removed_by)
{   
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(removed_by)) { return 0; }

    real_name = get_real_name(live,removed_by);

    if(!__PrisonerLists[where])   { return send_error(removed_by,"remove_prisoner() No prisoner list for "+where); }

    map_delete(__PrisonerLists[where],real_name);

    if(stringp(live)) {send_success(removed_by,capitalize(live)+" removed from prisoner list at "+where+".\n"); }
    if(objectp(live)) {send_success(removed_by,capitalize(live->query_name())+" removed from prisoner list at "+where+".\n"); }

    SAVE();

    return 1;
}

mapping query_prisoner_list(string where)
{
    if(!__PrisonerLists[where]) { return send_error(0,"query_prisoner_list() No prisoner list for that location"); }
    return __PrisonerLists[where];
}

string *query_prisoner_names(string where)
{
    if(!__PrisonerLists[where]) { return 0;send_error(0,"query_prisoner_names() No prisoner list for that location."); }
    return keys(__PrisonerLists[where]);
}

string *query_prisoner_aliases(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases=({}),real_name;
    int i;

    real_name = get_real_name(live,ob);

    if(!__PrisonerLists[where]) { return send_error(ob,"query_prisoner_aliases() No prisoner list for that location."); }
    criminals = __PrisonerLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_prisoner_aliases() No prisoner by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_prisoner_aliases() No aliases listed for that person. Tell a wiz."); }
    for(i=1;i<sizeof(tmp);i++)// yes i=1 intentionally
    {
        aliases += ({ tmp[i] });
    }
    return aliases;
}

string query_prisoner_adjective(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__PrisonerLists[where]) { return send_error(ob,"query_prisoner_adjective() No prisoner list for that location."); }
    criminals = __PrisonerLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_prisoner_adjective() No prisoner by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_prisoner_adjective() No adjective listed for that person. Tell a wiz."); }
    return tmp[0];
}

int add_prisoner_alias(string live,string alias,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__PrisonerLists[where]) { return send_error(ob,"add_prisoner_alias() No prisoner list for that location."); }
    criminals = __PrisonerLists[where];
    if(!sizeof(keys(criminals))) { return send_error(ob,"add_prisoner_alias() No criminals in that location"); }
    if(!criminals[real_name]) { return send_error(ob,"add_prisoner_alias() That person is not wanted."); }

    criminals[real_name] += ({ alias });
// added by *Styx* to get rid of the "Unknown" once an alias is added 9/20/05
    if(member_array("unknown", criminals[real_name]) != -1)
        criminals[real_name] -= ({ "unknown" });

    send_success(ob,capitalize(alias)+" added.\n");

    SAVE();

    return 1;
}

int is_prisoner(mixed live,string where,object ob)
{
    string real_name,*criminals;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__PrisonerLists[where]) { return 0; }
    criminals = keys(__PrisonerLists[where]);
    if(member_array(real_name,criminals) != -1) { return 1; }
    return 0;
}

int add_jailer(mixed live,string where,object added_by)
{   
    mapping jailer=([]);
    string real_name,alias,adj;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(added_by)) { return 0; }
    if(!is_valid_location(where)) { return send_error(added_by,"add_jailer() "+where +" is not a valid location"); }

    real_name = get_real_name(live,added_by);
    adj = get_desc(live,added_by);

    if(stringp(live)) { alias = live; }
    if(objectp(live)) { alias = live->query_name(); }
    if(!added_by->is_player() || avatarp(added_by)) { alias = "unknown"; }

    if(!__JailersLists[where]) { __JailersLists[where] = ([]); }

    jailer[real_name] = ({ adj , alias });
    __JailersLists[where] += jailer;

    if(stringp(live)) { send_success(added_by,capitalize(live)+" added to jailers list for "+where+".\n"); }
    if(objectp(live)) { send_success(added_by,capitalize(live->query_name())+" added to jailers list for "+where+".\n"); }

    SAVE();
    return 1;                                        
}

int remove_jailer(mixed live,string where,object removed_by)
{   
    string real_name;

    if(!stringp(live) && !objectp(live)) 
    { 
        if(stringp(live)) { send_error(removed_by,"Remove jailer - You don't know anyone named "+capitalize(live)+".");  }
        if(objectp(live)) { send_error(removed_by,"Remove jailer - You don't know anyone named "+live->QCN+"."); }
        return 0;
    }
    if(!objectp(removed_by)) { return 0; }

    real_name = get_real_name(live,removed_by);

    if(!__JailersLists[where])   { return send_error(removed_by,"remove_jailer() No jailer list for "+where); }

    map_delete(__JailersLists[where],real_name);

    if(stringp(live)) { send_success(removed_by,capitalize(live)+" removed from jailers list at "+where+".\n"); }
    if(objectp(live)) { send_success(removed_by,capitalize(live->query_name())+" removed from jailers list at "+where+".\n"); }

    SAVE();
    return 1;
}

mapping query_jailer_list(string where)
{
    if(!__JailersLists[where]) { return send_error(0,"query_jailer_list() No jailer list for that location"); }
    return __JailersLists[where];
}

string *query_jailer_names(string where)
{
    if(!__JailersLists[where]) { return send_error(0,"query_jailer_names() No jailer list for that location."); }
    return keys(__JailersLists[where]);
}

string *query_jailer_aliases(string live,string where,object ob)
{
    mapping jailers = ([]);
    string *tmp,*aliases=({}),real_name;
    int i;

    real_name = get_real_name(live,ob);

    if(!__JailersLists[where]) { return send_error(ob,"query_jailer_aliases() No jailer list for that location."); }
    jailers = __JailersLists[where];
    if(!jailers[real_name]) { return send_error(ob,"query_jailer_aliases() No jailer by that name in "+where); }
    tmp = jailers[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_wanted_aliases() No aliases listed for that person. Tell a wiz."); }
    for(i=1;i<sizeof(tmp);i++)// yes i=1 intentionally
    {
        aliases += ({ tmp[i] });
    }
    return aliases;
}

string query_jailer_adjective(string live,string where,object ob)
{
    mapping jailers = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__JailersLists[where]) { return send_error(ob,"query_jailer_adjective() No jailer list for that location."); }
    jailers = __JailersLists[where];
    if(!jailers[real_name]) { return send_error(ob,"query_jailer_adjective() No jailer by that name in "+where); }
    tmp = jailers[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_jailer_adjective() No adjective listed for that person. Tell a wiz."); }
    return tmp[0];
}

int add_jailer_alias(string live,string alias,string where,object ob)
{
    mapping jailers = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__JailersLists[where]) { return send_error(ob,"add_jailer_alias() No jailer list for that location."); }
    jailers = __JailersLists[where];
    if(!sizeof(keys(jailers))) { return send_error(ob,"add_jailer_alias() No jailers in that location"); }
    if(!jailers[real_name]) { return send_error(ob,"add_jailer_alias() That person is not a jailer."); }

    jailers[real_name] += ({ alias });
// added by *Styx* to get rid of the "Unknown" once an alias is added 9/20/05
    if(member_array("unknown", jailers[real_name]) != -1)
        jailers[real_name] -= ({ "unknown" });

    send_success(ob,capitalize(alias)+" added.\n");

    SAVE();

    return 1;
}

int is_jailer(mixed live,string where,object ob)
{
    string real_name,*jailers;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__JailersLists[where]) { return 0; }
    jailers = keys(__JailersLists[where]);
    if(member_array(real_name,jailers) != -1) { return 1; }
    return 0;
}

void add_bounty(mixed live,string where,int amount,object ob)
{
    mapping bounties = ([]);
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(ob)) { return 0; }
    if(!intp(amount)) { return 0; }
    if(!is_valid_location(where)) { return send_error(ob,"add_bounty() "+where +" is not a valid location"); }

    real_name = get_real_name(live,ob);

    if(!__BountyLists[where]) { __BountyLists[where] = ([]); }

    bounties[real_name] = amount;
    __BountyLists[where] += bounties;

    if(!is_wanted(live,where,ob)) { add_wanted(live,where,ob); }

    if(stringp(live)) { send_success(ob,capitalize(live)+" given "+amount+" gold bounty in "+where+".\n"); }
    if(objectp(live)) { send_success(ob,capitalize(live->query_name())+" given "+amount+" gold bounty in "+where+".\n"); }

    SAVE();

    return 1;

}

void remove_bounty(mixed live,string where,object ob)
{
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(ob)) { return 0; }

    real_name = get_real_name(live,ob);

    if(!__BountyLists[where])   { return send_error(ob,"remove_bounty() No bounty list for "+where); }

    map_delete(__BountyLists[where],real_name);

    if(stringp(live)) { send_success(ob,capitalize(live)+"'s bounty in "+where+" has been removed.\n"); }
    if(objectp(live)) { send_success(ob,capitalize(live->query_name())+"'s bounty in "+where+" has been removed.\n"); } 

    SAVE();

    return 1;
}

mapping query_bounties(string where)
{
    if(!__BountyLists[where]) { return send_error(0,"query_bounties() No bounties in that location."); }
    return __BountyLists[where];
}

int query_bounty_amount(mixed live,string where,object ob)
{
    mapping bounties = ([]);
    string real_name;

    if(!objectp(live) && !stringp(live)) { return 0; }
    if(!objectp(ob)) { return 0; }

    real_name = get_real_name(live,ob);

    if(!__BountyLists[where]) { return send_error(ob,"query_bounty_amount() No bounties in that location."); }
    bounties = __BountyLists[where];
    if(!sizeof(keys(bounties))) { return 0; }
    if(!bounties[real_name]) { return 0; }

    return bounties[real_name];
}

int has_bounty(mixed live,string where,object ob)
{
    string real_name,*criminals;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__BountyLists[where]) { return 0; }
    criminals = keys(__BountyLists[where]);
    if(member_array(real_name,criminals) != -1) { return 1; }
    return 0;
}

void add_fine(mixed live,string where,int amount,object added_by)
{   
    mapping criminal=([]);
    string real_name,alias,adj;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(added_by)) { return 0; }
    if(!is_valid_location(where)) { return send_error(added_by,"add_fine() "+where +" is not a valid location"); }

    real_name = get_real_name(live,added_by);
    adj = get_desc(live,added_by);

    if(stringp(live)) { alias = live; }
    if(objectp(live)) { alias = live->query_name(); }
    if(!added_by->is_player() || avatarp(added_by)) { alias = "unknown"; }

    if(!__FineLists[where]) { __FineLists[where] = ([]); }

    criminal[real_name] = ({ amount, adj , alias });
    __FineLists[where] += criminal;

    if(stringp(live)) { send_success(added_by,capitalize(live)+" fined "+amount+" in "+where+".\n"); }
    if(objectp(live)) { send_success(added_by,capitalize(live->query_name())+" fined "+amount+" in "+where+".\n"); }

    SAVE();

    return 1;                                        

}

void remove_fine(mixed live,string where,object ob)
{
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(ob)) { return 0; }

    real_name = get_real_name(live,ob);

    if(!__FineLists[where])   { return send_error(ob,"remove_fine() No fine list for "+where); }

    map_delete(__FineLists[where],real_name);

    if(stringp(live)) { send_success(ob,capitalize(live)+"'s fine in "+where+" has been removed.\n"); }
    if(objectp(live)) { send_success(ob,capitalize(live->query_name())+"'s fine in "+where+" has been removed.\n"); }

    SAVE();

    return 1;
}

mapping query_fines(string where)
{
    if(!__FineLists[where]) { return send_error(0,"query_fines() No fines in that location."); }
    return __FineLists[where];
}

int query_fine_amount(mixed live,string where,object ob)
{
    mapping fines = ([]);
    string real_name;

    if(!objectp(live) && !stringp(live)) { return 0; }
    if(!objectp(ob)) { return 0; }

    real_name = get_real_name(live,ob);

    if(!__FineLists[where]) { return send_error(ob,"query_fine_amount() No fines in that location."); }
    fines = __FineLists[where];
    if(!sizeof(keys(fines))) { return 0; }
    if(!fines[real_name]) { return 0; }

    return fines[real_name][0];
}

string *query_fine_names(string where)
{
    if(!__FineLists[where]) { return 0;send_error(0,"query_fine_names() No prisoner list for that location."); }
    return keys(__FineLists[where]);
}

string *query_fine_aliases(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases=({}),real_name;
    int i;

    real_name = get_real_name(live,ob);

    if(!__FineLists[where]) { return send_error(ob,"query_fine_aliases() No prisoner list for that location."); }
    criminals = __FineLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_fine_aliases() No prisoner by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_fine_aliases() No aliases listed for that person. Tell a wiz."); }
    for(i=2;i<sizeof(tmp);i++)// yes i=2 intentionally
    {
        aliases += ({ tmp[i] });
    }
    return aliases;
}

string query_fine_adjective(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__FineLists[where]) { return send_error(ob,"query_fine_adjective() No prisoner list for that location."); }
    criminals = __FineLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_fine_adjective() No prisoner by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_fine_adjective() No adjective listed for that person. Tell a wiz."); }
    return tmp[1];
}

int add_fine_alias(string live,string alias,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__FineLists[where]) { return send_error(ob,"add_fine_alias() No prisoner list for that location."); }
    criminals = __FineLists[where];
    if(!sizeof(keys(criminals))) { return send_error(ob,"add_fine_alias() No criminals in that location"); }
    if(!criminals[real_name]) { return send_error(ob,"add_fine_alias() That person is not wanted."); }

    criminals[real_name] += ({ alias });
// added by *Styx* to get rid of the "Unknown" once an alias is added 9/20/05
    if(member_array("unknown", criminals[real_name]) != -1)
        criminals[real_name] -= ({ "unknown" });

    send_success(ob,capitalize(alias)+" added.\n");

    SAVE();
    return 1;
}

int has_fine(mixed live,string where,object ob)
{
    string real_name,*criminals;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__FineLists[where]) { return 0; }
    criminals = keys(__FineLists[where]);
    if(member_array(real_name,criminals) != -1) { return 1; }
    return 0;
}

int add_banned(mixed live,string where,object added_by)
{   
    mapping criminal=([]);
    string real_name,alias,adj;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(added_by)) { return 0; }
    if(!is_valid_location(where)) { return send_error(added_by,"add_banned() "+where +" is not a valid location"); }

    real_name = get_real_name(live,added_by);
    adj = get_desc(live,added_by);

    if(stringp(live)) { alias = live; }
    if(objectp(live)) { alias = live->query_name(); }
    if(!added_by->is_player() || avatarp(added_by)) { alias = "unknown"; }

    if(!__BannedLists[where]) { __BannedLists[where] = ([]); }

    criminal[real_name] = ({ adj , alias });
    __BannedLists[where] += criminal;

    if(stringp(live)) { send_success(added_by,capitalize(live)+" added to banned list for "+where+".\n"); }
    if(objectp(live)) { send_success(added_by,capitalize(live->query_name())+" added to banned list for "+where+".\n"); }

    SAVE();
    return 1;                                        
}

int remove_banned(mixed live,string where,object removed_by)
{   
    string real_name;

    if(!stringp(live) && !objectp(live)) { return 0; }
    if(!objectp(removed_by)) { return 0; }

    real_name = get_real_name(live,removed_by);

    if(!__BannedLists[where])   { return send_error(removed_by,"remove_banned() No banned list for "+where); }

    map_delete(__BannedLists[where],real_name);

    if(stringp(live)) { send_success(removed_by,capitalize(live)+" removed from banned list at "+where+".\n"); }
    if(objectp(live)) { send_success(removed_by,capitalize(live->query_name())+" removed from banned list at "+where+".\n"); }

    SAVE();

    return 1;
}

mapping query_banned_list(string where)
{
    if(!__BannedLists[where]) { return send_error(0,"query_banned() No banned list for that location"); }
    return __BannedLists[where];
}

string *query_banned_names(string where)
{
    if(!__BannedLists[where]) { return send_error(0,"query_banned_names() No banned list for that location."); }
    return keys(__BannedLists[where]);
}

string *query_banned_aliases(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases=({}),real_name;
    int i;

    real_name = get_real_name(live,ob);

    if(!__BannedLists[where]) { return send_error(ob,"query_banned_aliases() No banned list for that location."); }
    criminals = __BannedLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_banned_aliases() No banned person by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_banned_aliases() No aliases listed for that person. Tell a wiz."); }
    for(i=1;i<sizeof(tmp);i++)// yes i=1 intentionally
    {
        aliases += ({ tmp[i] });
    }
    return aliases;
}

string query_banned_adjective(string live,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__BannedLists[where]) { return send_error(ob,"query_banned_adjective() No banned list for that location."); }
    criminals = __BannedLists[where];
    if(!criminals[real_name]) { return send_error(ob,"query_banned_adjective() No banned person by that name in "+where); }
    tmp = criminals[real_name];
    if(!sizeof(tmp)) { return send_error(ob,"query_banned_adjective() No adjective listed for that person. Tell a wiz."); }
    return tmp[0];
}

int add_banned_alias(string live,string alias,string where,object ob)
{
    mapping criminals = ([]);
    string *tmp,*aliases,real_name;

    real_name = get_real_name(live,ob);

    if(!__BannedLists[where]) { return send_error(ob,"add_banned_alias() No banned list for that location."); }
    criminals = __BannedLists[where];
    if(!sizeof(keys(criminals))) { return send_error(ob,"add_banned_alias() No criminals in that location"); }
    if(!criminals[real_name]) { return send_error(ob,"add_banned_alias() That person is not banned."); }

    criminals[real_name] += ({ alias });
// added by *Styx* to get rid of the "Unknown" once an alias is added 9/20/05
    if(member_array("unknown", criminals[real_name]) != -1)
        criminals[real_name] -= ({ "unknown" });

    send_success(ob,capitalize(alias)+" added.\n");
    SAVE();
    return 1;
}

int is_banned(mixed live,string where,object ob)
{
    string real_name,*criminals;
    if(!objectp(ob)) { return 0; }    
    real_name = get_real_name(live,ob);

    if(!__BannedLists[where]) { return 0; }
    criminals = keys(__BannedLists[where]);
    if(member_array(real_name,criminals) != -1) { return 1; }
    return 0;
}

void clean_criminals()
{
    clean_wanted();
    clean_prisoners();
    clean_jailers();
    clean_bounties();
    clean_fines();
    clean_banned();
    return;
}

void clean_wanted() // Will likely cause lag
{
    int i,j;
    string *areas,*wanted;
    mapping criminals;
    if(!__WantedLists || __WantedLists == ([]) ) { return; }
    areas = keys(__WantedLists);
    for(i=0;i<sizeof(areas);i++)
    {
        criminals = __WantedLists[areas[i]];
        wanted = keys(criminals);
        for(j=0;j<sizeof(wanted);j++)
        {
            if(find_player(wanted[j])) { continue; }
            if(user_exists(wanted[j])) { continue; }
            map_delete(__WantedLists[areas[i]],wanted[j]);
        }
    }
    SAVE();
    return;
}

void clean_prisoners() // Will likely cause lag
{
    int i,j;
    string *areas,*prisoners;
    mapping criminals;
    if(!__PrisonerLists || __PrisonerLists == ([]) ) { return; }
    areas = keys(__PrisonerLists);
    for(i=0;i<sizeof(areas);i++)
    {
        criminals = __PrisonerLists[areas[i]];
        prisoners = keys(criminals);
        for(j=0;j<sizeof(prisoners);j++)
        {
            if(find_player(prisoners[j])) { continue; }
            if(user_exists(prisoners[j])) { continue; }
            map_delete(__PrisonerLists[areas[i]],prisoners[j]);
        }
    }
    SAVE();
    return;
}

void clean_banned() // Will likely cause lag
{
    int i,j;
    string *areas,*banned;
    mapping criminals;
    if(!__BannedLists || __BannedLists == ([]) ) { return; }
    areas = keys(__BannedLists);
    for(i=0;i<sizeof(areas);i++)
    {
        criminals = __BannedLists[areas[i]];
        banned = keys(criminals);
        for(j=0;j<sizeof(banned);j++)
        {
            if(find_player(banned[j])) { continue; }
            if(user_exists(banned[j])) { continue; }
            map_delete(__BannedLists[areas[i]],banned[j]);
        }
    }
    SAVE();
    return;
}

void clean_jailers() // Will likely cause lag
{
    int i,j;
    string *areas,*jailers;
    mapping jailers_map;
    if(!__JailersLists || __JailersLists == ([]) ) { return; }
    areas = keys(__JailersLists);
    for(i=0;i<sizeof(areas);i++)
    {
        jailers_map = __JailersLists[areas[i]];
        jailers = keys(jailers_map);
        for(j=0;j<sizeof(jailers);j++)
        {
            if(find_player(jailers[j])) { continue; }
            if(user_exists(jailers[j])) { continue; }
            map_delete(__JailersLists[areas[i]],jailers[j]);
        }
    }
    SAVE();
    return;
}

void clean_bounties() // Will likely cause lag
{
    int i,j;
    string *areas,*bounties;
    mapping criminals;
    if(!__BountyLists || __BountyLists == ([]) ) { return; }
    areas = keys(__BountyLists);
    for(i=0;i<sizeof(areas);i++)
    {
        criminals = __BountyLists[areas[i]];
        bounties = keys(criminals);
        for(j=0;j<sizeof(bounties);j++)
        {
            if(!stringp(bounties[j])) { continue; }
            if(find_player(bounties[j])) { continue; }
            if(user_exists(bounties[j])) { continue; }
            map_delete(__BountyLists[areas[i]],bounties[j]);
        }
    }
    SAVE();
    return;
}

void clean_fines() // Will likely cause lag
{
    int i,j;
    string *areas,*fines;
    mapping criminals;
    if(!__FineLists || __FineLists == ([]) ) { return; }
    areas = keys(__FineLists);
    for(i=0;i<sizeof(areas);i++)
    {
        criminals = __FineLists[areas[i]];
        fines = keys(criminals);
        for(j=0;j<sizeof(fines);j++)
        {
            if(find_player(fines[j])) { continue; }
            if(user_exists(fines[j])) { continue; }
            map_delete(__FineLists[areas[i]],fines[j]);
        }
    }
    SAVE();
    return;
}

void SAVE()
{
    seteuid(UID_DAEMONSAVE);
	save_object(SAVE_FILE);
    seteuid(getuid());
    return;
}