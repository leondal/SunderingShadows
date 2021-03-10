#include <std.h>

#define DCOL "%^BOLD%^%^WHITE%^"

#define POSSIBLE_EFFECTS ([ "bless" : "/cmds/spells/b/_bless.c",\
"resistance" : "/cmds/spells/r/_resistance.c",\
"barkskin" : "/cmds/spells/b/_barkskin.c",\
"blight" : "/cmds/spells/b/_blight.c",\
"bulls strength" : "/cmds/spells/b/_bulls_strength.c",\
"invisibility" : "/cmds/spells/i/_invisibility.c",\
"detect invisibility" : "/cmds/spells/d/_detect_invisibility.c",\
"entropic warding" : "/cmds/spells/e/_entropic_warding.c",\
"vigor" : "/cmds/spells/v/_vigor.c",\
"fire shield" : "/cmds/spells/f/_fire_shield.c",\
"fly" : "/cmds/spells/f/_fly.c",\
"freedom of movement" : "/cmds/spells/f/_freedom_of_movement.c",\
"guidance" : "/cmds/spells/g/_guidance.c",\
"haste" : "/cmds/spells/h/_haste.c",\
"heroism" : "/cmds/spells/h/_heroism.c",\
"insight" : "/cmds/spells/i/_insight.c",\
"levitate" : "/cmds/spells/l/_levitate.c",\
"nimbus of light" : "/cmds/spells/n/_nimbus_of_light.c",\
"neutralize poison" : "/cmds/spells/n/_neutralize_poison.c",\
"oppression" : "/cmds/spells/o/_oppression.c",\
"owls wisdom" : "/cmds/spells/o/_owls_wisdom.c",\
"remove blindness" : "/cmds/spells/r/_remove_blindness.c",\
"see the unseen" : "/cmds/spells/s/_see_the_unseen.c",\
"shield of shadows" : "/cmds/spells/s/_shield_of_shadows.c",\
"spider climb" : "/cmds/spells/s/_spider_climb.c",\
"spiderwalk" : "/cmds/spells/s/_spiderwalk.c",\
"stoneskin" : "/cmds/spells/s/_stoneskin.c",\
"strength of stone" : "/cmds/spells/s/_strength_of_stone.c",\
"sustenance" : "/cmds/spells/s/_sustenance.c",\
"sylvan vigor" : "/cmds/spells/s/_sylvan_vigor.c",\
"thicken skin" : "/cmds/spells/t/_thicken_skin.c",\
"tongues" : "/cmds/spells/t/_tongues.c",\
"touchsight" : "/cmds/spells/t/_touchsight.c",\
"true seeing" : "/cmds/spells/t/_true_seeing.c",\
"umbral sight" : "/cmds/spells/u/_umbral_sight.c" ])

#define SCOLS (["deep purple" : ({"%^BOLD%^%^MAGENTA%^", "%^MAGENTA%^"}),\
"deep blue" : ({"%^BLUE%^", "%^BOLD%^%^BLUE%^"}),\
"emerald green" : ({"%^GREEN%^", "%^BOLD%^%^GREEN%^"}),\
"flaming red" : ({"%^RED%^", "%^BOLD%^%^RED%^"}),\
"brilliant yellow" : ({"%^YELLOW%^", "%^BOLD%^%^YELLOW%^"}),\
"powder blue" : ({"%^CYAN%^", "%^BOLD%^%^CYAN%^"})])

#define PCOLS (["deep purple" : "%^B_MAGENTA%^",\
"deep blue" : "%^B_BLUE%^",\
"emerald green" : "%^B_GREEN%^",\
"flaming red" : "%^B_RED%^",\
"brilliant yellow" : "%^B_YELLOW%^",\
"powder blue" : "%^B_CYAN%^" ])

#define VALID_DRINK_TYPES ({"alcoholic", "water", "soft drink", "caffeine"})

inherit OBJECT;

