#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("crumpled paper");
    set_id(({ "paper", "crumpled paper", "parchment", }));
    set_short("%^MAGENTA%^A piece of crumpled paper%^RESET%^");
    set_long("%^BOLD%^%^MAGENTA%^This is a piece of paper that has "+
    "been crumpled up into a wad. It might be important, so you should "+
    "read it.%^RESET%^");
    set_read("%^BOLD%^%^MAGENTA%^I do not think that I will make it home....\n"+
    "I have learned little about this place but I now know that "+
    "my venture into here was a foolish one. This place changes, "+
    "constantly, as if manipulated by something tremendously "+
    "powerful. The stairs up are gone now but there is a "+
    "%^BOLD%^%^YELLOW%^doorway%^BOLD%^%^MAGENTA%^ which seems "+
    "to move around on its own, somehow. It leads up and from "+
    "upstairs, there is another %^BOLD%^%^YELLOW%^doorway%^BOLD%^"+
    "%^MAGENTA%^ that leads back down... I think there is a basement "+
    "somewhere also, but I have not been able to find it. And BY THE GODS "+
    "do NOT go on the roof... something is living there and "+
    "it is not alone. I think a ritual of sorts is taking place, "+
    "I snuck through and got a look, there is a giant skeleton on an "+
    "altar, but it requires a blood sacrifice from a ceremonial dagger, as "+
    "far as I can tell. I have found no such dagger and if it is here "+
    "it is my belief that it has been broken apart and hidden, so "+
    "that no one might interrupt the ceremony until HE "+
    "is ready. I hide this in the bed, but I am not sure which "+
    "bed or which room, sometimes the room I am in is a laboratory, "+
    "or a dining hall, or even a storage room. My hope is that "+
    "what I have learned will help someone who comes after me "+
    "to be rid of this abominable place once and for all. "+
    "I fear, if not, something sinister, even more sinister "+
    "than what is on the roof will swallow up the entire "+
    "Deku Island. Gods be with you....%^RESET%^");

    set_language("wizish");
    set_weight(0);
    set_value(0);
}