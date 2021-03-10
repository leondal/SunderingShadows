// trying to fix to use set_read() - last change was 6/01  *Styx* 8/2003
// didn't seem to be working and I couldn't make it work, so reverted it to 
// an add_action - Lujke April 15 2007
#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("readpage_fun","read");
}
void create() {
    ::create();
    set_name("note");
    set_id(({"note", "page"}));
    set_short("%^RESET%^%^GREEN%^A note page from a journal%^RESET%^");
    set_long(
	"%^MAGENTA%^This is a note page that was torn from a journal. There "
	"is much writing covering it which can be read."
	"%^RESET%^"
    );
    set_weight(1);
    set_value(5);
//    set_read( (:TO, "readpage_fun":) );
}

int readpage_fun(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "page" && str != "note") {
	notify_fail("Read what?\n");
	return 0;
    }
    tell_room(EETO,"%^RED%^"+ETOQCN+
     " reads over a page of writing for a few minutes, then looks up with "
    +"a troubled look in "+ETO->query_possessive()+" eyes.%^RESET%^" ,ETO);
    tell_object(ETO, "%^RED%^The note scrawled in black ink reads:\n"
    +"\n%^BOLD%^%^BLUE%^"
    +"     It is with great haste now that I continue to write\n"
    +"this journal to tell of the misfortune which has gripped me\n"
    +"in fear and panic for the last few days now. The sun of day\n"
    +"causes such a uncontrollable sickness and fever within my soul\n"
    +"that it is only by candlelight and with most of my inner\n"
    +"strength hellbent upon the purpose to warn and inform those\n"
    +"who one day shall come to discover whereas I have gone and to\n"
    +"what damnable fate I have condemned myself. I write now of my\n"
    +"epic (epic...if I can call it epic for there is no honour nor\n"
    +"glory within this tale) adventure as a friend to those who\n"
    +"now discover it, yet by the time another's eyes perceive this\n"
    +"I will be an enemy to all within the land of the living...there\n"
    +"is no escape from it; I am forever damned.\n"
    +"     It began shortly after the first two Vampyres of the trio\n"
    +"were slain and the third vanished. The rulers of the lands (I\n"
    +"was never one to have rulers, but was always willing to aid the\n"
    +"leaders of our fair lands as it suited my purposes) asked I,\n"
    +"Vecna, master of all forms of Necromantic magic, to seek out\n"
    +"the third of the trio of Vampyres and slay it before it could\n"
    +"regain it's strength and ravish the lands once again. I relished\n"
    +"in the chance to do this, not to stop or slay it's evil malice,\n"
    +"but because it was an ample chance to examine and learn more\n"
    +"about these deadly creatures; all things of death and undeath\n"
    +"did I long to learn of...such an idiotic pursuit I now realise.\n"
    +"     I hunted the lands for many moons to find where the creature\n"
    +"had chosen to lay in waiting for it's power to replenish, and with\n"
    +"each passing moon I feared it's power...no...*felt* it's power\n"
    +"growing (even then I began to realise the strange interest the\n"
    +"creature had with myself). I had nearly given up all hope for\n"
    +"near the end of my search two very important things troubled my\n"
    +"soul. One, I knew I had run out of time and that it would be fully\n"
    +"replenished by now and the thought of facing it at full strength\n"
    +"darkened my soul with immense fear. The second reason troubled\n"
    +"me more...it had visited me in my troubled sleep, in my dreams\n"
    +"I could see it's face and hear it's garbled whisper, telling me\n"
    +"of a power far greater than that which possessed it's troubled\n"
    +"soul, telling me where to find this, how to do this, to achieve\n"
    +"that which I spent a lifetime to learn, the secret of how one may\n"
    +"\n%^RED%^(The page ends here.)");
    return 1;
}

	
