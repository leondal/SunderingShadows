//inherit room to sprinkle in drow at night, random no sticks, etc. - Originally created 
//by Styx and modified by Saide 11/15/03 
#include <std.h>
#include "graveyard.h"
#include <daemons.h>
#define SD "/d/common/daemon/randstuff_d"
#define PN "deku_dead_names"

inherit CVAULT;

string bname;
int searched, no_name, digging, has_dug;

void create() {
 ::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   if(!random(3)) set_property("no sticks",1);
   set_name("shadowlord graveyard");
   set_short("%^BOLD%^%^WHITE%^Shadowlord Graveyard%^RESET%^");
   
   set_long((:TO,"long_desc":));

  set_smell("default","The air here reeks with a strong odor "+
  "of death and decay.");
  set_listen("default","There is only an ominous silence.");

  set_items(([
   ({"statues","memorials"}) : "%^RED%^These statues once served "+
   "as memorials to those who have died.  While at one time "+
   "they were of various creatures, people, or things, "+
   "now they are all broken and lay in ruin.%^RESET%^",
   ({"headstones","stones"}) : (:TO,"headstone_desc":),
   ({"ruins","ruin"}) : "%^RED%^The ruins of statues and "+
   "headstones litter the area near the footpath, mixing "+
   "with the thick weeds.  There is no telling what "+
   "could be concealed by them.%^RESET%^",
   ({"burial places","graves"}) : "%^RED%^Most of these graves "+
   "have been defiled in some manner, some of them have "+
   "been completely dug up and some look to be only recently "+
   "disturbed.  You think you could dig deeper down into them "+
   "if you wanted, but what you might find is anyones guess.%^RESET%^",
   ({"path","footpath","meager path",
   "meager footpath"}) : "%^GREEN%^This meager "+
   "footpath leads through the graveyard.  It is "+
   "littered with holes and rocks, making any travel "+
   "on it potentially dangerous, it has had no upkeep "+
   "in a very long time.%^RESET%^",
   ({"weeds","weed","thick weed","thick weeds"}) : "%^GREEN%^These "+
   "weeds have grown up around the path in thick clumps.%^RESET%^",
   ({"rocks","rock"}) : "%^BOLD%^%^WHITE%^These rocks litter "+
   "the meager path that leads through the graveyard.  "+
   "They are mostly small but an occassional larger one makes the "+
   "journey even more harrowing.%^RESET%^",
   ({"holes","hole"}) : "%^RED%^These holes dot the meager "+
   "path that leads through the graveyard.  Some of them "+
   "are shallow while others are up to several feet deep, they "+
   "add to the danger of traveling through this abandoned "+
   "graveyard.%^RESET%^",
   ({"inhabit","inhabitants"}) : "%^RED%^Your mind "+
   "occassionally drifts to the inhabitants of this "+
   "place, what are they?  Where did they come from?  "+
   "Or even are there any?%^RESET%^",
   ({"defiled"}) : "%^RED%^Most of the graves have been "+
   "defiled in one way or another, some have been "+
   "completely dug up while others look to have been only "+
   "recently disturbed.%^RESET%^",
   ] ));
   searched = 0;
   no_name = 0;
   set_search("ruins",(:TO,"ruins_search":));
   set_search("ruin",(:TO,"ruins_search":));
   set_search("headstones",(:TO,"name_search":));
   set_search("stones",(:TO,"name_search":));
   //set_search("hole",(:TO,"hole_search":));
   //set_search("holes",(:TO,"hole_search":));

   //set_search("default","The graveyard is littered with broken "+
   //"headstones, ruins, and holes make traveling hazardous.");
   
   set_search("default","The ruins catch your attention.");
   if(base_name(TO) != GRAVEYARD && 
    (string)EVENTS_D->query_time_of_day() == "night") { 
     switch(random(4)) {
      case 0:
       set_monsters(({GY_MOBS +"ghoul"}),({1}));
       set_monsters(({GY_MOBS +"gy_juju"}),({random(2) + 1}));
       break;
      case 1:
       set_monsters(({GY_MOBS+"gy_juju"}),({random(2) + 1}));
       set_monsters(({GY_MOBS+"gy_skeleton"}),({random(3) + 2}));
       break;
      case 2:
       set_monsters(({GY_MOBS+"gy_babu"}),({random(2) + 1}));
       set_monsters(({GY_MOBS+"gy_skeleton"}),({random(2) + 1}));
       break;
      case 3:
       set_monsters(({GY_MOBS+"ghoul"}),({1}));
       set_monsters(({GY_MOBS+"gy_skeleton"}),({1 + random(2)}));
       break;
     } 
   set_repop(15);
 }
}

