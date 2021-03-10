#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("readpage_fun","read");
}
void create() {
    ::create();
    set_name("note");
    set_id(({"note"}));
    set_short("%^RESET%^%^GREEN%^A note page from a journal%^RESET%^");
    set_long(
	"%^MAGENTA%^This is a note page that was torn from a journal. There "
	"is much writing covering it which can be read."
	"%^RESET%^"
    );
    set_weight(1);
    set_value(5);
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
    write("%^RED%^The note scrawled in black ink reads:\n"
	"\n%^BOLD%^%^BLUE%^"
	"the ritual that it came to me with such a force of reckoning\n"
	"unlike any mortal envisioning I had encountered in my waking\n"
	"life before me.\n"
	"     I have already spoken of the Limbo which creatures such as my\n"
	"companion and myself now fear more than we feared death in our\n"
	"mortal lives. My companion failed to mention the visions one gets\n"
	"after the ritual is completed but before the process completes.\n"
	"It is the waiting or latency period which is the worst. Perhaps\n"
	"the transformation to a Vampyre does not include such visions.\n"
	"I think it does, but my companion knew I would have destroyed\n"
	"myself before succumbing to this nonsense if I had been aware.\n"
	"What I have seen is the rage I will wreak upon the land of the\n"
	"living in my final form. A Vampyre can do much damage to the souls\n"
	"of this land in it's passage of existance, but alternative measures\n"
	"can allow it to feast on the life blood of lower forms if it wishes\n"
	"too. In fact, they have been known to feast upon the very stones\n"
	"of the earth if need be. And it is only mortal souls who will\n"
	"attempt to do what we fear most...destroy us. The form I choose,\n"
	"so foolishly, that of Lychzd or Lich as most mortals refer to it as,\n"
	"is so evil in it's passion to build it's undead empire, it will\n"
	"actively seek to enslave everything mortal within the entire\n"
	"realm it exists upon. When I turn fully forward into that form,\n"
	"I have seen in my visions what I will attempt to do, a great venom\n"
	"of destruction and venom shall crawl across the lands, building\n"
	"an army of undead and pure wretched evil which will consume everything\n"
	"within it's wake. And I have seen worse. I have seen that all things\n"
	"must pass, even the death span of a Lich, for there is no power, but\n"
	"that of the Immortals which can exist forever. The time I will live\n"
	"in death as a Lich, the time which I can hope to rule this savage\n"
	"power is like a grain of sand upon all the beaches in this realm of\n"
	"existance, when compared to the time I will spend in Limbo, tormented\n"
	"and enslaved by the very souls I will own within this undeathtime.\n"
	"I hope my words are clear, I hope this reaches someone who realises\n"
	"what I have done and why. It is not your pity I seek, no that would\n"
	"even be asking to much...I write this only to explain what happened\n"
	"to the great Necromancer Vecna, and to explain what I am about to\n"
	"do to ensure that I am prevented from releasing my power across\n"
	"this land and that there will be a means to remove me forever from\n"
	"this realm of existance. It is six hours by my estimation until\n"    
	"\n%^RED%^(The page ends here.)"
    );
    say("%^RED%^"+TPQCN+
        " reads over a page of writing for a few minutes, then looks up with "
	"a troubled look in "
	+TP->query_possessive()+
	" eyes.%^RESET%^"
    ,TP);
    return 1;
}
