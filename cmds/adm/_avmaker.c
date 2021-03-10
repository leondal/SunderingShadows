// Avatar Maker for ShadowGate
// GarrettWare 2002.
//

#include <std.h>
#include <security.h>

#define LEVEL 150
#define POSITION "avatar"
#define LOUNGE "/d/dagger/avalounge"
int help();

int cmd_avmaker(string command) {
  object newuser;
  string user_name, user_password, user_email;
  string crypted_password;

  seteuid(getuid());
  if (!stringp(command)) {
    return help(); 
  } 
  if (sscanf(command, "-u=%s -p=%s -e=%s",user_name, user_password, user_email) != 3) {
    return help();
  }
  if (user_exists(user_name=lower_case(user_name))) {
    return notify_fail("%^BOLD%^%^RED%^ERROR: %^WHITE%^You probably want to use xmote to promote them!\n");
  }
  if (!mkdir("/inv/"+user_name)) {
    write("%^BOLD%^%^RED%^WARNING: %^WHITE%^Failed to create inventory directory! (/inv/"+user_name+")");
  }
  if (!mkdir("/d/avatars/"+user_name)) {
    write ("%^BOLD%^%^RED%^WARNING: %^WHITE%^Failed to create items directory! (/d/avatars/"+user_name+")");
  }
  if (!mkdir("/avatar/"+user_name)) {
    write("%^BOLD%^%^RED%^WARNING: %^WHITE%^Failed to create old avatar persona directory! (/avatar/"+user_name+")");
  }
  if (!objectp(newuser=new("/std/user.c"))) {
    return notify_fail("%^BOLD%^%^RED%^WARNING: %^WHITE%^Couldn't load or allocate a new user object? That's bad.\n");
  }
  write(identify(newuser));
  seteuid(UID_USERACCESS);
  write(identify(geteuid(TO)));
  newuser->set_name(user_name);
    newuser->set_vis_name(user_name);
  write(identify(newuser->query_name()));
  newuser->setup();
  seteuid(getuid());
  seteuid(UID_ADVANCE);
  newuser->set_position(POSITION);
  seteuid(getuid());
  seteuid(UID_USERACCESS);
  write(identify(geteuid(TO)));
    crypted_password = crypt(user_password, 0);
  newuser->set_password(crypted_password);
  write("pass="+identify(user_password));
  write("crypted_password="+identify(crypted_password));
  newuser->set_email(user_email);
  write("email="+identify(user_email));
  seteuid(getuid());
  newuser->set_property("where block", 1);
  if (random(2)) newuser->set_gender("male");
    else newuser->set_gender("female");
  newuser->set_level(LEVEL);
  newuser->set_race("human");
  newuser->set_alignment(5);
  newuser->set_player_height(71);
  newuser->set_player_weight(150);
  newuser->set_hair_color("black");
  newuser->set_eye_color("black");
  newuser->move(LOUNGE);
  newuser->set_class("fighter");
  newuser->set_mlevel("fighter",LEVEL);
  newuser->set_guild_level("fighter",LEVEL);
  newuser->set_max_hp(2500);
  newuser->set_hp(newuser->query_max_hp());
  newuser->set_max_sp(2500);
  newuser->set_sp(newuser->query_max_sp());
  newuser->set_max_mp(2500);
  newuser->set_hp(newuser->query_max_mp());
  newuser->set_stats("strength",10);
  newuser->set_stats("dexterity",10);
  newuser->set_stats("intelligence",10);
  newuser->set_stats("constitution",10);
  newuser->set_stats("wisdom",10);
  newuser->set_stats("charisma",10);
  newuser->set_stats("exceptional_strength",00);
  newuser->save_player(user_name);
  newuser->enable_commands();
  newuser->force_me("alias reset");
  newuser->save_player(user_name);
  newuser->quit();
  destruct(newuser);
return 1;
}

int help() {
  write(@Garrett
avmaker -u=username -p=password -e=email@address.com
  Creates an avatar with the specified username and password.
  Level is set to LEVEL, Position is set to POSITION, and they are moved
  to the Lounge and saved. They can then log in.
Garrett
	);
  return 1;
}