int name_search() {
    string *names,tmpname;
    if(base_name(TO) == GRAVEYARD || (string)EVENTS_D->query_time_of_day() != "night") {
        write("You can make out no legible writing.");
        return 1;
    }
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^CYAN%^ carefully examines a few of "+
        "the glowing headstones.%^RESET%^",TP);
    }
    if(no_name == 0) {
        if(!random(5)) {
            names = SAVE_D->query_array("deku_dead_names_used_array");
            tmpname = names[random(sizeof(names))];
           
            if(member_array(tmpname,names) != -1) {
                bname = tmpname;
                SAVE_D->set_value(PN,bname);
            }
        }
        no_name = 1;
    }
    if(bname) {
       tell_object(TP,"%^CYAN%^You carefully examine "+
       "several of the glowing headstones and make "+
       "out the name "+bname+".%^RESET%^");
       return 1;
    }
    tell_object(TP,"%^CYAN%^You carefully examine several of "+
    "the glowing headstones but find none of them to contain "+
    "any legible writing.%^RESET%^");
    return 1;       
}

void reset() {
    ::reset();
    if(!random(10)) {
        digging = 0;
        has_dug = 0;
    }
    if((string)EVENTS_D->query_time_of_day() == "day" 
    && sizeof(SAVE_D->query_array(PN)) != 0) {
        SAVE_D->remove_array(PN);
        bname = 0;
    }
}

void init() {
    ::init();
    add_action("dig_function","dig");
}

void dig_activity(string str) {
    if (remove_call_out("do_digging") != -1) {
        tell_object(TP, "You stop digging and stand up.");
        TP->remove_paralyzed();
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+" suddenly stops digging and "+
            "stands up.",TP);
            digging = 0;
            return;
        }
        tell_room(TO,"Suddenly the dirt stops flying and "+
        "for a moment you again wonder if someone was "+
        "digging in one of the graves....",TP);
        digging = 0;
        return;
    }
    return;
}

void dig_where() {
    write("You could try digging in the graves here.");
}

int dig_function(string str) {
    if(!str) {
        dig_where();        
        return 1;
    }
    if(str == "in graves" || str == "graves" || str == "grave"
    || str == "burial places") {
        if(digging == 1) {
            write("Someone is already digging in that grave!");
            return 1;
        }
        write("You drop to the ground and begin digging down "+
        "into one of the open graves!");
        TP->set_paralyzed(100,"You are busy digging into one of "+
        "the graves!");
        input_to("dig_activity",1);
        digging = 1;
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+" drops to the ground and begins "+
            "digging down into one of the open graves!",TP);
        }
        if(TP->query_invis()) {
            tell_room(TO,"You notice dirt begin flying out of "+
            "one of the open graves and you almost think "+
            "that someone is digging down into it.",TP);
        }
        call_out("do_digging",10,TP);
        return 1;
    }
    return 0;
}

void nothing_found(object who) {
    if(!objectp(who)) return;
    tell_object(who,"%^RED%^...nothing...%^RESET%^");
    if(!who->query_invis()) {
        tell_room(TO,who->QCN+"%^RED%^ continues digging "+
        "for a little while and then gives up, having found "+
        "nothing of value.",who);
        return 1;
    }
    tell_room(TO,"Suddenly the dirt stops flying and "+
    "for a moment you again wonder if someone was "+
    "digging in one of the graves....",who);
    return 1;
}

int do_digging(object who) {
    if(!objectp(who)) { 
        digging = 0;
        return 1;
    }
    tell_object(who,"%^RED%^You continue digging and your "+
    "search yields....");
    who->set_paralyzed(0);
    digging = 0;
    if(has_dug) {
        nothing_found(who);
        return 1;
    }
    if(!has_dug) {
        has_dug = 1;
        if(!random(30)) {
            SD->find_stuff(TO,"random");
            tell_object(who,"%^RED%^....something of "+
            "%^BLUE%^value!%^RESET%^");
            if(!TP->query_invis()) {
                tell_room(TO,who->QCN+"%^RED%^ continues digging "+
                "for a little while and finally manages to find "+
                "something of value!%^RESET%^",who);
                return 1;
            }
            tell_room(TO,"Suddenly the dirt stops flying and "+
            "for a moment you again wonder if someone was "+
            "digging in one of the graves....",who);
            return 1;
        }
        nothing_found(who);
        return 1;
    }
}

int ruins_search() {
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ digs through a deep "+
        "pile of the ruins.%^RESET%^",TP);
    }
    tell_object(TP,"%^BOLD%^%^BLACK%^You dig through a deep pile "+
    "of ruins.%^RESET%^");
    if(searched == 0 && !random(16)) {
        tell_object(TP,"%^RED%^Your search yields something "+
        "of value.%^RESET%^");
        if(!TP->query_invis()) {
            tell_room(TO,TPQCN+"%^RED%^ finds something of value "+
            "beneath the ruins.%^RESET%^",TP);
        }
        SD->find_stuff(TO,"random");
        searched = 1;
        return 1;
    }
    tell_object(TP,"%^RED%^You give up the search after "+
    "digging through the ruins and finding nothing.%^RESET%^");
    
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^RED%^ seems to find nothing of "+
        "interest in the ruins.%^RESET%^",TP);
    }

    searched = 1;
    return 1;
}
    
void query_buried_name(string what) {
    if(what == "stones" || what == "headstones") {
        return bname;
    }
}

