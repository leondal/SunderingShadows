//     _report.c
//     Created by Firedragon on 12/21/96
//adapted by Circe 7/27/04 to show general information rather than
//actual HP to aid in rp.  Messages taken from _con.c

#include <std.h>

inherit DAEMON;

int cmd_report()
{
   int x;
   string check, sub;
   if(TP->query_invis()){
      tell_object(TP,"%^CYAN%^You make a small motion with your hand to "+
         "draw attention to your condition.%^RESET%^");
      return 1;
//added to keep them from being able to tell if they are hidden this way.
   }
   sub = TPQCN;
   x = (((int)TP->query_hp()*100)/(int)TP->query_max_hp());
      if(x>100)     check = "%^BOLD%^%^GREEN%^"+sub+" looks unusually healthy.";
	else if(x>90) check = "%^YELLOW%^"+sub+" is in top shape.";
	else if(x>75) check = "%^WHITE%^%^BOLD%^"+sub+" is in decent shape.";
	else if(x>60) check = "%^WHITE%^"+sub+" is slightly injured.";
	else if(x>45) check = "%^MAGENTA%^"+sub+" is hurting.";
	else if(x>30) check = "%^ORANGE%^"+sub+" is badly injured.";
	else if(x>15) check = "%^RED%^%^BOLD%^"+sub+" is terribly injured.";
	else if(x> -1)  check = "%^RED%^"+sub+" is near death.";
      else check = "%^RED%^"+TP->QS+" should be unconscious.  You "+
         "may need to notify a wiz.";
      tell_object(TP,"%^CYAN%^You make a small motion with your hand "+
         "to draw attention to your condition.%^RESET%^");
      tell_room(ETP,""+check+"",TP);
      return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

report - expose your condition

%^CYAN%^DESCRIPTION%^RESET%^

This command will display human-readable message about state of your health points to everyone in the room.

%^CYAN%^SEE ALSO%^RESET%^

con, score, look, hp, show
");
}
