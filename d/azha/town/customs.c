// Imperial Customs Office, Azha Province
// Thorn@ShadowGate
// 4/6/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(1);  
	set_short("Imperial Customs Office, Azha Province");
  set_long(
@AZHA
%^BOLD%^Imperial Customs Office, Azha Province%^RESET%^
	You have found yourself inside of a spacious stone building 
brimming with boxes and ledgers.  Clerks work busily to process
imports into the empire, and charge the appropriate tariffs. Imperial
Customs also handles the licensing of merchants allowed to do
business in the import-export market.  A clerk looks up briefly as
you enter, and then returns to his work.
AZHA
    );
	set_exits(([
	"south" : "/d/azha/town/fort1"  
  ] ));     
	set_smell("default","The smell of old books and parchment fills the air.");
	set_items(([
		"boxes" : "These boxes probably hold receipts and other such useless things.\n",
		"ledgers" : "These boxes probably record transactions with Customs.\n",
	] ));
}

reset() {
	object ob;
	
	::reset();
	if(!present("areopagus", TO)) new(AMONDIR+"areopagus")->move(TO);
	if(!present("alemir", TO)) new(AMONDIR+"alemir")->move(TO);
	if(!present("customsguard", TO)) {
		ob=new(AMONDIR+"watchman");
		ob->set_id( ({ "customsguard", "guard", "customs guard" }) );
		ob->set_short( "Customs Guard" );
		ob->set_name( "Customs Guard" );
		ob->set_long(
@GUARD
	You are looking at a militia soldier detailed to guard the 
Customs Office in Azha.  It appears to be boring duty, but his training
insures that he is alert and watching everyone who comes in and out,
particularly you.
GUARD
		);		
		ob->move(TO);
	}
	AOVER->setup_monsters(TO, "public");
/*
	AOVER->add_monster(TO, AMONDIR+"sweeper", 1);
*/
}

	
