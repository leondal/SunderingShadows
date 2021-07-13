//altered by ~Circe~ so that the caster may have only 1 up at a time,
//cannot move around after casting, and has a delay before being
//able to cast again after discussions with other wizzes
//rebalancing domains 5/10/08
//_listening_shadow
// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <std.h>
#include <magic.h>
inherit SPELL;

object shadow,remote;
string theName;
#define DELAY 300
//This *should* equal a 5 minute delay, I think.  That's the
//intention anyway.  ~Circe~ 5/10/08

void create(){
    ::create();
    set_spell_name("listening shadow");
    set_spell_level(([ "assassin" : 4, "mage" : 8 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS listening shadow on TARGET");
    set_description("This will move your shadow to listen to the room you're in or to follow the player indicated. You "
"receive everything heard by the shadow.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
}

int preSpell(){
    if(caster->query_property("remote scrying")){
        tell_object(caster,"You are already listening somewhere!");
        return 0;
    }
    if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
    if((int)caster->query_property("remote scrying time")+DELAY > time()){
        tell_object(caster,"You cannot command your shadow again so soon.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^BLACK%^As your murmur your prayer, "+
        "the shadows swirl around you.%^RESET%^");
    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" murmurs a prayer"+
        " as the shadows swirl around "+caster->QO+".%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof){
    object ob, blockobj;
    int bonus,power;

    if (!arg){
        tell_object(caster,"%^RED%^You leave the shadow here to listen for you.%^RESET%^");
        if(place->query_property("no scry")){
           tell_object(caster,"Something blocks your attempt!");
           return;
        }
        bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
        power = clevel + bonus + random(6);
        if(blockobj = present("blockerx111", place)){
           if(power < blockobj->query_block_power()){
              tell_object(caster,"Something blocks your attempt!");
              return;
           }
        }
        shadow = new("/d/magic/obj/shadowlistener");
        shadow->set_caster(caster);
        shadow->set_property("spell",TO);
        shadow->set_property("spelled", ({TO}) );
        shadow->set_scry_power(power);
        shadow->move(place);
        theName = place->query_short();
        spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
        caster->set_property("remote scrying",1);
        addSpellToCaster();
        return;
    }

    if (ob = find_player(caster->realNameVsProfile(arg))){
        if (objectp(ob) && !wizardp(ob)){
            tell_object(caster,"%^BOLD%^%^BLACK%^You carefully and silently"+
		        " send your shadow off to stand watch on "+arg+".%^RESET%^");
            if(environment(ob)->query_property("no scry")){
                tell_object(caster,"Something blocks your attempt!");
                return;
            }
            bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
            power = clevel + bonus + random(6);
            if(blockobj = present("blockerx111", environment(ob)) || blockobj = present("blockerx111",ob)){
               if(power < blockobj->query_block_power()){
                  tell_object(caster, "Something blocks your attempt!");
                  return;
               }
            }
            shadow = new("/d/magic/obj/shadowlistener");
            shadow->set_caster(caster);
            shadow->set_property("spell",TO);
            shadow->set_property("spelled", ({TO}) );
            shadow->set_target(ob);
            shadow->set_scry_power(power);
            shadow->move(environment(ob));
            theName = ob->query_short();
            spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
            set_end_time();
            call_out("dest_effect",spell_duration);
            caster->set_property("remote scrying",1);
            addSpellToCaster();
            return;
        }
    }
    tell_object(caster,"Your power goes unfocused.");
}

void dest_effect(){
    if (objectp(shadow))
        shadow->dest_me();
    if(objectp(caster)) {
      caster->remove_property("remote scrying");
      caster->remove_property("remote scrying time");
      caster->set_property("remote scrying time",time());
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

string query_spell_display(){
   return "Listening Shadow: "+theName;
}