int query_max_uses();
int query_EffectLvl();
int is_flask();
int query_uses(); 
int filter_special_effects(string str);
void choose_effect();
varargs void setup_flask(int flag);

string myCol, myLiqCol, CorkCol, LCol;
int uses, MaxUses, EffectLvl;
mapping MyEffect;




int filter_special_effects(string str)
{
    if(!stringp(str)) return 0;
    if(member_array(str, VALID_DRINK_TYPES) != -1) return 0;
    return 1;
}

void choose_effect()
{
    string *Peffects, which, *Cols;
    int x;
    Peffects = keys(POSSIBLE_EFFECTS);
    which = Peffects[random(sizeof(Peffects))];

    MyEffect = ([which : ([ "spell" : POSSIBLE_EFFECTS[which], "uses" : uses ]) ]);

    Cols = keys(SCOLS);
    myLiqCol = Cols[random(sizeof(Cols))];
    
    myCol = SCOLS[myLiqCol][random(sizeof(SCOLS[myLiqCol]))];

    LCol = PCOLS[myLiqCol];

    CorkCol = "%^RESET%^%^B_BLUE%^";
    EffectLvl = 15;
    return;
}

string *query_my_effects() { return keys(MyEffect); }
string *query_all_possible() { return keys(POSSIBLE_EFFECTS); }
mapping query_effect_mapping() { return MyEffect; }


varargs void setup_flask(int flag)
{
    string *Peffects, which, Estring;   
    int x;
    Peffects = keys(MyEffect);    
    x = sizeof(Peffects);
    if(x == 1) Estring = Peffects[0];
    else if(x == 2)
    {
        Estring = implode(Peffects, " and ");
    }
    else if(x != 0)
    {
        Peffects[(x-1)] = "and "+Peffects[(x-1)];
        Estring = implode(Peffects, ", ");
    }
    if(!stringp(Estring)) 
    {
        Estring = "This particular flask is currently empty.%^RESET%^";
    }
    else
    {
        Estring = "This particular flask "+
        "contains liquid that has been imbued with "+Estring+
        ".%^RESET%^";
    }

    set_name("flask");
    if(!query_uses()) set_short(myCol+"An empty flask%^RESET%^");    
    else set_short(myCol+"A flask of "+myLiqCol+myCol+" liquid%^RESET%^");
    
    set_id( ({"flask", "flask of "+Estring, "flask of "+myLiqCol+" liquid", 
    "flask of liquid"}));
    
    set_lore(myCol+" The origin of this flask is not well know. However "+
    "there are some legends that suggest the flask itself was created "+
    "by a goblin craftsman, who stamped the bottom of it with his insignia. "+
    "The same legends suggest that he was neither good nor evil, but "+
    "rather cared more about crafting something that would last "+
    "beyond his own lifetime. The liquid inside the flask "+
    "is rumored to mix and retain properties, should it be filled "+
    "with certain liquids. "+Estring);
    if(!flag) return;
    if(EffectLvl < 30) EffectLvl += random(6);
    if(EffectLvl > 30) EffectLvl = 30;
}

string get_my_long()
{
    string myLong;
    myLong = myCol+"This small flask is made from a very thick and "+
    "sturdy clear glass. A stopper of wood has been carefully "+
    "inserted into the opening at the top, to prevent it "+
    "from spilling its contents unintentionally. A handle "+
    "starts near the base of it and widens as it nears the top. A stamp has been placed "+
    "on the bottom of it, in the form of a small semi-circle with "+
    "%^BOLD%^%^WHITE%^s%^BOLD%^%^YELLOW%^t%^BOLD%^%^WHITE%^a%^BOLD%^%^YELLOW%^"+
    "r%^BOLD%^%^WHITE%^s%^RESET%^"+myCol+" surrounding it.%^RESET%^";

    if(uses)
    {
        myLong += " You can "+
        "<%^RESET%^check"+myCol+"> the flask or <%^RESET%^drink"+myCol+
        "> from it. You could also <%^RESET%^empty"+myCol+"> the "+
        myLiqCol+" liquid from it, if you wanted to.%^RESET%^";
    }
    
    if(uses < MaxUses)
    {
        myLong += myCol+" You can <%^RESET%^fill with something"+myCol+"> or "+
        "simply <%^RESET%^fill flask"+myCol+"> to "+
        "increase the amount of liquid inside if you wanted to.%^RESET%^";
    }        
    else
    {
        myLong += myCol+" It is currently empty. You can <%^RESET%^check"+myCol+
        "> it to be sure. Maybe you can fill it with something?%^RESET%^";
    }
    return myLong;
}

