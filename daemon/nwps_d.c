#include "nwps_d.h"

int calc_exp_for_next(string name, object player){
    int exp, nwpexp;
    int level;
    int seed;

    nwpexp = player->query_nwp_exp(name);
    exp = player->query_total_nwp_exp();
    level = player->query_nwp(name);
    seed = player->query_nwp_seed(name);
    if (level < 5) {
        return nwpexp + (seed*(level?level:1)) - (int)player->query_nwp_bonus(name);
    } else if (level < 10) {
        return nwpexp + (seed*(level?level:1)) + (exp/100) - (int)player->query_nwp_bonus(name);
    } else {
        return nwpexp + (seed*(level?level:1)) + (exp/50)- (int)player->query_nwp_bonus(name);
    }
}

int valid_nwp(string str){
    return 1;
}

int has_stats(object player, string name){
    string * stats;
    int mod, level, i, stat;

    if(!NWPS_MAP[name]) return 1;
    stats = NWPS_MAP[name]["stats"];
    level = (int)player->query_nwp(name) +1;

    switch(level) {
      case 0..5: mod = 8; break;
      case 6..10: mod = 10; break;
      case 11..15: mod = 12; break;
      default: mod = 14; break;
    }
      
    for (i=0;i<sizeof(stats);i++) {
      stat = (int)player->query_stats(stats[i]);
      if (stat < mod) return 0;
    }
    return 1;
}

int advance_nwp(string name, object player){
    int exp, totexp, freeexp;

    exp = calc_exp_for_next(name,player);
    //
    //freeexp = player->query_free_exp();
    if(exp>0) return -1;
    return exp;
}

int add_nwp(object player, string name, int bonus){
    string * stats;
    int *mins;
    int base,i,j;
    int penalty, stat;
    string *myclass;

    if(!NWPS_MAP[name]) return 1;
    stats = NWPS_MAP[name]["stats"];
    mins = NWPS_MAP[name]["mins"];
    myclass = NWPS_MAP[name]["classes"];
    base = NWPS_MAP[name]["base"];

    //Check prerequisite profs here
    
    for (i=0;i<sizeof(stats);i++) {
        stat = (int)player->query_stats(stats[i]);
//         if (stat < mins[i]) return 0;
        if (!has_stats(player,name)) return 0;
// adding to fix drow and others getting above 18  *Styx*  3/23/03
        if(stat < 18)
           penalty += 18 - stat;
    }
    base += (penalty*100);
    base -= bonus;

    for (i=0;i<sizeof(myclass);i++) {
        if (player->is_clasys(myclass[i])) {
            j=1;
        }
    }
    if (j) {
        base = base/2;
    }
    player->add_nwp(name,base);
    return 1;

}

int perform_nwp(object player, string name) {
    int exp;
    int percent,multiple, prof, temp,min,num;

    multiple = NWPS_MAP[name]["exp percent"];
    multiple = multiple?multiple:2;
    exp = player->query_nwp_exp(name)+player->query_nwp_bonus(name);
    prof = player->query_nwp(name);
    temp = exp/5000;
     percent = /*(multiple*exp)/5000*/ temp*multiple + ( (random(100)+1)* (prof+1));

     if(player->has_nwp(name) && num = calc_exp_for_next(name,player))
     {
        min = num / 100; // 1 percent (dimishes as exp to next gets lower)    
        if(min > percent) { percent = min; }
     }

//    percent = (multiple*exp)/10000 + 2+random(40);
//  adjusting % to slow down lower level adv/make higher levels more reasonable
//   if (percent < 0) percent *= -1; 
  // This didn't work.
   // overflow percent hack? Lets see...
    player->set_nwp_bonus(name,percent);
    if( 0 /* 1 to debug */ && objectp(find_player("garrett")))
	if(player->has_nwp(name)) 
 	  tell_object(find_player("garrett"), "%^CYAN%^"+player->query_cap_name()+
	  " has "+exp+" exp, bonus of "+player->query_nwp_bonus(name)+
	  ", and gets "+percent+" more on a level "+prof+" in "+name+".");
    //.1% the total exp of the player added as a bonus to the 
}

void advance_player(object player, string myclass, int level){
    int i,j, k;
    string *keyy;
    keyy = keys(NWPS_MAP);
    j=sizeof(keyy);
    for (i=0;i<j;i++) {
        if (NWPS_MAP[keyy[i]]["free classes"]) {
            if (member_array(myclass, NWPS_MAP[keyy[i]]["free classes"]) != -1) {
                if (player->has_nwp(keyy[i])){
                    player->set_nwp(keyy[i],(int)player->query_nwp(keyy[i])+1);
                } else {
                    add_nwp(player,keyy[i],0);
                    player->set_nwp(keyy[i],level);
                }
            }
        }
    }
}
void reduce_player(object player, string myclass, int level){
    int i,j, k;
    string *keyy;
    if(player->query_property("converting")) { return; }
    keyy = keys(NWPS_MAP);
    j=sizeof(keyy);
    for (i=0;i<j;i++) {
        if (NWPS_MAP[keyy[i]]["free classes"]) {
            if (member_array(myclass, NWPS_MAP[keyy[i]]["free classes"]) != -1) {
                if (player->has_nwp(keyy[i])){
                    player->set_nwp(keyy[i],(int)player->query_nwp(keyy[i])-1);
                } else {
                    add_nwp(player,keyy[i],0);
                    player->set_nwp(keyy[i],level);
                }
            }
        }
    }
}

