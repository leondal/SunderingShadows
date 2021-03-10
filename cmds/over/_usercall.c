// File:        _call.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     allow wizards to call functions in objects
// Credits:     see _refs.c

#include <security.h>
#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit "/adm/daemon/refs_d";

#define SYNTAX "Syntax: usercall <playername>;<function>;<arg>;<arg>\n"
#define FUNC_LIST ({\
  "query_rname",\
  "query_title",\
  "query_email",\
  "query_ip",\
  "query_class",\
  "query_race",\
  "query_guild",\
  "query_level",\
  "query_hp",\
  "query_max_hp",\
  "query_attackers",\
  "query_hunted",\
  })
#define TAB "\t"

mixed do_usercall( string ob, string func, mixed args );

int cmd_usercall( string a )
{
  string str, *exp_a,*temp;
  mixed objs, funcs, args, tmp, ret, rets;
  string ob;
  int i, s, fi, fs;

    if((string)previous_object()->query_position() == "ambassador") return 0;
    if((string)previous_object()->query_position() == "builder") return 0;
    if((string)previous_object()->query_position() == "apprentice") return 0;
    if((string)previous_object()->query_position() == "creator")
       write("**WARNING** Misuse of this function will be punished\n");
    if( !a ) { notify_fail( SYNTAX ); return 0; }

  seteuid( geteuid( previous_object() ) );
  exp_a = explode( a, ";" );
  s = sizeof( exp_a );
  objs = exp_a[0];
  if( s > 1 )
    funcs = exp_a[1];
  else
    funcs = FUNC_LIST;
  if( s == 3 )
    args = ({ exp_a[2] });
  if( s > 3 )
    args = exp_a[2..(s-1)];

  objs = resolv_ref( objs );
  if( !pointerp( objs ) ) objs = ({ objs });
  tmp = ({ });
  s = sizeof( objs );
  for( i = 0 ; i < s ; i++ ) {
    if( stringp( objs[i] ) )
      ob = objs[i];
    if( !ob ) write( "Can't identify " + identify( objs[i] ) +" as a string." );
    else tmp += ({ ob });
  }

  if( !sizeof( tmp ) ) return 1;
  objs = tmp;

  funcs = resolv_ref( funcs );
  if( !pointerp( funcs ) ) funcs = ({ funcs });
  tmp = ({ });
  s = sizeof( funcs );
  for( i = 0 ; i < s ; i ++ ) {
    if( stringp( funcs[i] ) )
      tmp += ({ funcs[i] });
    else
      write( "Can't identify " + identify( funcs[i] )+" as a string." );
  }

  if( !sizeof( tmp ) )
    return 1;
  funcs = tmp;

  if( pointerp( args ) && ( s = sizeof( args ) ) )
    for( i = 0 ; i < s ; i++ )
      args[i] = resolv_ref( resolv_str( args[i] ) );

  rets = ({ });
  s = sizeof( objs );
  fs = sizeof( funcs );
  for( i = 0 ; i < s ; i++ ) {
    str = identify( objs[i] );
    for( fi = 0 ; fi < fs ; fi++ ) {
      //      if(interactive(objs[i])) {
      //	if(!archp(this_player())) {
      //	  if(objs[i] != this_player()) {
      //	    write("Only arches can call interactive objects.");
      //	    return 1;
      //	  }
      //	}
      //      }
      //if((string)this_player()->query_position() == "apprentice")
      //if(!interactive(objs[i])) {
      //      write("Only creators can call non-interactive objects.");
      //      write("You may only call yourself.");
      //      return 1;
      //}
      ret = do_usercall( objs[i], funcs[fi], args );
      if( ret[0] ) rets += ({ ret[0] });
      if( fs == 1 ) str = wrap( str + ret[1] );
      else str += (fi?"":"\n") + wrap( ret[1] );
    }
    message("Ninfo", str, this_player());
  }
  switch( sizeof( rets ) )
  {
    case 0: rets = 0; break;
    case 1: rets = rets[0];
  }
  set_ref( 0, rets );

  return 1;
}

mixed do_usercall( string ob, string func, mixed args )
{
  mixed ret, err;
  int i, s;
  string str;

  s = sizeof(args);

  str="->"+func+"("+identify(args)+")";

  switch( s )
  {
    case 0: err=catch(ret=USERCALL->user_call(ob,func));break;
    case 1: err=catch(ret=USERCALL->user_call(ob,func,args[0]));break;
    case 2: err=catch(ret=USERCALL->user_call(ob,func,args[0],args[1]));break;
    case 3: err=catch(ret=USERCALL->user_call(ob,func,args[0],args[1],args[2]));break;
    default: err=catch(ret=USERCALL->user_call(ob,func,args[0],args[1],args[2],args[3]));
  }

  if( err ) return ({ 0, str + TAB + "= ERR(" + identify( err ) + ")" });
  return ({ ret, str + TAB + "= " + identify( ret ) });
}

int help()
{
    message("Nhelp", SYNTAX+
    "Effect: Calls the function <function> in player object <object>,\n"+
    "passing as many arguments <arg> as you give.\n"+
    "If no function is specified a dump of the object is given.\n"+
    "<object> and <function> can be arrays (eg \"users\")\n"+
    "See also: refs\n", this_player());
  return 1;
}
