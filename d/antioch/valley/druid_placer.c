// changes by Styx per T's suggestion to not clone but use the master object for unique
// mobs & to solve other bugs with them filling up the VOID w/o desting.  10/24/02

#include <std.h>
#include "valley.h"

// part of the in-process change by *Styx*, not used yet
#define DRUIDS ({ "druid1", "druid2", "druid3", "druid4", "druid5", "druid6", "druid7", "druid8", "druid9", "druid10", "druid11", "druid12" })

inherit ROOM;

void place_druids1();
void place_druids2();
void place_druids3();
void place_druids4();
void place_druids5();
void place_druids6();
void place_druids();

int x, total;

string DRUID1, DRUID2, DRUID3, DRUID4, DRUID5, DRUID6;

void create() {
	::create();
	set_terrain(MEADOWLANDS);
	set_travel(FOOT_PATH);
	set_property("outdoors",3);
	set_property("light",3);
}

void reset() {
	::reset();
	if(x == 1) return 1;
	else {
		call_out("place_druids1",1,TO);
		x = 1;
	}
	return 1;
}

/* thoughts/in process for an easier way that will check as they get chosen  *Styx*
which = random(sizeof(DRUIDS));
     for(i=0; i<sizeof(DRUIDS); i++) {
	which = random(sizeof(DRUIDS));
 //        who = lives[i];
	if(objectp(DRUIDS[which]))
	   continue;
        
        return;
              }
           }
if(!objectp(DRUIDS[which])) {
   DRUID1 = MONS+DRUIDS[which];
*/   

int place_druids() {
/* objectp checks added by *Styx* to avoid making duplicates which the set_unique
   sends to the void and makes it buggy for some reason.  Also using master object
   per T's suggestion on unique mobs, using find_object_or_load to be safe per Garrett
*/
	if(!objectp(DRUID1))	   find_object_or_load(DRUID1)->move(ROOMS+"v42");
	if(!objectp(DRUID2))	   find_object_or_load(DRUID2)->move(ROOMS+"v29");
	if(!objectp(DRUID3))	   find_object_or_load(DRUID3)->move(ROOMS+"v14");
	if(!objectp(DRUID4))	   find_object_or_load(DRUID4)->move(ROOMS+"g3");
	if(!objectp(DRUID5))	   find_object_or_load(DRUID5)->move(ROOMS+"g41");
	if(!objectp(DRUID6))	   find_object_or_load(DRUID6)->move(ROOMS+"g102");
	return 1;
}

int place_druids1() {
//    DRUID1 = MONS+"druid"+(random(11)+1);  // thinking this should work instead (shorter)
	switch(random(11)) {
		case 0:
			DRUID1 = MONS+"druid1";
			break;
		case 1:
			DRUID1 = MONS+"druid2";
			break;	
		case 2:
			DRUID1 = MONS+"druid3";
			break;	
		case 3:
			DRUID1 = MONS+"druid4";
			break;	
		case 4:
			DRUID1 = MONS+"druid5";
			break;	
		case 5:
			DRUID1 = MONS+"druid6";
			break;	
		case 6:
			DRUID1 = MONS+"druid7";
			break;	
		case 7:
			DRUID1 = MONS+"druid8";
			break;	
		case 8:
			DRUID1 = MONS+"druid9";
			break;	
		case 9:
			DRUID1 = MONS+"druid10";
			break;	
		case 10:
			DRUID1 = MONS+"druid11";
			break;	
		case 11:
			DRUID1 = MONS+"druid12";
			break;	
	}
	call_out("place_druid2",1,TO);
	return 1;
}

int place_druid2() {
	switch(random(11)) {
		case 0:
			DRUID2 = MONS+"druid1";
			break;
		case 1:
			DRUID2 = MONS+"druid2";
			break;	
		case 2:
			DRUID2 = MONS+"druid3";
			break;	
		case 3:
			DRUID2 = MONS+"druid4";
			break;	
		case 4:
			DRUID2 = MONS+"druid5";
			break;	
		case 5:
			DRUID2 = MONS+"druid6";
			break;	
		case 6:
			DRUID2 = MONS+"druid7";
			break;	
		case 7:
			DRUID2 = MONS+"druid8";
			break;	
		case 8:
			DRUID2 = MONS+"druid9";
			break;	
		case 9:
			DRUID2 = MONS+"druid10";
			break;	
		case 10:
			DRUID2 = MONS+"druid11";
			break;	
		case 11:
			DRUID2 = MONS+"druid12";
			break;	
	}
	if(DRUID1 == DRUID2) {
		call_out("place_druid2",1,TO);
		return 1;
	}
	else {
		call_out("place_druid3",1,TO);
		return 1;
	}
}

