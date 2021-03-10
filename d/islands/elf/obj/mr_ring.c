//code shamelessly stolen from thorn
#include <std.h>
inherit "/d/common/obj/jewelry/ring.c";
int uses, old;
object protect;

int resist_magic();
int takeoff();
void create()
{
    ::create();
    set_property("ring of magic protection", 1);
    set_property("magic", 1);
    set_name("ring");
    set_id(({"ring", "ring of magic protection","obsidian ring",
            "glowing obsidian ring"}));
    set_short("%^RESET%^%^BOLD%^%^BLACK%^an obsidian ring%^RESET%^");
    set_long("%^MAGENTA%^This is a rather elegant ring made from %^BOLD%^%^BLACK%^obsidian.  "+
	"%^RESET%^%^MAGENTA%^Crafting anything from such material is quite difficult.  "+
	"All of the imperfections in the ring are rather in the "+
	"shape of %^BOLD%^%^BLACK%^runes%^RESET%^%^MAGENTA%^.  It looks somewhat dark and rough from a"+
	" distance but closer inspecting shows the masterwork craftsmanship.%^RESET%^");
    set_lore("Thise rings are favorites of the gold elven "+
	"mages who wish to practice magic with less danger.  "+
	"They are quite valuable and can also double as a badge"+
	" of pride.  Many stories exist about how rings like "+
	"these saved and elf's life");
    set_property("lore difficulty",30);
    set_value(2025);
    set_wear((:TO,"do_wear":));
    set_remove((:TO,"takeoff":));
    uses = roll_dice(1,12)+10;
}

int do_wear()
{
    object *stuff, onering;
    int i,j, flag;

    stuff = ETO->all_armour();
    j = sizeof(stuff);

    for(i=0;i<j;i++)
    {
        if((string)stuff[i]->query_type() == "ring" &&
stuff[i]->query_property("ring of magic protection"))
        {
            onering = stuff[i];
            flag = 1;
            break;
        }
    }

    if(flag)
    {
        write("%^BOLD%^The magic of this ring "+
		"reacts with the one already worn...\n"+
            "and they %^RED%^EXPLODE!!");
		ETO->cause_typed_damage(ETO,0,roll_dice(5,10),"fire");
        if(!onering->remove()) destruct(TO);
        if(!TO->remove()) destruct(TO);
        return 0;

    }

    if(ETO->query_property("raised resistance"))
    {
        tell_object(ETO,"%^BOLD%^The magical spell protecting you"+
		" conflicts with the magic in the ring, and it "+
            "forcefully repels your hand!");
        return 0;
    }

    if((int)ETO->query_highest_level() < 20)
    {
        tell_object(ETO,"%^BOLD%^You aren't powerful enough"+
		" to use this item yet!");
        return 0;
    }

    protect = ETO;
    protect->set_property("magic resistance", 60);
    protect->set_property("raised resistance", 1);
    set_heart_beat(30);

    tell_object(ETO, "%^CYAN%^The ring flashes brightly for a brief instant "+
        "on your finger and then fades to a %^GREEN%^green glow.");
    TO->set_short("%^GREEN%^a glowing obsidian ring");
    return 1;
}

void heart_beat()
{
    if (!objectp(TO->query_worn())) TO->takeoff();
    if(!objectp(TO) || !objectp(ETO) || !objectp(protect)) return;

    if(uses <= 0)
    {
        tell_object(protect, "%^GREEN%^The ring flashes and suddenly "+
            "is no more!");
        set_heart_beat(0);

        takeoff();
        if(!TO->remove()) destruct(TO);
        return 1;
    }

    if(!ETO->is_monster()) { uses--; }

    tell_object(protect, "%^GREEN%^The ring %^BOLD%^flashes%^RESET%^%^GREEN%^ for a moment.");
    return 1;
}

int takeoff()
{
    set_heart_beat(0);
    if(objectp(protect))
    {
    protect->set_property("magic resistance",-60);
    protect->set_property("raised resistance",-1);
    }
    TO->set("short","%^RESET%^%^BOLD%^%^BLACK%^an obsidian ring%^RESET%^");

    protect = 0;
    return 1;
}
