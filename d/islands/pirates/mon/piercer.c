#include <std.h>
#include "../piratedefs.h"

inherit WEAPONLESS;

int x;
int timer;
int droped;
int counter;
int y;
void piercem(object targ);

void create(){
    ::create();
    set_name("piercer");
    set_id(({"piercer"}));
    set_short("piercer");
    set_long("This incredible creature looks like all the other stalactites "+
       "except for two tiny eye slits which open and stare intently at you.");
    set_gender("male");
    set_race("piercer");
    set_body_type("piercer");
    x=(random(4)+1);
    y=5;
    set_hd(x,1);
    set_mlevel("fighter",10);
    set_exp(x*100);
    add_limb("torso","torso",0,0,0);
    set_wielding_limbs(({"torso"}));
    set("aggressive","agg_func");
    set_funcs(({"acidspit"}));
    set_func_chance(100);
    set_invis();
    set_property("swarm",1);
}

int agg_func(){
    if(wizardp(TP)) return 1;
    if(TP->query_invis())  return 1;
    timer=(roll_dice(1,8));
    call_out("piercem",timer,TP);
}

void piercem(object targ){
if (!present(targ)) return 0;
else{
tell_object(targ,"%^BOLD%^Stalactites start falling on you from the ceiling!!");
tell_room(environment(targ),"%^BOLD%^Stalactites start falling on "+targ->query_cap_name()+"!!",targ);
    if((TO)->query_invis())  set_invis();
    targ->do_damage("torso",(roll_dice(x,4)));
    command("kill "+targ->query_cap_name());
    droped=1;
}
}

void acidspit(object targ){

counter++;
if(droped==0 || counter==y)  piercem(targ);
    if((roll_dice(1,20))>(targ->query_stats("dexterity"))){
   tell_object(targ,"%^BOLD%^%^GREEN%^The piercer sprays acid on you while it tries to climb back up to the ceiling.%^RESET%^");
    tell_room(environment(targ),"The piercer sprays acid on "+targ->query_cap_name()+" while trying to escape.",targ);
	targ->do_damage("torso",x);

    }else{
    tell_object(targ,"The piercer's acid spit misses you.");
   tell_room(environment(targ),"The piercer's acid spit misses "+targ->query_cap_name()+".",targ);
    }
}

void die(object thing){
    if(!random(4)) {
        new("/d/antioch/valley/obj/gem")->move(ETO);
        tell_room(ETO, "%^BOLD%^A gem falls from its body as the piercer breaks apart.");
    }
    return ::die(thing);
}