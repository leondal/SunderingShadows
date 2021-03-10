// Room inheritable for Laerad
// High Mortal area
// Coded by Bane
/*  Index out of bounds
program: realms/styx/cavern.c, object: realms/styx/cavern line 56
'     heart_beat' in 'realms/styx/cavern.c' ('  realms/styx/cavern')line 56
Heart beat in realms/styx/cavern turned off.
*/

#include <std.h>
inherit ROOM;
int flag;

void create(){
    ::create();
   set_terrain(NAT_TUNNEL);
   set_travel(FOOT_PATH);
   set_long("%^BOLD%^%^BLACK%^You are standing in an underground cavern system. A small stream is running along one of the walls winding its way through the room. The ceiling is fairly low, only about 9 feet from the ground. Lichen and other assorted mosses cover about 90 percent of the walls, glowing a strange flourescent yellow and lighting up the area. Stalagtites and stalagmites litter the ceilings and floor.");
    set_property("no teleport",1);
   set_property("continue heartbeat",1);
    set_heart_beat(1);
}

void init(){
    string *exits;
    int i;
    ::init();
    exits = ({});
    exits = TO->query_exits();
    for(i=0;i<sizeof(exits);i++)
      add_action("leaving",exits[i]);
}

void leaving(){
    if(random(20) < 3){
      if(flag) return 0;
      if(!interactive(TP)) return 0;
        if(!wizardp(TP) && !TP->query_true_invis()) {
            write("A magical force seems to hold your feet in place.");
            return 1;
        }
    }
    return 0;
}

void heart_beat(){
    object *things, moving, *inven;
    string *exits,*ids;
    int i, j, a, b;
    ::heart_beat();
    
    exits = ({});
    inven = ({});
    things = ({});
    exits = TO->query_exits();
    
    i = sizeof(exits);
    j = random(i);
    things = all_living(TO);
    if(!sizeof(things)) return 1;
    moving = things[random(sizeof(things))];
    inven = all_inventory(moving);

    if(random(100) < 2) {
      if(!TO->query_property("no magic",1)){
        tell_room(TO,"The room seems to darken.");
        set_property("no magic",1);
      }
    }

    if(random(100) < 3){
      if(TO->query_property("no magic",1)){
	    tell_room(TO,"The room seems to brighten.");
	    remove_property("no magic");
      }
    }
    if(!moving || !objectp(moving))  return;

    if(random(100) < 2){
      tell_object(moving,"You feel a tingling sensation.");
      moving->do_damage(moving->return_target_limb(),-2);
    }

    if(random(100) < 2){
      if(interactive(moving)){
        if(moving->query_paralyzed() || !exits)  return;
        if(!wizardp(moving) && !moving->query_true_invis()){
          flag = 1;
          tell_object(moving,"A magical force shoves you "+exits[j]+"!");
          moving->force_me(exits[j]);
          flag = 0;
        }
      }
    }

    if(random(100) < 2) {
     return; //DISABLING this function due to complaints, 4 Dec 19, Uriel
      if(interactive(moving)) {
        if(!inven)  return;
        if(!wizardp(moving) && !moving->query_true_invis()) {
//            for(a=0;a<1;a++){  was already specifying variable b so don't need this
//            b isn't used elsewhere so moving definition to here to avoid bugs
           b = random(sizeof(inven));
// adding check for "no animate" to catch most system objects per bug report *Styx* 10/02
	   if(inven[b]->query_property("no animate") || !objectp(inven[b])) 
		return;
           tell_object(moving,"A magical force tries making you drop "
		+inven[b]->query_name()+"!");
// added check for cursed items to not be dropped  *Styx*  9/8/02
	    if(inven[b]->query_enchantment() < 0)  
		return; //changed to drop items by ID rather than name, to fix items that don't get dropped -Ares 7/17/05
        if(inven[b]) { ids = inven[b]->query_id(); }
            moving->force_me("drop "+ids[0]);
        }
      }
    }
}
