#include <std.h>
inherit CVAULT;
void hauntings();
void do_hauntings();
int HauntFlag;

void create() 
{
    ::create();
	HauntFlag = 0;
}

void reset() 
{
  	::reset();
  	do_hauntings();
	hauntings();
}

void hauntings() {
    int i;
    string *exits, *num;
    exits = TO->query_exits();
    num = ({});
	if(!sizeof(exits))
	{
		if(!HauntFlag)
		{
			HauntFlag = 1;
			call_out("hauntings", 0);
			return;
		}
		return;
	}
    for(i = 0;i < sizeof(exits);i++) 
	{
    	num += ({"GoThroughDoor"});
        continue;
    }
    if(sizeof(exits) > 0) 
	{
      set_pre_exit_functions(exits,num);
    }       
}

void do_hauntings() {
  if(random(100) <= 50) {
     switch(random(12)) {
       case 0: 
         tell_room(TO,"%^CYAN%^A loud wail echoes through the "+
         "house!%^RESET%^");
         break;
       case 1:
         tell_room(TO,"%^RED%^A blood curling scream bursts "+
         "forth from the walls!%^RESET%^");
         break;
       case 2:
         tell_room(TO,"%^MAGENTA%^You hear a female voice yell:"+
         "%^RESET%^ Please, somebody HELP ME!");
         break;
       case 3:
         tell_room(TO,"%^BOLD%^%^BLACK%^A loud and long hiss issues "+
         "from somewhere within the house.%^RESET%^");
         break;
       case 4:
         tell_room(TO,"%^RED%^Screams erupt from all around you, "+
         "the cries of agony almost defeaning.%^RESET%^");
         break;
       case 5:
         tell_room(TO,"%^RED%^Drops of crimson fall from the ceiling "+
         "and seep into the floor!%^RESET%^");
         break;
       case 6:
         tell_room(TO,"%^YELLOW%^A hint of daisies fills the air and "+
         "you hear the sudden startled %^RED%^cry%^YELLOW%^ of a "+
         "little girl.%^RESET%^");
         break;
       case 7:
         tell_room(TO,"%^BOLD%^%^WHITE%^%^A voice whispers from "+
         "behind you!%^RESET%^");
         break;
       case 8:
         tell_room(TO,"%^CYAN%^You hear the loud weeping of someone "+
         "in distress!%^RESET%^");
         break;
       case 9:
         tell_room(TO,"%^RED%^A strong scent of sulfur assaults "+
         "your nostrils!%^RESET%^");
         break;
       case 10:
         tell_room(TO,"%^BOLD%^%^BLACK%^The air is suddenly heavy "+
         "with the odor of decay!%^RESET%^");
         break;
       case 11:
         tell_room(TO,"%^BOLD%^%^WHITE%^A sudden cool breeze flows "+
         "over your flesh.%^RESET%^");
         break;
      }
   }
}

int GoThroughDoor() {
   do_hauntings();
   return 1;
}


