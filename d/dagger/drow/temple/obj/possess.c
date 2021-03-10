#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("huki_possess_ob");
    set_short("");
    set_id(({"huki_possess_ob"}));
    set_property("no animate",1);
    set_long("");
    set_weight(1);
}

void init() {          
    int x;	
    ::init();
	if ( living ( environment ( TO ) ) )
 	  call_out ( "possess", 1, environment ( TO ) );
	else
	  TO -> remove();
   add_action ( "no_can_do", "drop" );
   add_action ( "no_can_do", "give" );
   add_action ( "no_can_do", "hide" );
}
                                      
int no_can_do() {
  object me = environment ( TO );
  if ( !me ) return 1;
  message ( "my_action",
      "%^RESET%^%^BOLD%^You are currently possessed and "
      "are uncapable of doing anything like that!%^RESET%^"
  ,me );
  message ( "other_action",
      "%^RESET%^%^BOLD%^"+me->query_cap_name()+""
      " attempts to do something but stumbles to the ground in "
      "great pain!"
  ,environment ( me ), me );
  return 1;
}

void possess ( object me ) {
    int x;                          
    int xx;   
    int amt = ( 3 )+random( 3 );

    if ( !me ) return;

    message("my_action",
 	"%^MAGENTA%^You suddenly feel an evil seep into your body.%^RESET%^"
    ,me);
    message("other_action",
	"%^MAGENTA%^"+me->query_cap_name()+" cackles in a low, evil "
	"and possessed manner.%^RESET%^"
    ,environment(me),me);
    for (x=1; x<=amt; x++) {
    xx = x*15+random(9);
    call_out ( "possess_fun", ( xx ), me);
    }
call_out ( "removal", ( 220 ), me );
return 1;
}                                      

void possess_fun(object ob) {    
    object *exit,*here,me,*players,sucker;
    int w,num_p,z,y;
    me = environment( TO );
    if ( !ob ) return;
    message("my_action",
	"%^RED%^You feel the will of Lloth control your body!"
	"%^RESET%^"
    ,ob);
    ob->do_damage("head",roll_dice(1,4));
    for(y=1;y<4;y++) {
        write("%^CYAN%^Lloth forces you to move!%^RESET%^");
        exit = environment(TP)->query_exits();
        z = random(sizeof(exit));
        me -> force_me(exit[z]);
    }
    here=environment(me);
    players=all_inventory(here);
    num_p=sizeof(players);
    for(w=0;w<num_p;w++) {
        sucker=players[w];
        if((living(sucker)) && sucker !=(me) && sucker->query_level() < 400) {
            if(!sucker->kill_ob(me,0)) {
                me->kill_ob(sucker,0);
                write("%^BLUE%^Lloth forces you to attack "
                      +sucker->query_cap_name()+"!%^RESET%^"
                );
            }
        }         
    }
    return 1;
}
void removal(object ob) {

    if ( !ob ) return 1;                          

    message ( "my_action", 
	"%^BOLD%^%^RED%^You slowly regain possession "
	"of your body.%^RESET%^"
    ,ob );
    message ( "my_action",
	"%^BOLD%^%^RED%^A shadow is emerges from "+ob->query_cap_name()+" "
	"body and dissolves into the ground.%^RESET%^"
    ,environment ( ob ), ob );
    TO -> remove();
return;
}
