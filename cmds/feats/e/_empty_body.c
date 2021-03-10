#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int BaseFlag;

void create()
{
   ::create();
   feat_type("instant");
   feat_category("KiDefense");
   feat_name("empty body");
   feat_prereq("Monk L18");
   feat_syntax("empty_body");
   feat_desc("This feat allows a Monk who is unarmored, unarmed, or wielding small weapons to empty her body of all vulnerabilities, excluding force damage, and to fade from view, if not already hidden, for one minute. Because of the energy that it requires from the monk it has a short delay before it can be used again.");
   set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }
   if((int)ob->query_class_level("monk") < 18 || (int)ob->query_alignment() > 3)
   {
      dest_effect();
      return 0;
   }
    return ::prerequisites(ob);
}

int cmd_empty_body(string str)
{
   object feat;
   if(!objectp(TP)) { return 0; }
   if((int)TP->query_class_level("monk") < 18) return 0;
   if((int)TP->query_alignment() > 3) return 0;
   if(!(int)USER_D->can_spend_ki(TP, 4))
   {
       tell_object(TP, "%^BOLD%^%^CYAN%^Your empty body attempt fails, you lack the needed ki.%^RESET%^");
       dest_effect();
       return 1;
   }
   feat = new(base_name(TO));
   feat->setup_feat(TP,str);
   return 1;
}

void execute_feat()
{
    object *weapons;
    int x;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    ::execute_feat();
    if(objectp(caster->query_property("empty body")))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^You are currently already under the effects of empty body!");
        dest_effect();
        return;
    }
    if(!(int)USER_D->can_spend_ki(TP, 4))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^Your empty body attempt fails, you lack the needed ki.%^RESET%^");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using empty body") > time())
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^Your empty body attempt fails, you must wait longer.%^RESET%^");
        dest_effect();
        return;
    }
    if((int)caster->query_property("using instant feat"))
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
        dest_effect();
        return;
    }
    if(caster->query_casting())
    {
        tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
        dest_effect();
        return;
    }
    weapons = caster->query_wielded();

    for(x = 0;x < sizeof(weapons);x++)
    {
        if(!objectp(weapons[x])) continue;
        if((int)weapons[x]->query_size() > 1)
        {
            tell_object(caster, "%^BOLD%^%^GREEN%^Your "+weapons[x]->query_short()+
            " prevents you from emptying your body of its vulnerabilities!%^RESET%^");
            dest_effect();
            return;
        }
        continue;
    }
    if(!caster->is_ok_armour("barb"))
    {
        tell_object(caster, "%^BOLD%^%^GREEN%^Your armor "+
        "prevents you from emptying your body of its vulnerabilities!%^RESET%^");
        dest_effect();
        return;
    }

    if(!(int)caster->spend_ki(8))
    {
        tell_object(caster, "%^BOLD%^%^CYAN%^Your empty body attempt fails, you lack the needed ki.%^RESET%^");
        dest_effect();
        return;
    }
    if(!caster->query_invis())
    {
        tell_object(caster, "%^BOLD%^%^WHITE%^You harness your inner Ki, emptying your body of all of its vulnerabilities, as "+
        "you fade from view!%^RESET%^");
    }
    else
    {
        tell_object(caster, "%^BOLD%^%^WHITE%^You harness your inner Ki, emptying your body of all of its vulnerabilities!");
    }
    if(objectp(environment(caster)))
    {
        if(!caster->query_invis()) tell_room(environment(caster), caster->QCN+"%^BOLD%^%^WHITE%^ fades from view!%^RESET%^", caster);
    }
    caster->set_property("using empty body", time() + 180);
    caster->set_property("empty body", TO);
    if(!caster->query_invis())
    {
        caster->set_magic_hidden(1);
        BaseFlag = 1;
    }
    call_out("dest_effect", 60);
    return;
}

void dest_effect()
{
    object myEB;
    if(!objectp(caster))
    {
        ::dest_effect();
        remove_feat(TO);
        return;
    }
    if(objectp(myEB = caster->query_property("empty body")))
    {
        if(myEB == TO)
        {
            if(BaseFlag && (int)caster->query_invis())
            {
                if(caster->query_invis()) tell_room(environment(caster), caster->QCN+"%^BOLD%^%^WHITE%^ fades back into view!%^RESET%^", caster);
                tell_object(caster, "%^BOLD%^%^CYAN%^You feel body shudder violently as you suddenly regain your vulnerabilities and fade fade back into view!%^RESET%^");
                caster->set_magic_hidden(0);
            }
            else
            {
                tell_object(caster, "%^BOLD%^%^CYAN%^You feel body shudder violenty as you suddenly regain your vulnerabilities!%^RESET%^");
            }
            caster->remove_property("empty body");
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
