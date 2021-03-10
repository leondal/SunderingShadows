// Azha Merchant's Bank
// Thorn@ShadowGate
// 2/9/97
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit BANK;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_short("Azha Merchant's Bank");
  set_long(
@AZHA
%^BOLD%^GREEN%^Azha Merchant's Bank%^RESET%^

  The Merchant's Bank of Azha was founded to make it possible for all
of the traders and merchants coming into Azha to safely store their
money.  Travellers will find that they can deposit or withdraw
their money in any one of the locations in league with this bank.

  You see dozens of merchants and townfolk waiting in lines for the
tellers to help them.  As you might expect, the Town Watch keeps a
presence here, carefully overseeing events.

  If you <read sign> you will get a list of the services that this
bank can offer you.
AZHA
	);
  set_items(
        (["bank" : "You are in its huge lobby. There is a counter in "
            "front of you\nand and exit behind you.",
          "customers" : "They are wandering about aimlessly.",
          "sign" : "Reading it will give you a list of commands.",
          "teller" : "The teller looks at you impatiently.",
          "counter" : "A teller waits behind it for you to do something.",
          "exit" : "It leads out into the street."])
          );

	set_exits(([
	"west" : "/d/azha/town/west1"  
  ] ));     
  set_smell("default","The smell of money fills your nostrils.");
  set_listen("default","The sounds of rustling coins fill your ears.");
}

reset() 
{
	object ob;
	
	::reset();
	AOVER->setup_monsters(TO, "public");
	if(!present("bankguard", TO)) {
		ob=new(AMONDIR+"watchman");
		ob->set_id( ({ "bankguard", "guard", "bank guard" }) );
		ob->set_short( "Bank Guard" );
		ob->set_name( "Bank Guard" );
		ob->set_long(
@GUARD
	You are looking at a militia soldier detailed to guard the 
Merchants's Bank of Azha.  He carefully eyes all transactions
occurring in the building, and is ready to stop any would-be
thieves.
GUARD
		);		
		ob->move(TO);
	}
}

