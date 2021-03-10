// restricted builders & apprentices from using this *Styx*  4/10/03
// also filtering out higher or equal level wizzes *Styx*  8/16/03

#include <daemons.h>
#include <std.h>

#define CURR_USER userlist[iter]
#define CU_IP_NUM query_ip_number(CURR_USER)
#define CU_NAME (string)userlist[iter]->query_name()
#define FIRST_OCTET(x) implode(explode(x,".")[0..0],".")

string ipprint(string theclass, string * who) {
  string my_output;
   string posxxx; 
   if(!objectp(TP)) { return 0; }
   posxxx = lower_case((string)TP->query_position());
   if(posxxx == "builder" || posxxx == "apprentice")
   {
       tell_object(TP,"You cannot use this command as a builder or apprentice.");
       return 1;
   }
  switch (atoi(FIRST_OCTET(theclass))) {
  case 0..126 :
    my_output="A:";
    break;
  case 127:
    my_output="Local:";
    break;
  case 128..191:
    my_output="B:";
    break;
  case 192..223:
    my_output="C:";
    break;
  case 224..239:
    my_output="D(Multicast):";
    break;
  case 240..254:
    my_output="E(xperimental):";
    break;
  case 255:
    my_output="Broadcast(?):";
    break;
  default:
    my_output="?:";
  }
  my_output += identify(who);
  return my_output;
}

int cmd_closeips() {
  object * userlist = users();
  mapping ip4=([]), ip3=([]), ip2=([]), userips=([]);
  int iter = 0;
  int count = 0;
  string *temp,output;
  if((string)TP->query_position() == "builder" || (string)TP->query_position() == "apprentice")
     return notify_fail("Sorry, you don't have access to this command yet.\n");
  for (iter=0;iter<sizeof(userlist); iter++) {
    if (!objectp(userlist[iter])) continue;
// added by Styx to filter higher level immortals out 8/16/03
    if(userlist[iter]->query_invis() && userlist[iter]->query_lowest_level() >= TP->query_lowest_level())
	continue;
    //    if (wizardp(userlist[iter])) continue;
    if( archp(userlist[iter])) continue;
    userips[CU_NAME]=CU_IP_NUM;
    if (ip4[CU_IP_NUM])
      ip4[CU_IP_NUM] += ({CU_NAME});
    else
      ip4[CU_IP_NUM] = ({CU_NAME});
    temp = implode(explode(CU_IP_NUM,".")[0..2],".");
    if (ip3[temp])
      ip3[temp] += ({CU_NAME});
    else
      ip3[temp] = ({CU_NAME});
    temp = implode(explode(CU_IP_NUM,".")[0..1],".");
    if (ip2[temp])
      ip2[temp] += ({CU_NAME});
    else
      ip2[temp] = ({CU_NAME});

  }
  map_delete(ip2,0);
  map_delete(ip3,0);
  map_delete(ip4,0);
  count = 0;
  output = "Users with a %^BOLD%^%^RED%^FULL%^RESET%^ IP match:\n";
  for (iter=0;iter<sizeof(values(ip4));iter++) {
    if (sizeof(values(ip4)[iter]) > 1) {
      output += ipprint(keys(ip4)[iter], values(ip4)[iter]);
      if ((count++ % 2) && (iter<sizeof(values(ip3))) )
	output += ".\n";
      else output += ", ";
    }
  }
  count = 0;
  output += "\nUsers with a %^YELLOW%^THREE-FOURTHS%^RESET%^ IP match:\n";
  for (iter=0;iter<sizeof(values(ip3));iter++) {
    if (sizeof(values(ip3)[iter]) > 1) {
      output +=ipprint(keys(ip3)[iter], values(ip3)[iter]);
      if ((count++ % 2) && (iter<sizeof(values(ip3))) )
	output += ".\n";
      else output += ", ";
    }
  }
  count = 0;
  output += "\nUsers with a %^GREEN%^ONE-HALF%^RESET%^ IP match:\n";
  for (iter=0;iter<sizeof(values(ip2));iter++) {
    if (sizeof(values(ip2)[iter]) > 1) {
      output += ipprint(keys(ip2)[iter], values(ip2)[iter]);
      if ((count++ % 2) && (iter<sizeof(values(ip2))) )
	output += ".\n";
      else output += ", ";
    }
  }
  this_player()->more(output);
  write(output);
  return 1;
}
