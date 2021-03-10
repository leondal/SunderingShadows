//      /bin/mortal/_who.c
//      from the Nightmare Mudlib
//      lists users() in an interesting format and sorting order
//      created by Descartes of Borg 03 july 1993
//	redesigned by Kalinash 12 Jan 94
//   re-redesigned by Belphy@Shadowgate  in Oct 94
//   re-designed for druids only by Pator@ShadowGate 15/11/95
//    adjusted so can be used in druidsymbol
 
#include <std.h>
#include <daemons.h>
#include <druids.h>
#include <ansi.h>
 
#define DEFAULT_SORT "l";
#define CLS ESC+"[H"+ESC+"[2J";

inherit DAEMON;
inherit ABILITIES_DIR+"dlevel.c";

string class;
string level_color(object who);
string list_users(string *races, string order);
 
int cmd_druids()
{
    string order,class1;
    int i;
	set_author("pator");
        class1 = this_player()->query_class();
    if(!this_player()->is_class("druid"))
	  {
	    order = DEFAULT_SORT;
	    this_player()->more(explode(list_users(({"druid"}), order), "\n"));
	    return 1;
	  }
	else
	  { notify_fail("You are not allowed to use druidic commands !\n");
	    return 0;
	  }
}
 
string level_color(object who) {
  int i, x;
  string tmp;
  
  tmp = "%^WHITE%^%^BOLD%^";    /* Default Color */
  class = (string)who->query_level();
  switch(class) {
    case GOD           : tmp = "%^BOLD%^%^GREEN%^"  ; break;
    case ARCH          : tmp = "%^BOLD%^%^YELLOW%^"    ; break;
    case ELDER         : tmp = "%^BOLD%^%^GREEN%^"  ; break;
    case OVERSEER      : tmp = "%^BOLD%^%^YELLOW%^" ; break;
    case DEVELOPER     : tmp = "%^BOLD%^%^BLUE%^"   ; break;
    case CREATOR       : tmp = "%^BOLD%^%^GREEN%^";    break;
    case APPRENTICE    : tmp = "%^BOLD%^%^RED%^";     break;
    case BUILDER       : tmp = "%^BOLD%^%^RED%^";     break;
    default            : tmp = "%^BOLD%^%^GREEN%^"; break;
               }
  return tmp;
}

