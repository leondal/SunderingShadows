#include <std.h>

inherit OBJECT;

void dest_effect();

object caster,casting_spell;
int duration,FLAG;

void create()
{
    ::create();
    set_id( ({ "table","shadowfeast","shadow feast","feast","heroes feast","stall","food stall","long food stall" }) );
    set_name("shadow feast");
    set_short("%^YELLOW%^A long food stall%^RESET%^");
    set_long("%^ORANGE%^This long table is covered with a patchwork stained cloth.  "+
		"From the color and quality, it was clearly gathered from tables across "+
		"the city. The stall's constant use means that there is never time to "+
		"clean up the many spills and crumbs that cover it. On top are "+
		" wooden plates, wooden and clay bowls, more cloths for holding food, "+
		"and iron pots of bland soups, stews of strange tubers, and hard, plain bread."+
		" Jugs of water and watered down wine dot the stall, refilling from wooden"+
		" barrels sitting back near the volunteers and dead-eyed civil servants."+

		"\n\nType <feast> to eat from the table.");
    set_weight(100000);
    set("value", 0);
    set_property("no animate",1);
    set_property("no offer", 1);
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
