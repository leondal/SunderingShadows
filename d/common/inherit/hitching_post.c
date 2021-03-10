//hitching_post.c - Inheritable for hitching posts.  Circe 4/23/04
//adapted from Crystal's Antioch code
//use for a stable room to leave horses.  Remember to set terrain and travel!!
//Also, set_long, set_items, set_smell & set_listen
//You'll need to add a set_pre_exit_functions(({"exit"}),({"GoThroughDoor"}));
#include <std.h>

inherit VAULT; //for those stables with gates/doors

/*
#define MOUNTS ({"horse","hippogriff","strider","lizard","bear","wolf","bear","worg","dragon","boar","tyrg","cheetah","donkey","charger","stallion","mare","gelding","pony"})
*/

// added so they won't get cleaned up if there's stuff in them -Ares
int clean_up()
{
    if(!objectp(TO)) { return ::clean_up(); }
    if(sizeof(all_inventory(TO))) { return 1; }
    else { return ::clean_up(); }
}

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_name("A tethering post");
	set_short("A tethering post");
}

void init()
{
	::init();
	add_action("tether","tether");
    add_action("untether","untether");
}

int tether(string str)
{
   string name;
   object obj;
   obj = present(str);

	if(!present(str)) {
		notify_fail("That isn't even here!\n");
		return 0;
	}
//	if(member_array(str,MOUNTS) == -1) {
	if(!obj->query_is_mount()) {
		notify_fail("You should only tether mounts!\n");
		return 0;
	}
	if(TP != (object)obj->query_owner()) {
		notify_fail("You should only tether your own "+str+".\n");
		return 0;
	}
	if(obj->query_current_rider()) {
		notify_fail("You have to dismount before you can tether your "+str+".\n");
		return 0;
	}
	else {
		write("You loop your mount's reins around a tethering post.\n");
		say(""+TPQCN+" loops "+TP->QP+""+
		" "+str+"'s reins around the tethering post.\n");
		obj->set_property("tethered",1);
		name = obj->query_short();
		obj->set_short(""+name+" (tethered)");
            if ( TP->query_followers() && member_array(obj,TP->query_followers()) == 1){
               TP->remove_follower(obj);
            }
		return 1;
	}
}

int untether(string str)
{
   string name;
   object obj;
   obj = present(str);

   if(!present(str)) {
      notify_fail("That isn't even here!\n");
      return 0;
   }
//	if(member_array(str,MOUNTS) == -1) {
	if(!obj->query_is_mount()) {
		notify_fail("This tethering post is only for mounts.\n");
		return 0;
	}
	if(TP != (object)obj->query_owner()) {
		notify_fail("You should only untether your own "+str+".\n");
		return 0;
	}
   if(!obj->query_property("tethered")) {
      notify_fail("Um, that "+str+" isn't even tethered...\n");
      return 0;
   }
   if(obj->query_current_rider()) {
      notify_fail("No one should be riding a tethered "+str+".\n");
      return 0;
   }
   else {
      obj->remove_property("tethered");
      write("You unloop your mount's reins from the tethering post.");
      say(""+TPQCN+" unloops "+TP->QP+" mount's reins"+
      " from the tethering post.");
      if(obj->query_current_rider()) return 1;
      name = obj->query_name();
      obj->set_short(name);
      return 1;
   }
}

int GoThroughDoor()
{
   object obj;

   if(TP->query_in_vehicle()) {
      obj = (object)TP->query_in_vehicle();
      if(obj->query_property("tethered")) {
         tell_object(TP,"You try to leave but haven't untethered your mount yet!");
         tell_room(ETP,""+TPQCN+" tries to leave without untethering"+
         " "+TP->QP+" mount, and doesn't get very far!",TP);
         return 0;
      }
   }
   return ::GoThroughDoor();
}