void create() 
{
    ::create();
    uses = 4;
    MaxUses = uses*4;
    choose_effect();
    setup_flask();
   
    set_long((:TO, "get_my_long":));
    
    set_property("lore difficulty", 10 + random(12));
    
    set_weight(2);
    set_value(150 + random(150));
    
}
int query_max_uses() { return MaxUses; }
int query_EffectLvl() { return EffectLvl; }
int is_flask() { return 1; }
int query_uses() 
{
    int x, y = 0;
    string *FlaskEffects;
    FlaskEffects = query_my_effects();
    for(x = 0;x < sizeof(FlaskEffects);x++)
    {
        y += MyEffect[FlaskEffects[x]]["uses"];
    }
    return y;
}

varargs int add_effect(string which, int amt, int strength)
{
    string *SpecialEffects;
    int y;
    if(!intp(amt)) return 0;
    if(!stringp(which)) return 0;
    y = query_max_uses() - query_uses();
    if(y <= 0) return 0;
    if(amt > y) amt = y;
    if(!mapp(MyEffect)) MyEffect = ([]);
    if(!MyEffect[which])
    {
        if(member_array(which, VALID_DRINK_TYPES) != -1)
        {
            if(!intp(strength) || strength < 0) strength = 5;
            MyEffect += ([which : ([ "uses" : amt, "strength" : strength]) ]);
            return 1;
        }
        else 
        {
            SpecialEffects = filter_array(keys(MyEffect), "filter_special_effects", TO);
            //can only have 2 special effects at any given time per flask - Saide
            if(sizeof(SpecialEffects) > 2) return 0;
            MyEffect += ([which : ([ "uses" : amt, "spell" : POSSIBLE_EFFECTS[which] ]) ]);
            return 1;
        }
    }
    else
    {
        if(member_array(which, VALID_DRINK_TYPES) != -1)
        {
            if(!intp(strength) || strength < 0) strength = 5;   
            MyEffect[which]["strength"] += strength;
            MyEffect[which]["uses"] += amt; 
            return 1;
        }
        else 
        {
            MyEffect[which]["uses"] += amt;
            return 1;
        }
    }
    return 0;
}

string query_liq_col() { return myLiqCol; }
string query_my_col() { return myCol; }

void init()
{
    ::init();
    add_action("check_contents", "check");
    add_action("drink_act", "drink");
    add_action("empty_act", "empty");
    add_action("fill_act", "fill");
}

