inherit "/std/room";

string bounce_room;
int locked;


create()
{
  object ob;

  ::create();

  set_light(2);
  set_indoors(1);
set_short("Zeeks house");

  set_long("You notice the whole room has been made of fine woods. "
           "It has been deaked out with gold trim and large coloums. "
           "You notice a drafting table, and a large, pine, table, with a "
           "computer and a pile of papers on it. It looks like the master of "
           "this room, is a nice, friendly person.");
  set_smell("default", "You smell freshly cut wood that is very soothing.");
   set_exits( ([ "out" : "/d/shadow/room/beach/park1.c",
                "closet" : "/d/shadow/room/beach/homes/zeekcl.c",
           ]) );

  locked = 1;
   bounce_room = "/d/shadow/room/beach/park1.c";












}


void init() 
{
  ::init();
  if(locked==1  && (string)this_player()->query_name() == "struphen") 
   {
     write("You use the large door.\n");
     return;
   }
      if (locked==1 && (string)this_player()->query_name() != "zeek" &&!archp(this_player()))
   {
     write("It is locked.\n");
     tell_object( find_living("zeek"), this_player()->query_cap_name()+
                  " %^CYAN%^tells you: %^BLUE%^I tried to enter your house.\n");
     this_player()->move(bounce_room);
     write_file("/realms/zeek/logs/std", (string)this_player()->query_name()+
                "Tries to enter house at"+ ctime(3))+".\n";
   }

  add_action("lock_room", "lock");
  add_action("unlock_room", "unlock");
  add_action("permit_entry", "allow");
  add_action("eject_player", "remove");

}


int permit_entry (string name)
{
  object user;
  int oldlock;

  if(!name)
   {
     write("You must say who you want to come in!\n");
     return 1;
   }
  if ((string)this_player()->query_name() != "zeek")
    return 0;
  user = find_player(name);
  if(!user)
   {
     write("There is no user by that name.\n");
     return 1;
   }
  if(present(user,this_object()))
   {
     write(capitalize(name)+" is already here!\n");
     return 1;
   }
  oldlock = locked;
  locked = 0;
  user->move_player(this_object());
  locked = oldlock;
  write("You allow "+capitalize(name)+" into your house.\n");
  tell_object(user,"Zeek lets you into his house.\n");
  say(capitalize(name)+" has been allowed to enter Zeeks house.\n");
  return 1;
}


int lock_room()
{
  if ((string)this_player()->query_name() != "zeek") 
    return 0;
  if(locked)
   {
     write("The house is already locked.\n");
     return 1;
   }
  locked = 1;
  write("You lock the house.\n");
  return 1;
}



int unlock_room()
{
  if ((string)this_player()->query_name() != "zeek") 
    return 0;
  if (!locked)
   {
     write("The house is already unlocked!\n");
     return 1;
   }
  locked = 0;
  write("You unlock the house.\n");
  return 1;
}


int eject_player(string str) 
{
  object player;
  if ((string)this_player()->query_name() != "zeek") 
    return 0;
  if(!str)
   {
     write("You must say who you want removed!\n");
     return 1;
   }
  player = find_player(str);
  if(!player || !present(player, this_object()))
   {
     write("There is no player named "+capitalize(str)+"here.\n");
     return 1;
   }
  write("You remove "+capitalize(str)+" from the room!\n");
  tell_object(player, "Zeek removes you from "
                      "his house.\n");
  player->move_player(bounce_room);
  return 1;
}
































