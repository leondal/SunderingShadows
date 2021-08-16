#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit RT;

string original_long;
int has_blood;
object myMon;

void create()
{
    has_blood = 0;
    ::create();
    original_long = "%^BOLD%^%^MAGENTA%^The boards beneath your feet on this portion of the "+
    "roof have been reinforced with a thick %^CYAN%^blue %^BOLD%^%^MAGENTA%^metal that "+
    "gives off a considerable heat. An %^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^ made from "+
    "%^BOLD%^%^BLACK%^charred bones%^BOLD%^%^MAGENTA%^ has been constructed here. "+
	"The bones that were laying around chaotically have been piled at each corner of the "+
    "%^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^. Large spears protrude from the "+
    "center of each pile and each spear has the rotting head of some humanoid "+
    "creature stuck down onto it. Each head is %^RESET%^%^ORANGE%^chanting%^BOLD%^%^MAGENTA%^"+
    " constantly, chaotically, in some "+
    "ancient mysterious language and each head is surrounded by an %^BOLD%^%^CYAN%^impenetrable field%^BOLD%^"+
    "%^MAGENTA%^ of %^BOLD%^%^RED%^crackling energy%^BOLD%^%^MAGENTA%^. Atop the altar rests a massive, "+
    "monstrous %^BOLD%^%^WHITE%^"+
    "skeletal creature%^BOLD%^%^MAGENTA%^ with a %^BOLD%^%^BLACK%^pure black%^BOLD%^%^MAGENTA%^"+
    " orb inset deep into each of its eye sockets.%^RESET%^";

    set_long(original_long);


    set_items(([
    ({"boards", "floor", "blue metal", "metal"}) : "%^CYAN%^The floor here "+
    "has been reinforced with a thick blue metal. It is giving off a considerable "+
    "heat.%^RESET%^",

    ({"altar", "bone altar", "charred altar"}) : "%^BOLD%^%^BLACK%^This massive altar "+
    "is perhaps twelve feet long and six feet wide. It has been constructed from "+
    "the charred bones that are found throughout this place.%^RESET%^",

    ({"spears", "large spears"}) : "%^BOLD%^%^RED%^These large spears protrude up from "+
    "the center of the piles of bones. They appear to be more ceremonial than anything and "+
    "resting atop each one is the rotting head of some type of humanoid creature.%^RESET%^",

    ({"piles", "bone piles"}) : "%^BOLD%^%^BLACK%^The bones, which were thrown about "+
    "chaotically on most of the roof, have been piled into four deliberate piles, one at "+
    "each corner of the altar, and a large spear protrudes up from each pile.%^RESET%^",

    ({"head", "heads", "rotting heads", "field", "impenetrable field",
    "crackling energy", "energy"}) : "%^RESET%^%^ORANGE%^These heads, one staked upon "+
    "each of the spears, are constantly and chaotically chanting in an ancient, mysterious "+
    "language. They are bloated and rotted to the point of almost being unrecognizable, however, "+
    "there eyes are a %^BOLD%^%^RED%^deep red%^RESET%^%^ORANGE%^ and are seething with "+
    "fury. An impenetrable field of crackling energy surrounds each head, preventing "+
    "anyone or anything from ever coming into contact with them.%^RESET%^",

    ({"creature", "skeletal creature", "monstrous creature"}) : "%^BOLD%^%^RED%^"+
    "The creature that rests atop the altar is composed entirely of dark red bones. "+
    "Each bone is marred with complicated %^CYAN%^runes%^BOLD%^%^RED%^ of "+
    "binding. It looks quite lifeless as if it is missing part of a %^BOLD%^%^CYAN%^sacrifice"+
    "%^BOLD%^%^RED%^ needed to bring it to life. You are not sure how wise bringing "+
    "it to life might be, however.%^RESET%^",
    ]));

    set_listen("default", "%^RESET%^%^ORANGE%^The heads chant constantly and chaotically in some "+
    "ancient mysterious language.%^RESET%^");

    set_exits((["north" : RROOMS+"28", "northeast" : RROOMS+"29", "east" : RROOMS+"24", "southeast" : RROOMS+"19",
    "south" : RROOMS+"18", "southwest" : RROOMS+"17", "west" : RROOMS+"22", "northwest" : RROOMS+"27" ]));

}