int fill_act(string str)
{
    object targFlask, targOb;
    mapping Tmp;
    string *AddedEffects, which, what, ThisEffect, MC, MLC;
    int x, flag = 0;
    if(!stringp(str)) return 0;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;

    if(sscanf(str, "%s with %s", which, what) != 2) 
    {
        if(EETO->query_property("fill waterskin"))
        {
            
            if(TO->add_effect("water", 2 + random(3), 20))
            {
                tell_object(ETO, myCol+"You bend down and fill the flask with some "+
                "water and watch in amazement as it changes to a "+myLiqCol+" hue!%^RESET%^");
            
                if(!ETO->query_invis()) 
                {
                    tell_room(EETO, ETOQCN+myCol+" bends down and fills "+ETO->QP+ " flask "+
                    "with some water and amazingly it changes to a "+myLiqCol+" hue!%^RESET%^", ETO);
                }
                TO->setup_flask(1);
                return 1;
            }
            else
            {
                tell_object(ETO, myCol+"You bend down and fill the flask with some "+
                "water and watch in amazement as it changes to a "+myLiqCol+" hue but "+
                "you realize the flask is full and watch as the water spills out!%^RESET%^");
            
                if(!ETO->query_invis()) 
                {
                    tell_room(EETO, ETOQCN+myCol+" bends down and fills "+ETO->QP+ " flask "+
                    "with some water and amazingly it changes to a "+myLiqCol+" hue but then "+
                    "spills out of the flask!%^RESET%^", ETO);
                }
                return 1;
            }            
        }     
        return 0;
    }
    
    if(!present(which, ETO)) return 0;
    if(!objectp(targFlask = present(which, ETO))) return 0;
    if(!targFlask->is_flask()) return 0;
    if(!present(what, ETO)) return 0;
    if(!objectp(targOb = present(what, ETO))) return 0;

    if(targOb == targFlask) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You cannot fill a flask with itself!%^RESET%^");
        return 1;
    }
    MC = targFlask->query_my_col();
    MLC = targFlask->query_liq_col();
    //limit 'special effects' to two per flask 
    if(targOb->is_flask()) 
    {
        if(!targOb->query_uses())
        {
            tell_object(ETO, MC+"That flask is empty!%^RESET%^");
            return 1;
        }
        AddedEffects = targOb->query_my_effects();
        Tmp = targOb->query_effect_mapping();
        
        for(x = 0;x < sizeof(AddedEffects);x++)
        {
            ThisEffect = AddedEffects[x];
            if(targFlask->add_effect(ThisEffect, Tmp[ThisEffect]["uses"], Tmp[ThisEffect]["strength"]))
            {
                tell_object(ETO, MC+"You pour some liquid from "+targOb->query_short() + MC+
                " into "+targFlask->query_short()+MC+" and it changes to a "+MLC+ " hue.%^RESET%^");
                if(!ETO->query_invis())
                {
                    tell_room(EETO, ETOQCN+MC+" pours some liquid from "+targOb->query_short() +MC+
                    " into "+ETO->QP+" "+targFlask->query_short()+MC+" and it changes to a "+MLC+" hue!%^RESET%^", ETO);
                }
                flag = 1;
            }
            else 
            {
                tell_object(ETO, MC+"You spill some of the liquid from "+targOb->query_short()+MC+"!"); 
                if(!ETO->query_invis()) tell_room(EETO, ETOQCN+MC+" spills some liquid out of "+targOb->query_short()+MC+"!%^RESET%^", ETO);
            }
            continue;
        }
        targFlask->setup_flask(1);
        targOb->clear_uses();        
        return 1;
    }
    else if(stringp(ThisEffect = targOb->query("type")))
    {
        if(member_array(ThisEffect, VALID_DRINK_TYPES) == -1)
        {
            tell_object(ETO, MC+"You don't think that you can fill "+targFlask->query_short()+ MC +" with "+
            targOb->query_short()+MC+"!%^RESET%^");
            return 1;
        }
        else if(targFlask->add_effect(ThisEffect, 2+random(2), (int)targOb->query("strength")))
        {
            tell_object(ETO, MC+"You pour some liquid from "+targOb->query_short() + MC + 
            " into "+targFlask->query_short()+MC+" and it changes to a "+MLC+ " hue.%^RESET%^");
            if(!ETO->query_invis())
            {
                tell_room(EETO, ETOQCN+MC+" pours some liquid from "+targOb->query_short() +MC+
                " into "+ETO->QP+" "+targFlask->query_short()+MC+" and it changes to a "+MLC+" hue!%^RESET%^", ETO);
            }
            targFlask->setup_flask(0);
        }
        else 
        {
            tell_object(ETO, MC+"You spill some of the liquid from "+targOb->query_short()+MC+"!"); 
            if(!ETO->query_invis()) tell_room(EETO, ETOQCN+MC+" spills some liquid out of "+targOb->query_short()+MC+"!%^RESET%^", ETO);
        }
        targOb->remove();
        return 1;
    }
    else
    {
        tell_object(ETO, MC+"You don't think that you can fill "+targFlask->query_short()+ MC+" with "+
        targOb->query_short()+MC+"!%^RESET%^");
        return 1;   
    }
}
    
