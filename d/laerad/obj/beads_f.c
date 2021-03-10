//Coded by Bane//

#include <std.h>

inherit OBJECT;

int uses;
object oldenv, globe, globe2, ob;

void release();

void create()
{
  ::create();
    set_id(({"string","beads","string of beads"}));
    set_name("A string of beads");
    set_short("A string of beads");
    set_weight(5);
    uses = random(4)+5;
}

void init()
{
  ::init();
    add_action("read_p","read");
    add_action("throw_b","throw");
    if(uses == 5)
      {
	set_long("A string of beautiful black beads. There are 5 beads "
		 "remaining on the string. An inscription can be seen on a "
		 "small plate attached to the string.");
	set_value(3500);
	return 1;
      }
    if(uses == 6)
      {
	set_long("A string of beautiful black beads. There are 6 beads "
		 "remaining on the string. An inscription can be seen on a "
		 "small plate attached to the string.");
	set_value(3800);
 	return 1;
      }
    if(uses == 7)
      {
	set_long("A string of beautiful black beads. There are 7 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(4100);
 	return 1;
      }
    if(uses == 8)
      {
	set_long("A string of beautiful black beads. There are 8 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(4500);
	return 1;
      }
}

int read_p(string str)
{
  if(!str) return notify_fail("Read what?\n");
  if(str != "plate") return 0;
  write("These are magical beads of force. To use them type 'throw bead "+
	"at <target>'. Remember that you can only use each bead once.");
  return 1;
}

int throw_b(string str)
{
  string who;
  if(!str) return notify_fail("Throw what?\n");
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

  if(sscanf(str,"bead at %s",who) != 1) return notify_fail("Wrong syntax.\n");
  if(!(ob = present(who,environment(TP))))
    return notify_fail("That is not here!\n");
  if(uses < 1)
    {
      write("There are no beads left!");
      return 1;
    }
  if(!TP->kill_ob(ob,0)) return 1;
  tell_object(ob,"%^BOLD%^BLUE%^"+TP->query_cap_name()+" removes a bead from "+TP->query_possessive()+" string and throws it at you!");
  tell_object(TP,"%^BOLD%^BLUE%^You remove a bead from your string and throw "
	      "it at "+ob->query_cap_name()+"!");
  tell_room(ETP,"%^BOLD%^BLUE%^"+TP->query_cap_name()+" removes a bead from "+
	    TP->query_possessive()+" string and throws it at "+
	    ob->query_cap_name()+"!",({ob,TP}));
  tell_object(ob,"%^BOLD%^CYAN%^The bead hits you exploding with tremendous "
	      "force!");
  tell_room(ETP,"%^BOLD%^CYAN%^The bead hits "+ob->query_cap_name()+
	    " exploding with tremendous force!",ob);
  ob->do_damage(ob->return_target_limb(),roll_dice(5,4));
  uses -= 1;
  if(uses == 0)
    {
      set_short("A piece of string");
      set_long("A piece of string");
      set_value(0);
    }
  if(uses == 1)
    {
      set_long("A string with a beautiful black bead. There is 1 bead "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate that is attached to the string.");
	set_value(500);
    }
  if(uses == 2)
    {
	set_long("A string of beautiful black beads. There are 2 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(900);
    }
  if(uses == 3)
    {
	set_long("A string of beautiful black beads. There are 3 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(1500);
    }
  if(uses == 4)
    {
	set_long("A string of beautiful black beads. There are 4 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(2100);
    }
  if(uses == 5)
    {
	set_long("A string of beautiful black beads. There are 5 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(3500);
    }
  if(uses == 6)
    {
	set_long("A string of beautiful black beads. There are 6 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(3800);
    }
  if(uses == 7)
    {
	set_long("A string of beautiful black beads. There are 7 beads "+
	"remaining on the string. An inscription can be seen on a small "+
	"plate attached to the string.");
	set_value(4100);
    }
  if(!"/daemon/saving_d"->saving_throw(ob,"spell"))
    {
      oldenv=environment(ob);
      globe=new("/d/laerad/obj/globe.c");
      globe2=new("/d/laerad/obj/globe2.c");
      tell_object(ob,"%^BOLD%^An invulnerable globe of force erupts from the bead trapping you within!");
      tell_room(ETP,"%^BOLD%^An invulnerable globe of force erupts from the bead trapping "+ob->query_cap_name()+" within!",ob);
      ob->move(globe);
      globe2->move(oldenv);
      call_out("release",70);
      return 1;
    }
  else
    {
      tell_object(ob,"%^BOLD%^You are thrown to the ground by the explosion!");
      tell_room(ETP,"%^BOLD%^"+ob->query_cap_name()+" is thrown to the ground by the explosion!",ob);
      ob->set_paralyzed(20,"You are stunned from the blast.");
      return 1;
    }
}

void release()
{
  object *tempinv;
  int i, j;

  tempinv=all_inventory(globe);
  i = sizeof(tempinv);
  for(j=0;j<i;j++)
    {
      tempinv[j]->move(oldenv);
    }
  globe2->remove();
  tell_room(environment(ob),"%^BOLD%^The globe collapses.");
  globe->remove();
}
