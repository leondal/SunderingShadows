//  Overseer Daemon for Azha
//  Natael@ShadowGate
//  961012
//  overseer.c

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/azha/monsters.h"
#include "/d/tsarven/include/southern.h"

#define DEGRADE_TIME 75
#define DEGRADE_AMT 2
#define MAX_POPULATION 60

inherit OBJECT;


int townStatus;  // Town Status gauge
int numMonsters;  // counter of monsters made w/ this daemon
object *resetMons;  // Monsters to be dested on next reset

object *queue_for_reset(object add);
void add_timed_monster(object room, string file, string track);
int processTimedMonsters();
int add_monster(object room, string monster, int num);
int always_add_monster(object room, string monster, int num);
int setup_monsters(object room, string rmtype);	
int change_tstatus(int x);
int change_town_status(int x);
string query_town_status();
int initOverseer();


create() {
	::create();
	initOverseer();
}

reset() {
	::reset();
	processTimedMonsters();
}
	
	
int initOverseer() {
	townStatus = 1;
	numMonsters = 0;
	call_out("degrade_state", DEGRADE_TIME);
}

//  TOWN STATUS -- There are a number of statuses that the town can be
// in.  If the status worsens, then somethings automatically occur, like
// auto-emoting some warnings, extra watchmen, Imperial Garrison deployment
// or possibly a caravan....

string query_town_status() {
	if(townStatus <= 5) return "normal";
	else if(townStatus <= 20) return "disturbed";
	else if(townStatus <= 40) return "agitated";
	else if(townStatus <= 60) return "chaotic";
	else if(townStatus > 60) return "beseiged";
	else return "error!";
}

int change_town_status(int x) { return townStatus += x; }

int change_tstatus(int x) { return townStatus += x; }

int query_tstatus() { return townStatus; }

int degrade_state() { 
	if(townStatus >= DEGRADE_AMT) townStatus -= DEGRADE_AMT;
	call_out("degrade_state", DEGRADE_TIME);
	return townStatus;
}

//  END OF TOWN STATUS

//  ENCOUNTERS -- Depending on the mood of the city, the players will 
// meet different people at certain places.  This function determines
// the various places, and what the players will meet there depending
// on the status of the town.

int setup_monsters(object room, string rmtype) {
	string type;
	int x;
	
	type = rmtype;
	if(query_town_status() == "error!") return -1;
	switch(type) {
	  case "strategic":
	  		always_add_monster(room, SGT,1);
			always_add_monster(room, SOLDIER, random(8));
			return 2;
			break;
	  case "barracks":
	  	    add_monster(room, SGT,1);
			always_add_monster(room, SOLDIER, random(6)+2);
			return 2;
			break;
	  case "fort":
	  		add_monster(room, SGT,1);
			always_add_monster(room, SOLDIER, 1);
			return 2;
			break;
	  case "patrol":
			add_monster(room, SCOUT, 1);
			return 2;
			break;
	  case "street":
            always_add_monster(room,"/d/shadow/obj/misc/street_light",1);
			if((random(100)+1) <= 15) add_monster(room, THIEF,1);
			add_monster(room, TOWNIE, random(5));
			break;
	  case "market":
            always_add_monster(room,"/d/shadow/obj/misc/street_light",1);
			if((random(100)+1) <= 30) add_monster(room, THIEF,1);
            always_add_monster(room, "/d/azha/mon/merchant", 1);
			add_monster(room, TOWNIE, random(2)+1);
			break;			
	  case "gate":
            always_add_monster(room,"/d/shadow/obj/misc/street_light",1);
			add_monster(room, TOWNIE, random(2));
			add_monster(room, SOLDIER, random(5));
			add_monster(room, SGT,1);
			break;						
	  case "intersection":
			if((random(100)+1) <= 30) add_monster(room, THIEF,1);
            always_add_monster(room,"/d/shadow/obj/misc/street_light",1);
			always_add_monster(room, WATCH,1);
			add_monster(room, TOWNIE, random(5));
			break;
	  case "public":
			if((random(100)+1) <= 10) add_monster(room,THIEF,1);
			add_monster(room,TOWNIE,random(4));
			break;
	  default:
			break;
	}		
	return 1;
}