int place_druid3() {
	switch(random(11)) {
		case 0:
			DRUID3 = MONS+"druid1";
			break;
		case 1:
			DRUID3 = MONS+"druid2";
			break;	
		case 2:
			DRUID3 = MONS+"druid3";
			break;	
		case 3:
			DRUID3 = MONS+"druid4";
			break;	
		case 4:
			DRUID3 = MONS+"druid5";
			break;	
		case 5:
			DRUID3 = MONS+"druid6";
			break;	
		case 6:
			DRUID3 = MONS+"druid7";
			break;	
		case 7:
			DRUID3 = MONS+"druid8";
			break;	
		case 8:
			DRUID3 = MONS+"druid9";
			break;	
		case 9:
			DRUID3 = MONS+"druid10";
			break;	
		case 10:
			DRUID3 = MONS+"druid11";
			break;	
		case 11:
			DRUID3 = MONS+"druid12";
			break;	
	}
	if(DRUID2 == DRUID3 || DRUID1 == DRUID3) {
		call_out("place_druid3",1,TO);
		return 1;
	}
	else {
		call_out("place_druid4",1,TO);
		return 1;
	}
}

int place_druid4() {
	switch(random(11)) {
		case 0:
			DRUID4 = MONS+"druid1";
			break;
		case 1:
			DRUID4 = MONS+"druid2";
			break;	
		case 2:
			DRUID4 = MONS+"druid3";
			break;	
		case 3:
			DRUID4 = MONS+"druid4";
			break;	
		case 4:
			DRUID4 = MONS+"druid5";
			break;	
		case 5:
			DRUID4 = MONS+"druid6";
			break;	
		case 6:
			DRUID4 = MONS+"druid7";
			break;	
		case 7:
			DRUID4 = MONS+"druid8";
			break;	
		case 8:
			DRUID4 = MONS+"druid9";
			break;	
		case 9:
			DRUID4 = MONS+"druid10";
			break;	
		case 10:
			DRUID4 = MONS+"druid11";
			break;	
		case 11:
			DRUID4 = MONS+"druid12";
			break;	
	}
	if(DRUID4 == DRUID1 || DRUID4 == DRUID2 || DRUID4 == DRUID3) {
		call_out("place_druid4",1,TO);
		return 1;
	}
	else {
		call_out("place_druid5",1,TO);
		return 1;
	}
}

int place_druid5() {
	switch(random(11)) {
		case 0:
			DRUID5 = MONS+"druid1";
			break;
		case 1:
			DRUID5 = MONS+"druid2";
			break;	
		case 2:
			DRUID5 = MONS+"druid3";
			break;	
		case 3:
			DRUID5 = MONS+"druid4";
			break;	
		case 4:
			DRUID5 = MONS+"druid5";
			break;	
		case 5:
			DRUID5 = MONS+"druid6";
			break;	
		case 6:
			DRUID5 = MONS+"druid7";
			break;	
		case 7:
			DRUID5 = MONS+"druid8";
			break;	
		case 8:
			DRUID5 = MONS+"druid9";
			break;	
		case 9:
			DRUID5 = MONS+"druid10";
			break;	
		case 10:
			DRUID5 = MONS+"druid11";
			break;	
		case 11:
			DRUID5 = MONS+"druid12";
			break;	
	}
	if(DRUID5 == DRUID1 || DRUID5 == DRUID2 || DRUID5 == DRUID3 || DRUID5 == DRUID4) {
		call_out("place_druid5",1,TO);
		return 1;
	}
	else {
		call_out("place_druid6",1,TO);
		return 1;
	}
}

int place_druid6() {
	switch(random(11)) {
		case 0:
			DRUID6 = MONS+"druid1";
			break;
		case 1:
			DRUID6 = MONS+"druid2";
			break;	
		case 2:
			DRUID6 = MONS+"druid3";
			break;	
		case 3:
			DRUID6 = MONS+"druid4";
			break;	
		case 4:
			DRUID6 = MONS+"druid5";
			break;	
		case 5:
			DRUID6 = MONS+"druid6";
			break;	
		case 6:
			DRUID6 = MONS+"druid7";
			break;	
		case 7:
			DRUID6 = MONS+"druid8";
			break;	
		case 8:
			DRUID6 = MONS+"druid9";
			break;	
		case 9:
			DRUID6 = MONS+"druid10";
			break;	
		case 10:
			DRUID6 = MONS+"druid11";
			break;	
		case 11:
			DRUID6 = MONS+"druid12";
			break;	
	}
	if(DRUID6 == DRUID1 || DRUID6 == DRUID2 || DRUID6 == DRUID3 || DRUID6 == DRUID4 || DRUID6 == DRUID5) {
		call_out("place_druid6",1,TO);
		return 1;
	}
	else {
		call_out("place_druids",1,TO);
		return 1;
	}
}