int clear_uses()
{
    MyEffect = ([]);
    setup_flask(0);
}


int adjust_uses(string which, int x) 
{
    if(!intp(x)) return 0;
    if(!stringp(which)) return 0;
    if(!mapp(MyEffect)) MyEffect = ([]);
    if(!MyEffect[which]) return 0;
    
    MyEffect[which]["uses"] -= x;
    if(MyEffect[which]["uses"] <= 0) 
    {
        setup_flask(0);
        map_delete(MyEffect, which);
    }
    if(!query_uses()) 
    {
        clear_uses();
        return 0;
    }
    return query_uses();
}


void process_effects(object who, object flask)
{
    object EffectOb;
    mapping MyTmp;
    string *effects, ThisEffect;
    int x, y;
    if(!objectp(who)) return;
    if(!objectp(flask)) return;
    
    effects = flask->query_my_effects();
    MyTmp = flask->query_effect_mapping();
    if(!mapp(MyTmp)) tell_object(who, "ERROR: Something is wrong with the mapping!");
    if(!pointerp(effects))
    {
        tell_object(who, "ERROR: There is something wrong with your flask.");
        return;
    }
    for(x = 0;x < sizeof(effects);x++)
    {
        if(effects[x] == "soft drink") 
        {
            y = MyTmp[effects[x]]["strength"];
            if(!intp(y)) continue;
            y *= 20;
            if(!who->add_quenched(y)) 
            {
                tell_object(who, "%^RESET%^%^WHITE%^Your stomach is already sloshing around!%^RESET%^");
                continue;            
            }
        }
        else if(effects[x] == "caffeine")
        {
            y = MyTmp[effects[x]]["strength"];
            if(!intp(y)) continue;
            y *= 10;
            if(!who->add_quenced(y)) continue;
            if((int)who->query_intox() < y) 
            {
                tell_object(who, "%^RESET%^%^RED%^The caffeine seems to have no effect.%^RESET%^");
                continue;
            }
        }
        else if(effects[x] == "water")
        {
            y = MyTmp[effects[x]]["strength"];
            if(!intp(y)) continue;
            y *= 50;
            if(!who->add_quenched(y)) 
            {
                tell_object(who, "%^RESET%^%^WHITE%^Your stomach is already sloshing around!%^RESET%^");
                continue;
            }
        }
        else if(effects[x] == "alcoholic")
        {
            y = MyTmp[effects[x]]["strength"];
            if(!intp(y)) continue;
            y *= 10;
            if(!who->add_intox(y)) 
            {
                tell_object(who, "%^RESET%^%^RED%^The alcohol seems to have no effect.%^RESET%^");
                continue;
            }
        }
        ThisEffect = effects[x];
        if(member_array(ThisEffect, VALID_DRINK_TYPES) != -1)
        {
            switch(ThisEffect)
            {
                case "caffeine":
                    tell_object(who, "%^BOLD%^%^WHITE%^You feel a rush of caffeine "+
                    "hit your system!%^RESET%^");
                    who->add_intox(-(y/2));                    
                    break;                
                case "water": case "soft drink":
                    tell_object(who, "%^BOLD%^%^CYAN%^The liquid quenches your thirst!%^RESET%^");
                    break;
                case "alcoholic":
                    tell_object(who, "%^BOLD%^%^BLACK%^You feel a rush as the alcohol hits your "+
                    "system!%^RESET%^");
                    break;
            }
            flask->adjust_uses(ThisEffect, 1);
            continue;
        }
        else
        {
            if(!file_exists(POSSIBLE_EFFECTS[effects[x]])) 
            {
                tell_object(who, "ERROR: Something wrong with "+effects[x]+" in your flask.");
                continue;
            }
            if(catch(EffectOb = new(POSSIBLE_EFFECTS[effects[x]])))
            {
                tell_object(who, "ERROR: Something wrong with "+effects[x]+" in your flask.");
                continue;
            }
            EffectOb->set_spell_type("potion");
            EffectOb->use_spell(who, who, flask->query_EffectLvl(), 100, "potion");
            flask->adjust_uses(effects[x],1);
            continue;
        }
    }
    who->set_property("drank_from_flask", -1);    
    return;
}

