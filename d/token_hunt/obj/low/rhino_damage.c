#include <std.h>
inherit OBJECT;

int hits;
object target;


void create() 
{
    ::create();
    set_name("rhino arrowhead");
    set("id", ({ "remote_rhino_damage"}) );
    set_short("");
    set_long("");
    set_property("no animate", 1);
    set_weight(0);
    hits=random(10)+10;
    set_property("no disenchant",1);
}


int drop() { return 1; }


void set_target(object obj) 
{ 
    if(objectp(obj)) { target = obj; }
    call_out("pain",to_float("0."+(roll_dice(1,4)+5)));
}


void pain() 
{
    if(!objectp(ETO) || ETO != target || target->query_ghost() || hits < 1)
    {
        TO->move("/d/shadowgate/void");
        TO->remove();
        return;
    }
    tell_object(ETO,"%^RESET%^%^BOLD%^%^RED%^The black arrowhead throbs underneath your skin!%^RESET%^");
    ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 3), "piercing");
    hits--;
    call_out("pain",to_float("0."+(roll_dice(1,4)+5)));
}