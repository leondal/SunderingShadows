#include <std.h>

inherit "/std/comp_vend.c";

object *recent, tp;
string tpqcn;
int i;

void create()
{
    ::create();
    set_name("lavasha");
    set_id( ({ "lavasha", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Lavasha, sorceress of the tower");
    set("aggressive", 0);
    set_long("Lavasha is an extraordinarily beautiful elven "+
        "enchantress with dark brown hair, disarming green eyes, "+
        "and a comely form.  Her robe is of a pink silk, and she "+
        "wears matching gloves.  Lavasha is known to be the "+
        "caretaker of the tower, being the one who magically "+
        "erected it, as well as enhanced it in a multitude of ways."+
        "  To support the magi and make a living, she manages a "+
        "component shop within her tower.  She smiles at her "+
        "customers warmly, offering her assistance.\n"+
	"<help shop> will get you a list of shop commands.\n");
    set_gender("female");
    set_alignment(3);
    set("race", "elf");
    set_class("mage");
    set_hd(20,2);
    set_level(20);
    set_guild_level("mage",20);
    set_body_type("human");
    set_stats("charisma",25);
    set_property("no bump", 1);
    set_wielding_limbs( ({ "right hand","left hand" }) );
    set_emotes(4,({"%^MAGENTA%^Lavasha says%^RESET%^: You "+
        "will always be welcome here, dear magi.",
        "%^MAGENTA%^Lavasha says%^RESET%^: Look around my shop "+
        "as you wish, and I'll be happy to assist you when "+
        "you're ready.","Lavasha smiles at you warmly.","Lavasha "+
        "chants a few magical words softly while staring at you.",
        "Lavasha beckons you forth.","Lavasha charmingly winks "+
        "at you.","Lavasha sweeps her hair as she peers around the "+
        "store, then back at you."}), 0);
    set_emotes(20, ({"%^MAGENTA%^Lavasha says%^RESET%^: Run "+
        "while you still can you fool!","%^MAGENTA%^Lavasha says"+
        "%^RESET%^: I will have no mercy for such incompetence "+
        "like you!", "Lavasha raises her arms, recalling another "+
        "spell.","Lavasha brushes her hair out of her face with "+
        "her hand."}), 1);
    set_components(100);
    set_spell_chance(100);
    set_spells(({"fireball","lightning bolt","acid arrow",
        "cone of cold"}));
    set_property("strength","spells");
    recent=({});
}

void init()
{
    int i;
    string *comms;
    ::init();
    if((string)TP->query_gender() != "male")
        return;
    comms=({"hug","french","kiss","fondle","cuddle","grope","snuggle","caress",
        "touch","lick"});
    for(i=0;i < sizeof(comms);i++)
        add_action("take_over",comms[i]);
    if( interactive(TP) &&
        member_array(TP,recent) == -1 &&
        find_call_out("grin") == -1 )
        call_out("grin",5,TP);
}

void grin(object male)
{
    if(!male)
        return;
    if(present(male,environment(TO)))
    {
        tell_object(male,"Lavasha grins at you seductively.");
        tell_room(environment(TO),"Lavasha grins at "+
            male->query_cap_name()+" seductively.",male);
        for(i=0;i < sizeof(recent);i++)
        {
            if(!recent[i])
                recent -= ({ recent[i] });
        }
        recent += ({ male });
        while(sizeof(recent) > 3)
            recent -= recent[0];
    }
}

int take_over(string str)
{
    if( (str != "lavasha") ||
        (find_call_out("make_moves") != (-1)) )
        return 0;
    tp=TP;
    tpqcn=TPQCN;
    if(!tp->query_married())
        return 0;
    if(!present(tp->query_married(),environment(TO)))
        return 0;
    call_out("make_moves",2,0);
    return 1;
}

void make_moves(int num)
{
    int wait;
    if(!tp)
        return 1;
    if(!tp->query_married())
        return 1;
    if(!present(tp,environment(TO)))
        return 1;
    if(!present(tp->query_married(),environment(TO)))
        num=6;
    switch(num)
    {
        case 0:
            tell_object(tp,"As you approach Lavasha, she embraces "+
                "you and holds you tightly against her warm body.");
            tell_room(environment(TO),"%^BOLD%^%^MAGENTA%^As "+tpqcn+" "+
                "approaches Lavasha, she embraces "+
                tp->query_objective()+" and holds "+
                tp->query_objective()+" tightly against her body.",
                tp);
            wait=5;
            break;
        case 1:
            tell_object(tp,"%^CYAN%^Lavasha whispers in your ear:  "+
                "%^RESET%^MISHRATZ FERRIZ LASHVA GRALLUR...");
            tell_room(environment(TO),"%^CYAN%^Lavasha whispers "+
                "something in "+tpqcn+"'s ear.",tp);
            wait=10;
            break;
        case 2:
            tell_object(tp,"%^BOLD%^%^MAGENTA%^The elven woman "+
                "overpowers your mind, smiling at you contently.");
            tell_room(environment(TO),"%^BOLD%^%^MAGENTA%^The "+
                "elven woman gazes into "+tpqcn+"'s eyes, "+
                "smiling contently.",tp);
            tp->set_paralyzed(5000,"You are under the Lavasha's "+
                "spell, helpless in her arms.");
            wait=10;
            break;
        case 3:
            tell_object(tp,"%^BOLD%^%^RED%^Lavasha frenches you "+
                "passionately and deeply.");
            tell_room(environment(TO),"%^BOLD%^%^RED%^Lavasha "+
                "frenches "+tp->query_objective()+" passionately "+
                "and deeply.",tp);
            tp->force_me("moan");
            wait=10;
            break;
        case 4:
            tell_object(tp,"%^BOLD%^%^RED%^She tightens her hold "+
                "on your body, her tongue moving inside your "+
                "mouth.");
            tell_room(environment(tp),"%^BOLD%^%^RED%^She tightens "+
                "her hold on "+tpqcn+".\n%^RESET%^"+tpqcn+" seems "+
                "to be enjoying this thoroughly.",tp);
            break;
            wait=10;
        case 5:
            tell_object(tp,"She presses down harder on your lips "+
                "with hers, and you feel the pulsating heat of her "+
                "breasts against your chest.");
            tell_room(environment(TO),"%^BOLD%^%^RED%^"+tpqcn+
                " goes limp in Lavasha's arms as she presses her "+
                "lips against "+tp->query_possessive()+" harder.",
                tp);
            wait=15;
            break;
        case 6:
            tell_object(tp,"Lavasha softly pulls herself away, "+
                "with an evil grin on her lips.\nYou are left "+
                "feeling dizzy.");
            tell_room(environment(TO),"Lavasha softly pulls "+
                "herself away from "+tpqcn+", with an evil grin "+
                "on her lips.\n"+tpqcn+" seems a bit dizzy.",tp);
            tp->set_paralyzed(0,"You're dizzy.");
            break;
    }
    if(num < 6)
    {
        num++;
        call_out("make_moves",wait,num);
    }
    return 1;
}

void die(object ob)
{
    object shop;
    shop=find_object_or_load("/d/shadow/room/city/cguild/"+
        "mage/compshop");
    shop->stone();
    return ::die(ob);
}

void remove()
{
   if( find_call_out("make_moves") != (-1) )
   {
       if(tp)
           tp->set_paralyzed(0,"You're dizzy.");
   }
   return ::remove();
}