void init()
{
    ::init();
    add_action("sac_act", "sacrifice");
    add_action("plunge_act", "plunge");
}

int GoThroughDoor()
{
    object mon;
    if(!objectp(TP)) return 0;
    if(objectp(mon = present("skeleton of aurus devar", TO)))
    {
        tell_object(TP, mon->query_short()+"%^BOLD%^%^RED%^ prevents you from escaping!%^RESET%^");
        return 0;
    }
    return ::GoThroughDoor();
}


void adjust_room()
{
    switch(has_blood)
    {
        case 0:
            set_long(original_long);
            add_item(({"creature", "skeletal creature", "monstrous creature"}), "%^BOLD%^%^RED%^"+
            "The creature that rests atop the altar is composed entirely of dark red bones. "+
            "Each bone is marred with complicated %^CYAN%^runes%^BOLD%^%^RED%^ of "+
            "binding. It looks quite lifeless as if it is missing part of a %^BOLD%^%^CYAN%^sacrifice"+
            "%^BOLD%^%^RED%^ needed to bring it to life. You are not sure how wise bringing "+
            "it to life might be, however.%^RESET%^");
            break;
        case 1:

            set_long("%^BOLD%^%^MAGENTA%^The boards beneath your feet on this portion of the "+
            "roof have been reinforced with a thick %^CYAN%^blue %^BOLD%^%^MAGENTA%^metal that "+
            "gives off a considerable heat. An %^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^ made from "+
            "%^BOLD%^%^BLACK%^charred bones%^BOLD%^%^MAGENTA%^ has been constructed here. "+
            "The bones that were laying around chaotically have been piled at each corner of the "+
            "%^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^. Large spears protrude from the "+
            "center of each pile and each spear has the rotting head of some humanoid "+
            "creature stuck down onto it. Each head is %^RESET%^%^ORANGE%^chanting%^BOLD%^%^MAGENTA%^"+
            " constantly, chaotically, in some "+
            "ancient mysterious language and each head is surrounded by an %^BOLD%^%^CYAN%^impenetrable field%^BOLD%^"+
            "%^MAGENTA%^ of %^BOLD%^%^RED%^crackling energy%^BOLD%^%^MAGENTA%^. Atop the altar rests a massive, "+
            "monstrous %^BOLD%^%^WHITE%^"+
            "skeletal creature%^BOLD%^%^MAGENTA%^ with a %^BOLD%^%^BLACK%^pure black%^BOLD%^%^MAGENTA%^"+
            " %^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^u%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^YELLOW%^s%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^i"+
            "%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g %^BOLD%^%^MAGENTA%^orb inset deep into each "+
            "of its eye sockets.%^RESET%^");

            add_item(({"creature", "skeletal creature", "monstrous creature"}), "%^BOLD%^%^RED%^"+
            "The creature that rests atop the altar is composed entirely of dark red bones. "+
            "Each bone is marred with complicated %^CYAN%^runes%^BOLD%^%^RED%^ of "+
            "binding. The %^BOLD%^%^BLACK%^pure black%^BOLD%^%^MAGENTA%^ orbs set into its "+
            "eye sockets are %^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^u%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^YELLOW%^s%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^i"+
            "%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g%^BOLD%^%^RED%^ rapidly. You are "+
            "enraged by it for some reason and want to %^BOLD%^%^CYAN%^plunge%^BOLD%^"+
            "%^RED%^ the dagger into it!%^RESET%^");

            break;

        case 2:

            set_long("%^BOLD%^%^MAGENTA%^The boards beneath your feet on this portion of the "+
            "roof have been reinforced with a thick %^CYAN%^blue %^BOLD%^%^MAGENTA%^metal that "+
            "gives off a considerable heat. An %^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^ made from "+
            "%^BOLD%^%^BLACK%^charred bones%^BOLD%^%^MAGENTA%^ has been constructed here. "+
            "The bones that were laying around chaotically have been piled at each corner of the "+
            "%^BOLD%^%^WHITE%^altar%^BOLD%^%^MAGENTA%^. Large spears protrude from the "+
            "center of each pile and each spear has the rotting head of some humanoid "+
            "creature stuck down onto it. Each head is %^RESET%^%^ORANGE%^chanting%^BOLD%^%^MAGENTA%^"+
            " constantly, chaotically, in some "+
            "ancient mysterious language and each head is surrounded by an %^BOLD%^%^CYAN%^impenetrable field%^BOLD%^"+
            "%^MAGENTA%^ of %^BOLD%^%^RED%^crackling energy%^BOLD%^%^MAGENTA%^.%^RESET%^");

            remove_item(({"creature", "skeletal creature", "monstrous creature"}));
            break;
	}
}

