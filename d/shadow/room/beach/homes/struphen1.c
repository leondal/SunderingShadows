inherit "/std/room";

string bounce_room;
int locked;


create()
{
  object ob;

  ::create();

  set_light(2);
  set_indoors(1);
  set_short("Struphens house");
  set_long("This house has been made of fine woods.  "
           "It has been deaked out with gold trim and large coloums.  "
           "You notice a doile on a gold table.  "
           "A large rug is on the floor.  "
           "");
 set_smell("default", "You smell fresh water from out side.");
  set_exits( ([ "out" : "/d/shadow/room/beach/park1.c",
           ]) );


  locked = 1;
  bounce_room = "/d/shadow/room/beach/park1.c";












}


void init() 
{
  ::init();
  if(locked==1  && (string)this_player()->query_name() == "zeek") 
   {
    write("You use the back door.\n");
     return;
   }
      if (locked==1 && (string)this_player()->query_name() != "struphen" &&!archp(this_player()))
   {
     write("The house is locked.\n");


     this_player()->move(bounce_room);


   }

  add_action("lock_room", "lock");
  add_action("unlock_room", "unlock");
 
  add_action("eject_player", "remove");

}




































int lock_room()
{
  if ((string)this_player()->query_name() != "struphen") 
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
  if ((string)this_player()->query_name() != "struphen") 
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
  if ((string)this_player()->query_name() != "struphen") 
    return 0;
  if(!str)
   {
     write("You must say who you want removed!\n");
     return 1;
   }
  player = find_player(str);
  if(!player || !present(player, this_object()))
   {
     write("There is no one named "+capitalize(str)+"here.\n");
     return 1;
   }
  write("You remove "+capitalize(str)+" from the room!\n");
  tell_object(player, "Struphen removes you "
                      "from the house.\n");
  player->move_player(bounce_room);
  return 1;
}
