void long_desc() {
    
    if((string)EVENTS_D->query_time_of_day() != "night") { 
    
        return "%^BOLD%^%^WHITE%^This once proud graveyard has "+
        "fallen into a state of disarray.  Once used by the locals "+
        "of this island to bury their dead, it has obviously "+
        "long since been abandoned.  The %^RESET%^statues%^BOLD%^"+
        "%^WHITE%^ that were used for %^BOLD%^%^BLACK%^memorials"+
        "%^BOLD%^%^WHITE%^ are now broken and lay in "+
        "%^BOLD%^%^BLACK%^ruin%^BOLD%^%^WHITE%^.  Even the "+
        "%^RESET%^headstones%^BOLD%^%^WHITE%^ which were once "+
        "used to mark the %^BOLD%^%^BLACK%^burial places"+
        "%^BOLD%^%^WHITE%^ of the dead now lay broken, and "+
        "the %^RED%^graves%^BOLD%^%^WHITE%^ which they marked "+
        "have been %^BOLD%^%^BLACK%^defiled%^BOLD%^%^WHITE%^.  "+
        "A %^RED%^meager footpath%^BOLD%^%^WHITE%^ leads through the "+
        "graveyard and, like the rest of the place, it "+
        "has seen no upkeep.  Thick %^RESET%^%^GREEN%^"+
        "weeds%^BOLD%^%^WHITE%^ grow up around it, and "+
        "it is littered with %^BOLD%^%^BLACK%^holes%^BOLD%^"+
        "%^WHITE%^ and %^RESET%^rocks%^BOLD%^%^WHITE%^.  "+
        "You are forced to not only watch for whatever "+
        "might happen to %^BOLD%^%^BLACK%^inhabit%^BOLD%^%^WHITE%^ "+
        "this place, but to carefully consider your "+
        "own steps as well.%^RESET%^";
    }
    
     return "%^BOLD%^%^WHITE%^This once proud graveyard has "+
        "fallen into a state of disarray.  Once used by the locals "+
        "of this island to bury their dead, it has obviously "+
        "long since been abandoned.  The %^RESET%^statues%^BOLD%^"+
        "%^WHITE%^ that were used for %^BOLD%^%^BLACK%^memorials"+
        "%^BOLD%^%^WHITE%^ are now broken and lay in "+
        "%^BOLD%^%^BLACK%^ruin%^BOLD%^%^WHITE%^.  Even the "+
        "%^CYAN%^glowing%^RESET%^ headstones%^BOLD%^%^WHITE%^ which were once "+
        "used to mark the %^BOLD%^%^BLACK%^burial places"+
        "%^BOLD%^%^WHITE%^ of the dead now lay broken, and "+
        "the %^RED%^graves%^BOLD%^%^WHITE%^ which they marked "+
        "have been %^BOLD%^%^BLACK%^defiled%^BOLD%^%^WHITE%^.  "+
        "A %^RED%^meager footpath%^BOLD%^%^WHITE%^ leads through the "+
        "graveyard and, like the rest of the place, it "+
        "has seen no upkeep.  Thick %^RESET%^%^GREEN%^"+
        "weeds%^BOLD%^%^WHITE%^ grow up around it, and "+
        "it is littered with %^BOLD%^%^BLACK%^holes%^BOLD%^"+
        "%^WHITE%^ and %^RESET%^rocks%^BOLD%^%^WHITE%^.  "+
        "You are forced to not only watch for whatever "+
        "might happen to %^BOLD%^%^BLACK%^inhabit%^BOLD%^%^WHITE%^ "+
        "this place, but to carefully consider your "+
        "own steps as well.%^RESET%^";
}    

void headstone_desc() {	
	string tmp = ".";
	if(base_name(TO) == "/d/deku/fortress/grave1")
	{
		if(objectp(TP)) 
		{
			if(!TP->query("first_burial_name")) 
			{
				TP->set("first_burial_name", "salvirius");
			}
		}
		if((string)EVENTS_D->query_time_of_day() != "night")
		{
			tmp = ".  However, beneath the writing, "+
		      "in a totally different script, is the word "+
			"'%^RESET%^Salvirius%^BOLD%^"+
		      "%^WHITE%^'%^RESET%^%^RESET%^";
		}
		else 
		{
			tmp = ".  Resting strangely, as if written on top of "+
			"the glow, is the "+
			"word '%^RESET%^Salvirius%^BOLD%^%^WHITE%^'%^RESET%^";
		}

	}
    	if((string)EVENTS_D->query_time_of_day() != "night") 
	{
      	return "%^BOLD%^%^WHITE%^These headstones lay in "+
        	"ruin near the graves they once marked.  The writings "+
        	"that were once proudly displayed on them are now less "+
        	"than garble and completely illegible" + tmp;
      }
    	return "%^BOLD%^%^WHITE%^These headstones lay in ruin near "+
    	"the graves they once marked.  Strangely, in the dark of night "+
    	"they give off a bright %^CYAN%^glow%^BOLD%^%^WHITE%^ "+
    	"and you consider carefully searching them to perhaps "+
	"discover what names once adorned them"+tmp;
}

