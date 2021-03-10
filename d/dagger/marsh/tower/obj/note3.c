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
	"shoulder. I leapt from my chair in fear that all was trickery\n"
	"and he had weakened my fear for himself only to lower my guard\n"
	"in such to slay me. But he quickly sat down in the very chair\n"
	"I often fall asleep in late at night while absorbed in research\n"
	"and said, `It is I, Slatulzzk. Do not fear me for we are of a kindred\n"
	"spirit and I wish no harm to befall you.'\n"
	"     We spent most of that night talking of things no mortals\n"
	"were ever meant to hear...things which now I wish I had never\n"
	"heard or known. He left me stunned and deep in thought mintues\n"
	"before the sun began to rise in the east. I gazed upon the sunrise\n"
	"despite the way it made my eyes feel as though they were bleeding\n"
	"inside their sockets. Before it fully had risen I collapsed to the\n"
	"floor and slumbered through the entire day, my dreams not of my\n"
	"companion, but filled with horrible visions which even now I block\n"
	"out of my mind lest madness consume me entirely and I fail to finish\n"
	"writing to those who will finally come to destroy me.\n"
	"     We spent the next evening (yes he came yet again, unseen\n"
	"and unheard as creatures of the night are so aptly enabled)\n"
	"travelling to places where mortals tend to avoid even when\n"
	"surrounded by daylight. Even to this moment I am sure that had I\n"
	"not had my companion with me I would have perished at the hands of\n"
	"the creatures who guarded the various resting grounds and shrines\n"
	"of the places we needed to plunder. Various mystical devices,\n"
	"and instruments, ancient artifacts, and rare components did we\n"
	"gather. Foolishly, I made a list of these things, a list which\n"
	"I misplaced later. I had meant to destroy it, but it's location\n"
	"escapes me and even now as I try to remember it's whereabouts I\n"
	"wracked with such pains like I have never felt before. My only\n"
	"relief from the thought that I made such a list, is that I failed\n"
	"to record the ritual of steps and preparations needed to complete\n"
	"the vile passage into undeath. During the gathering, during the\n"
	"preparation, during the ritual and even during the final speaking\n"
	"of the invocation, I never once had doubts or remorse for what I\n"
	"was doing. I now wonder if my passion for the project clouded my\n"
	"true senses or if something far greater was purposely keeping\n"
	"my mind clouded. Nonetheless, I failed to question the sanity of\n"
	"what I was about to do.\n"
	"     It was not until after all was done and the walk into undeath\n"
	"slowly began to creep into my soul and body did I begin to see\n"
	"the horror of what I had done. It was in the evening following\n"
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

	
