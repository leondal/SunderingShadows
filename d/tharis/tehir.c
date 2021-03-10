//Our tebrin

#include <std.h>

inherit ROOM;

   string *names = ({"tristan"});

void create()
{
  ::create();
  set_name("The tehir");
    set_properties((["light":2,"indoors":0]));
   set_climate("mountain");
  set("short","The Pegataur tribal tehir");
  set("long","%^BOLD%^%^YELLOW%^The Pegataur tribal tehir%^RESET%^\n"
      "%^CYAN%^This large airy room has been carved from the side of a great "
      "mountain hidden deep in the Smokey Mountain Range. The high vaulted "
      "ceiling rises above you in a certain celestial beauty. The large room, "
      "hidden so very well, contains great treasures. The natural beauty of "
      "the room stems from the great magic wielded by the elfs. A small "
      "corner holds a stand which has upon it a larger spellbook. In another "
      "small corner is a small chaple from which the devote elfs worship "
      "for their priestly powers. And in another corner stands racks of "
      "weapons, so the elfs can skill themselves in the martial arts.");
  set_items( ([
	       "spellbook":"Do you really think a mighty wizard would allow "
	                   "you to peer in his or her spellbook? I think not!",
	       "chaple":"This serene spot is not to a god but to a concept. "
	                "To gain there abilities the elfs love life but "
	                "do not dedicate it.",
	       "weapons":"In excellent quality, these weapons are obviously "
	                 "treated in a revered manner."
	       ]) );
  set_exits( ([
	       "west" : "/realms/pegasus/rooms/balcony",
	       "south" : "/realms/pegasus/workroom"
	       ]) );
  set_invis_exits( ({"south"}) );
  names = ({});
}
	
void init()
{
  object *user;
  int i,j;
  
  ::init();
  
  if(wizardp(TP) && (((string)TP->query_race() != "elf" || 
		     (string)TP->query_name() == "zeek") && 
		     member_array((string)TP->query_name(), names ) == -1 ))
    {
      user = users();
      i = sizeof(user);
      for(j = 0;j < i;j++)
	if((string)user[j]->query_race() == "elf")
	  tell_object(user[j],"%^BOLD%^"+TPQCN+" just attempted to violate "
		      "the pagataur home!!");
      TP->move_player("/d/shadowgate/void", " as "+TP->query_subjective()+
		      " falls trying to gain access to the elf home.");
    }
  
  
  TP->new_body();
  if((string)TP->query_race() == "elf")
    {
      add_action("add_guest", "add");
      add_action("remove_guest", "remove");
      add_action("guestlist", "guestlist");
    }
  add_action("eject_fun","eject");
  add_action("permit","permit");
}
	
int guestlist(string str)
{
  int i, j;

  if(str != "elf")
    {
      return 0;
    }

  i = sizeof(names);
  write("This is a list of people allowed in the elf tribal tehir:");
  for(j=0; j < i; j++)
    {
      write(""+names[j]+"");
    }
  return 1;
}

int add_guest(string input)
{
  string *args;
  int i, j;
  if( !input )
    {
      write("Proper usage is: add elf <guest|guests> name1 name2...");
      return 1;
    }
  args = explode(input, " ");
  i = sizeof(args);
  if( args[0] != "elf" )
    {
      write("Proper usage is: add elf <guest|guests> name1 name2...");
      return 1;
    }
  if( args[1] != "guest" && args[1] != "guests" )
    {
      write("Proper usage is: add elf <guest|guests> name1 name2...");
      return 1;
    }
  for(j=2; j < i; j++)
    {
      names += ({ args[j] });
      write("Guest "+args[j]+" added to guest list.");
    }
  return 1;
}

int remove_guest(string input)
{
  string *args;
  int i, j;
  if( !input )
    {
      write("Proper usage is: remove elf <guest|guests> name1 name2...");
      return 1;
    }
  args = explode(input, " ");
  i = sizeof(args);
  if( args[0] != "elf" )
    {
      write("Proper usage is: remove elf <guest|guests> name1 name2...");
      return 1;
    }
  if( args[1] != "guest" && args[1] != "guests" )
    {
      write("Proper usage is: remove elf <guest|guests> name1 name2...");
      return 1;
    }
  for(j=2; j < i; j++)
    {
      names -= ({ args[j] });
      write("Guest "+args[j]+" removed from guest list.");
    }
  return 1;
}

int permit(string str)
{
  object ob;
  
  if(ob = find_player(str))
    {
      tell_room(TO,"%^BOLD%^%^CYAN%^The elfs have allowed "+
		ob->query_cap_name()+" to enter!");
      
      if(wizardp(ob))
	ob->set_race("elf");
      ob->move_player(TO);
    }
  else write("No such Player!");
  return 1;
}

int eject_fun(string str)
{
  object ob;
  
  if(ob = present(str))
    {
      tell_room(TO,"%^BOLD%^The elfs have removed "+ob->query_cap_name()+" from their abode!");
      if(wizardp(ob)) 
	{
	  ob->set_race("elf");
	  ob->new_body();
	}
      ob->move_player("/d/shadowgate/adv_main");
    }
  return 1;
}

		
