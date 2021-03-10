#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("folded note");
    set_id(({ "paper", "folded paper", "note", }));
    set_short("%^BOLD%^%^WHITE%^A hastily scrawled and carefully folded note%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This dingy piece of paper has been carefully folded. You "+
    "can make out some writing on it that looks like someone scrawled it in quite a hurry."+
    " You should read it.%^RESET%^");
    set_read("%^RESET%^It seems that they were wrong.... there is no treasure here... "+
    "or at least nothing that I want to find. I have come here because of the "+
    "rumor of some unexplored 'tombs' but I haven't found them, I don't think any of the "+
    "others have either.\n\nI did notice some strange figures, that looked somehow perverted "+
    "or corrupted, no doubt by foul magic, whispering amongst themselves. They all seemed to have "+
    "disappeared from the desert now though. They kept repeating some phrase, over and over and over "+
    "again, I will never forget it. 'Asantra show me the way' as if they were expecting something to "+
    "happen.... or someone to literally show them a way to some place... A few of them were also mumbling "+
    "something about a series... and I think they said that the second or third part of the series was "+
    "'wer' a draconic word for the, according to the boss. \n\nI don't know what happened "+
    "to them either. I did see a few of them coming off one of the larger sand dunes, so I went up "+
    "to explore and found the corpse of some enormous minotaur, something some ogres were mumbling "+
    "about and calling a 'dreadhorn', whatever that means. They seemed to think it an ancient minotaur "+
    "of some renown, I think it's better off dead.\n\nI did see one of those figures carrying a horn that "+
    "might have come from that minotaur or one like it, but I've decided I should wait around here for "+
    "the adventurers that will undoubtably come and try to take what I can from them. We have all decided to do the "+
    "same. We have also each been sharing and keeping up with what we might find, maybe will will have something "+
    "decent to take back home with us before this is all over.%^RESET%^");

    set_language("wizish");
    set_weight(0);
    set_value(0);
}