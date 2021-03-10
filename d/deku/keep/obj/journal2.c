#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("journal entry");
    set_id(({ "journal entry", "journal","parchment","paper","torn parchment","torn paper"}));
    set_short("torn piece of parchment");
    set_obvious_short("torn piece of parchment");
    set_long("This is a torn piece of parchment with writing on it.");
    set_read("I have just entered the lair of the beasts.  The entrance was "+
    "in the forest as I "+
    "was told... there I found the remains of my friend.. "+
    "I am still pained by it, but I know "+
    "that now I have no time to mourn.  I still believe that "+
    "those keys provide an answer, "+
    "perhaps even a method into this lair, I dread to "+
    "think that there is such an easy way "+
    "out... the wolves could venture out whenever they wished.  "+
    "I'm not sure what I will do now, "+
    "I must look for my other companion... I fear the worst.  I've seen some of the "+
    "hieroglyphics but I know of none of the command words my friend said he heard some of "+
    "them issue... I do remember he even mentioned an ogre and that some of the words seemed "+
    "almost like names to him.  I know not what they could be, I suppose it's possible that "+
    "they have an intricate system here somehow, I've found "+
    "parts of this place is really well "+
    "kept, as if they have a method that they follow.  "+
    "I finish this now, one of them is coming, "+
    "I MUST hide this for later.");
    set_language("gnomish");
    set_weight(1);
    set_value(1);
}