#include <std.h>
#include <daemons.h>

#define PROF_DIVISOR             5.0
#define ADDITION_CONSTANT        0.0
#define PROFICIENCY_WEIGHT      40.0
#define CONDITION_WEIGHT        40.0
#define LOG_BASE               100.0
#define PI                   3.14159
#define CONDITION_RANGE        100.0
#define CONDITION      currentStatus

int ac, decayRate, decayStatus, currentStatus=100;

int repair_delta(int condition);
int repairMe(int percent);
void create(){
    decayRate = 100;
}

int repairMe(int percent){
    return currentStatus;
}

void set_ac(int x) { ac = x; }

int query_ac() 
{ 
    int tmpval, scaled;
    if(objectp(ETO))
    {
        if(userp(ETO) && intp(scaled = TO->query("scaledlevel")) && scaled > 0)
        {        
            tmpval = ac;
            tmpval = to_int(to_float(scaled)/to_float(ETO->query_base_character_level()) * tmpval);
            return tmpval;
        }
    }
    return ac; 
}

/******
int repair(int prof, object player){
    int bottom;  
    int top; 
    int percent,stat;
    
    

    bottom= -1*currentStatus;
    top = 100-currentStatus; 
    bottom = bottom<-100?-100:bottom;

    prof = prof *5;


    percent = random(100)+bottom+prof;
    if (percent > top+20) {
        percent = top+20;

    }

    stat = repairMe(percent);

//    currentStatus = stat;
    if (stat < currentStatus) {
        tell_object(player,"You feel you have done more harm than good in your efforts to repair this item.");
        return -1;
    } else {
        tell_object(player,"You go to work on the item and it appears better off for your efforts.");
        return 1;
    }

}
*******************************************************************/

int repair_formula(int proficiency) {

  float fnord;

  // We need .5 * PI / CONDITION_RANGE to make the condition range be
  // half of the period of the cosine function. (otherwise it slopes back
  // up to 1.)
  // Here ends your lesson in trig functions.

  // Garrett.

  fnord = CONDITION_WEIGHT*cos(0.5*PI*CONDITION/CONDITION_RANGE);

  // I'm not sure if I needed the 2/PI part, I might have forgotten that
  // in looking at my Excel spreadsheet.

  fnord += PROFICIENCY_WEIGHT*atan(proficiency/PROF_DIVISOR);
  fnord += proficiency*1.0;

  fnord += ADDITION_CONSTANT;

  if (to_int(floor(fnord)) == 0) {
     return 1;
  } else {
     return to_int(floor(fnord));
  }
}

int repair_delta(int condition){
  if (condition > 100)
    return 1;
  // Just in case...

  switch(condition){
  case 90..100 :
    return 1;
    break;
  case 80..89:
    return 2;
    break;
  case 70..79:
    return 5;
    break;
  case 50..69:
    return 10;
    break;
  default:
    return 20;
    break;
  }
 return 20;
}

    
int repair(int prof, object player) {
  int roll, chance, change, newstatus, integermath;
  float math;
  
  change = repair_delta(currentStatus);
  change += (prof/5);
  
  roll = random(100)+1;
  if (roll > 95) {
    newstatus = repairMe(-1*change);
//    tell_object(player,"Extreme roll of negative "+change+"");
    // Break.
  } else if (roll < 6) {
    newstatus = repairMe(change);
//    tell_object(player,"Extreme roll of "+change+"");
    // Fixed.
  } else { 
    chance = repair_formula(prof);
    math = (chance - roll)*1.0 / (chance*1.0);
    math = ceil(math * change);
    integermath = math;
    newstatus = repairMe(integermath);
//    tell_object(player,"Repaired "+integermath+"");
  }
  if(newstatus < 0) {
    // Do we need this?
    //    set_overallStatus(status);
    tell_object(player,"You feel you have done more harm than good in your efforts to repair this item.");
    return -1;
  } else {
    // Do we need this?
    //    set_overallStatus(status);
    tell_object(player,"You go to work on the item and it appears better off for your efforts.");
    return 1;
  }
} 

void set_decay_rate(int x) { decayRate = x; }

int query_decay_rate() { return decayRate; }

void decay() {
    object ob;
    int diff, rate, newval;    
    string str;
    rate = decayRate;
    if (rate == 0) 
    {
        return;
    }
    if(living(TO)) return;
    if(TO->query_property("enchantment")) 
    {
        rate = (absolute_value((int)TO->query_property("enchantment"))+1) * rate;
    }
    decayStatus++;
    if(!(decayStatus%rate)) 
    {
        if(TO->is_weapon() || TO->is_armour()) diff = TO->decayMe();
        else 
        {
            if(!stringp(TO->query_short()) || TO->query_short() == "" || !strlen(TO->query_short())) return;
            diff = random(5)+1;
            newval = query_overallStatus() - diff;
            if (newval >= 100) newval = 100;
            if (newval <= 0) newval = 0;
            set_overallStatus(newval);
            diff = diff * -1;
        }
        diff = 100 - currentStatus; // We want how much off perfect for the message....
        if(objectp(ETO))
        {
            ob = ETO;
            str = TO->query_eng_short();
            if((diff > 0) && (diff < 30))
               message("environment","Your "+str+" is showing noticeable wear.",ob);
            if((diff > 29) && (diff < 50))
                message("environment","Your "+str+" has taken quite a beating.",ob);
            if((diff > 49) && (diff < 70))
                message("environment","Your "+str+" is now quite damaged.",ob);
            if((diff > 69) && (diff < 90))
                 message("environment","Your "+str+" is falling apart!",ob);
            if(diff > 89)
            message("environment","Your "+str+" is now practically useless.",ob);
        }
        return;
    }
    return;
}

void set_overallStatus(int i){
    currentStatus=i;
}
int query_overallStatus(){
    return currentStatus;
}

string query_broken()
{
    if(living(TO)) return "";
    if(!objectp(TO)) return "";
    if(TO->is_diseas() || TO->is_poison()) return "";
    switch (currentStatus) {
    case 0..20:
        return " utterly worthless";
    case 21..40:
        return " nearly unserviceable";
    case 41..60:
        return " seriously damaged";
    case 61..80:
        return " damaged";
    case 81..95:
        return " well used";
    default: 
        return "";
    }
}

int query_measure(){
    return 0;
}
