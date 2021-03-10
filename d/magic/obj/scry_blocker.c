// Scry Blocker
// For use with /daemon/ic_scry_locate_d
// Follows around the player or target that it is protecting
// and blocks any scry attempts into that area.
// Thorn@ShadowGate
// 4 January 2001
// scry_blocker.c

#include <std.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
#define ETC    environment(control)

inherit OBJECT;

object observer, target, control;
int no_move, block_scry, ready, psi_damager, bard_damager, ranger_block;

void self_destruct();
void block_scrying();
void set_psi_damager(int x);
int query_psi_damager();
void set_bard_damager(int x);
int query_bard_damager();

void create(){
    ::create();
    
    set_name("scry blocker");
    set_property("no detect",1);
    set_id(({"blockerx111"}));
    set_short(0);
    set_hidden(1);
    //add_limb("body","",0,0,0);
    block_scry = 0;
    ready = 0;
    set_heart_beat(1);
}

int move(mixed dest){
    ::move(dest);
    if(!ready) ready = 1;
}

void set_target(object ob){
   target = ob;
   target->set_property("block scrying", TO);
   TO->move(target);
}

void set_block_power(int x){
   block_scry = x;
}

int query_block_power(int x) {
	return block_scry;
}

void die(object ob){
}

void heart_beat()
{
    object to_block;
    if(!objectp(TO)) return;

    //if(!ready) return;
    if(!objectp(target)) {
        self_destruct();
        return;
    }
	block_scrying();
    //if(!no_move && objectp(environment(target))) 
        //if(ETO != environment(target))
            //move(environment(target));
    if(ETO != target) move(target);

    if(!objectp(ETO)) 
    {
        self_destruct();
        return;
    }

    if(living(ETO))
    {
        if(!objectp(EETO)) 
        {
            self_destruct();
            return;
        }
        else
        {
            to_block = EETO;
        }
    }
    else
    {
        to_block = ETO;
    }

    if(isCivilization(to_block->query_terrain()) && ranger_block) {
        self_destruct();
        return;
    }
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

// If this object is observing a room instead of a person.
void no_move() { no_move = 1; }

// This call initiates the self-destruct sequence for this scry 
// attempt.  It will use the scry and locate daemon call to 
// properly clean up any objects or properties that are left
// over and exit gracefully.
void self_destruct() {
	if(objectp(target)) target->remove_property("block scrying");
    if(objectp(TO)) TO->remove();
    return;
}

void block_scrying() 
{
    object *inv;
    object control, scry_object, observer,to_block;
    int i, dmg;
	
    if(!objectp(ETO)) return;
    
    if(living(ETO)) 
    { 
        if(!objectp(EETO)) return;
        else to_block = EETO;
    }
    else to_block=ETO;

    inv = all_inventory(to_block);
    for(i=0;i<sizeof(inv);i++) 
    {
        if(!objectp(inv[i])) continue;
        if(inv[i]->is_priest_scry())
        {
            if(inv[i]->query_scry_power() > TO->query_block_power()) return;
            else
            {
                inv[i]->self_destruct();
                return;
            }
        }
        if(inv[i]->is_scry_object()) 
        {
            //There is no scry power on scry objects.  Having it check control's
            //scry power instead to make the blockers work correctly.  ~Circe~ 6/20/08
            control = inv[i]->query_control();
            if(!objectp(control)) continue;
            if(objectp(control) && control->query_scry_power() > TO->query_block_power()) return;
            else
            {
                //break;
                control = inv[i]->query_control();
                if(!objectp(control)) { return; }
                if(objectp(environment(control)))
                {
                    tell_object(environment(control), 
                    "%^BOLD%^RED%^Suddenly, some sort of interference garbles "
                    "the scrying!");
                }
                if(TO->query_psi_damager())
                {
                    observer = control->query_observer();
                    if(!objectp(observer)) continue;
                    if(living(ETO))
                    {
                        tell_object(ETO,"%^BOLD%^%^MAGENTA%^Your "+
                        "reserve of psychic energy lashes out at "+
                        "the one who dares to scry you!");
                    }
                    tell_object(observer,"%^BOLD%^%^MAGENTA%^A "+
                    "sudden surge of energy snaps your mind!");
                    if(objectp(environment(observer)))
                    {
                        tell_room(environment(observer),"%^BOLD%^"+
                        "%^MAGENTA%^"+observer->QCN+" suddenly "+
                        "cries out in pain and grabs "+observer->QP+" "+
                        "head!",observer);
                    }
                    dmg = TO->query_psi_damager();
                    if(dmg < 8) dmg = 8;
                    if(!SAVING_D->saving_throw(observer, "will", 0)) 
                    {
                        observer->do_damage("head",roll_dice(dmg,6));
                        //d8 seemed way too much for this power, so I adjusted to d6
                    }
                    else
                    {
                        if(living(ETO))
                        {
                            tell_object(ETO,"%^BOLD%^%^CYAN%^"+observer->QCN+" "+
                            "resists some of your power!");
                        }
                        observer->do_damage("head",roll_dice((dmg/2),6));
                     }
                }
                if(TO->query_bard_damager())
                {
                    observer = control->query_observer();
                    if(!objectp(observer)) continue;
                    tell_object(observer,"%^BOLD%^%^MAGENTA%^Suddenly, "+
                    "horrific images of your worst fears appear before "+
                    "your eyes, and you can't help but to stagger "+
                    "away in fright, losing your concentration!");
                    if(objectp(environment(observer)))
                    {
                        tell_room(environment(observer),"%^BOLD%^"+
                        "%^MAGENTA%^"+observer->QCN+" suddenly staggers "+
                        "back, a look of raw fear on "+observer->QP+" face "+
                        "as "+observer->QS+" loses control of the scrying spell!",observer);
                    }
                    dmg = TO->query_bard_damager();
                    if(dmg < 8) dmg = 8;
                    if(!SAVING_D->saving_throw(observer, "will", 0)) observer->do_damage("head",roll_dice(dmg,6));
                    else observer->do_damage("head",roll_dice((dmg/2),6));
                }
                SCRY_D->stop_scry(control, 1);
            }
	    }
	}
	return;
}

void set_psi_damager(int x){
   psi_damager = x;
}

int query_psi_damager(){
   return psi_damager;
}

void set_ranger_block(int x){ ranger_block = x; }
int query_ranger_block(){ return ranger_block; }

void set_bard_damager(int x){
   bard_damager = x;
}

int query_bard_damager(){
   return bard_damager;
}
