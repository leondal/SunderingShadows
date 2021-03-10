#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400

object ob;

int cmd_age(string str){
  int totage, birthday, temp, days, hours, min, sec;
  string message;

   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }

  if(!str){
    ob = TP;
    str = TPQN;
  } else {
    str = lower_case(str);
    
    if(!ob = find_player(str)) {
      if (!user_exists(str))
	return notify_fail("That person does not exist.\n");
      totage = USERCALL->user_call(str,"query_age");
      birthday = USERCALL->user_call(str,"query_birthday");
      if(objectp(ob) && !interactive(ob)) {
	write("That is not a living object.\n");
      }
    } else {
      totage = ob->query_age();
      birthday = ob->query_birthday();
    }
    days = totage/DAYLEN;
    temp = totage%DAYLEN;
    hours = temp/HRLEN;
    temp = temp%HRLEN;
    min = temp/MINLEN;
    sec = temp%MINLEN;
    
    message = "%^RESET%^%^BOLD%^"+capitalize(str)+" is "+days+" days, ";
    message += hours+":%^BOLD%^"+min+"."+sec+" old.";
    message += "\n";
    message += "They started playing on :";
    message += ctime(birthday)+".";
    message += "\n";
    message += "They have played this character :";
    message += ((totage * 100) / (time() - birthday)) + " % since then.";
    tell_object(TP, message);
    return 1;
  }
}

void help(){
  write(
	"This will give you the total playing time of the named person."
	);
}
