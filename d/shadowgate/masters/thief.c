//thief.c ... for the masters

inherit "/d/shadowgate/masters/masters.c";

void create(){
  ::create();
  set_name("Thief master");
  set_id(({"Thieving master", "thief", "master"}));
  set_short("Master Thief");
  set_long(
@OLI
  This is a grand figure. Many times your greatest hope. Yet
his job is simple now.... he is to make you ready for the 
world of shadowgate and your quest to make a name for you as a 
thief.
OLI
  );
  set_class("thief");
}

void init(){
  ::init();
  //To be adjusted as needed
}

void kit_sub_class(){
    write("Currently a few special thieves can join the assassins guild to become true assassins.");
  return 1;
}

void help_file(){
  write("The thief lives by guile and speed.");
  write(
@OLI
 You are granted several abilities:
 
 detect -> this will allow you to detect noise in the next room
 sneak  -> this will allow you to move silently to other rooms
 hide_in_shadows -> this command should be aliased.
                 -> it is to allow you to become unseen by others
                     in the room
 stab   -> this is to back stab an ememy
 steal  -> This allows you to steal items from others
 pp -> This allows you to steal money from others
 pick -> This allows you to pick locks on doors and chests

 find -> this allows you to find traps in a room
 remove -> this allows you to remove traps from a room.
 find   -> to find traps on doors, objects, or chests
 remove -> to remove the traps
 skills -> this command must be used to improve your skills upon 
          gaining levels
OLI
 );
  return 1;
}

void done(){
  write("You may enter the world of Shadowgate now...");
  write("Much of thy life is set...but you must always seek");
  write("what you want.");
  write("%^BOLD%^Seek out adventure. Allow the world to benefit ");
  write("%^BOLD%^ you, but never allow it to hurt you.");
  write("%^BOLD%^%^RED%^YOU MUST: type skills first to aquire thieving skills");
  pick_diety();
  return 1;
}
