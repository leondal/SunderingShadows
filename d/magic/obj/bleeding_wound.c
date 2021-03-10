#include <std.h>
#include <magic.h>
inherit OBJECT;

int level;
object target;
string limb;


void create() 
{
    ::create();
    set_name("bleeding wound");
    set("id", ({ "wound_bleeding_object"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_property("magic",1);
    set_property("noMissChance",1);
    set_weight(0);
}


int drop() { return 1; }


void set_target(object obj) 
{ 
    if(objectp(obj)) { target = obj; }
    limb = obj->return_target_limb();
    TO->move(obj);
    call_out("bleed",ROUND_LENGTH);
}

void set_level(int lvl) { level = lvl; }


void bleed() 
{
    if(!objectp(ETO) || ETO != target || target->query_ghost() || !level)
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    
    if(target->fort_save(level))
    {
        tell_object(target, "%^GREEN%^The bleeding on your "+limb+" finally stops, you are no longer loosing your vital life essence.%^RESET%^");
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    
    tell_object(target, "%^BOLD%^%^RED%^The wound on your "+limb+" is bleeding, draining your vital life essence!%^RESET%^");
    target->do_damage(limb, roll_dice(1,level) + level / 2);    
    call_out("bleed",ROUND_LENGTH);
}