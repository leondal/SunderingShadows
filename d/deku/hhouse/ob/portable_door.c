#include <std.h>
#include "../inherits/area_stuff.h"

inherit OBJECT;
int delay;
object myRoom;

void create()
{
    ::create();
    set_name("portable door");
    set_value(5000);
    set_weight(5);

    set_id(({"doorway", "portable doorway", "door", "portable door"}));

    set_property("no animate", 1);

    set_obvious_short("%^BOLD%^%^MAGENTA%^portable door%^RESET%^");

    set_short("%^BOLD%^%^CYAN%^Au%^BOLD%^%^WHITE%^r'%^BOLD%^%^CYAN%^u"+
    "%^BOLD%^%^WHITE%^s D%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^v%^BOLD%^%^CYAN%^"+
    "a%^BOLD%^%^WHITE%^r's%^BOLD%^%^MAGENTA%^ portable door%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This tiny door is constructed from a "+
    "%^BOLD%^%^MAGENTA%^bright purple%^BOLD%^%^CYAN%^ material. It almost "+
    "feels like a fabric but it is much more solid and sturdy. It is outlined "+
    "with a %^RESET%^%^ORANGE%^dull gold%^BOLD%^%^CYAN%^ and slightly jagged "+
    "material that wavers almost constantly. There are illegible words "+
    "covering almost all of it that shift about constantly, seemingly without "+
    "rhyme or reason. The only one that you can decipher is "+
    "%^BOLD%^%^WHITE%^crawl%^BOLD%^%^CYAN%^ and you are not sure what that "+
    "might mean. It has no visible means of opening or closing that you can "+
    "ascertain.%^RESET%^");

    set_property("lore difficulty", 20);
    set_lore("%^BOLD%^%^WHITE%^Created long ago by Ao'rus Devar, sometime "+
    "after his mind had changed, this doorway is said to open a portal "+
    "into the mind, which one can enter. What might rest inside the "+
    "portal is a mystery though, however, there is one obvious way to find "+
    "out and that is to %^BOLD%^%^CYAN%^crawl%^BOLD%^%^WHITE%^ into the door "+
    "and see what happens.%^RESET%^");
    delay = 0;
    set_heart_beat(1);
}

int is_invincible() { return 1; }

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(delay <= 0) return;
    delay--;
    if(delay < 0)
    {
        delay = 0;
        tell_object(ETO, "%^BOLD%^%^CYAN%^You feel a %^BOLD%^%^RED%^warmth"+
        "%^BOLD%^%^CYAN%^ emanate from the door and you realize that "+
        "you can now crawl into it again!%^RESET%^");
    }
    return;
}

void init()
{
    ::init();
    add_action("entry_function", "crawl");
}

int entry_function(string what)
{
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!stringp(what)) return 0;
    if(!living(ETO)) return 0;
    if(TO != present(what, ETO)) return 0;
    if (ETO->query_bound() ||
    ETO->query_unconscious() ||
    ETO->query_paralyzed())
    {
        ETO->send_paralyzed_message("info", ETO);
        return 1;
    }
    if(delay)
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^The door fails to respond to your urging "+
        "and you are unable to crawl into it!%^RESET%^");
        return 1;
    }
    if(EETO->query_property("no teleport") || ETO->query_property("teleport proof") > 60 + random(10) || EETO->query_property("teleport proof") > 60 + random(10) )
    {
        tell_object(ETO, "%^BOLD%^%^RED%^Magical forces bar your entry into the door!%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^Willing yourself, you manage to %^YELLOW%^crawl "+
    "%^BOLD%^%^WHITE%^through the doorway and find yourself some place else!%^RESET%^");

    tell_room(EETO, "%^BOLD%^%^WHITE%^You watch in amazement as "+ETOQCN+"%^BOLD%^%^WHITE%^ "+
    "squeezes "+ETO->QO+"self into a tiny "+TO->query_name()+"!%^RESET%^", ETO);

    if(!objectp(myRoom))
    {
        myRoom = new(DOORROOM);
    }
    myRoom->setup_room(ETO);
    ETO->move(myRoom);
    ETO->force_me("look");
	//upping to approximately every 30 minutes
    delay = 900;

    return 1;
}