int empty_act(string str)
{
    object targFlask;

    if(!stringp(str)) return 0;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!present(str, ETO)) return 0;
    if(!objectp(targFlask = present(str, ETO))) return 0;
    if(!targFlask->is_flask()) return 0;
    if(!targFlask->query_uses()) 
    {   
        tell_object(ETO, "%^BOLD%^%^WHITE%^The flask is already empty!%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You turn your "+targFlask->query_short()+
    "%^BOLD%^%^WHITE%^ up, pop the cork out, and empty the contents!%^RESET%^");

    if(!ETO->query_invis()) 
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ turns up "+ETO->QP+" "+targFlask->query_short()+
        " up, pops the cork, and empties the contents!%^RESET%^", ETO);
    }
    targFlask->clear_uses();;
    return 1;
}



int drink_act(string str)
{
    object targFlask;

    if(!stringp(str)) return 0;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!present(str, ETO)) return 0;
    if(!objectp(targFlask = present(str, ETO))) return 0;
    if(!targFlask->is_flask()) return 0;
    if(ETO->query_property("drank_from_flask"))
    {
        tell_object(ETO, "You have already drink from a flask. You should wait a while longer.");
        return 1;
    }
    if(!targFlask->query_uses())
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^That flask is empty!%^RESET%^");
        return 1;
    }
    tell_object(ETO, myCol+"You take a quick drink from "+targFlask->query_short()+"!%^RESET%^");

    if(!ETO->query_invis()) tell_room(EETO, ETOQCN+myCol+" takes a long drink from "+targFlask->query_short()+"!%^RESET%^", ETO);
    ETO->set_property("drank_from_flask", 1);
    call_out("process_effects", 6, ETO, targFlask);
    return 1;
}



