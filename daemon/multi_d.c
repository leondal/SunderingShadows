// /adm/daemons/multi_d.c
// A Nightmarish object.
// Keeps track of multiple characters (See also: /bin/adm/_link.c)
// Created by Pallando (93-05-26)
// NB No checks have been put in to prevent wizards faking calls.
//    I'll leave the Law arches to decide how paranoid they wish to be. 8-)


// 3600 = 60 * 60 = number of second in an hour =
// amount of time after logging out that a user can log in a second character
#include <save.h>
#include <security.h>

#define DELAY_PERIOD 86400

mapping links;
string *non_voting;
mapping entered;
mapping whoWhen;

protected void save_data() {
   seteuid(UID_DAEMONSAVE);
   save_object(SAVE_MULTI);
   seteuid(getuid());
}

protected void restore_data() {restore_object(SAVE_MULTI);}

void create() {
   seteuid( getuid() );
   restore_data();
   if( !links ) links = ([]);
   if( !non_voting ) non_voting = ({});
   if( !whoWhen) whoWhen = ([]);
   if (!entered)
   entered = ([ ]);
}

void list_links() {
   string *names;
   int loop;

   names = keys( links );
   names -= non_voting;
   loop = sizeof( names );
   if( !loop ) {write( "No multiple characters yet."); return;}
   write( "The following multiple characters are registered:");
   while( loop-- )
      write( names[loop] + " is also: " +
             implode( links[names[loop]], ", " ));
}

mixed is_linked_char( string name ) {return links[name];}

int non_voter( string name ) {return -1 != member_array( name, non_voting );}

int make_link( string *names ) {
   int loop, size;
   string voting,*realNames;
   if( !pointerp( names ) ) return 0;
   size = sizeof( names );
   if( size < 2 ) return 0;
   realNames = names;
   for( loop = 0 ; loop < size ; loop++ )
      if( links[names[loop]] ) {
         voting = names[loop];
         realNames = distinct_array(links[names[loop]] + names);
         //write("realNames = "+identify(realNames));
         //write("links[names[loop]] = "+identify( links[names[loop]]));
         break;
      }

   non_voting += realNames[1..size-1];
   size = sizeof(realNames);
   for( loop = 0 ; loop < size ; loop++ ) {

      links[realNames[loop]] = ( realNames - realNames[loop..loop] );
      //write("key = "+realNames[loop]+" value "+identify(links[realNames[loop]]));
   }
   save_data();
   return 1;
}

int unlink( string name ) {
   // If name is the main character, break the entire link
   // Otherwise just remove name fom it.
   string *names;
   int loop, size;

   names = ({ name}) + links[name];
   size = sizeof( names );
   for( loop = 0 ; loop < size ; loop++ )
      map_delete( links, names[loop] );
   if( ( size > 2 ) && non_voter( name ) ) {
      non_voting -= names;
      make_link( names[1..size-1] );
   }
   else {
      non_voting -= names;
      save_data();
   }
   return 1;
}

/************** Functions to keep track of who has logged in or out ***/

// Called by the remove() function in /std/user.c
void quit( string name ) {
   if( !name ) return;
   if( links[name] ) {
      if( !entered[name] ) {
         // Possible cheat attempt.
         // Law can decide if they want to log it or not.
         // Will also be caused if chars are linked while logged in.
      }
      entered[name] = time();
   }
}

// Called by the switch_player() function in /adm/login.c
int query_prevent_login( string name ) {
   // Put a test for arches here, if you want to make sure they can
   // always log in.
   string *names;
   // st = -1 if character is logged in, else time of logout
   int loop, size, st;

   if( !name ) return 0;
   if( undefinedp( names = links[name] ) ) return 0;
   // Always allow arches in.
   if( member_group( name, "superuser" ) ||
       member_group( name, "assist"    )    ) return 0;
   size = sizeof( names );
   for( loop = 0 ; loop < size ; loop++ ) {
      // The next line is only useful in the case that you link some chars
      // While they are loged in, then one logs out and trys to log in again.
      if( find_player( names[loop] ) ) entered[names[loop]] = -1;
      if( st = entered[names[loop]] ) {
         if( st < 0 ) {
            write( "Another character of yours, " + capitalize( names[loop] ) +
                   " is already logged in." );
            // Log this event if you want to.
            return 1; // prevent login
         }
         if( ( time() - st ) < DELAY_PERIOD ) {
            write( "Sorry, " + capitalize( names[loop] ) + " logged out only "+
                   ( time() - st ) / 60 + " minutes ago.  Try later." );
            // Log this event if you want to.
            return 1;
         }
         map_delete( entered, names[loop] );
      }
   }
   entered[name] = -1;
   return 0;
}

void add_name(string who, int length) {
   who = lower_case(who);
   whoWhen[who] = time() + length*86400;
}

mapping queryLockedNames() {
   return whoWhen;
}

void remove_name(string who) {
   who = lower_case(who);
   whoWhen = map_delete(whoWhen,who);
}

int is_allowed(string who) {
   who = lower_case(who);
   if(whoWhen[who]) {
      if(whoWhen[who] > time()) {
         return 0;
      }
      else
         map_delete(whoWhen, who);
   }
   return 1;
}


void clean_history(string name) {
  map_delete(entered,name);
}