int add_monster(object room, string monster, int num) {
	int x,i,y;
	string *ids;
	object monsterobj;
	
	if(numMonsters >= MAX_POPULATION) return 1;
	monsterobj = new(monster);
	ids = monsterobj->query_id();
        monsterobj->remove();
	if(num <= 0) return 0;
	i=num;
	y=i;
	
//  Make sure that duplicates are not created each reset unless
//  they were killed or moved since last reset
	for(x=0;x<y;x++) {
		if(present(ids[0]+" "+(y-x), room)) i--;
	}

//  Clones the number of monsters remaining that need to be 
//  placed into the room to make the tally.  If no extra monsters
//  are needed this reset, then none are made.
	if(i <= 0) return 0;
	for(x=0;x<i;x++) {
		new(monster)->move(room);
		numMonsters++;
	}
	return numMonsters;
}

int always_add_monster(object room, string monster, int num) {
	int x,i,y;
	string *ids;
	object monsterobj;
	
	monsterobj = new(monster);
	ids = monsterobj->query_id();
        monsterobj->remove();
	if(num <= 0) return 0;
	i=num;
	y=i;
	
	for(x=0;x<y;x++) {
		if(present(ids[0]+" "+(y-x), room)) i--;
	}

	if(i <= 0) return 0;
	for(x=0;x<i;x++) {
		new(monster)->move(room);
		numMonsters++;
	}
	return numMonsters;
}

//  We'll destroy any monsters created this way at the next reset
//  This should control wandering monsters who want to get away
//  from us and multiply out of control.	
void add_timed_monster(object room, string file, string track) {
	object ob;
	
	new(file)->move(room);
	call_out("queue_for_reset", 10, ob);
	return;
}	
	
object *queue_for_reset(object add) {
	if(!resetMons) resetMons == ({ });
	if(!add) return resetMons;
        resetMons = resetMons + ({ add });
	return resetMons;
}

int processTimedMonsters() {
	object *inv, splat, *lineup;
	int w,x,y,z;
	
	lineup = resetMons;
	w=sizeof(lineup);
	if(!w) return 0;
	for(x=0;x<w;x++) {
		splat = resetMons[x];
		inv = all_inventory(splat);
		for(z=0;z<sizeof(inv);z++) {
			if(!(inv[z]->remove())) destruct(inv[z]);
		}
		if(!(splat->remove())) destruct(splat);
	}
	return 1;
}

// add_object
// Adds 'num' objects of one type and keeps the same number
// in the room despite resets or updates.  Could be used
// for things other than rooms, but with monsters and other
// similar things, there's no point to it.

int add_object(object room, string file, int num) {
	int x,i,y;
	string *ids;
	object obj;
	
	obj = new(file);
	ids = obj->query_id();
     obj->remove();
	if(num <= 0) return 0;
	i=num;
	y=i;
	
//  Make sure that duplicates are not created each reset unless
//  they were bought since last reset
	for(x=0;x<y;x++) {
		if(present(ids[0]+" "+(y-x), room)) i--;
	}

//  Clones the number of objects remaining that need to be 
//  placed into the room to make the tally.  If no extra objects
//  are needed this reset, then none are made.
	if(i <= 0) return 0;
	for(x=0;x<i;x++) {
		new(file)->move(room);
	}
	return num;
}

// cheap_imitation
// Same as add_object except there is the possibility that a cheap
// imitation of that object is added instead.
int cheap_imitation(
                    object room, 
                    string file, 
                    int num,
                    int real
                   )
{
	int x,i,y;
	string *ids;
	object obj, im;
	
	obj = new(file);
	ids = obj->query_id();
      if(num<= 0) {   
// moved the remove up here so it doesn't strand the objects if they aren't needed *Styx*
// 12/6/04, last change 7/30/01
	obj->remove();
	return 0;
      }
	i=num;
	y=i;
	
//  Make sure that duplicates are not created each reset unless
//  they were bought since last reset
	for(x=0;x<y;x++) {
		if(present(ids[0]+" "+(y-x), room)) i--;
	}

//  Clones the number of objects remaining that need to be 
//  placed into the room to make the tally.  If no extra objects
//  are needed this reset, then none are made.  A roll is made
//  to see if instead of the real thing, you get a cheap imitation.
	if(i <= 0) {
// added a remove so it doesn't strand the objects if they aren't needed *Styx*
// 12/6/04, last change 7/30/01
	   obj->remove();
	   return 0;
  	}
	for(x=0;x<i;x++) {
		if(real>random(100)) new(file)->move(room);
		else {
		  im=new("/d/azha/obj/fake");
		  im->move(room);
		  im->set_short((string)obj->query_short());
		  im->set_name((string)obj->query_name());
		  im->set_id((string *)obj->query_id());
                  im->set_type((string)obj->query_type());
                  im->set_long((string)obj->query_long());
		  im->set_value((int)obj->query_value());
		}
	}
    obj->remove();
	return num;
}