void display_full_level(object who, float perc)
{
    string dis, flask, myCork, ebot, fbot, etop, ftop, eupp, fupp, emid, fmid, spac, elower, flower;
    if(!objectp(who)) return;
    if(!floatp(perc)) return;
    

    //myCork = "  "+CorkCol+"%^BOLD%^%^WHITE%^|%^BOLD%^%^BLACK%^@@@@@@%^BOLD%^%^WHITE%^|%^RESET%^\n";

    myCork = "%^BOLD%^%^WHITE%^  __|%^RESET%^%^ORANGE%^===%^RESET%^%^BOLD%^%^WHITE%^|________%^RESET%^\n";

    //spac = "   %^BOLD%^%^WHITE%^______ %^RESET%^\n";
        
    spac = "%^BOLD%^%^WHITE%^     ___%^RESET%^\n";

    
    flask = "\n";

    flask += spac;

    flask += myCork;
    //flask += spac;

    etop = "%^BOLD%^%^WHITE%^ [      ===]  / /%^RESET%^";
    ftop = "%^BOLD%^%^WHITE%^ ["+LCol+"      %^RESET%^%^BOLD%^%^WHITE%^===]  / /%^RESET%^\n";
    etop += " %^RESET%^\n";

    //etop = "   %^RESET%^%^BOLD%^%^WHITE%^(    )%^RESET%^\n";
    //ftop = "   %^RESET%^%^BOLD%^%^WHITE%^("+LCol+"~~~~%^RESET%^%^BOLD%^%^WHITE%^)%^RESET%^\n";
    
    eupp = "%^BOLD%^%^WHITE%^ |      ===| / /%^RESET%^";
    fupp = "%^BOLD%^%^WHITE%^ |"+LCol+"      %^RESET%^%^BOLD%^%^WHITE%^===| / /%^RESET%^";
    eupp += " \n";
    fupp += " \n";

    //eupp = "  %^BOLD%^%^WHITE%^(      )\n";
    //fupp = "  %^BOLD%^%^WHITE%^("+LCol+"~~~~~~%^RESET%^%^BOLD%^%^WHITE%^)\n";
    
    emid = " %^BOLD%^%^WHITE%^|      ===|/ /%^RESET%^";
    fmid = " %^BOLD%^%^WHITE%^|"+LCol+"      %^RESET%^%^BOLD%^%^WHITE%^===|/ /%^RESET%^";
    emid += "\n";
    fmid += "\n";

    elower = " %^BOLD%^%^WHITE%^|      ===|_/%^RESET%^";
    flower = " %^BOLD%^%^WHITE%^|"+LCol+"      %^RESET%^%^BOLD%^%^WHITE%^===|_/%^RESET%^";
    elower += "\n";
    flower += "\n";
    
    //emid = " %^BOLD%^%^WHITE%^(        )\n";
    //fmid = " %^BOLD%^%^WHITE%^("+LCol+"~~~~~~~~%^RESET%^%^BOLD%^%^WHITE%^)\n";

    ebot = " %^BOLD%^%^WHITE%^[_________]%^RESET%^";
    fbot = " %^BOLD%^%^WHITE%^["+LCol+"_________%^RESET%^%^BOLD%^%^WHITE%^]%^RESET%^";
    ebot += "\n";
    fbot += "\n";


    //ebot = "  %^BOLD%^%^WHITE%^(______)\n";
    //fbot = "  %^BOLD%^%^WHITE%^("+LCol+"______%^RESET%^%^BOLD%^%^WHITE%^)\n";
    
    
    
    if(perc >= 1)
    {
        ///dis = "The flask appears to be full.\n";
        flask += ftop + fupp + fmid + flower + fbot;
    }
    else if(perc >= 0.80 && perc < 1)
    {
        //dis = "The flask appears about three quarters full.\n";
        flask += etop + fupp + fmid + flower + fbot;
    }
    else if(perc >= 0.60 && perc < 0.80)
    {
        //dis = "The flask appears about half full.\n";
        flask += etop + eupp + fmid + flower + fbot;
    }
    else if(perc >= 0.40 && perc < 0.60)
    {
        //dis = "The flask appears about a quarter full.\n";
        flask += etop + eupp + emid + flower + fbot;
    }
    else if(perc >= 0.01 && perc < 0.40)
    {
        flask += etop + eupp + emid + elower + fbot;
    }    
    else 
    {
        //dis = "The flask appears empty.\n";
        flask += etop + eupp + emid + elower +ebot;
    }    
    //flask += bot;
    dis = flask;
    tell_object(who, dis);
    return;    
}


int check_contents(string str) 
{
    float perc;
    if(!str) 
    { 
        notify_fail("Check what?\n");
        return 0;
    } 
    if(!id(str))
    {
        if (TO != present(str,ETO)) 
        {
            notify_fail("You do not have that.");
            return 0;
        } 
    }
    tell_object(ETO, "You examine the "+str+" to determine how much liquid remains.");
    perc = to_float(to_float(query_uses()) / to_float(MaxUses));
    display_full_level(ETO, perc);
    return 1;
}