string list_users(string *races, string order) {
    object *who,obj;
    string mark, pator, tmp, *person, melnmarn,title, dstatus;
    int i,j,maxj, max, x,length,inc;
    who = filter_array(users(), "which_users", this_object(), races);
    switch(order) 
    {   case "a": tmp = "sort_by_name"  ; break;
        case "l": tmp = "sort_by_level" ; break;
        default:  tmp = "sort_by_level" ; break;  }
    who = sort_array(who, tmp, this_object());
    max = sizeof(who);
    pator = CLS;
      pator += read_file("/d/priest/docs/druids.txt");
    if(sizeof(races) && max == 1)
        pator += "%^BOLD%^%^BLACK%^                  --=>%^RESET%^%^WHITE%^ There is only 1 druid online. %^BOLD%^%^BLACK%^<=--";
    else
        if(max == 1)
            pator += "%^BOLD%^%^BLACK%^                --=>%^RESET%^%^WHITE%^ You are the only druid online! %^BOLD%^%^BLACK%^<=--";
        else
            pator += "%^BOLD%^%^BLACK%^            --=>%^RESET%^%^WHITE%^ There are currently "+max+" druids online! %^BOLD%^%^BLACK%^<=--";
    pator +="\n";
    pator += "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--";
    pator +="\n";

    max = sizeof(who);
    if(max)
    for(i=0; i<max; i++) {
	tmp = "";
        if( (who[i]->query_level() >= BUILDER) && (who[i]->query_level() <
APPRENTICE) )
          tmp += "Builder ---- ";
        else
        if( (who[i]->query_level() >= APPRENTICE) && (who[i]->query_level() < CREATOR)
)
          tmp +=   "Apprentice - ";
        else
        if( (who[i]->query_level() >= CREATOR) && (who[i]->query_level() <
DEVELOPER) )
          tmp += "Creator ---- ";
        else
        if( (who[i]->query_level() >= DEVELOPER) && (who[i]->query_level() <
OVERSEER) )
          tmp +=  "Developer -- ";
        else
        if( (who[i]->query_level() >= OVERSEER) && (who[i]->query_level() <
ELDER) )
          tmp +=  "Overseer --- ";
        else
        if( (who[i]->query_level() >= ELDER) && (who[i]->query_level() < ARCH) )
  tmp +=  "Elder ------ ";
        else
        if( (who[i]->query_level() >= ARCH) && (who[i]->query_level() < GOD) )
        tmp += "Arch ------- "; 
        else
        if( (who[i]->query_level() >= GOD) )
  tmp += "God -------- ";
        else
        tmp += "%^BOLD%^%^WHITE%^"+arrange_string("Level "
		+who[i]->query_level()+"%^BOLD%^%^BLACK%^ --- ",13);
        if(in_edit(who[i]) || in_input(who[i])){
          tmp += "%^BOLD%^##%^RESET%^ ";
	  length = 40;}
	else length = 43;
	tmp += level_color(who[i]);
        if(!who[i]->query_alignment()) /* Newbie hasn't gone through Setter yet */
          melnmarn = capitalize((string)who[i]->query_name())+" the new adventurer";
        else if((string)who[i]->query_title()) {
          melnmarn = (string)who[i]->query_title();
	
        }
        else
          melnmarn = "("+capitalize((string)who[i]->query_name())+")";
        if(in_edit(who[i]) || in_input(who[i])){
	  if(who[i]->query_invis());
	  else if(strlen((string)who[i]->query_title()) > length-4)
	    melnmarn = arrange_string(melnmarn,length-4);   
	}

	melnmarn = arrange_string(melnmarn,length-1);
	tmp += melnmarn+" ";
        if(query_idle(who[i]) > 300)
            tmp += "%^BOLD%^%^RED%^[Idle "+(query_idle(who[i]) / 60)+"]%^RESET%^";
 	else
            { dstatus= dlevel(who[i]);
       tmp +="%^RESET%^%^BOLD%^%^BLUE%^"+NAMEFORMAT[dstatus]+"%^RESET%^"; }
        if(PRISON_D->is_imprisoned((string)who[i]->query_name()))
          tmp += "%^BOLD%^%^YELLOW%^[In Jail]";
  	else
        tmp = arrange_string(tmp, 75);
        person = explode(tmp,"\n");
        maxj = sizeof(person);
        if(person) {
          tmp = person[0]+"\n";
          if(maxj>0)
            for(j=1; j<maxj; j++) {
              tmp += arrange_string("     "+level_color(who[i])+person[j],75);
              tmp += "\n";
            }
        }  
    pator += tmp;
    }
    pator += "%^GREEN%^--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--==--";
    return pator;
}

int which_users(object who, string *classes)
{
    string my_class;
    int i;
    if(!who->query_name()) return 0;
    if( (who->query_quietness()) && wizardp(who) && !wizardp(TP) )
        { return 0; }
    if((who->query_invis()) && (wizardp(who)))
        {
	if(this_player()->query_level() < who->query_level())
      	return 0;
        }
     if( (who->query_quiecense()) && wizardp(who) && !wizardp(TP) )
        { return 0; }
   if(!(i=sizeof(classes))) return 1;
    my_class = (string)who->query_class();
    while(i--) if(classes[i] == my_class) return 1;
    return 0;
}
 
int sort_by_name(object alpha, object beta) {
    return strcmp((string)alpha->query_name(), (string)beta->query_name());
}

 
int sort_by_level(object alpha, object beta) {
    int a, b;
 
    a = (int)alpha->query_level();
    b = (int)beta->query_level();
    if(a > b) return -1;
    if(b > a) return 1;
    a = wizardp(alpha);
    b = wizardp(beta);
    if( (a && b) || (!a && !b) )
      return strcmp((string)alpha->query_name(), (string)beta->query_name());
    if(a) return 1;
    return -1;
}

