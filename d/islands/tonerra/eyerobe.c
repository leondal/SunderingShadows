#include <std.h>
#include <magic.h>
#define caster TO->query_worn()
inherit ARMOUR;
object oldenv, *conceal;
object *invisobs();
int i, num=0;
void dest_effect();
void env_change();
void see_room();
void see_changes();
int uses;
void create(){
    ::create();
    set_id(({"robe","robe of eyes"}));
    set_name("robe of eyes");
    set_short("%^BOLD%^%^GREEN%^Robe Of Eyes%^RESET%^");
    set_long(
       "This magnificent robe is made of silk. Once wearing it, it is said to
contain a magic that bestows magic sight upon it's wearer. To do so, one has
only to wear the robe and type <visions>."
    );
    set_type("clothing");
    set_ac(1);
    set_limbs(({"torso"}));
    set_weight(10);
    set_value(5000);
    set_remove((:TO,"remove_me":));
}
void init(){
    ::init();
    add_action("visions","visions");
}
int visions(string str){
    string who;
    object ob;
    int roll;
    if(!TO->query_worn()){
        write("You have to wear this first.");
        return 1;
    }
    if(uses > 4){
       write("The magic has been drained from this robe.");
        return 1;
    }
	oldenv=environment(caster);
	tell_room(environment(caster),""+
    caster->query_cap_name()+"'s eyes snap open and flash "+
    "bright green for an instant.",TP);
    conceal = invisobs();
	if( conceal == ({}) )
    	tell_object(caster,"Nothing currently "+
    		"around you is concealed from your sight.");
	else
    	see_room();
	set_heart_beat(1);
	return 1;
}
object *invisobs()
{
    object *stuff, *invis;
    invis = ({});
     stuff = all_inventory(environment(caster));
    for(i=0;i<sizeof(stuff);i++)
        if( stuff[i]->query_invis() &&
             (!wizardp(stuff[i]) ) )
           invis += ({ stuff[i] });
    return invis;
}
void see_room()
{
    if( (conceal = invisobs()) == ({}) )
    return;
    for(i=0;i<sizeof(conceal);i++)
    {
        tell_object(caster,"You sense that "+
         capitalize(conceal[i]->query_true_name())+" is near you.");
    }
}
void see_changes()
{
    object *invis;
    invis = invisobs();

    // First detect things that aren't near the caster anymore.
    for(i=0;i<sizeof(conceal);i++)
    {
        if( member_array(conceal[i],invis) < 0 )
        {
            if(conceal[i])
                tell_object(caster, "You no "+
                    "longer detect "+capitalize(conceal[i]->query_true_name())+
                    " in the vicinity.");
            else
                tell_object(caster, "Something "+
                    "invisible has left the vicinity.");
        }
    }
    // Then detect things that just arrived  near the caster.
    for(i=0;i<sizeof(invis);i++)
    {
        if( member_array(invis[i],conceal) < 0 )
            tell_object(caster, "You sense that "+
                capitalize(invis[i]->query_true_name())+" is close to you.");

    }
    conceal = invis;
}
void heart_beat()
{
    
    if(environment(caster) != oldenv)
    {
        oldenv=environment(caster);
        see_room();
    }
    else
        if(conceal != invisobs())
            see_changes();
}
int remove_me(){
	set_heart_beat(0);
	return 1;
}
