// File:        _refs.c
// Mudlib:      Nightmare (but see below)
// Purpose:     Lists refs set.
// Author:      Douglas Reay (Pallando @ TMI, Nightmare, many other muds ...
//                            want me on yours as well?  Mail me at TMI-2  8-)
// ***********  HISTORY OF THE REFS COMMANDS AND RELATED CODE  ***************
// Once upon a time, in a mud far from here (Genesis) Lars wrote a
// general purpose object tracer.  This was an object people cloned
// that added actions to them, including a simple call command.
// Many wizards copied this file, adding their own functions, some
// creating monstrosities many thousands of line long, consuming disc
// and memory resources.  The best of these was the scroll object tracer.
// 92-06-**   Pallando created a wiztool on Ephemeral Dales (a 2.* LPmud)
//            that kept the code for commands in seperate bins.
// 92-10-**   Wrote commands for the wiztool that did the same as the scroll
//            but allowed multiple references (which were kept as a associated
//            arrays in a daemon in the cmds bin).
// 93-01-02   Moved wiztool commands to TMI and converted to real user commands.
//            Users no longer need to clone an object to use call, etc.
//            refs kept in ob_data mapping in user
// 93-03-**   Work done on get_object() by Watcher@TMI (details in that file)
// 93-05-**   code copied to Nightmare.  refs kept in seperate mapping in user.
//            shared ref functions file moved to /adm/daemon/
// Mud where work done: Ephemeral Dales, TMI, Tabor, Nightmare, Actuator
// Simul_efuns:  identify(), resolv_str(), get_object(), get_objects()
// Commands: call cref dref eref move ref refs sc ss tref unref

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit "/adm/daemon/refs_d";

int cmd_refs( string a )
{
  mapping refs;
  string *k;
  int i, s;

  refs = get_refs();
  if( !mapp(refs) || !(k=keys(refs)) || !(s=sizeof(k)) )
  {
    write( "You have no references set.\n" );
    return 1;
  }
  if( -1 != member_array( "default", k ) )
  {
    k -= ({ "default" });
    k = ({ "default" }) + k; // Make sure the default gets displayed first.
  }
  for( i = 0 ; i < s ; i++ )
    write( wrap( sprintf( "%-15s%s", k[i], identify( refs[k[i]] ) ) ) );
  return 1;
}

int help()
{
  write( @EndText
                    Help file on ref commands
                   ===========================

The commands in this directory allow you to do the things the scroll
object tracer does, but without a seperate object.  It also allows
you to set multiple references of any variable type and call functions
with any arguments.

  call <O>;<S>;<V>;<V>     calls function <S> in object <O> with args <V>
  ref [<S>;]<V>            sets reference <S> to variable <V>
  refs                     displays the references you have set
  unref <S>                unsets reference <S>
  eref [<S>;]<O>           sets reference <S> to the environment of <O>
  cref [<O>]               clones object <O>
  tref [<O>;]<S>           tells object <O> message <S>
  ss [<O>]                 scans the inventory of object <O>
  sc [<O>]                 recursively scans the inventory of object <O>
EndText
// Break needed because text too long for one block.
+ @EndText

Any of the arguments, except reference names, can be references.
A reference is specified by a "#" before the reference names.
Arguments given in [] are optional and will default.

NB  If you want to you can do

alias gref    move $* to me
alias summon  move $* to here
alias iref    call $*;query_id
alias all     call users;query;$*
EndText
  );
  return 1;
}
