#include <std.h>
#define EO environment(owner)

inherit OBJECT;

int max_hold_time, held_time, rest_time, faint_time, exposed_time;
object owner;

void set_max_hold_time(int x);
int query_max_hold_time();
void reset_held_time();
void reset_exposed_time();
void check_attacks();
object query_owner();
int query_faint_time();  //time taken for vacuum exposure to cause loss of consciousness
void set_faint_time(int faint); 
int query_exposed_time(); // time exposed to a vacuum, even if you can breath 

void create(){
    ::create();
    set_id( ({"suffocation_ob", "suff_ob"}) );
    set_name("drowning");
    set_short("");
    set_long("");
    set_weight(0);
    set_property("no animate", 1);
    set_property("noMissChance", 1);
}

void start_suffocation(){
    int x;
    owner = ETO;
    if(!objectp(owner) || !living(owner)) TO->remove();
    //set_heart_beat(1);
    x = (int)ETO->query_stats("constitution");
    x *= 6;
    x /= 3;
    rest_time = 0;
    set_max_hold_time(x);
    faint_time = (int)ETO->query_stats("constitution");
    reset_exposed_time();    
    reset_held_time();
        //moved the set_heart_beat(1) down here - so that 
        //all the above variables get set first - not 
        //certain that it would cause anything to go wrong
        //but seems like it has the potential to - Saide, July 1, 2008
        set_heart_beat(1);
    return;
}

void set_max_hold_time(int x){
    max_hold_time = x;
}

int query_max_hold_time(){
    return max_hold_time;
}

void reset_held_time(){
    held_time = 0;
}

void reset_exposed_time(){
    exposed_time = 0;
}

int query_exposed_time(){
  return exposed_time;
}

int query_held_time(){
    return held_time;
}

void heart_beat(){
    int dam, tmp_cond;
    string suff_msg, recover_msg;
    if(!objectp(TO)) return;
    if(!objectp(owner) || ETO != owner){
        remove();
        return;
    }
    if (environment(owner)->query_property("vacuum")){
      suff_msg = "You've run out of breath!";
      recover_msg = "You've caught your breath, and are ready to hold it"
        +" again!";
    }
    if (environment(owner)->query_property("underwater") ){     
      suff_msg = "You're drowning!";
      recover_msg = "You've caught your breath, and feel like another swim!";
    }
    if((environment(owner)->query_property("underwater") && 
    !environment(owner)->query_property("air pocket") && 
    !environment(owner)->query_property("surface") && 
    !present("underwtr_breath_ob", owner) && 
    !owner->query_property("water breather"))||
    (environment(owner)->query_property("vacuum")&&
    !present("vacuum_breath_ob", owner)&&
    member_array("water", owner->query_divine_domain()) < 0 &&
    !owner->query_property("vacuum breather")))
    {
        held_time++;
        rest_time = 0;
        if(held_time > max_hold_time)
        {
            //Some damage headed your way
            dam = held_time - max_hold_time;
            if(!(dam%6))
            {
                owner->do_damage("torso", roll_dice(dam, 6));
                tell_object(owner, suff_msg);
                owner->add_attacker(TO);
                owner->continue_attack();
                if (objectp(owner)) owner->remove_attacker(TO);
                return;
            }
        }
    }
    else 
    {
        held_time -= ((int)owner->query_stats("constitution"))/3;
        rest_time += ((int)owner->query_stats("constitution"))/3;
        if ( (held_time < 0) && !present("underwtr_breath_ob", owner))
        {
            tell_object(owner, recover_msg);
            if (owner->query_property("has cast")){
              owner->remove_property("has cast");
            }
            TO->remove();
        }
        if((rest_time > 23) && (held_time > 0) )
        {
            tell_object(owner, "You are catching your breath.");
            rest_time -= 23;
        }
    }
    if(environment(owner)->query_property("vacuum")&&
    !present("vacuum_resist_ob", owner)&& 
    !owner->query_property("resist vacuum")&&!owner->query_true_invs()){
        exposed_time++;
        if(exposed_time > faint_time && owner->query_condition()>0)
        {
            tell_object(owner, "%^BOLD%^%^BLUE%^You %^RED%^pass out"
              +" %^BLUE%^from exposure to the %^BOLD%^%^BLACK%^vac"
              +"%^RESET%^%^BLUE%^uu%^BOLD%^%^BLACK%^m%^RESET%^");
            owner->set_condition(owner->query_used_stamina()+ owner->query_condition() + 30);
            return;
        } else {
          tmp_cond = owner->query_condition();
          owner->set_condition(owner->query_used_stamina()+ 10);
          if (tmp_cond>0 && owner->query_condition()<1){
            tell_object(owner, "%^BOLD%^%^BLUE%^You %^RED%^pass out"
              +" %^BLUE%^from exposure to the %^BOLD%^%^BLACK%^vac"
              +"%^RESET%^%^BLUE%^uu%^BOLD%^%^BLACK%^m%^RESET%^");
          }
          if (owner->query_condition()>10 && random(3)){
            tell_object(owner, "The lack of pressure in the"
              +" %^BOLD%^%^BLACK%^vac%^RESET%^%^BLUE%^uu%^BOLD%^%^BLACK%^"
              +"m%^RESET%^ makes you feel %^BOLD%^%^CYAN%^f%^RESET%^a"
              +"%^BOLD%^%^WHITE%^i%^CYAN%^nt");
          }
        }
    } else {
      reset_exposed_time();
    }
    return;
}

int save_me(string file){
    return 1;
}

int drop(){
    return 1;
}

object query_owner(){
    return owner;
}

void set_held_time(int x){
    held_time = x;
}

int query_faint_time(){
  return faint_time;
}

void set_faint_time(int faint){
  faint_time = faint;
}
