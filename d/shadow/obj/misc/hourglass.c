// File : hourglass.c
// Pator@ShadowGate
// Wed May 17 1995
#include <std.h>
#include <daemons.h>

inherit OBJECT;
inherit "/adm/simul_efun/time.c";

create() {
    ::create();
   set_id(({ "hourglass" }));
   set_name("hourglass");
   set_short("A hourglass good for telling time");
   set_long(
@HOURGLASS
This is a nice hourglass. It is made out of strong wood and the best glass
available. Pator created the special sand that makes this hourglass the best
timeteller there is. There is also a little brass plate on top of the hourglass and you think that the runes on it could hold some information!
HOURGLASS
   );
   set("read", (: "read" :));
   set_weight(3);
   set("currency","gold");
   set("value", random(3));
}
string make_cap_season(string str1)
{
  switch  (str1)
    {
    case "summer" : str1 = "Summer"; break;
    case "autumn" : str1 = "Autumn"; break;
    case "winter" : str1 = "Winter"; break;
    case "spring" : str1 = "Spring"; break;
    }
  return str1;
}


int write_time(string thedate,int x) 
{ string Day,Month,Year,WeekDay,Time,Season;
  int day,year;
  sscanf(thedate,"%s %s %s %s %s",WeekDay,Month,Day,Time,Year);
  Month = EVENTS_D->query_month_name(x);
  WeekDay = EVENTS_D->query_day_name(x);
  Season = season(x);
  Season = make_cap_season(Season);
  day = date(x);
  year = EVENTS_D->query_year(x);
  Time = ctime(time());
  write("\n-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-");
  write("You turn the hourglass around and you see runes light up !");
  write("You see on the brass plate :\n");
  write("On ShadowGate the weekday is : "+WeekDay+".");
  write("The season is                : "+Season+".");
  write("The date is                  : "+Month+" "+day+" "+year+".");
  write("And the mudtime is           : "+Time+".");
  write("-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-=O=-\n");
  return 1;
}
int time_tell()
{ int x;
  string date;
  x = time();
  date = ctime(x);
  write_time(date,x); 
  return 1;
}
  
int read(string str)
{
  if (!str) { notify_fail("silly you .. reading nothing !!");
	      return 0;
	    }
  else
    {
      if (!(str == "brass plate" || str == "plate" || str == "runes"))
         { notify_fail("You can't read "+str+" here !!");
           return 0;
         }
      else
        {
          write("You don't understand much , but you figure out that turn will do the trick !\n");
          return 1;
        }
    }
}

int turn(string str) 
{
    if (!str) { notify_fail("Can you turn nothing at home ??\n");
		return 0;
	      }
    else
      {
	if (!(str =="hourglass"))
	  { notify_fail("Pitty you can't turn your "+str+ " !!\n");
	    return 0;
	  }
        else
	  { time_tell();
	    return 1;
	  }
      }
}

void init()
{
  ::init();
  add_action("read","read");
  add_action("turn","turn");
  }

