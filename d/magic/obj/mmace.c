// magic mace for spells

#include <std.h>

inherit WEAPON;

string owner;

void create(){
    ::create();
    set_id(({"mace","magic mace"}));
    set_type("bludgeoning");
    set_prof_type("magic weapons");
    set_weight(0);
    set_value(0);
    set_wield((:TO, "extra_wield":));
}

int query_size(){
   if(living(ETO))
      return ETO->query_size();
   else return 3;
}

void init(){
   ::init();
   if(stringp(owner)) return;
   if(interactive(TP) && TP == ETO){
       owner = TPQN;
   }
}

int extra_wield(){
    if(interactive(TP) && owner != (string)TPQN){ 
        tell_object(TP,"You are not allowed to wield this mace.");
        return 0;
    }
    else 
        return 1;
}

int drop(){
    tell_object(TP,"Your hand will not release the divine mace!");
    return 1;
}

int save_me(string file){ return 1;}
