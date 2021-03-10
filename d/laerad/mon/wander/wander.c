// wander code for laerad
// changed by *Styx* 12/14/03 to use set_nogo functionality & let them get into the wasteland too

#include <std.h>
#define WADIR "/d/laerad/wasteland/"
#define SW "/d/laerad/swamp/swamp"

inherit WEAPONLESS;

// int count;

void create(){
   ::create();
   set_nogo( ({ SW+"01", SW+"03", SW+"05", SW+"07", SW+"11", SW+"12", WADIR+"waste1" }) );
   set_moving(1);
   set_speed(25);

//	call_out("start_wonder",1);
}

/*
void start_wonder(){
    if(objectp(ETO))
        environment(TO)->init();
}

int test_heart(){ return 1;}
void heart_beat(){
        string *exits, exitn;
        int i,j;
        ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;

        if(count > 20){
                if((mixed *)TO->query_attackers() == ({})){
                       if(objectp(environment(TO)))
                        exits = environment(TO)->query_exits();

                        i = sizeof(exits);
                        if(exits && i){
                                j = random(i);
                                exitn = (string)environment(TO)->query_exit(exits[j]);
				if(exitn != WADIR+"waste66" && exitn != WADIR+"waste67" && exitn != WADIR+"waste78" && exitn != WADIR+"waste79" && exitn != WADIR+"waste80" && exitn != WADIR+"waste89" && exitn != WADIR+"waste90" && exitn != WADIR+"waste91" && exitn != WADIR+"waste97" && exitn != WADIR+"waste98" && exitn != WADIR+"waste99" && exitn != WADIR+"waste100" && exitn != WADIR+"waste101" )
                                        TO->force_me(exits[j]);
                        }
                }
                count = 0;
        }
        count++;
}
*/