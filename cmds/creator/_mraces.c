//	/wizards/kalinash/bin/_mraces.c
//	Lists monster races for you.
//	By Kalinash@Nightmare on 29 Dec 93
//	Heavily modified by Melnmarn@ShadowGate

#include <std.h>

inherit DAEMON;
void show_race_info(string str);

int cmd_mraces(string str){
    string *files;
    int inc; 

seteuid("Root");
   files = get_dir("/adm/db/mon_races/*");
	if(!str){
	    tell_object(this_player(),"%^GREEN%^The following monster body types are available beyond normal races:\n");
	    tell_object(this_player(),"%^BOLD%^%^BLUE%^-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
         tell_object(this_player(),"\n%^YELLOW%^"+format_page(files, 4));
         tell_object(this_player(),"%^BOLD%^%^BLUE%^-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	 tell_object(this_player(),"%^GREEN%^ For more information on a particular race, type '%^BOLD%^mraces <racename>%^RESET%^%^GREEN%^'!");
  	 tell_object(this_player(),"Also use the <races> command to see the 'normal' races available.");

	    return 1;
	}
      if(member_array(str,files) == -1)
		return notify_fail("That is not a valid monster race!!\n");
	show_race_info(str);
	return 1;
}

void show_race_info(string str){
    string temp, *limbs, *wield, *tmp, message;
    int inc;
	temp = read_file("/adm/db/mon_races/"+str);
   wield = explode(explode((explode(temp,"\n")[0]),":")[1],";");
	limbs = explode(temp,"\n");
	write("%^BOLD%^%^RED%^  Body Type: %^YELLOW%^"+capitalize(str));
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-");
	message = "%^BOLD%^%^GREEN%^Wieldable Limbs: ";
	for(inc = 0;inc < sizeof(wield); inc++)
	    message += "\n%^CYAN%^  "+capitalize(wield[inc]);
	message += "\n%^BOLD%^%^GREEN%^Available Limbs: %^CYAN%^";
	for(inc = 1;inc < sizeof(limbs); inc++){
	    tmp = explode(limbs[inc],":");
	    message += "\n  "+capitalize(tmp[0]);
	}
	write(message);
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-");
	write("Also use the <races> command for the 'normal' races available.");
}

void help()
	{

	tell_object(this_player(),
@MELNMARN
Syntax:   mraces [race_name]
Alone, this command will list all the available 
non-standard monster body types available on ShadowGate.
With the optional race_name, it will show the races
body parts, and wielding limbs.
MELNMARN
);
	return;
	}
