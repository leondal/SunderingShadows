#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("huki_vomit_ob");
    set_short("");
    set_id(({"huki_vomit_ob"}));
    set_long("");
    set_weight(1);
   set_property("no animate",1);
   set_property("monsterweapon",1);
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
    int amt = 6 + random ( 6 );

    if ( !me ) return;

    message("my_action",
 	"%^BOLD%^%^YELLOW%^You suddenly feel very ill.%^RESET%^"
    ,me);
    message("other_action",
	"%^BOLD%^%^GREEN%^"+me->query_cap_name()+" looks sick.%^RESET%^"
    ,environment(me),me);
    for (x=1; x<=amt; x++) {
    xx = x*8+random(8);
    call_out ( "sick", ( xx ), me);
    }
call_out ( "removal", ( 120 ), me );
return 1;
}                                      

void sick(object ob) {    

    if ( !ob ) return;

    message("my_action",
	"%^BOLD%^%^RED%^You scream in terror and agony while convulsing and "
	"vomiting violently. Your chest heaves in pain and your eyes "
	"feel as if they are bleeding!%^RESET%^"
    ,ob);
    message("other_action",
	"%^BOLD%^%^RED%^"+TPQCN+" screams in terror and agony while "
	"convulsing and vomiting violently!%^RESET%^"
	,environment(ob),ob);
    ob->do_damage("torso",roll_dice(3,4));
    ob->set_paralyzed(1,"%^BOLD%^%^YELLOW%^You vomit and cannot move!%^RESET%^");
return;
}         

void removal(object ob) {

    if ( !ob ) return 1;                          

    message ( "my_action", "%^BOLD%^%^CYAN%^Your stomach begins to calm."
	      "%^RESET%^", ob );
    message ( "my_action", "%^BOLD%^%^CYAN%^"+ob->query_cap_name()+" "
	      "looks much better as colour begins to return to "
	      ""+ob->query_possessive()+" face.%^RESET%^", 
	      environment ( ob ), ob );
    TO -> remove();
return;
}
