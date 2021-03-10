#include <std.h>

inherit DAEMON;
void help();
//nosave string parse_time(int i);

int cmd_uptime(string str) {
   int up, ttl;
   string s;

   up = uptime();
   s = parse_time(up);
   write("%^GREEN%^Up "+s+" since "+ctime(time()-uptime())+"%^RESET%^");
   ttl = "/adm/daemon/shutdown_d.c"->query_time_left();
   if(ttl > 0) {
     write("%^RED%^BOLD%^WARNING:%^WHITE%^ Reboot in %^YELLOW%^"+ttl/60+"%^WHITE%^ minute(s).");
   }
   return 1;
}

void help() {
   write("
%^CYAN%^NAME%^RESET%^

uptime - show uptime

%^CYAN%^SEE ALSO%^RESET%^

who, version
"
   );
}

protected string
parse_time(int t)
{
   string str;
   str=(t%60)+"s";
   t /= 60;
   if(t%60>0)
      str=t%60+"m "+str;
   t /= 60;
   if(t%24>0)
      str=t%24+"h "+str;
   t /= 24;
   if(t>0)
      str=t+"d "+str;
   return str;
}
