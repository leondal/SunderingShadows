#include <std.h>

inherit OBJECT;

void dest_effect();

object caster,casting_spell;
int duration,FLAG;

void create()
{
    ::create();
    set_id( ({ "table","banquet table","banquet","feast","heroes feast" }) );
    set_name("Heroes Feast");
    set_short("%^YELLOW%^An elaborate banquet table%^RESET%^");
    set_long("%^ORANGE%^This huge banquet table is covered with a silken cloth.  "+
		"Woven upon the cloth are images of all sorts of dragons, "+
		"celestials, demons, devils, elementals, and other fantastic"+
		" beasts, displayed in a heroic fashion.  The table is crowded"+
		" with platters of %^BOLD%^%^WHITE%^silver%^RESET%^%^ORANGE%^ "+
		"and %^YELLOW%^gold%^RESET%^%^ORANGE%^, each overflowing with "+
		"mouth-watering treats.  Racks of %^RED%^roasted meat%^ORANGE%^,"+
		" %^BOLD%^%^RED%^thick juicy steaks%^RESET%^%^ORANGE%^,"+
		" %^YELLOW%^stuffed pheasants%^RESET%^%^ORANGE%^, and "+
		"%^BOLD%^%^CYAN%^seared seafood%^RESET%^%^ORANGE%^ rest on silver platters.  "+
		"A large cornucopia filled with fresh %^BOLD%^%^GREEN%^a%^YELLOW%^p%^RED%^"+
		"p%^GREEN%^l%^YELLOW%^e%^RED%^s%^RESET%^%^ORANGE%^, %^MAGENTA%^grapes"+
		"%^ORANGE%^, oranges, %^YELLOW%^lemons%^RESET%^%^ORANGE%^, "+
		"%^BOLD%^%^MAGENTA%^peaches %^RESET%^%^ORANGE%^and %^BOLD%^%^GREEN%^"+
		"melons%^RESET%^%^ORANGE%^ spills out onto the cloth.  In golden"+
		" dishes %^GREEN%^roasted asparagus%^ORANGE%^, %^RED%^baked potatoes"+
		"%^ORANGE%^, roasted ears of %^YELLOW%^corn%^RESET%^%^ORANGE%^, "+
		"and %^BOLD%^%^GREEN%^fresh greens%^RESET%^%^ORANGE%^ lay.  Platters of "+
		"gold hold fresh baked %^MAGENTA%^pastries%^ORANGE%^,"+
		" %^BOLD%^%^WHITE%^cakes%^RESET%^%^ORANGE%^, and %^CYAN%^pies%^ORANGE%^.  "+
		"Glass decanters of %^MAGENTA%^wine%^ORANGE%^, %^BOLD%^%^CYAN%^water%^RESET%^"+
		"%^ORANGE%^, and %^YELLOW%^ale%^RESET%^%^ORANGE%^ rest near"+
		" ornate goblets. As you give a second look at the feast before you, "+
		"even more dishes seem to materialize.  A %^BOLD%^%^MAGENTA%^feast%^RESET%^"+
		"%^ORANGE%^ fit truly for a hero!\n\nType <feast> to eat from the table.");
    set_weight(100000);
    set("value", 0);
    set_property("no animate",1);
    set_property("no offer", 1);
    set_heart_beat(10);
}

void feast_func()
{
    if(!objectp(TP)) { return; }
    if(sizeof(TP->query_attackers()))
    {
        tell_object(TP,"You are much too busy to eat right now!");
        return 1;
    }
    if(!(int)TP->add_stuffed(50000) && !(int)TP->add_quenched(50000))
    {
        tell_object(TP,"You are already much too full for anymore food or drink.");
        return 1;
    }
    TP->add_stuffed(50000);
    TP->add_quenched(50000);
    TP->set_condition(0);
    tell_object(TP,"You eat and drink your fill of the delicious cuisine and feel "
        "refreshed and revitalized.");
    return 1;
}

void init()
{
    ::init();
    add_action("feast_func","feast");
    return;
}

void set_duration(int x)            { duration = x; }
void set_caster(object obj)         { caster = obj; }
void set_casting_spell(object obj)  { casting_spell = obj; }

void heart_beat()
{
    if(!objectp(ETO))
    {
        dest_effect();
        return;
    }
    if(!objectp(caster) || !userp(caster))
    {
        call_out("dest_effect",duration);
        set_heart_beat(0);
        return;
    }
    if(!present(caster,ETO) && !FLAG)
    {
        FLAG = 1;
        call_out("dest_effect",duration);
        return;
    }
    if(present(caster,ETO) && FLAG)
    {
        FLAG = 0;
        remove_call_out("dest_effect");
        return;
    }
    return;
}

void dest_effect()
{
    tell_object(ETO, "The banquet table vanishes before your eyes!");
    if (objectp(casting_spell)) {
        casting_spell->dest_effect();
    }
    TO->remove();
    return;
}
