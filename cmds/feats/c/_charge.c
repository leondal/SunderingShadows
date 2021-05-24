#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

#define VOID "/d/shadowgate/void"
#define PATHFINDER "/daemon/pathfinder_d.c" // Added by Lujke 15 October 05

void create() {
    ::create();
    feat_type("instant");
    feat_category("Horsemanship");
    feat_name("charge");
    feat_prereq("Ride-by attack");
    feat_syntax("charge TARGET");
    feat_desc("A mounted character can attempt to charge down a foe, causing enhanced damage if they successfully impact.Charges from several rooms distant will do greater damage.If the charge is not completed in a short time, your mount will tire and lose too much speed to continue the charge.");
    set_target_required(0);
}

int allow_shifted() { return 0; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(!FEATS_D->has_feat(ob,"ride-by attack")) {
      dest_effect();
      return 0;
    }
    return ::prerequisites(ob);
}

int cmd_charge(string str) 
{
    object feat, ob;
    if(!objectp(TP) || !stringp(str))
    {
        dest_effect();
        return 0;
    }
    if(str == "off" && TP->query_property("charging")) 
    {
        ob = TP->query_property("charging object");
        if(objectp(ob)) 
        {
            if(ob->query_property("ended_charge"))
            {
                dest_effect();
                return 0;
            }
        }        
        if (objectp(ob)) ob->remove();
        TP->remove_property("charging object");
        TP->remove_property("using instant feat");
        TP->remove_property("charging");
        tell_object(TP,"%^BOLD%^%^BLUE%^You stop charging.");
        tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" pulls "+TPQP+" horse up.",TP);
        dest_effect();
        return 1;
    }
    feat = new(base_name(TO));
    feat->setup_feat(TP,str);
    return 1;
}

void execute_feat() {
    object victim, ob;
    ::execute_feat();
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_paralyzed() || (int)caster->query_tripped() || (int)caster->query_bound()) {
        tell_object(caster,"You can't charge while stunned!");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat")) {
        tell_object(caster,"You are already in the middle of using a feat!");
        dest_effect();
        return;
    }
    if (caster->query_property("charging")){
        tell_object(caster,"You can only charge in one direction at a time!");
        dest_effect();
        return;
    }
    if((present(arg,place)) == caster) {
        tell_object(caster,"Don't charge at yourself!");
        dest_effect();
        return;
    }
    if (ob = caster->query_property("charging object")) 
    {
        if (objectp(ob)) 
        {
            ob->remove();
        }
        caster->remove_property("charging object");
    }
    victim = PATHFINDER ->far_present(place, arg, 5);
    if(!objectp(victim)) {
      tell_object(caster, "Are you sure? Your mount can't see a "+arg+" to charge at within 5 rooms."
                     +"\nUse %^BOLD%^%^YELLOW%^<charge off>%^RESET%^ if you change your mind.");
    }
    
	if((caster->query_race() != "centaur") && (caster->query_race() != "wemic")) {
	if (!caster->query_in_vehicle()){
        tell_object(caster,"You can't charge on foot!");
        dest_effect();
        return;
    }
	}
    caster->use_stamina(roll_dice(1,6));
    caster->remove_property("charge_target_found");
    caster->set_property("using instant feat",1);
    ob = new("/cmds/cavalier/charge");
    ob->set_tp(caster);
    ob->set_target(arg);
    caster->set_property("charging",1);
    if(objectp(ob)) 
    {
      ob->do_exit();
      caster->set_property("charging object", ob);
      //caster->add_post_exit_func((:ob,"do_exit":));
    }
    call_out("dest_effect",60);
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}

