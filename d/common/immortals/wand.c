// Code based on Tristan's original twig.
// I stand on the shoulders of giants.
// Garrett.
// added pk death flag switcher *Styx* 9/24/06

#include <std.h>

inherit OBJECT;

void create(){
        ::create();
        
        set_name("A baited stick");
        set_short("A strange stick");
        set_id(({"twig","small twig","stick"}));
        set_long(@LONG
This is a small twig.
You notice there is a carrot dangling from a string from the end, how odd!
With this stick, you can:
    here 
       This returns the file name of the room. Wizzes sometimes need this.
    oldgrant <playername> <amount> 
          Good for... well, you can figure it out...
	  Abuse this and it will all end in lightning, or maybe on a golf tee.
    nwpbonus <playername> <amount> <nwpname>
    deed <playername> <deed> 
          Adds a deed to the list of accomplishments on a player.
	  "Achieved: <insert deed here>" 
          No punctuation added.
    pkflag [playername] [set || clear]
	  To add a PK flag to someone who has been pked and doesn't have it
	- or - remove one that is in error
LONG
		 );
}

void init(){
  ::init(); 
  add_action("files","here");
  add_action("exp","oldgrant");
  add_action("do_mark_deed","deed");
  add_action("nwp_bonus","nwpbonus");
  add_action("pk_flag", "pkflag");  // added by *Styx*
}

int files(string str){
  string name;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  write("%^BOLD%^The file name of this room is:");
  name = base_name(ETP);
  write(""+name);
  return 1;
}

int save_me(string file) {return 1;}

int exp(string str){
  string name;
  int amount;
  object targplay;
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if (!str) return notify_fail("grant <name> <amount>\n");
  if(sscanf(str,"%s %d",name, amount) != 2) return notify_fail("grant name amount\n");
  name=lower_case(name);
  
  if (objectp(targplay=find_player(name)) && interactive(targplay)) {
    targplay->fix_exp(amount,TP);
    targplay->resetLevelForExp(0);
    write("Player "+name+" granted "+amount+" exp");
  } else {
    write("Player "+name+" is invalid or not interactive.");
  }
  return 1;
}

int nwp_bonus(string str) {
  string targplay, nwp;
  int bonus, old_bonus;
  object ob;
  
  if(!avatarp(ETO)) {
    tell_object(ETO,"The item mysteriously vanishes.");
    TO->remove();
    return 0;
  } // Added security!!! A must have. :)
  if (3 != sscanf(str,"%s %d to %s",targplay, bonus,nwp)) {
    return notify_fail("nwpbonus <player> <bonus> <nwpname>\n");
  } else {
    if (!objectp(ob=find_player(targplay))) {
      return notify_fail("Player `"+targplay+"' not found.");
    } else {
      if (!ob->has_nwp(nwp)) {
	return notify_fail("They don't have that NWP!");
      } else {
	old_bonus=ob->query_nwp_bonus(nwp);
	ob->set_nwp_bonus(nwp,bonus);
	write(targplay+" granted "+bonus+" NWPXP in "+nwp+
	      ". (Was at "+old_bonus+".)");
	return 1;
      }
    }
  }
}

int do_mark_deed(string str)
{
  string name, deed;
  object targplay;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str) return notify_fail("deed <name> <important_deed>\n");
  if (sscanf(str,"%s %s",name, deed) != 2) return notify_fail("deed <name> <important_deed>\n");
   name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
   tell_object(targplay,"You have accomplished "+deed+"!");
   write("Player "+name+" noted for accomplishing "+deed+"!");
   return targplay->set_mini_quest("Achieved: "+deed,1,"Achieved: "+deed);
   } else {
   return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}

int pk_flag(string str) {
  string name, which;
  object targplay;
  if (!avatarp(ETO)) {
     tell_object(ETO,"The item mysteriously vanishes.");
     TO->remove();
     return 0;
  } // Added security!!! A must have. :)
  if (!str) 
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  if (sscanf(str,"%s %s",name, which) != 2) 
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  if(which != "on" && which != "off")
  if (sscanf(str,"%s %s",name, which) != 2) 
	return notify_fail("syntax is <pkflag [name] on> or <pkflag [name] off>\n");
  name=lower_case(name);
  if (objectp(targplay = find_player(name)) && interactive(targplay))  {
     tell_object(targplay,"Your PK status flag has been changed to "+which+".");
     write("You have changed "+name+"'s PK status flag to "+which+".");
     switch(which) {
	case "on":  targplay->set_pk_death_flag();  break;
	case "off":  targplay->remove_pk_death_flag();  break;
	default:  write("Something didn't work right, please try again.");
     }
   } else {
     return notify_fail("Player "+ name +" not found or not interactive.\n");
   }
}
