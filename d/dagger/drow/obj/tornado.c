#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("huki_tornado_ob");
    set_short("");
    set_id(({"huki_tornado_ob"}));
    set_long("");
    set_weight(1);
}

void init() {          
    int x;	
    ::init();
	if ( living ( environment ( TO ) ) )
 	  call_out ( "storm", 1, environment ( TO ) );
	else
	  TO -> remove();
   add_action ( "no_can_do", "drop" );
   add_action ( "no_can_do", "give" );
   add_action ( "no_can_do", "hide" );
}
                                      
int no_can_do() {
  object me = environment ( TO );
  if ( !me ) return 1;
  message ( "my_action", "%^RESET%^%^BOLD%^The tornado prevents you from "
	    "being able to do that!%^RESET%^", me );
  message ( "other_action", "%^RESET%^%^BOLD%^"+me->query_cap_name()+""
	    " attempts to do something but the tornado prevents them!", environment ( me ), me );
  return 1;
}

void storm ( object me ) {
    int x;                          
    int xx;   
    int amt = 2 + random ( 4 );

    if ( !me ) return;

    message("my_action",
 	"%^BOLD%^%^BLUE%^A tornado swirls about you!%^RESET%^"
    ,me);
    message("other_action",
	"%^BOLD%^%^BLUE%^A tornado swirls about "+me->query_cap_name()+"!%^RESET%^"
    ,environment(me),me);
    for (x=1; x<=amt; x++) {
    xx = x*8+random(8);
    call_out ( "swirl", ( xx ), me);
    }
call_out ( "removal", ( 70 ), me );
return 1;
}                                      

void swirl(object ob) {    

    if ( !ob ) return;

    message("my_action",
	"%^BLUE%^The great tornado buffets you to the ground causing you "
	"great pain!%^RESET%^"
    ,ob);
    message("other_action",
	"%^BLUE%^"+TPQCN+" is thrown to the ground by the tornado surrounding "
	"their body!%^RESET%^"
	,environment(ob),ob);
    ob->do_damage("torso",roll_dice(3,4));
    ob->set_paralyzed(1,"%^BOLD%^%^BLUE%^The tornado holds you down!%^RESET%^");
return;
}         

void removal(object ob) {

    if ( !ob ) return 1;                          

    message ( "my_action", "%^BOLD%^%^BLUE%^The tornado dissipates."
	      "%^RESET%^", ob );
    message ( "my_action", "%^BOLD%^%^BLUE%^The tornado surrounding "
		+ob->query_cap_name()+" dissipates.%^RESET%^"
	       ,environment ( ob ), ob );
    TO -> remove();
return;
}