void devar_awakening(object who)
{
    object mon;
    if(!objectp(who)) return;
    if(!objectp(TO)) return;
    if(present("skeleton of aorus devar", TO)) return;
    switch(has_blood)
    {
        case 1:

            tell_room(TO, "%^BOLD%^%^WHITE%^The %^BOLD%^%^BLACK%^black orbs%^BOLD%^%^WHITE%^ "+
            "of the skeletal creature begin %^BOLD%^%^WHITE%^p%^BOLD%^%^YELLOW%^u%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^YELLOW%^s%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^i"+
            "%^BOLD%^%^YELLOW%^n%^BOLD%^%^WHITE%^g rapidly as the %^BOLD%^%^RED%^BLOOD"+
            "%^BOLD%^%^WHITE%^ is absorbed by its bones!%^RESET%^");
            adjust_room();
            break;
        case 2:
            tell_room(TO, "%^BOLD%^%^RED%^The skeletal creature on the altar rises up and "+
            "stands.... The %^BOLD%^%^BLACK%^black orbs%^BOLD%^%^RED%^ that serve as its eyes "+
            "are seething with a profound %^BOLD%^%^BLACK%^HATRED%^BOLD%^%^RED%^ as it turns "+
            "to face "+who->QCN+"%^BOLD%^%^RED%^!%^RESET%^", who);

            tell_object(who, "%^BOLD%^%^RED%^The skeletal creature on the altar rises up "+
            "and stands.... The %^BOLD%^%^BLACK%^black orbs%^BOLD%^%^RED%^ that serve as its eyes "+
            "are seething with a profound %^BOLD%^%^BLACK%^HATRED%^BOLD%^%^RED%^ as it turns "+
            "to face you!%^RESET%^");
            mon = new(HHMON+"aurus_devar_bones");
            mon->move(TO);
            mon->awoken(who);
            adjust_room();
            break;

	}

}

int plunge_act(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;

    if(present("arag dyne", TO))
    {
        tell_object(TP, "%^BOLD%^%^RED%^Arag Dyne will not let you close enough to the "+
        "altar to do that!%^RESET%^");
        return 1;
    }

    if(present("skeleton of aorus devar", TO))
    {
        tell_object(TP, "%^BOLD%^%^RED%^It would be unwise to do that now.%^RESET%^");
        return 1;
    }

    if(has_blood > 1)
    {
        tell_object(TP, "%^BOLD%^%^RED%^The dagger sacrifice has already been completed.%^RESET%^");
        return 1;
    }

    if(!stringp(str) || str != "dagger")
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^Plunge what into the skeletal creature? Your "+
        "%^BOLD%^%^RED%^dagger%^BOLD%^%^CYAN%^?%^RESET%^");
        return 1;
    }

    if(!objectp(ob = present("hhousebloodrite", TP)))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You realize that you are missing some important part needed for "+
        "the sacrifice.%^RESET%^");
        return 1;
    }

    if(!ob->query_wielded())
    {
        tell_object(TP, "%^BOLD%^%^RED%^You must be wielding the dagger!%^RESET%^");
        return 1;
    }

    tell_object(TP, "%^BOLD%^%^RED%^You walk to the altar and plunge your irridescent "+
    "dagger down into the chest of the skeletal creature! You are UNABLE to remove it "+
    "as the creature slowly begins stirring......%^RESET%^");
    ob->move("/d/shadowgate/void");
    ob->remove();
    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ walks to the altar and plunges "+TP->QP+
    " irridescent dagger down into the chest of the skeletal creature!!! "+TP->QS+
    " is UNABLE to remove it as the creature slowly begins stirring.....%^RESET%^", TP);
    has_blood = 2;
    call_out("devar_awakening", 5, TP);
    return 1;
}

