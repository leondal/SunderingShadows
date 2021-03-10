#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("huki_vomit_ob");
    set_short("");
    set_id(({"huki_vomit_ob"}));
    set_long("");
    set_weight(1);
}

void init() {          
    int x;	
    ::init();
	if ( living ( environment ( TO ) ) )
 	  call_out ( "puke", 1, environment ( TO ) );
	else
	  TO -> remove();
   add_action ( "no_can_do", "drop" );
   add_action ( "no_can_do", "give" );
   add_action ( "no_can_do", "hide" );
}
                                      
int no_can_do() {
  object me = environment ( TO );
  if ( !me ) return 1;
  message ( "my_action", "%^RESET%^%^BOLD%^You are in great pain and "
	    "are uncapable of doing anything like that!%^RESET%^", me );
  message ( "other_action", "%^RESET%^%^BOLD%^"+me->query_cap_name()+""
	    " attempts to do something but stumbles to the ground in "
	    "great pain!", environment ( me ), me );
  return 1;
}

void puke ( object me ) {
    int x;                          
    int xx;   
    int amt = 6 + random ( 6  hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
 	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"tower":"%^BOLD%^%^BLACK%^The large black obsidian tower is made "
	"of a perfectly smooth polished stone. Other than the "
	"%^RED%^banners%^BLACK%^ there are no discernable markings "
	"or openings on the tower.%^RESET%^",
	"banners":"%^RED%^The banners bear the "
	"%^WHITE%^%^BOLD%^spider symbol%^RESET%^%^RED%^ of Lloth.",
	"cloud":"The cloud hangs dark and heavy and casts it's doom upon "
	"the surrounding area.",
	"street":"The street is made up of cobblestones and winds "
	"through the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city40.c"
    ]));
}
void init() {
    ::inittats("wisdom",10);
    set_stats("intelligence",10);
    set_stats("charisma",3);
    set("aggressive",25);
set_property("swarm",1);
    set_emotes(3, ({
        "%^BLUE%^The Giant Gar swims voilently towards you.%^RESET%^",
	"%^BLUE%^The Giant Gar brushes it's scaly skin against you as it swims by.%^RESET%^" 
	}),0);
}
