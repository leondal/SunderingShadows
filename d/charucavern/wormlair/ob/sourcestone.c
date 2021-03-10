#include <std.h>

#define POSSIBLE_EFFECTS ([ "bless" : "/cmds/spells/b/_bless.c",\
"resistance" : "/cmds/spells/r/_resistance.c",\
"barkskin" : "/cmds/spells/b/_barkskin.c",\
"blight" : "/cmds/spells/b/_blight.c",\
"bulls strength" : "/cmds/spells/b/_bulls_strength.c",\
"invisibility" : "/cmds/spells/i/_invisibility.c",\
"detect invisibility" : "/cmds/spells/d/_detect_invisibility.c",\
"entropic warding" : "/cmds/spells/e/_entropic_warding.c",\
"vigor" : "/cmds/spells/v/_vigor.c",\
"fly" : "/cmds/spells/f/_fly.c",\
"guidance" : "/cmds/spells/g/_guidance.c",\
"levitate" : "/cmds/spells/l/_levitate.c",\
"owls wisdom" : "/cmds/spells/o/_owls_wisdom.c",\
"see the unseen" : "/cmds/spells/s/_see_the_unseen.c",\
"shield of shadows" : "/cmds/spells/s/_shield_of_shadows.c",\
"spider climb" : "/cmds/spells/s/_spider_climb.c",\
"spiderwalk" : "/cmds/spells/s/_spiderwalk.c",\
"sustenance" : "/cmds/spells/s/_sustenance.c",\
"sylvan vigor" : "/cmds/spells/s/_sylvan_vigor.c",\
"thicken skin" : "/cmds/spells/t/_thicken_skin.c",\
"true seeing" : "/cmds/spells/t/_true_seeing.c",\
"umbral sight" : "/cmds/spells/u/_umbral_sight.c" ])

#define SCOLS (["deep purple" : ({"%^BOLD%^%^MAGENTA%^", "%^MAGENTA%^"}),\
"deep blue" : ({"%^BLUE%^", "%^BOLD%^%^BLUE%^"}),\
"emerald green" : ({"%^GREEN%^", "%^BOLD%^%^GREEN%^"}),\
"flaming red" : ({"%^RED%^", "%^BOLD%^%^RED%^"}),\
"brilliant yellow" : ({"%^YELLOW%^", "%^BOLD%^%^YELLOW%^"}),\
"midnight black" : ({"%^BOLD%^%^BLACK%^"}),\
"snow white" : ({"%^BOLD%^%^WHITE%^"}),\
"powder blue" : ({"%^CYAN%^", "%^BOLD%^%^CYAN%^"}), ])

inherit OBJECT;

int delay;

string SCOL, StoneColor, MySpell;

void create() 
{
    string *Cols, *MySpells;
    int x;
    ::create();
    Cols = keys(SCOLS);
    StoneColor = Cols[random(sizeof(Cols))];
    
    x = random(sizeof(SCOLS[StoneColor]));
    SCOL = "%^RESET%^" + SCOLS[StoneColor][x];
    
    set_id( ({ "stone", "source stone", "sourcestone", 
    StoneColor+" stone"}) );
    
    set_name("a "+StoneColor+ " stone");

    set_obvious_short(SCOL+"A "+StoneColor+" source stone%^RESET%^");

    set_short(SCOL +"A "+StoneColor+" %^BOLD%^%^WHITE%^s%^RESET%^"+SCOL+
    "ou%^BOLD%^%^WHITE%^rc%^RESET%^"+SCOL+"e %^BOLD%^%^WHITE%^st%^RESET%^"+SCOL+
    "o%^BOLD%^%^WHITE%^n%^RESET%^"+SCOL+"e%^RESET%^");
    
    MySpells = keys(POSSIBLE_EFFECTS);
    MySpell = MySpells[random(sizeof(MySpells))];
    
    set_long(SCOL+"This mysterious "+StoneColor+" stone is very thin and "+
    "almost perfectly square. It is entirely smooth. In fact, it appears almost "+
    "flawless. It gives off a slight %^BOLD%^%^WHITE%^aura"+SCOL+" that is "+
    "difficult to identify. You have an almost uncontrollably desire to %^BOLD%^%^WHITE%^"+
    "focus"+SCOL+" on it, as if something within the stone is calling out to you.%^RESET%^");
    set_weight(1);

    set_lore(SCOL+"These stones were rumored to be quite common in the Charu Mountains "+
    "region of the world at one point. They are known as sourcestones. The rumors relating to their "+
    "origins are a lot more shrouded in mystery. Some legends suggest that they were "+
    "imbued by a wizard of some renown years ago and were passed out through the region. "+
    "However, another rumor suggests that they are in fact naturally occuring because of "+
    "something that happened within the region centuries ago. Neither rumor has "+
    "that much credibility behind it and both are spotty to say the least. What is known "+
    "for certain is that these stones are imbued with some measure of magic which can "+
    "be activated simply by focusing on the stone intently. This particular stone is "+
    "imbued with "+MySpell+".%^RESET%^");

    set_property("lore difficulty", 15);


}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("focus", "focus");
    }
}
int query_delay() { return delay; }
int set_delay(int x) { delay = x; }
string query_MySpell() { return MySpell; }
void set_MySpell(string str) { if(stringp(str)) MySpell = str; }

int focus(string str)
{
    string me;
    object EffectOb, targOb, who;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(!objectp(targOb = present(str, ETO))) return 0;
    if(!objectp(environment(targOb))) return 0;
    who = environment(targOb);
    if(!living(who)) return 0;
    
    me = targOb->query_short();
    
    if((int)targOb->query_delay() > time()) 
    {
        tell_object(who, me +SCOL+" fails to respond!%^RESET%^");
        return 1;
    }
    else
    {
        
        if(catch(EffectOb = new(POSSIBLE_EFFECTS[targOb->query_MySpell()])))
        {
            tell_object(who, "ERROR: Something wrong with "+MySpell+" in your sourcestone.");
            return 1;
        }
        tell_object(who, SCOL+"You begin focusing intently on "+me+" and feel knowledge flood your mind!%^RESET%^");
        
        tell_room(environment(who), who->QCN+SCOL+" begins focusing intently on "+who->QP+" "+me+SCOL+"!%^RESET%^", who);
        EffectOb->use_spell(who, who, 20, 100);
        if(random(1)) 
        {
            tell_object(who, me+SCOL+" crumbles to dust!%^RESET%^");
            tell_room(environment(who), who->QCN+SCOL+"'s "+me+SCOL+" crumbles to dust!%^RESET%^", who);
            targOb->remove();
            return 1;
        }
        else 
        {
            targOb->set_delay(time() + 600);
            return 1;
        }       
        return 1;
    }
    return 1;
    
    
}

int isMagic() { return 2;}
