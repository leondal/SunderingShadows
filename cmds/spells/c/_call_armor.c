//~Circe~ 9/27/15 for psywarriors

#include <priest.h>
inherit SPELL;

object myarmor;
#define TYPES ({"light","medium","heavy"})


void create() {
    ::create();
    set_spell_name("call armor");
    set_spell_level(([ "psywarrior" : 1 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS call armor on <light|medium|heavy>");
    set_description("This power allows the psywarrior to create a "
       "suit of armor using only her mental prowess. The armor is "
       "crafted from energy and may take the form of either light, "
       "medium, or heavy armor. The type is chosen by the psywarrior "
       "at the time of manifesting. If no choice is made, the armor "
       "will automatically take the form of medium armor. In addition "
       "to any other IDs the armor may have, the ID <energy armor> will "
       "always work.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^RESET%^%^ORANGE%^"+caster->QCN+" waves a hand lazily in the air, eyes focused elsewhere.%^RESET%^";
}

void spell_effect(int prof)
{
      int mylevel;
    	if (!objectp(caster)){
        dest_effect();
        return;
    	}
      if(!arg) arg = "medium";
      if(member_array(arg,TYPES) == -1){
         tell_object(caster,"That is not a valid type!  You must "
            "choose light, medium, or heavy.");
         if(objectp(TO)) TO->remove();
         return;
      }
    	if (interactive(caster)){
         tell_object(caster, "%^BOLD%^%^YELLOW%^A suit of "+arg+" armor made of pure "
            "energy materializes before you as you concentrate!");
      }
      tell_room(place,"%^BOLD%^%^YELLOW%^The air around "+caster->QCN+" begins "
         "to shimmer before coalescing into a suit of "+arg+" armor made of "
         "pure energy!%^RESET%^",caster);
      switch(arg){
         case "light": myarmor = new("/d/common/obj/armour/studded.c");
            myarmor->set_short("%^BOLD%^%^WHITE%^a s%^RESET%^h%^BOLD%^i%^RESET%^m"
               "%^CYAN%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^CYAN%^n%^RESET%^g %^BOLD%^suit "
               "of st%^RESET%^u%^BOLD%^dd%^RESET%^%^CYAN%^e%^BOLD%^%^WHITE%^d "
               "ar%^RESET%^m%^BOLD%^or%^RESET%^");
            myarmor->set_long("%^RESET%^This suit of s%^RESET%^h%^BOLD%^i%^RESET%^m"
               "%^CYAN%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^CYAN%^n%^RESET%^g armor bears "
               "little resemblance to its mundane counterpart. Where leather would be "
               "fastened with rivets, this seems to simply hover together, providing "
               "protection for the wearer. Though the armor is crafted from energy, "
               "it does still over some encumberment.");
               break;
         case "heavy": myarmor = new("/d/common/obj/armour/fullplate.c"); //May want to consider making this plate.c instead, especially at low levels
            myarmor->set_short("%^BOLD%^%^WHITE%^a s%^RESET%^h%^BOLD%^i%^RESET%^m"
               "%^CYAN%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^CYAN%^n%^RESET%^g %^BOLD%^suit "
               "of fu%^RESET%^l%^BOLD%^lpl%^RESET%^%^CYAN%^a%^BOLD%^%^WHITE%^te%^RESET%^");
            myarmor->set_long("%^RESET%^This impressive suit of armor is made from "
               "flat plates of %^CYAN%^pure e%^BOLD%^n%^RESET%^%^CYAN%^ergy%^RESET%^ "
               "that are contoured to fit the wearer. The typical chainmail and padding "
               "are missing, as this armor requires no help in protecting the wearer "
               "from heavy blows. Though the fullplate is lighter than its mundane "
               "counterparts, it does still ofer some encumberment.");
            myarmor->set_owned(caster);
            break;
         default: myarmor = new("/d/common/obj/armour/chain.c");
            myarmor->set_short("%^BOLD%^%^WHITE%^a s%^RESET%^h%^BOLD%^i%^RESET%^m"
               "%^CYAN%^m%^RESET%^e%^BOLD%^r%^RESET%^i%^CYAN%^n%^RESET%^g %^BOLD%^suit "
               "of ch%^RESET%^%^CYAN%^a%^WHITE%^i%^BOLD%^nm%^RESET%^a%^BOLD%^il%^RESET%^");
            myarmor->set_long("%^RESET%^This armor is made of interlocking rings made of "
               "%^CYAN%^pure e%^BOLD%^n%^RESET%^%^CYAN%^ergy%^RESET%^. The layer of %^BOLD%^"
               "%^CYAN%^air %^RESET%^beneath it helps cushion the impact of blows, much as "
               "the traditional quilted material would. The links yield easily to blows, "
               "absorbing some of the shock. The suit of armor is lighter than its mundane "
               "counterparts, though it does still ofer some encumberment.");
            break;
      }
      myarmor->add_id("energy armor");
      myarmor->set("value",0);
      myarmor->move(caster);
      myarmor->set_size((int)caster->query_size());
      caster->remove_paralyzed();
      caster->force_me("wear armor");
      spell_successful();
      mylevel = clevel;
      spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
      set_end_time();
      call_out("dest_effect",spell_duration);
}

void dest_effect() {
    if (objectp(caster)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^The energy forming the "+
           "armor disperses, leaving you vulnerable.");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^The armor around "+
           ""+caster->QCN+" fades away.",caster);
        caster->force_me("unwear armor");
    }
    if(objectp(myarmor)) myarmor->remove();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