int sac_act(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;

    if(present("arag dyne", TO))
    {
        tell_object(TP, "%^BOLD%^%^RED%^Arag Dyne will not let you close enough to the "+
        "altar to do that!%^RESET%^");
        return 1;
    }
    if(present("skeleton of aorus devar", TO))
    {
        tell_object(TP, "%^BOLD%^%^RED%^It would be unwise to do that now.%^RESET%^");
        return 1;
    }

    if(has_blood)
    {
        tell_object(TP, "%^BOLD%^%^RED%^The blood sacrifice has already been completed.%^RESET%^");
        return 1;
    }

    if(!stringp(str) || str != "blood")
    {
        tell_object(TP, "%^BOLD%^%^CYAN%^Sacrifice what? Your %^BOLD%^%^RED%^blood%^BOLD%^%^CYAN%^?%^RESET%^");
        return 1;
	}

    if(!objectp(ob = present("hhousebloodrite", TP)))
    {
        tell_object(TP, "%^BOLD%^%^WHITE%^You realize that you are missing some important part needed for "+
        "the sacrifice.%^RESET%^");
        return 1;
    }

    if(!ob->query_wielded())
    {
        tell_object(TP, "%^BOLD%^%^RED%^You must be wielding the dagger!%^RESET%^");
        return 1;
    }

    tell_object(TP, "%^BOLD%^%^RED%^You walk to the altar and while standing above the "+
    "skeletal creature you slash into the flesh of your own hand!! Your BLOOD drips down, "+
    "splashing all over the skeletal remains!!%^RESET%^");

    TP->cause_typed_damage(TP, 0, roll_dice(2, 12), "slashing");
    //POISON_D->ApplyPoison(TP, HHOB+"blood_rite_poison",ob, "injury");

    tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ walks to the altar and while standing above the "+
    "skeletal creature slashes into the flesh of "+TP->QP+" own hand! "+TP->QP+
    " BLOOD drips down, splashing all over the skeletal remains!%^RESET%^", TP);

    has_blood = 1;
    return 1;
}
void reset()
{
    ::reset();
    if(!objectp(TO)) return;
    if(has_blood)
    {
        has_blood = 0;
        adjust_room();
    }
    if(!present("arag dyne", TO) && !sizeof(TO->query_combatants())) new(HHMON+"arag_dyne")->move(TO);
    return;
}


void head_damage(object targ, int heads)
{
    int dam;
    string *myWords = ({"zero", "one", "two", "three", "four"}), headNum;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!intp(heads)) heads = 1;
    headNum = myWords[heads];

    tell_object(targ, "%^RESET%^%^ORANGE%^You feel a powerful force trying to destroy your mind as the "+
    "gaze of "+headNum+ " of the heads focuses on you%^RESET%^!");

    tell_room(TO, "%^RESET%^%^ORANGE%^The gaze of "+headNum+" of the heads focuses on "+targ->QCN+
    "%^RESET%^%^ORANGE%^!%^RESET%^", targ);

    if(targ->will_save(38 + (heads*4)))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You manage to resist the force trying to destroy your mind!%^RESET%^");
        return;
	}
    tell_object(targ, "%^BOLD%^%^CYAN%^You begin screaming in agony and collapse to your knees as the "+
    "force penetrates your mind!%^RESET%^");

    tell_room(TO, targ->QCN+"%^BOLD%^%^CYAN%^ begins screaming in agony and collapses to "+targ->QP+
    " knees!%^RESET%^", targ);
    dam = roll_dice((20*heads), 4);

    targ->cause_typed_damage(targ, 0, dam, "mental");

    targ->set_paralyzed(25, "%^BOLD%^%^CYAN%^You struggle to shake off the effects of the "+
    "mental assault!%^RESET%^");
    return;
}

void register_arag(object ob)
{
    if(objectp(ob)) myMon = ob;
}

void query_myMon()
{
    if(objectp(myMon)) return myMon;
    return 0;
}
